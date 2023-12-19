import 'dotenv/config';
import express from 'express';
import pg from 'pg';
import bcrypt from 'bcrypt';
import session from 'express-session';
import passport from 'passport';
import passportLocal from 'passport-local';
import flash from 'express-flash';

const PORT = process.env.PORT || 3000;
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

app.use(session({
    secret: process.env.SESSION_SECRET,
    resave: false,
    saveUninitialized: false,
}));
app.use(passport.initialize());
app.use(passport.session());

passport.use(new passportLocal.Strategy( /*{ usernameField: "username", passwordField: "password" },*/ async (username, password, done) => {
    console.log(`passportLocal.Strategy() => username:${username}, password:${password}`);
    try{
        let response = await db.query(`SELECT * FROM users WHERE username = '${username}';`);
        if(response.rowCount > 0) {
            if(await isValidUser(username, password) === true) {
                return done(null, {id: response.rows[0].id, username: username});
            } else {
                return done(null, false, {message: `Wrong password.`});
            }
        } else {
            return done(null, false, {message: `No user registered with username ${username}.`});
        }
    } catch (err) {
        console.error(err);
        return done(null, false, {message: 'Error occured in local-strategy.'});
    }
} ));

passport.serializeUser( (user, done) => {
    console.log(`passport.serializeUser() => user: `); console.log(user);
    done(null, user.id);
});

passport.deserializeUser( async (id, done) => {
    try{
        let response = await db.query(`SELECT id, username FROM users WHERE id=${id};`);
        if(response.rowCount > 0) {
            console.log(`passport.deserializeUser() => id: ${id}`);
            return done(null, response.rows[0]);
        } else {
            return done(err);
        }
    } catch (err) {
        return done(err);
    }
});

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
    if(req.isAuthenticated()){
        res.redirect("/secret");
    } else{
        res.render("register.ejs");
    }
});

app.get("/login", (req, res) => {
    if(req.isAuthenticated()){
        res.redirect("/secret");
    } else{
        res.render("login.ejs");
    }
});

app.get("/logout", (req, res) => {
    req.logout((err) => {
        if (err) { return next(err); }
        res.redirect('/');
    });
});

app.get("/secret", proceedIfAuthenticated, (req, res) => {
    console.log(`/secrets => `); console.log(req.user);
    res.render("secrets.ejs", {username: 'USER_NAME'});
});

function proceedIfAuthenticated(req, res, next){
    if(req.isAuthenticated()){
        return next();
    }
    res.redirect("/login");
}

app.get("/submit", (req, res) => {
    res.render("submit.ejs");
});  

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
        
        // passport.authenticate("local", {
        //     successRedirect: "/secret",
        //     failureRedirect: "/login"
        // });
        res.redirect("/login");
    } else{
        console.log("Registration failed.");
        res.redirect('/register?error=' + encodeURIComponent('registration_failed'));
    }
});

app.post("/login", await passport.authenticate("local", {
    successRedirect: "/secret",
    failureRedirect: "/login"
}));

app.post("/submit", (req, res) => {
    console.log("post -> /submit");
    console.log(req.body);
    res.render("home.ejs");
})

app.listen(PORT, () => {
    console.log(`Server is running at port ${PORT}`);
});

async function insertIntoDB (userName, password) {
    let isInsertionSuccessful = false;
    try{
        let saltRounds = parseInt(process.env.SALT_ROUND);

        // https://stackoverflow.com/questions/48799894/trying-to-hash-a-password-using-bcrypt-inside-an-async-function
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

async function isValidUser(userName, password) {
    let ret = false;
    try {
        let response = await db.query(
            `SELECT * FROM users WHERE username = '${userName}';`);
        if(response.rowCount > 0) {
            // https://stackoverflow.com/questions/48799894/trying-to-hash-a-password-using-bcrypt-inside-an-async-function
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