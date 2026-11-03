const express = require('express');
const router = express.Router();

router.get('/', (req, res) => {
    res.send("<h1>All users of Express</h1>");
})

router.post('/', (req, res) => {
    res.send("<h1>User added successfully through express!!</h1>");
})

router.put('/', (req, res) => {
    res.send("<h1>User updated successfully through express!!!</h1>");
})

router.delete('/', (req, res) => {
    res.send("<h1>User deleted successfully through express!!!</h1>");
})

module.exports = router;