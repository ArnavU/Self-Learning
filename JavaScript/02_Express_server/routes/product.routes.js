const express = require('express');
const router = express.Router();

router.get('/', (req, res) => {
    res.send("<h1>All Products from express</h1>");
})

router.post('/', (req, res) => {
    res.send("<h1>Product added successfully through express!!</h1>");
})

router.put('/', (req, res) => {
    res.send("<h1>Product updated successfully through express!!!</h1>");
})

router.delete('/', (req, res) => {
    res.send("<h1>Product deleted successfully through express!!!</h1>");
})

module.exports = router;