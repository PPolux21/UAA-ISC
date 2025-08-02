const questions = [
    {
        question: "¿Cual es la capital de Francia?",
        options: ["Berlín", "Madrid", "París", "Lisboa"],
        answer: 2
    },
    {
        question: "¿Cuál es el océano más grande?",
        options: ["Atlántico", "Índico", "Ártico", "Pacífico"],
        answer: 3
    },
    {
        question: "¿Quién escribió 'Cien años de soledad'?",
        options: ["Pablo Neruda", "Gabriel García Márquez", "Jorge Luis Borges", "Mario Vargas Llosa"],
        answer: 1
    },
    {
        question: "¿Cuál es el planeta más cercano al sol?",
        options: ["Venus", "Tierra", "Marte", "Mercurio"],
        answer: 3
    }
];

let currentQuestionIndex = 0;
let score = 0;

const questionElement = document.getElementById('question');
const optionsElement = document.getElementById('options');
const nextButton = document.getElementById('next');
const feedbackElement = document.getElementById('feedback');
const scoreElement = document.getElementById('score');

function startGame() {
    currentQuestionIndex = 0;
    score = 0;
    nextButton.classList.add('hidden');
    scoreElement.classList.add('hidden');
    showQuestion();
}

function showQuestion() {
    resetState();
    const currentQuestion = questions[currentQuestionIndex];
    questionElement.innerText = currentQuestion.question;

    currentQuestion.options.forEach((option, index) => {
        const button = document.createElement('button');
        button.innerText = option;
        button.classList.add('option-button');
        button.addEventListener('click', () => selectAnswer(index));
        optionsElement.appendChild(button);
    });
}

function resetState() {
    nextButton.classList.add('hidden');
    feedbackElement.innerText = '';
    optionsElement.innerHTML = '';
}

function selectAnswer(selectedIndex) {
    const currentQuestion = questions[currentQuestionIndex];
    const correctIndex = currentQuestion.answer;
    
    if (selectedIndex === correctIndex) {
        feedbackElement.innerText = '¡Correcto!';
        score++;
        optionsElement.children[selectedIndex].classList.add('correct');
    } else {
        feedbackElement.innerText = 'Incorrecto. La respuesta correcta era: ' + currentQuestion.options[correctIndex];
        optionsElement.children[selectedIndex].classList.add('incorrect');
        optionsElement.children[correctIndex].classList.add('correct');       
    }

    let buttons = document.querySelectorAll('.option-button');

    buttons.forEach(function(button) {
        button.disabled = true;
    });

    nextButton.classList.remove('hidden');
}

nextButton.addEventListener('click', () => {
    currentQuestionIndex++;
    if (currentQuestionIndex < questions.length) {
        showQuestion();
    } else {
        showScore();
    }
});

function showScore() {
    resetState();
    questionElement.innerText = 'Juego terminado';
    scoreElement.innerText = `Tu puntuación: ${score} de ${questions.length}`;
    scoreElement.classList.remove('hidden');
}

startGame();
