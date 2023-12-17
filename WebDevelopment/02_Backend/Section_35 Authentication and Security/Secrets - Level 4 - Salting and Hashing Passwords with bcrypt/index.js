import 'dotenv/config';
import express from 'express';
import pg from 'pg';
import bcrypt from 'bcrypt';

const PORT = 3000;
const app = express();

app.use(express.urlencoded({extended: true}));
app.use(express.static('public'));

const db = new pg.Client({
    database: 'authentication',
    user: 'postgres',
    password: 'postgrespass',
    host: 'localhost',
    port: 5432
});
db.connect();

async function createTable(tableName, query) {
    try {
      // check if the table already exists
      const doesExist = await db.query(`SELECT EXISTS (
              SELECT 1
              FROM pg_tables
              WHERE tablename = '${tableName}');`);
  
      if (doesExist.rows[0].exists === false) {
        // does NOT exist, so create the table
        let fullQuery = `CREATE TABLE ${tableName} ( ${query} );`
        const response = await db.query(fullQuery);
        console.log(`${tableName} table is created.`);
      } else {
        console.log(`${tableName} table already exists. No need to create.`);
      }
    } catch (err) {
      console.log(`Error in creating table ${tableName}.`);
    }
}

// creating task table in db
await createTable(
    'users', 
    `
        id SERIAL PRIMARY KEY,
        username TEXT UNIQUE,
        password TEXT NOT NULL
    `
);

app.get("/", (req, res) => {
    res.render("home.ejs");
});

app.get("/register", (req, res) => {
    res.render("register.ejs");
});

async function insertIntoDB (userName, password) {
    let isInsertionSuccessful = false;
    try{
        let saltRounds = parseInt(process.env.SALT_ROUND);

        //https://stackoverflow.com/questions/48799894/trying-to-hash-a-password-using-bcrypt-inside-an-async-function
        const hashedPassword = await new Promise((resolve, reject) => {
            bcrypt.hash(password, saltRounds, function(err, hash) {
              if (err) reject(err);
              resolve(hash);
            });
        });

        let response = await db.query(
            `INSERT INTO users (username, password)
            VALUES ('${userName}', '${hashedPassword}') RETURNING *;`
        );

        if(response.rowCount > 0) {
            isInsertionSuccessful = true;
        }
    } catch (err) {
        console.error(err);
    }
    return isInsertionSuccessful;
}   

app.post("/register", async (req, res) => {
    let isRegistrationSuccessful = false;
    try{
        let userName = req.body.username;
        let password = req.body.password;
    
        if(userName && password) {
            // add username & password into db
            let isInserted = await insertIntoDB(userName, password);
            console.log("isInserted = " + isInserted);
            if(isInserted === true){
                isRegistrationSuccessful = true;
            }
        }
    } catch (err) {
        console.error(err);
    }

    if(isRegistrationSuccessful === true){
        console.log("Successful registration.");
        res.render("secrets.ejs", { signedIn: true });
    } else{
        console.log("Registration failed.");
        res.redirect('/register?error=' + encodeURIComponent('registration_failed'));
    }
});


async function isValidUser(userName, password) {
    let ret = false;
    try {
        let response = await db.query(
            `SELECT * FROM users WHERE username = '${userName}';`);
        if(response.rowCount > 0) {
            ////https://stackoverflow.com/questions/48799894/trying-to-hash-a-password-using-bcrypt-inside-an-async-function
            let isMatched = await new Promise((resolve, reject) => {
                bcrypt.compare(password, response.rows[0].password, function(err, result) {
                  if (err) reject(err)
                  resolve(result)
                });
            });

            if(isMatched === true){
                ret = true;
            }
        } 
    } catch (err) {
        console.error(err);
    }
    return ret;
}

app.get("/login", (req, res) => {
    res.render("login.ejs");
})

app.post("/login", async (req, res) => {
    let isLoginSuccessful = false;
    try{
        let userName = req.body.username;
        let password = req.body.password;

        if(userName && password) {
            // legit user
            isLoginSuccessful = await isValidUser(userName, password);
        }
    } catch (err) {
        console.error(err);
    }

    if(isLoginSuccessful) {
        console.log("Login successful.");
        res.render("secrets.ejs", { signedIn: true });
    } else {
        console.log("Login failed!");
        res.redirect('/login?error=' + encodeURIComponent('incorrect_credential'));
    }
});

app.get("/logout", (req, res) => {
    res.redirect("/");
});

app.get("/submit", (req, res) => {
    res.render("submit.ejs");
});

app.post("/submit", (req, res) => {
    console.log("post -> /submit");
    console.log(req.body);
    res.render("home.ejs");
})

app.listen(PORT, () => {
    console.log(`Server is running at port ${PORT}`);
});
