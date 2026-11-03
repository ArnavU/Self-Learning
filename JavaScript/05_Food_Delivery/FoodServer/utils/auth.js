const jwt = require('jsonwebtoken');

const { errorResult } = require('./result');
const config = require('./config');

async function auth(req, res, next) {
    const path = req.path;
    console.log("Path: " + path)
    if(path == '/user/signin' || path == '/user/signup' || path == '/food/menu') 
        next();
    else {
        const token = req.headers.token;
        try {
            const payload = jwt.verify(token, config.JWT_SECRET);
            req.headers.uid = payload.uid;
            next();
        } catch(error) {
            return res.send(errorResult(error.message));
        }
    }
}

module.exports = auth;