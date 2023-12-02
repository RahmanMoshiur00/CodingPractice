import express from "express";
import axios from "axios";
import fs from "fs";

const port = 3000;
const app = express();
const API_URL = "https://api.nasa.gov/planetary/apod";
const API_KEY = "8ypcs4uGRC1YNlYnfUVSXcob0jsQnpFfNSVyzu0A";

app.use(express.static("public"));

async function downloadImage(url, filename) {
  const response = await axios.get(url, { responseType: "arraybuffer" });

  fs.writeFile(filename, response.data, (err) => {
    if (err) throw err;
    console.log("Image downloaded successfully!");
  });
  return true;
}

app.get("/", async (req, res) => {
  try {
    var response = await axios.get(API_URL, {
      params: {
        api_key: API_KEY,
      },
    });

    var imageExt = "";
    for (var i = response.data.url.length - 1; i >= 0; i--) {
      if (response.data.url[i] == ".") {
        for (var j = i + 1; j < response.data.url.length; j++) {
          imageExt += response.data.url[j];
        }
        break;
      }
    }

    var imageName = response.data.title + "." + imageExt;
    console.log("Title: " + response.data.title);
    console.log("Image name: " + imageName);
    console.log("url: " + response.data.url);

    var message = {
      title: response.data.title,
      url: "images/" + imageName,
      explanation: response.data.explanation,
    };

    var imagePath = "./public/images/" + imageName;
    if (fs.existsSync(imagePath) === false) {
      await downloadImage(response.data.url, imagePath);
    }

    res.render("index.ejs", {
      message: message,
    });
  } catch (error) {
    console.error("Error occured: ", error);
    res.render("index.ejs", {
      message: {
        title: "no title to show",
        url: "invalid url",
        explanation: "no explanation to show",
      },
    });
  }
});

app.listen(port, () => {
  console.log("Server running at port " + port);
});
