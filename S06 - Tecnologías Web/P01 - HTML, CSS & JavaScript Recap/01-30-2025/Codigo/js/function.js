function show(){
    datos="";
    datos+= "nombre: "+document.getElementById("nombre").value;
    datos+="\n";

    datos+="edad: "+document.getElementById("edad").value;
    datos+="\n";

    if (document.getElementById("dama").checked) {
        datos+="sexo: femenino";
    } else if (document.getElementById("caballero").checked) {
        datos+="sexo: masculino";
    }
    datos+="\n";

    datos+="fecha: "+document.getElementById("fecha").value;

    alert(datos);
}