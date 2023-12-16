import express from 'express';
import pg from 'pg';

const PORT = 3000;
const app = express();

app.use(express.urlencoded({extended: true}));
app.use(express.static('public'));

const db = new pg.Client({
    database: 'permalist',
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
        const response = await db.query(query);
        console.log(`${tableName} table is created.`);
      } else {
        console.log(`${tableName} table already exists.`);
      }
    } catch (err) {
      console.log(`Error in creating table ${tableName}.`);
    }
}

// creating task table in db
await createTable(
    'task', 
    `CREATE TABLE task(
        id SERIAL PRIMARY KEY,
        title VARCHAR(100)
    );`
);

let listTitle = "Today";

app.get("/", async (req, res) => {
    try{
        let response = await db.query(`SELECT * FROM task ORDER BY id ASC;`);
        res.render("index.ejs", {
            listTitle: listTitle,
            listItems: response.rows
        })
    } catch (err) {
        console.error(err);
    }
});

app.post("/delete", async (req, res) => {
    try{
        let deleteId = parseInt(req.body.deleteItemId);
        // delete from db
        let response = await db.query(
            `DELETE FROM task
            WHERE id = ${deleteId};`
        );
    } catch (err) {
        console.error(err);
    }
    res.redirect("/");
});

app.post("/edit", async (req, res) => {
    try{
        let editId = parseInt(req.body.updatedItemId);
        let editTitle = req.body.updatedItemTitle;
        let response = await db.query(
            `UPDATE task
             SET title = '${editTitle}'
             WHERE id = ${editId};`
        );
    } catch (err) {
        console.error(err);
    }
    res.redirect("/");
});

app.post("/add", async (req, res) => {
    try{
        if(req.body.newItem){
            let newTaskTitle = req.body.newItem;
            let response = await db.query(
                `INSERT INTO task (title) VALUES ('${newTaskTitle}')`
            );
        }
    } catch (err) {
        console.error(err);
    }
    res.redirect("/");
});

app.listen(PORT, () => {
    console.log(`Server running at port ${PORT}`);
});