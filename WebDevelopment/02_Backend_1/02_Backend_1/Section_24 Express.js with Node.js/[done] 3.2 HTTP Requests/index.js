import exp from "express";
const app = exp();
var port = 3000;

app.listen(port, () => {
    console.log("Server running at port " + port + ".");
});

app.get("/", (req, res) => {
    console.log(req.rawHeaders);
    res.send("<h1>HOMEPAGE: Welcome to the home page.</h1>");
});

app.get("/contact", (req, res) => {
    res.send("Call me: +880123456789");
})

app.get("/about", (req, res) => {
    res.send("I'm a want-to-be-a-farmer PERSON.");
})

