import express from "express";
import axios from "axios";

const app = express();
const port = 3000;

app.use(express.urlencoded({ extended: true }));
app.use(express.static("public"));

app.get("/", async (req, res) => {
  try {
    var response = await axios.get("https://bored-api.appbrewery.com/random");
    var activity = response.data;
    res.render("index.ejs", { activity: activity });
  } catch (error) {
    console.error("Error message: " + error.message);
    res.render("index.ejs", {
      error: error.message,
    });
  }
});

app.post("/", async (req, res) => {
  console.log(req.body);

  //make the query string
  var queryString = "";
  if (req.body.type !== "") {
    queryString = "type=" + req.body.type;
  }
  if (req.body.participants !== "") {
    if (queryString) {
      queryString += "&";
    }
    queryString += "participants=" + req.body.participants;
  }

  //get activity data from api
  try {
    var response;
    var activity;
    if (queryString) {
      console.log("Query string:" + "https://bored-api.appbrewery.com/filter?" + queryString);
      response = await axios.get("https://bored-api.appbrewery.com/filter?" + queryString);
      activity = response.data[Math.floor(Math.random() * response.data.length)];
    } else {
      response = await axios.get("https://bored-api.appbrewery.com/random");
      activity = response.data;
    }

    res.render("index.ejs", {
      activity: activity,
    });
  } 
  catch (error) {
    console.error("Error message: ", error.message);
    res.render("index.ejs", {
      error: "No activities that match your criteria.",
    });
  }

  // Step 2: Play around with the drop downs and see what gets logged.
  // Use axios to make an API request to the /filter endpoint. Making
  // sure you're passing both the type and participants queries.
  // Render the index.ejs file with a single *random* activity that comes back
  // from the API request.
  // Step 3: If you get a 404 error (resource not found) from the API request.
  // Pass an error to the index.ejs to tell the user:
  // "No activities that match your criteria."
});

app.post("/submit", (req, res) => {
  
})

app.listen(port, () => {
  console.log(`Port running on ${port}`);
});
