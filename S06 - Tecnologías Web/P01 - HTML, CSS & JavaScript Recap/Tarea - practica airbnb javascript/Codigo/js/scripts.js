function button_click(){
  Swal.fire({
    title: 'Información Buscada',
    html: `
    <b>Ubicacion:</b> ${document.getElementById("ubicación").value} <br>
    <b>Llegada:</b> ${document.getElementById("llegada").value} <br>
    <b>Salida:</b> ${document.getElementById("salida").value} <br>
    <b>Adultos:</b> ${document.getElementById("adultos").value}<br> 
    <b>Niños:</b> ${document.getElementById("niños").value} <br>
    `,
    icon: "info",
    confirmButtonColor: "#ff1493"
  })
}