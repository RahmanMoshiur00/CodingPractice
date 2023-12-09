import express from "express";
import bodyParser from "body-parser";
import pg from "pg";

const app = express();
const port = 3000;

app.use(bodyParser.urlencoded({ extended: true }));
app.use(express.static("public"));

const db = new pg.Client({
  database: "world",
  user: "postgres",
  password: "postgrespass",
  host: "localhost",
  port: 5432,
});
db.connect();

// create visited_countries table in db
try {
  // check if visited_countries table already exists
  const doesExist = await db.query(`SELECT EXISTS (
      SELECT 1
      FROM pg_tables
      WHERE tablename = 'visited_countries');`);

  if (doesExist.rows[0].exists === false) {
    // does NOT exist
    const response = await db.query(`CREATE TABLE visited_countries (
      id SERIAL PRIMARY KEY,
      country_code CHAR(2) NOT NULL UNIQUE
    );`);
    console.log(`visited_countries table is created.`);
  } else {
    console.log(`visited_countries table already exists.`);
  }
} catch (err) {
  console.log(`Error in creating visited_countries table.`);
}

// close the db here
// db.end();

app.get("/", async (req, res) => {
  //Write your code here.
  // getting visited countries db table
  try {
    const response = await db.query(`SELECT * FROM visited_countries;`);
    console.log(`visited_countries::`);
    console.log(response.rows);

    let visitedCountries = [];
    response.rows.forEach((country) => {
      visitedCountries.push(country.country_code);
    });

    console.log("visited_countries[] -> ");
    console.log(visitedCountries);

    res.render("index.ejs", {
      total: visitedCountries.length,
      countries: visitedCountries,
    });
  } catch (err) {
    console.error(`Error occured`);
    res.render("index.ejs", {
      total: 0,
      countries: [],
    });
  }
});

app.post("/add", async (req, res) => {
  try {
  // namify the response
  console.log(req.body);
  let answer = req.body.country.trim();
  let words = answer.split(" ");
  for (let i = 0; i < words.length; i++) {
    words[i] = words[i][0].toUpperCase() + words[i].substr(1).toLowerCase();
  }
  answer = words.join(" ");
  // insert the country into visited_countries table
  // getting the country code
  let response = await db.query(`SELECT code
  FROM flags
  WHERE name = '${answer}';`);
  let countryCode = response.rows[0].code;

  // inserting
  response = await db.query(`INSERT INTO visited_countries (country_code)
  VALUES ('${countryCode}');`);
  } catch (err) {
    console.error(`Error is inserting the country code.`);
  }

  res.redirect("/");
});

app.listen(port, () => {
  console.log(`Server running on http://localhost:${port}`);
});
