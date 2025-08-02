// Escribe un programa que imprima los numeros del 1-100. 
// Para multiplos de 3 imprime "FIZZ" en lugar del numero 
// y para multiplos de 5 imprima "BUZZ", para multiplos de ambos "FIZZ BUZZ"

function fizzBuzz() {
    for (let i = 1; i <= 100; i++) {
        if (i % 3 === 0 && i % 5 === 0) {
            console.log("FIZZ BUZZ");
        } else if (i % 3 === 0) {
            console.log("FIZZ");
        } else if (i % 5 === 0) {
            console.log("BUZZ");
        } else {
            console.log(i);
        }
    }
}

fizzBuzz();