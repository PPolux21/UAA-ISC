// Retrieve books from localStorage or initialize an empty array
let books = JSON.parse(localStorage.getItem('books')) || []; // Obtiene los libros almacenados o inicializa un array vacío

let editingIndex = null;

const bookForm = document.getElementById('bookForm'); // Recupera el folmulario
const bookTableBody = document.querySelector('#bookTable tbody'); // Recupera la tabla de libros

// Function to render books in the table
function renderBooks() {
    bookTableBody.innerHTML = ''; // Limpia el contenido previo de la tabla
    books.forEach((book , index) => { // Itera sobre cada libro en el arreglo
        const row = document.createElement('tr'); // Crea una nueva fila de la tabla
        row.innerHTML = `
            <td>${book.title}</td>
            <td>${book.author}</td>
            <td>${book.publisher}</td>
            <td>${book.year}</td>
            <td>
                <button onclick="editBook(${index})">Edit</button>
                <button onclick="deleteBook(${index})">Delete</button>
            </td>

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

    if (editingIndex !== null) {
        books[editingIndex] = newBook;
        editingIndex = null;
    } else {
        // Add the new book to the array
        books.push(newBook); // Agrega el nuevo libro al array de libros   
    }

    // Save the updated array to localStorage
    localStorage.setItem('books', JSON.stringify(books)); // Guarda el array actualizado en localStorage

    // Render the updated book list
    renderBooks(); // Vuelve a renderizar la lista de libros

    // Clear the form
    bookForm.reset(); // Resetea el formulario
});

function editBook(index){
    let auxBook = books[index];
    document.getElementById('title').value = auxBook.title;
    document.getElementById('author').value = auxBook.author;
    document.getElementById('publisher').value = auxBook.publisher;
    document.getElementById('year').value = auxBook.year;
    editingIndex = index;
}

function deleteBook(index){
    books.splice(index,1);
    localStorage.setItem('books', JSON.stringify(books));
    renderBooks();
}

// Initial render
renderBooks(); // Renderiza los libros al cargar la página
