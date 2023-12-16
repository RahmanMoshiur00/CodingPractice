import express from "express";
import axios from "axios";
import bodyParser from "body-parser";

const app = express();
const port = 3000;
const API_URL = "https://secrets-api.appbrewery.com";

// HINTs: Use the axios documentation as well as the video lesson to help you.
// https://axios-http.com/docs/post_example
// Use the Secrets API documentation to figure out what each route expects and how to work with it.
// https://secrets-api.appbrewery.com/

//TODO 1: Add your own bearer token from the previous lesson.
const myBearerToken = "67d1467a-bf4e-4a45-898d-ce2c09068d5e";
const config = {
  headers: { Authorization: `Bearer ${myBearerToken}` },
};

app.use(bodyParser.urlencoded({ extended: true }));

app.get("/", (req, res) => {
  res.render("index.ejs", { content: "Waiting for data..." });
});

app.post("/get-secret", async (req, res) => {
  const searchId = req.body.secretId;
  try {
    const result = await axios.get(API_URL + "/secrets/" + searchId, config);
    res.render("index.ejs", { content: JSON.stringify(result.data) });
  } catch (error) {
    res.render("index.ejs", { content: JSON.stringify(error.response.data) });
  }
});

app.post("/post-secret", async (req, res) => {
  // TODO 2: Use axios to POST the data from req.body to the secrets api servers.
  try{
    var response = await axios.post(API_URL + "/secrets", 
    {
      secret: req.body.secret,
      score: req.body.score
    }, 
    config
    );

    res.render("index.ejs", {
      content: JSON.stringify(response.data)
    });
  }
  catch (error) {
    res.render("index.ejs", {
      content: JSON.stringify(error.data)
    })
  }
});

app.post("/put-secret", async (req, res) => {
  console.log("PUT");
  const searchId = req.body.secretId;
  console.log(req.body);
  // TODO 3: Use axios to PUT the data from req.body to the secrets api servers.
  try{
    var response = await axios.put(API_URL + "/secrets/" + searchId, 
    {
      id: req.body.secretId,
      secret: req.body.secret,
      score: req.body.score
    },
    config
    );

    res.render("index.ejs", {content: JSON.stringify(response.data)});
  }
  catch (error) {
    res.render("index.ejs", {content: JSON.stringify(error.message)});
  }
});

app.post("/patch-secret", async (req, res) => {
  console.log("PATCH");
  const searchId = req.body.id;
  var data;
  if(req.body.secret && req.body.score){
    data = {
      secret: req.body.secret,
      score: req.body.score
    };
  }
  else if(req.body.secret){
    data = { secret: req.body.secret };
  }
  else if(req.body.score){
    data = {score: req.body.score };
  }

  console.log(data);
  // TODO 4: Use axios to PATCH the data from req.body to the secrets api servers.
  try{
    var response = await axios.patch(API_URL + "/secrets/" + searchId, data, config);
    res.render("index.ejs", {content: JSON.stringify(response.data)});
  }
  catch (error) {
    res.render("index.ejs", {content: JSON.stringify(error.message)});
  }
});

app.post("/delete-secret", async (req, res) => {
  const searchId = req.body.secretId;
  // TODO 5: Use axios to DELETE the item with searchId from the secrets api servers.
  try{
    var response = await axios.delete(API_URL + "/secrets/" + searchId, config);
    res.render("index.ejs", {content: JSON.stringify(response.data)});
  }
  catch (error) {
    res.render("index.ejs", {content: JSON.stringify(error.data)});
  }
});

app.listen(port, () => {
  console.log(`Server is running on port ${port}`);
});
