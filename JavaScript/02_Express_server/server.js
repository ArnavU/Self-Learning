const express = require('express');
const userRoutes = require('./routes/user.routes');
const productRoutes = require('./routes/product.routes');
const orderRoutes = require('./routes/order.routes');
const app = express();

app.use('/user', userRoutes);
app.use('/product', productRoutes);
app.use('/order', orderRoutes);

app.get('/', (req, res) => {
    res.send("<h1>Server is running</h1>");
})

// console.log(1) 

// app.get('/user', (req, res, next) => {
//     console.log('Route handler 1');
//     next();
// });

// app.use((req, res, next) => {
//     console.log('Middleware executed');
//     next();
// });

// app.get('/user', (req, res) => {
//     console.log('Route handler 2');
//     res.send('User API');
// });

// console.log(2)

app.listen(4000, 'localhost', () => {
    console.log("Server is up and running on port no. 4000");
})