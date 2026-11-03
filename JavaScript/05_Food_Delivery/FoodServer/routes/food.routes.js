const express = require('express');
const multer = require('multer');
const fs = require('fs/promises');
const router = express.Router();

const pool = require('../db/pool')
const result = require('../utils/result')
const upload = multer({
    dest: "FoodImages"
})

// show all menu
router.get('/menu', async (req, res) => {
    const sql = 'SELECT * FROM food';
    try {
        const data = await pool.query(sql);
        res.send(result.successResult(data[0]))
    } catch(error) {
        res.send(result.errorResult(error.message));
    }
})

// add food items 
router.post('/add', upload.single('image'), async (req, res) => {
    const {name, description, price} = req.body;
    const {originalname, path, destination} = req.file;
    
    await fs.rename(path, `${destination}/${originalname}`);
    
    const sql = 'INSERT INTO food (name, price, description, image) VALUES (?,?,?,?);';
    try {
        const data = await pool.query(sql, [name, parseFloat(price), description, originalname]);
        res.send(result.successResult(data[0]));
    } catch(error) {
        res.send(result.errorResult(error.message));
    }
})

module.exports = router;
