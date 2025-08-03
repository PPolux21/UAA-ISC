//funcion description
function obtenerResultados(resultados){
    console.log("Respuesta del servidor: " + resultados);
}


function solicitudServidor(consulta, callback){
    setTimeout(function(){
        var respuesta = consulta + "lleno!";
        callback(respuesta);
    },5000);
}
  
solicitudServidor("Funcion Declarada: El vaso está medio  ", obtenerResultados);

//funcion expresion
const serverRequest = function (consulta, callback) {
    setTimeout(function(){
        var respuesta = consulta + "lleno!";
        callback(respuesta);
    },5000);
}

serverRequest("Funcion Expression: El vaso está medio  ", obtenerResultados);

//funcion arrow
const peticionServidor = (consulta, callback) =>{
    setTimeout(function(){
        var respuesta = consulta + "lleno!";
        callback(respuesta);
    },5000);
}

peticionServidor("Funcion Arrow: El vaso está medio  ", obtenerResultados)