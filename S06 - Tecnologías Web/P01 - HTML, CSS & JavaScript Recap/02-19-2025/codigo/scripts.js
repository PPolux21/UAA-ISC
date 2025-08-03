function guardarDatos() {
    if ((document.getElementById("nombre").value != "") && (document.getElementById("password").value != "")) {
        localStorage.nombre = document.getElementById("nombre").value;
        localStorage.password = document.getElementById("password").value;
    }else if((localStorage.nombre != undefined) && (localStorage.password != undefined)) {
        localStorage.removeItem("nombre");
        localStorage.removeItem("password");
    }
}

function recuperarDatos() {
    if ((localStorage.nombre != undefined) && (localStorage.password != undefined)) {
        document.getElementById("datos").innerHTML = `
            Nombre: ${localStorage.nombre} <br>
            Password: ${localStorage.password}
        `;
    } else {
        document.getElementById("datos").innerHTML = "No has introducido tu nombre y tu password";
    }
}