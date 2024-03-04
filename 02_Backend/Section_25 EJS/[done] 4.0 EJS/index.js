import express from "express";
import { dirname } from "path";
import { fileURLToPath } from "url";
const __dirname = dirname(fileURLToPath(import.meta.url));

const port = 3000;
const app = express();

app.use(express.urlencoded({extended: true}));

app.set('view engine', 'ejs');

app.get("/", (req, res) => {
    const d = new Date();
    let day = d.getDay();
    res.render(__dirname + "/views/index.ejs", {
        day: day
    });
})

app.listen(port, () => {
    console.log("Listening at port: " + 3000);
})

