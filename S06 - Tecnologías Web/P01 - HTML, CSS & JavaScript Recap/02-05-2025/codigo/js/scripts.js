function changeBackground(){
    let color = "#";
    for (let index = 0; index < 6; index++) {
        color += Math.floor(Math.random() * 16).toString(16);
    }
    document.getElementById("text").style.background = color;
}

document.getElementById("bg-changer").addEventListener("click",changeBackground)

function changeSize(){
    let size = (Math.floor(Math.random() * 55) + 5) + "px";
    document.getElementById("text").style.fontSize = size;
}

function clearArea(){
    document.getElementById("text").style.fontSize = "15px";
    document.getElementById("text").style.background = "#BEE6CD";
    document.getElementById("text").value = "";
}

document.getElementById("clear").addEventListener("mouseover",clearArea)