import express from "express";
import axios from "axios";
import fs from "fs";
import { title } from "process";

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

    var message;
    if(response.data.url.includes("youtube.com")) { // embedded video
        message = {
          title: response.data.title,
          url: response.data.url,
          explanation: response.data.explanation,
          contentType: "video",
        }
    }
    else { // image
      console.log("Image url: " + response.data.url);
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
      console.log("Image: " + imageName);

      var imagePath = "./public/images/" + imageName;
      if (fs.existsSync(imagePath) === false) {
        await downloadImage(response.data.url, imagePath);
      }

      message = {
        title: response.data.title,
        url: "images/" + imageName,
        explanation: response.data.explanation,
        contentType: "image"
      };
    }

    console.log("title: " + message.title);
    console.log("url: " + message.url);
    console.log("contentType: " + message.contentType)

    res.render("index.ejs", {
      message: message
    });
  } 
  catch (error) {
    console.error("Error occured: ", error);
    res.render("index.ejs", {
      message: {
        title: "no title to show",
        url: "invalid url",
        explanation: "no explanation to show",
        contentType: "none",
      },
    });
  }
});

app.listen(port, () => {
  console.log("Server running at port " + port);
});
