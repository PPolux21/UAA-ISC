let iconos;
let selectors = [];
//Vars del Winner Animation
let paresEncontrados = 0; // Nueva variable para contar los pares encontrados
const totalPares = 12; //Total de pares en el juego
let cont= 0; //Contador de Vics

/*Vars del Timer
let timeElapsed = 0; // Tiempo transcurrido en segundos
let timerInterval; // Referencia al temporizador*/

generarTablero();
/*startTimer();*/

function cargarIconos() {
  iconos = [
    `<img src="img/img1.jpg">`,
    `<img src="img/img2.webp">`,
    `<img src="img/img3.webp">`,
    `<img src="img/img4.webp">`,
    `<img src="img/img5.jpeg">`,
    `<img src="img/img6.jpg">`,
    `<img src="img/img7.jpg">`,
    `<img src="img/img8.jpg">`,
    `<img src="img/img9.jpg">`,
    `<img src="img/img10.jpg">`,
    `<img src="img/img11.jpg">`,
    `<img src="img/img12.jpg">`,
  ];
}

function generarTablero() {
  cargarIconos();
  paresEncontrados=0;

  let tablero = document.getElementById("tablero");

  let tarjetas = [];
  let len = iconos.length * 2;
  for (let i = 0; i < len; i++) {
    tarjetas.push(`
        <div class="card-area" onclick="cardSelector(${i})">
            <div class="card" id="card${i}">
                <div class="face front" id="back${i}">
                ${iconos[0]}
                </div>
                <div class="face back"><img src="img/detras.jpg"></div>
            </div>
        </div>
      `);
    if (i % 2 == 1) {
      iconos.splice(0, 1);
    }
  }
  tarjetas.sort(() => Math.random() - 0.5);
  tablero.innerHTML = tarjetas.join("");

}

function cardSelector(i) {
  let card = document.getElementById("card" + i);
  if (card.style.transform != "rotateY(180deg)") {
    card.style.transform = "rotateY(180deg)";
    selectors.push(i);
  }
  if (selectors.length == 2) {
    desSelectors(selectors);
    selectors = [];
  }
}

function desSelectors(selectors) {
  setTimeout(() => {
    let back1 = document.getElementById("back" + selectors[0]);
    let back2 = document.getElementById("back" + selectors[1]);

    if (back1.innerHTML != back2.innerHTML) {
      let c1 = document.getElementById("card" + selectors[0]);
      let c2 = document.getElementById("card" + selectors[1]);
      c1.style.transform = "rotateY(0deg)";
      c2.style.transform = "rotateY(0deg)";
    } else {
      back1.style.opacity = 0.1;
      back2.style.opacity = 0.1;

      paresEncontrados++;

      // Verifica si se encontraron todos los pares
      if (paresEncontrados === totalPares) {
        winnerAnimation(); 
      }
    }
  }, 1000);
}

function winnerAnimation() {
  const winnerMessage = document.getElementById('winnerMessage');
  
  // Llama a la función para incrementar y mostrar el contador de victorias
  contarVictoria();

  winnerMessage.style.display = 'block';
  
  setTimeout(() => {
      winnerMessage.style.display = 'none';
  }, 3000); // 3s
  setTimeout( () => { generarTablero();},3500 );
  
}

function contarVictoria() {
  cont++; // Incrementa la variable cont
  const contadorVictorias = document.getElementById('contadorVictorias');
  contadorVictorias.textContent = `Victorias: ${cont}`; // Muestra el nuevo valor
}

/*
function startTimer() {
  timeElapsed = 0;
  const timerDisplay = document.getElementById('timer');
  timerDisplay.textContent = `Tiempo: ${timeElapsed}s`;

  // Inicia el temporizador y actualiza cada segundo
  timerInterval = setInterval(() => {
      timeElapsed++;
      timerDisplay.textContent = `Tiempo: ${timeElapsed}s`;
  }, 1000);
}

function stopTimer() {
  clearInterval(timerInterval); // Detiene el temporizador
}*/
