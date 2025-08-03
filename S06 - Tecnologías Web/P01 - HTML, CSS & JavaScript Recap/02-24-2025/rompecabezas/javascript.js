const piezas = document.querySelectorAll('.piece');
const zonas = document.querySelectorAll('.dropzone');
let colocadas = 0;

// Se itera sobre cada elemento de piezas
piezas.forEach(pieza => {
    // Se agrega un evento a cada elemento de piezas de tipo dragstart
    pieza.addEventListener('dragstart', (e) => { 
        // Se almacena el id de la pieza en el objeto dataTransfer
        e.dataTransfer.setData('id', pieza.id);
    });
});

// Se itera sobre cada elemento de zonas
zonas.forEach(zona => {
    // Se agrega un evento para cada elemento de zonas de tipo dragover
    zona.addEventListener('dragover', (e) => {
        // Se previene el comportamiento predeterminado
        e.preventDefault();
    });

    // Se agrega un evento a todo elemento de zonas de tipo drop
    zona.addEventListener('drop', (e) => {
        // Se previene el comportamiento predeterminado 
        e.preventDefault();

        // Se obtiene el id de la pieza arrastrada
        const id = e.dataTransfer.getData('id');
        // Se obtiene la referencia al elemento arrastrado utilizando su id
        const pieza = document.getElementById(id);

        // Se verifica si la zona está vacía y si la pieza coincide con la zona correcta
        if (zona.children.length === 0 && id === zona.dataset.id) {
            // Se agrega la pieza dentro de la zona
            zona.appendChild(pieza);
            // Se cambia el cursor a "default" para indicar que ya no se puede mover
            pieza.style.cursor = 'default';
            // Se deshabilita la capacidad de arrastrar la pieza
            pieza.draggable = false;
            // Se incrementa el contador de piezas colocadas correctamente
            colocadas++;
        }

        // Se verifica si todas las piezas han sido colocadas correctamente
        if (colocadas === 4) {
            // Se muestra el botón de reinicio, agregado personal
            document.getElementById("reset").style.display = "block";
            // Se actualiza el mensaje que indica que el rompecabezas se completó
            document.getElementById('mensaje').textContent = '¡Rompecabezas completado!';
        }
    });
});

// Agregado personal del botón reset
document.getElementById("reset").addEventListener("click", () => {
    const origin = document.getElementsByClassName("pieces");
    piezas.forEach(pieza => {
        origin[0].appendChild(pieza);
    });
    colocadas = 0;
    document.getElementById("reset").style.display = "none";
    document.getElementById('mensaje').textContent = 'Arrastra las piezas a su posición correcta.';
});