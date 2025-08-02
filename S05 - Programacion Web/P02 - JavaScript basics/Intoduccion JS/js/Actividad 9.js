//Dado un array de numeros, crear una funcion que retorne el numero más grande

function numeroMaximo(array) {
    let maxNum = array[0];

    for (let i = 0; i < array.length; i++) {
        if (maxNum < array[i]) {
            maxNum = array[i];
        }
    }

    return maxNum;
}

console.log(numeroMaximo([5, 10, 20, 8, 3])); // 20