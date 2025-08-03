const middleNotif = document.getElementById('alert-text');
const leftNotif = document.getElementById('alert-text-left');
const rightNotif = document.getElementById('alert-text-right');

function resetAllColors(){
    middleNotif.style = "color: black;";
    leftNotif.style = "color: black;";
    rightNotif.style = "color: black;";

    const notifConainer = document.getElementsByClassName("alert-notify");
    for (let i = 0; i < notifConainer.length; i++) {
        notifConainer[i].style = "border-color: black;";
    }
}

function highlightAlert(num) {// 0:izquierda 3:middle 2:derecha
    const notifConainer = document.getElementsByClassName("alert-notify");
    notifConainer[num].style = "border-color: blue;";

    switch (num) {
        case 0:
            leftNotif.style = "color: blue;";
            break;
        case 1:
            middleNotif.style = "color: blue;";            
            break;
        case 2:
            rightNotif.style = "color: blue;";            
            break;
        default:
            break;
    }
}


function allowDrop(ev) {
    ev.preventDefault();
}

function drag(ev) {
    ev.dataTransfer.setData("text", ev.target.id);

    middleNotif.innerHTML = "La imagen ha se está trasladando";
    resetAllColors();
    highlightAlert(1);
}

function drop(ev) {
    ev.preventDefault();
    var data = ev.dataTransfer.getData("text");
    ev.target.appendChild(document.getElementById(data));
    if (ev.target.id === "div-origin")
    {
        leftNotif.innerHTML = "La imagen se ha colocado en el contenedor izquierdo";
        document.getElementById('image').src = "media/miata_closed.jpg";
        resetAllColors();
        highlightAlert(0);
    }else if (ev.target.id === "div-destiny") {
        rightNotif.innerHTML = "La imagen se ha colocado en el contenedor derecho";
        document.getElementById('image').src = "media/miata_opened.jpg";
        resetAllColors();
        highlightAlert(2);
    }
}


document.getElementById('div-origin').addEventListener("drop", drop);
document.getElementById('div-origin').addEventListener("dragover", allowDrop);
document.getElementById('div-origin').addEventListener("dragenter", function () {
    leftNotif.innerHTML = "Imagen entró en la zona del contenedor izquierdo";
    resetAllColors();
    highlightAlert(0);
});
document.getElementById('div-origin').addEventListener("dragleave", function () {
    leftNotif.innerHTML = "Imagen salió de la zona del contenedor izquierdo";
    resetAllColors();
    highlightAlert(0);
});

document.getElementById('image').addEventListener("dragstart", drag);
document.getElementById('image').addEventListener("dragend", function () {
    middleNotif.innerHTML = "La imagen ha terminado de trasladarse";
    resetAllColors();
    highlightAlert(1);
});


document.getElementById('div-destiny').addEventListener("drop", drop);
document.getElementById('div-destiny').addEventListener("dragover", allowDrop);
document.getElementById('div-destiny').addEventListener("dragenter", function () {
    rightNotif.innerHTML = "Imagen entró en la zona del contenedor derecho";
    resetAllColors();
    highlightAlert(2);
});
document.getElementById('div-destiny').addEventListener("dragleave", function () {
    rightNotif.innerHTML = "Imagen salió de la zona del contenedor derecho";
    resetAllColors();
    highlightAlert(2);
});