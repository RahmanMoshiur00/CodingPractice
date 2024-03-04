var userClickedPattern = [];
var gamePattern = [];
var buttonColours = ["red", "blue", "green", "yellow"];
var level = 0;
var isGameStarted = false;

function nextSequence() {
    level++;
    $("#level-title").text("Level " + level);
    var randomNumber = Math.floor(Math.random() * 4);
    var randomChosenColour = buttonColours[randomNumber];
    $("#" + randomChosenColour).fadeOut(200).fadeIn(200);
    playSound(randomChosenColour);
    gamePattern.push(randomChosenColour);
    console.log("gemePattern = ", gamePattern);
}

function playSound(name) {
    var audio = new Audio("./sounds/" + name + ".mp3");
    audio.play();
}

function animatePress(currentColour){
    $("#" + currentColour).addClass("pressed");
    setTimeout(function() {
        $("#" + currentColour).removeClass("pressed");
    }, 100);
    
}

function checkAnswer () {
    var isMatched = true;
    for(var i = 0; i < userClickedPattern.length; i++){
        if(i >= gamePattern.length || gamePattern[i] !== userClickedPattern[i]){
            isMatched = false;
            break;
        }
    }

    if(isMatched === false){ // terminate game
        gamePattern = [];
        userClickedPattern = [];
        isGameStarted = false;
        level = 0;
        $("body").css("background", "red");
        playSound("wrong");
        $("#level-title").text("Game Over. Press any key to restart.");
        setTimeout(function(){
            $("body").css("background", "#011F3F");
        }, 200);
    }
    else{ // matched 
        if(gamePattern.length === userClickedPattern.length) { // go to next level
            userClickedPattern = [];
            setTimeout(function(){
                nextSequence();
            }, 1000);
        }
        // else, do nothing
    }
} 

$(".btn").click(function (event){
    var userChosenColour = event.target.id;
    animatePress(userChosenColour);
    playSound(userChosenColour);
    userClickedPattern.push(userChosenColour);
    console.log("userClickedPattern = " + userClickedPattern);

    checkAnswer();
});


$("*").on("keydown", function(event) {
    if(isGameStarted === false){
        isGameStarted = true;
        nextSequence();
    }
});