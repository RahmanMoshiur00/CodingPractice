function setDiceImage(imgNo)
{
    var dice = Math.floor( Math.random() * 6 ) + 1;
    var imgTag = ".img" + imgNo;
    document.querySelector(imgTag).setAttribute("src", "./images/dice" + dice + ".png");
    return dice;
}

var val1 = setDiceImage(1);
var val2 = setDiceImage(2);

if (val1 > val2){
    document.querySelector("h1").innerHTML = "* Player 1 Wins!";
}
else if(val1 < val2){
    document.querySelector("h1").innerHTML = "Player 2 Wins! *";
}
else{
    document.querySelector("h1").innerHTML = "Draw!";
}
