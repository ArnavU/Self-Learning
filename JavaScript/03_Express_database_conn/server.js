const express = require('express');
const mysql2 = require('mysql2/promise');
const app = express();

const pool = mysql2.createPool({
    host: 'localhost',
    user: 'root',
    password: 'Arnav@123',
    database: 'sales'
});


app.get('/', async (req, res) => {
    const sql = 'SELECT * FROM customers;'
    const result = await pool.query(sql);

    return res.send(result[0]);
})

app.listen(4000, 'localhost', () => {
    console.log("Server is up and running on port 4000");
})