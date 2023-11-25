const fs = require("fs");

// fs.writeFile("newFile.txt", "Hello from SRBD.", (err) => {
//     if(err) {
//         console.log("Error occured!");
//         throw err;
//     }
//     console.log("The file has been saved.")
// });

fs.readFile("message.txt", "utf-8", function(e, d){
    if(e)
        throw e;
    console.log(d);
});

fs.readFile("newFile.txt", "utf-8", function(e, d){
    if(e)
        throw e;
    console.log(d);
});