import { render } from "ejs";
import express from "express";
import pg from "pg";

const PORT = 3000;
const app = express();

app.use(express.urlencoded({ extended: true }));
app.use(express.static("public"));

const db = new pg.Client({
  database: "world",
  user: "postgres",
  password: "postgrespass",
  host: "localhost",
  port: 5432,
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
      const response = await db.query(query);
      console.log(`${tableName} table is created.`);
    } else {
      console.log(`${tableName} table already exists.`);
    }
  } catch (err) {
    console.log(`Error in creating table ${tableName}.`);
  }
}

// creating 'user' table
await createTable(
  `user_info`,
  `CREATE TABLE user_info (
    id SERIAL PRIMARY KEY,
    name TEXT,
    color TEXT 
    );`
);

// creating 'country' table
await createTable(
  `country`,
  `CREATE TABLE country (
    id SERIAL PRIMARY KEY,
    name TEXT,
    code CHAR(2) 
    );`
);

// creating 'visited_country' table
await createTable(
  `visited_country`,
  `CREATE TABLE visited_country (
    user_id INTEGER REFERENCES user_info(id),
    country_code CHAR(2),
    PRIMARY KEY (user_id, country_code) 
    );`
);

let currentUserId = 0;

app.get("/", async (req, res) => {
  try {
    let response = await db.query(`SELECT * FROM user_info;`);
    let users = response.rows;

    if (users.length > 0) {
      // user is present
      console.log("/home");
      console.log(users);
      console.log(req.body);

      // set color based on selected user
      let color = "";
      if (currentUserId === 0) {
        //user id is not selected
        currentUserId = response.rows[0].id;
      }
      response = await db.query(
        `SELECT * FROM user_info WHERE id = ${currentUserId};`
      );
      color = response.rows[0].color;

      response = await db.query(
        `SELECT country_code FROM visited_country WHERE user_id = ${currentUserId}`
      );
      let totalCountries = response.rows.length;
      let countryCodes = [];
      response.rows.forEach((code) => {
        countryCodes.push(code.country_code);
      });

      res.render("index.ejs", {
        users: users,
        color: color,
        total: totalCountries,
        countries: countryCodes,
      });
    } else {
      res.render("index.ejs");
    }
  } catch (err) {
    console.error(err);
  }
});

app.post("/user", (req, res) => {
  try {
    console.log("/user");
    console.log(req.body);
    if (req.body.user) {
      currentUserId = parseInt(req.body.user);
      res.redirect("/");
    } else if (req.body.add) {
      res.render("new.ejs");
    } else {
      res.redirect("/");
    }
  } catch (err) {
    console.error(err);
  }
});

app.post("/new", async (req, res) => {
  //from new.ejs view
  try {
    console.log("/new");
    console.log(req.body);

    let userName = "";
    let userColor = "teal";
    if (req.body.name) {
      userName = req.body.name;
      if (req.body.color) userColor = req.body.color;
      let response = await db.query(`INSERT INTO user_info (name, color) 
            VALUES ('${userName}', '${userColor}');`);
    }
    res.redirect("/");
  } catch {
    console.error(err);
  }
});

app.post("/add", async (req, res) => {
  try {
    console.log("/add");
    // sanitizing country name input for case-insensitive match
    let countryInput = req.body.country.trim().toLowerCase();
    console.log("Entered country: " + countryInput);

    let query = `SELECT code FROM country WHERE LOWER(name) = '${countryInput}';`;
    let response = await db.query(query);
    console.log(response.rows);

    if (response.rowCount > 0) {
      let countryCode = response.rows[0].code;

      response =
        await db.query(`INSERT INTO visited_country (user_id, country_code) 
            VALUES (${currentUserId}, '${countryCode}')`);
    }

    res.redirect("/");
  } catch (err) {
    console.error(err);
  }
});

app.listen(PORT, () => {
  console.log(`Server running at port ${PORT}`);
});
