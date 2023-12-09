import { render } from 'ejs';
import express from 'express';
import pg from 'pg';

const PORT = 3000;
const app = express();

app.use(express.urlencoded({extended: true}));
app.use(express.static('public'));

app.get("/", (req, res) => {

    res.render("index.ejs", {});
});

app.post("/user", (req, res) => {

    res.render("new.ejs", {});
});

app.post("/add", (req, res) => {

    res.redirect("/");
});

app.post("/new", (req, res) => { //from new.ejs view
    
});

app.listen(PORT, () => {
    console.log(`Server running at port ${PORT}`);
})