var socket = io.connect("http://localhost:8080", { forceNew: true });

socket.on("messages", function (data) {
    console.log(data);
});

function render(data) {
    var user = localStorage.getItem("usuario");
    var html = data
        .map(function (elem, index) {
            if (elem.author == user) {
                return `<div class="message my-message">
                    <strong>${elem.author}</strong>
                    <p>${elem.text}</p>
            </div>`;
            } else {
                return `<div class="message">
                    <strong>${elem.author}</strong>
                    <p>${elem.text}</p>
            </div>`;   
            }
        })
        .join(" ");
  
    document.getElementById("messages").innerHTML = html;
} 
  
socket.on("messages", function (data) {
    render(data);
});

function addMessage(e) {
    var mensaje = {
        author: document.getElementById("username").value,
        text: document.getElementById("texto").value,
    };

    localStorage.setItem("usuario",document.getElementById("username").value);

    socket.emit("new-message", mensaje);
    return false;
}