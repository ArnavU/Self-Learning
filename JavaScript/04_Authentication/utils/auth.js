const jwt = require("jsonwebtoken");
const config = require("./config");
const { createErrorResult } = require("./result");

// vrify path && verify token
async function auth(req, res, next) {
    const path = req.path;
    if(path == '/user/signup' || path == '/user/signin') {
        next();
    } else { // verify token
        const token = req.headers.token;
        try {
            const payload = jwt.verify(token, config.JWT_SECRET);
            req.headers.uid = payload.uid;
            next();
        } catch(error) {
            res.send(createErrorResult(error));
        }
    }
}

module.exports = auth;