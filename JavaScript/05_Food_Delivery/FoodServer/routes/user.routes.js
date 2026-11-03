const express = require("express");
const cryptojs = require("crypto-js");
const jwt = require('jsonwebtoken');

const router = express.Router();

const pool = require("../db/pool");
const result = require("../utils/result");
const config = require("../utils/config");

router.post("/signup", async (req, res, next) => {
	const { name, email, password, mobile } = req.body;
	const hashPassword = cryptojs.SHA256(password);
	const sql = "INSERT INTO user (name,email,password,mobile) VALUES(?,?,?,?);";

	try {
		const data = await pool.query(sql, [name, email, hashPassword, mobile]);
		res.send(result.successResult(data[0]));
	} catch (error) {
		res.send(result.errorResult(error.message));
	}
});

router.post("/signin", async (req, res, next) => {
	const { email, password } = req.body;
    const hashPassword = cryptojs.SHA256(password);
    const sql = 'SELECT * FROM user WHERE email = ? AND password = ?;';

    try {
        const userData = await pool.query(sql, [email, hashPassword]);
        // user validation
        if(userData[0].length == 0) throw new Error("User not found!!!");

        const {uid, name, mobile} = userData[0][0];
        const payload = {uid};
        const token = jwt.sign(payload, config.JWT_SECRET);
        const data = {
            name, email, mobile, token
        }
        res.send(result.successResult(data));
    } catch(error) {
        return res.send(result.errorResult(error.message));
    }
});

module.exports = router;
