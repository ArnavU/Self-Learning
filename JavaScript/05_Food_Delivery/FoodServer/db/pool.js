const mysql = require('mysql2/promise');

const pool = mysql.createPool({
    host: 'localhost',
    user: 'root',
    password: 'Arnav@123',
    database: 'node_food_delivery'
})

module.exports = pool;