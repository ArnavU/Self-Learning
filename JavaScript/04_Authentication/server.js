const express = require('express')
const config = require('./utils/config');
const pool = require('./db/pool');
const auth = require('./utils/auth');
const userRouters = require('./routes/user.routes');
const app = express();

// middlewares
app.use(auth);
app.use(express.json());
app.use('/user', userRouters)

app.listen(4000, 'localhost', () => {
    console.log("Server is up and running at port no. 4000") 
})