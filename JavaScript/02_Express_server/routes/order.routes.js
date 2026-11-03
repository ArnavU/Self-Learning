const express = require('express');
const router = express.Router();

router.get('/', (req, res) => {
    return res.send("<h1>All order through express!!!</h1>");
})

router.post('/', (req, res) => {
    return res.send("<h1>Order created successfully through express!!!");
})

router.put('/', (req, res) => {
    return res.send("<h1>Order updated successfully through express!!")
})

router.delete("/", (req, res) => {
    return res.send("<h1>Order deleted successfully through express!!!");
})

module.exports = router;