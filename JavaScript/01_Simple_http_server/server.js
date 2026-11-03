const http = require("http");

function userRounter(req, res) {
	const method = req.method;
	if (method == "GET") {
		return res.end("<h1>All user data.</h1>");
	} else if (method == "POST") {
		return res.end("<h1>User added successfully.</h1>");
	} else if (method == "PUT") {
		return res.end("<h1>User updated successfully!!!</h1>");
	} else if (method == "DELETE") {
		return res.end("<h1>User deleted successfully!!!<h1>");
	}
}

function productRouter(req, res) {
    const method = req.method;
	if (method == "GET") {
		return res.end("<h1>All products data</h1>");
	} else if (method == "POST") {
		return res.end("<h1>Product added successfully!!!</h1>");
	} else if (method == "PUT") {
		return res.end("<h1>Product updated successfully!!!</h1>");
	} else if (method == "DELETE") {
		return res.end("<h1>Product deleted successfully!!!</h1>");
	}
}

const server = http.createServer((req, res) => {
	const path = req.url;

	res.setHeader("content-type", "text/html");

	// user
	if (path == "/user") {
		return userRounter(req, res);
	} else if (path == "/product") {
        return productRouter(req, res);
	}
	return res.end("<h1>Invalid request!!!");
});

server.listen(4000, "localhost", () => {
	console.log("Server running on port no. 4000");
});
