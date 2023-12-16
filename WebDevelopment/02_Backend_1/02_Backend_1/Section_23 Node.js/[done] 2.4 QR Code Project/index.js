/* 
1. Use the inquirer npm package to get user input.
2. Use the qr-image npm package to turn the user entered URL into a QR code image.
3. Create a txt file to save the user input using the native fs node module.
*/

import qr from "qr-image";
import fs from "fs";

fs.readFile("URL.txt", "utf-8", function(e, url){
    if(e)
        throw e;
    console.log("Text that is converted to QR code: " + url);
    var qr_svg = qr.image(url, { type: 'svg' });
    qr_svg.pipe(fs.createWriteStream('i_love_qr.svg'));
});

// const readline = rl.createInterface({
//     input: process.stdin,
//     output: process.stdout
// });

// readline.question('Enter the URL: ', url => {
//     console.log(`Entered url: ${url}!`);

//     writeFile("link.txt", url, (err) => {
//         if(err) {
//             console.log("Failed to save the url.");
//             throw err;
//         }
//         console.log("The url is saved.");
//         var qr_svg = qr.image(url, { type: 'svg' });
//         qr_svg.pipe(fs.createWriteStream('i_love_qr.svg'));
//     })
//     readline.close();
// });

// inquirer
//   .prompt([
//     /* Pass your questions in here */
//     "Enter the web link: "
//   ])
//   .then((answers) => {
//     // Use user feedback for... whatever!!
//     writeFile("link.txt", "www.samsung.net", (err) => {
//         if(err){
//             console.log(err);
//             throw err;
//         }
//         console.log("URL is written on the text file successfully!");
//     })
//   })
//   .catch((error) => {
//     if (error.isTtyError) {
//       // Prompt couldn't be rendered in the current environment
//     } else {
//       // Something else went wrong
//     }
//   });