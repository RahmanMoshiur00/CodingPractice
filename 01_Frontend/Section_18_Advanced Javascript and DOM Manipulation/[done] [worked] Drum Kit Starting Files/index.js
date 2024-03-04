var buttonArray = document.querySelectorAll(".drum");
for(var i = 0; i < buttonArray.length; i++) {
    buttonArray[i].addEventListener("click", handleClick);
}

function playAudio(audioName) {
    var audio = new Audio("./sounds/" + audioName + ".mp3");
    audio.play();
}

function makeSound(key) {
    switch (key) {
        case "w":
            playAudio("tom-1");
            break;
        case "a":
            playAudio("tom-2");
            break;
        case "s":
            playAudio("tom-3");
            break;
        case "d":
            playAudio("tom-4");
            break;
        case "j":
            playAudio("snare");
            break;
        case "k":
            playAudio("crash");
            break;
        case "l":
            playAudio("kick-bass");
            break;
        default:
            console.log("No sound mapped!");
            break;
    }
}

function handleClick () {
    var key = this.innerHTML;
    makeSound(key);
    makeAnnimation(key);
}

document.addEventListener("keydown", handleKeydown);

function handleKeydown (event) {
    var key = event.key;
    makeSound(key);
    makeAnnimation(key);
}

function makeAnnimation(key) {
    var keyClass = document.querySelector("." + key);
    keyClass.classList.add("pressed");
    setTimeout(function(){
        keyClass.classList.remove("pressed");
    }, 
    100); // 100ms
}