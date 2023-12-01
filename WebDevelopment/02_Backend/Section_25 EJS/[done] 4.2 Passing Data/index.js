import express from "express";
import bodyParser from "body-parser";
import { dirname } from "path";
import { fileURLToPath } from "url";
const __dirname = dirname(fileURLToPath(import.meta.url));

const app = express();
const port = 3000;

app.use(bodyParser.urlencoded({ extended: true }));

app.get("/", (req, res) => {
  res.render("index.ejs", {
    data: "Enter your name below"
  })
});

app.post("/submit", (req, res) => {
  const len = req.body["fName"].length + req.body["lName"].length;
  res.render("index.ejs", {
    data: `There are ${len} letters in your name.`
  })
});

app.listen(port, () => {
  console.log(`Server running on port ${port}`);
});
