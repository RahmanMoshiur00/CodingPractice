import express from "express";
import axios from "axios";

const app = express();
const port = 3000;
const API_URL = "https://secrets-api.appbrewery.com/";

//TODO 1: Fill in your values for the 3 types of auth.
const myUserName = "bengaliman";
const myPassword = "world";

app.get("/", (req, res) => {
  res.render("index.ejs", { content: "API Response." });
});

app.get("/noAuth", async (req, res) => {
  //TODO 2: Use axios to hit up the /random endpoint
  //The data you get back should be sent to the ejs file as "content"
  //Hint: make sure you use JSON.stringify to turn the JS object from axios into a string.

  var response = await axios.get(API_URL + "random");
  res.render("index.ejs", {
    content: JSON.stringify(response.data),
  });
});

app.get("/basicAuth", async (req, res) => {
  //TODO 3: Write your code here to hit up the /all endpoint
  //Specify that you only want the secrets from page 2
  //HINT: This is how you can use axios to do basic auth:
  // https://stackoverflow.com/a/74632908

  try {
    var response = await axios.post(API_URL + "register", {
      username: myUserName,
      password: myPassword
    });

    if(response.data.success) {
      response = await axios.get(API_URL + "all?page=2", {
        auth: {
          username: myUserName,
          password: myPassword,
        },
      });
  
      res.render("index.ejs", {
        content: JSON.stringify(response.data),
      });
    }
    else{
      res.render("index.ejs", {
        content: "Failed to register."
      });
    }
  } catch (error) {
    console.log(`Error: ${error.message}`);
    res.render("index.ejs", {
      content: error.message,
    });
  }
});

app.get("/apiKey", async (req, res) => {
  //TODO 4: Write your code here to hit up the /filter endpoint
  //Filter for all secrets with an embarassment score of 5 or greater
  //HINT: You need to provide a query parameter of apiKey in the request.
  try {
    var response = await axios.get(API_URL + "generate-api-key");
    const apiKey = response.data.apiKey;
    response = await axios.get(API_URL + "filter?", {
      params: {
        score: 5,
        apiKey: apiKey,
      },
    });
    res.render("index.ejs", {
      content: JSON.stringify(response.data),
    });
  } catch (error) {
    console.error("Error: " + error.message);
    res.render("index.ejs", {
      content: error.message,
    });
  }
});

app.get("/bearerToken", async (req, res) => {
  //TODO 5: Write your code here to hit up the /secrets/{id} endpoint
  //and get the secret with id of 42
  //HINT: This is how you can use axios to do bearer token auth:
  // https://stackoverflow.com/a/52645402

  try {
    var response = await axios.post(API_URL + "get-auth-token", {
      username: myUserName,
      password: myPassword,
    });
    console.log("token response: ", JSON.stringify(response.data));
    const token = response.data.token;
    const id = 42;
    response = await axios.get(API_URL + "secrets/" + id, {
      headers: {
        Authorization: `Bearer ${token}`,
      },
    });

    res.render("index.ejs", {
      content: JSON.stringify(response.data),
    });
  } catch (error) {
    console.error("Error: " + error.message);
    res.render("index.ejs", {
      content: error.message,
    });
  }
});

app.listen(port, () => {
  console.log(`Server is running on port ${port}`);
});
