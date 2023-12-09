import express from 'express';
import pg from 'pg';

const PORT = 3000;
const app = express();

const db = new pg.Client({
    database: "world", 
    user: "postgres",
    password: "postgrespass",
    host: "localhost",
    port: 5432
});
db.connect();

var quiz = [];
var currentQuiz;
var totalScore = 0;

db.query("SELECT * FROM capitals;", (err, res) => {
    if(err) {
        console.log("Failed to connect to the PostgreSQL server.");
    }
    else{
        quiz = res.rows;
    }
    db.end();
});

// middleware
app.use(express.urlencoded({extended: true}));
app.use(express.static('public'));

app.get("/", (req, res) => {
    generateQuiz();
    res.render("index.ejs", {
        question: currentQuiz
    });
});

app.post("/submit", (req, res) => {
    const answer = req.body.answer.trim();
    
    var wasCorrect = false;
    if(answer.toLowerCase() === currentQuiz.capital.toLowerCase()) {
        totalScore++;
        wasCorrect = true;
    }

    generateQuiz();
    res.render("index.ejs", {
        question: currentQuiz,
        totalScore: totalScore,
        wasCorrect: wasCorrect
     });
});

app.listen(PORT, (req, res) => {
    console.log("Server running at port " + PORT);
});

function generateQuiz() {
    const randomQuiz = quiz[ Math.floor(Math.random() * quiz.length) ];
    currentQuiz = randomQuiz;
    console.log(currentQuiz);
}