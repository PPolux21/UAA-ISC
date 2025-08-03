// Retrieve books from localStorage or initialize an empty array
let books = JSON.parse(localStorage.getItem('books')) || []; // Obtiene los libros almacenados o inicializa un array vacío

const bookForm = document.getElementById('bookForm'); // Recupera el folmulario
const bookTableBody = document.querySelector('#bookTable tbody'); // Recupera la tabla de libros

// Function to render books in the table
function renderBooks() {
    bookTableBody.innerHTML = ''; // Limpia el contenido previo de la tabla
    books.forEach(book => { // Itera sobre cada libro en el arreglo
        const row = document.createElement('tr'); // Crea una nueva fila de la tabla
        row.innerHTML = `
            <td>${book.title}</td> <!-- Agrega la celda con el título del libro -->
            <td>${book.author}</td> <!-- Agrega la celda con el autor del libro -->
            <td>${book.publisher}</td> <!-- Agrega la celda con el editor del libro -->
            <td>${book.year}</td> <!-- Agrega la celda con el año del libro -->
        `; // Agrega el contenido dentro tr (row)
        bookTableBody.appendChild(row); // Añade la fila a la tabla
    });
}

// Handle form submission
bookForm.addEventListener('submit', function(event) {
    event.preventDefault(); // Prevent form from reloading the page

    // Get form values
    const title = document.getElementById('title').value; // Obtiene el valor del título
    const author = document.getElementById('author').value; // Obtiene el valor del autor
    const publisher = document.getElementById('publisher').value; // Obtiene el valor del editor
    const year = document.getElementById('year').value; // Obtiene el valor del año

    // Create a new book object
    const newBook = { title, author, publisher, year }; // Crea un objeto con los valores anteriores

    // Add the new book to the array
    books.push(newBook); // Agrega el nuevo libro al array de libros

    // Save the updated array to localStorage
    localStorage.setItem('books', JSON.stringify(books)); // Guarda el array actualizado en localStorage

    // Render the updated book list
    renderBooks(); // Vuelve a renderizar la lista de libros

    // Clear the form
    bookForm.reset(); // Resetea el formulario
});

// Initial render
renderBooks(); // Renderiza los libros al cargar la página
