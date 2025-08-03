function randomNumbersFunc(n) {
    const listFunct = document.getElementById("function-list");
    let sum = 0;

    for (let i = 0; i < n ; i++) {
        const newListedElement = document.createElement("li");
        let randNum = Math.floor(Math.random() * 100)
        newListedElement.textContent = randNum;
        listFunct.appendChild(newListedElement);
        sum += randNum;
    }

    document.getElementById("function-sum").innerHTML = "suma = " + sum;
}

const randomNumbersExp = function (n){
    const listFunct = document.getElementById("expression-list");
    let sum = 0;

    for (let i = 0; i < n ; i++) {
        const newListedElement = document.createElement("li");
        let randNum = Math.floor(Math.random() * 100)
        newListedElement.textContent = randNum;
        listFunct.appendChild(newListedElement);
        sum += randNum;
    }

    document.getElementById("expression-sum").innerHTML = "suma = " + sum;
}

randomNumbersArr = (n) => {
    let numList = "";
    let sum = 0;

    for (let i = 0; i < n ; i++) {
        let randNum = Math.floor(Math.random() * 100);
        numList += randNum + "\n";

        sum += randNum;
    }
    document.getElementById("arrow-list").innerHTML = numList;
    document.getElementById("arrow-sum").innerHTML = "suma = " + sum;
}


randomNumbersFunc(10);
randomNumbersExp(10);
randomNumbersArr(10);