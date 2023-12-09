import express from 'express';
import pg from 'pg';

const app = express();
const PORT = 3000;

var quiz = [];
var totalScore = 0;
var currentQuiz;

app.use(express.urlencoded({extended: true}));
app.use(express.static('public'));

const db = new pg.Client({
    database: "world",
    user: "postgres",
    password: "postgrespass", 
    host: "localhost",
    port: 5432
});

db.connect();

db.query("SELECT * FROM flags", (err, res) => {
    if(err){
        console.log("Error occured in database: ", err);
    }
    else{
        quiz = res.rows;
    }
    db.end();
});

app.get("/", (req, res) => {
    getNewQuiz();
    res.render("index.ejs", {question: currentQuiz});
});

app.post("/submit", (req, res) => {
    const answer = req.body.answer.trim(); // removing prefix and suffix spaces
    var wasCorrect = false;
    console.log("Current name = " + currentQuiz.name + ", Answer = " + answer);
    if(currentQuiz.name.toLowerCase() === answer.toLowerCase()){
        totalScore++;
        wasCorrect = true;
    }
    getNewQuiz();
    res.render("index.ejs", {
        question: currentQuiz,
        totalScore: totalScore,
        wasCorrect: wasCorrect
    });
});

app.listen(PORT, (req, res) => {
    console.log("Server is running at port: " + PORT);
});

function getNewQuiz()
{
    const randomQuiz = quiz[Math.floor( Math.random() * quiz.length)];
    currentQuiz = randomQuiz;
    console.log(currentQuiz);
}