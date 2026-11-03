const express = require('express');
const { errorResult, successResult } = require('../utils/result');
const pool = require('../db/pool');
const router = express.Router();

/*
body = {
    "total" : "290.99",
    "cartItems" : [
        {"fid": 2, "qty": 3},
        {"fid": 3, "qty": 4}
    ]
}
*/

// add order
router.post('/', async(req, res) => {
    const sql1 = 'INSERT INTO orders (uid, total_amount) VALUES(?,?);';
    const sql2 = 'INSERT INTO orderdetails (oid, fid, quantity) VALUES(?,?,?);';
    const uid = req.headers.uid;
    const {total, cartItems} = req.body;
    try {
        const orderData = await pool.query(sql1, [uid, total]);
        const oid = orderData[0].insertId;
        for(item of cartItems) {
            await pool.query(sql2, [oid, item.fid, item.qty]);
        }
        res.send(successResult(orderData[0]));
    } catch(error) {
        res.send(errorResult(error.message));
    }
})

// view order history
router.get('/', async(req, res) => {
    const sql = 'SELECT * FROM orders WHERE uid = ?;';
    const uid = req.headers.uid;

    try {
        const data = await pool.query(sql, [uid]);
        res.send(successResult(data[0]));
    } catch(error) {
        res.send(errorResult(error.message));
    }
})


module.exports = router;