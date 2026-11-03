const express = require('express');
const cryptojs = require('crypto-js');
const router = express.Router();
const result = require("../utils/result");
const pool = require("../db/pool");
const jwt = require("jsonwebtoken");
const config = require("../utils/config")

// signup
router.post('/signup', async (req, res) => {
    const {name, email, password, mobile} = req.body;
    const sql = "INSERT INTO user (name, email, password, mobile) VALUES (?, ?, ?, ?);"
    const hashPassword = cryptojs.SHA256(password);

    try {
        const data = await pool.query(sql, [name, email, hashPassword, mobile]);
        res.send(result.createSuccessResult(data[0]));
    } catch(error) {
        res.send(result.createErrorResult(error.message));
    }
})

// signin
router.post('/signin', async(req, res) => {
    console.log("Sign in api called!!")
    const {email, password} = req.body;
    const sql = "SELECT * FROM user WHERE email = ? AND password = ?";
    const hashPassword = cryptojs.SHA256(password);

    try {
        const data = await pool.query(sql, [email, hashPassword]);
        const userData = data[0][0];
        if(!userData)
            throw new Error("User not found!");
        const payload = {uid: userData.uid};
        console.log("Payload: " + payload.toString())
        const token = jwt.sign(payload, config.JWT_SECRET);

        const user = {...userData, token};
        delete user.password;
        delete user.uid;
        res.send(result.createSuccessResult(user));
    } catch(error) {
        console.log("Error occrued in signin: " + error)
        res.send(result.createErrorResult(error.message));  
    }
})

// update
router.put('/', async(req, res) => {
    const uid = req.headers.uid;
    const mobile = req.body.mobile;
    const sql = "UPDATE user SET mobile = ? WHERE uid = ?;";

    try {
        const data = await pool.query(sql, [mobile, uid]);
        res.send(result.createSuccessResult(data[0]));
    } catch(error) {
        res.send(result.createErrorResult(error.message));
    }
})

// profile
router.get('/profile', async (req, res) => {
    const uid = req.headers.uid;
    const sql = "SELECT * FROM user WHERE uid = ?";
    
    try {
        const data = await pool.query(sql, [uid]);
        const userData = {...data[0][0]};
        delete userData.password;
        delete userData.uid;
        res.send(result.createSuccessResult(userData));
    } catch(error) {
        res.send(result.createErrorResult(error.message));
    }
})


// delete
router.delete('/', async(req, res) => {
    const uid = req.headers.uid;
    const sql = "DELETE FROM user WHERE uid = ?";
    
    try {
        const data = await pool.query(sql, [uid]);
        return res.send(result.createSuccessResult(data[0]));
    } catch(error) {
        res.send(result.createErrorResult(error.message));
    }
})

module.exports = router;