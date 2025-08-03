var express = require("express");
var app = express();
var server = require("http").Server(app);
var io = require("socket.io")(server);

server.listen(8080, function () {
    console.log("Servidor corriendo en http://localhost:8080");
});

var messages = [
    {
        author: "Mike",
        text: "Hey, just wondering if you got your photos printed?",
    },
    {
        author: "Xrop",
        text: "Bogos binted?",
    },
    {
        author: "Mike",
        text: "What",
    },
    {
        author: "Xrop",
        text: "👽",
    },
];

io.on("connection", function (socket) {
    console.log("Un cliente se ha conectado");
    socket.emit("messages", messages);

    socket.on("new-message", function (data) {
        messages.push(data);
      
        io.sockets.emit("messages", messages);
    });
});

app.use(express.static("../public"));

app.get("/hello", function (req, res) {
    res.status(200).send("Hello World!");
});