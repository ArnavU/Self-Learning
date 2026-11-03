const express = require('express');
const cors = require('cors');
const app = express();

const auth = require('./utils/auth');
const userRouter = require('./routes/user.routes');
const foodRouter = require('./routes/food.routes');
const orderRouter = require('./routes/orders.routes')

app.use('/foodimage', express.static('FoodImages'))
app.use(cors());
app.use(express.json());
app.use(auth);

app.use('/user', userRouter);
app.use('/food', foodRouter);
app.use('/order', orderRouter);

app.listen(4000, 'localhost', () => {
    console.log("Server is up and running on port no. 4000");
})