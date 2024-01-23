#include <iostream>
#include <string.h>

using namespace std;

// Clase abstracta MediosDeComunicacion
class MediosDeComunicacion {
protected:
    string nombre;
    string tipo;

public:
    MediosDeComunicacion(string _nombre, string _tipo) : nombre(_nombre), tipo(_tipo) {}
    virtual void mostrarInformacion() = 0; // Función virtual pura
    virtual void publicar() = 0; // Función virtual pura
};

// Clase Impresos
class Impresos : public MediosDeComunicacion {
public:
    Impresos(string _nombre, string _tipo) : MediosDeComunicacion(_nombre, _tipo) {}

    void mostrarInformacion() {
        cout << "Nombre: " << nombre << endl;
        cout << "Tipo: " << tipo << endl;
    }

    void publicar() {
        cout << "Publicando en formato impreso." << endl;
    }
};

// Clase Libros
class Libros : public Impresos {
private:
    int numPaginas;
    string autor;

public:
    Libros(string _nombre, string _tipo, int _numPaginas, string _autor) : Impresos(_nombre, _tipo), numPaginas(_numPaginas), autor(_autor) {}

    void mostrarInformacion() {
        Impresos::mostrarInformacion();
        cout << "Número de páginas: " << numPaginas << endl;
        cout << "Autor: " << autor << endl;
    }

    void publicar() {
        Impresos::publicar();
        cout << "Publicando libro." << endl;
    }
};

// Clase Electrónicos
class Electronicos : public MediosDeComunicacion {
public:
    Electronicos(string _nombre, string _tipo) : MediosDeComunicacion(_nombre, _tipo) {}

    void mostrarInformacion() {
        cout << "Nombre: " << nombre << endl;
        cout << "Tipo: " << tipo << endl;
    }

    void publicar() {
        cout << "Publicando en formato electrónico." << endl;
    }
};

// Clase Cinematografia
class Cinematografia : public Electronicos {
private:
    int duracion;
    string director;

public:
    Cinematografia(string _nombre, string _tipo, int _duracion, string _director) : Electronicos(_nombre, _tipo), duracion(_duracion), director(_director) {}

    void mostrarInformacion() {
        Electronicos::mostrarInformacion();
        cout << "Duración: " << duracion << " minutos" << endl;
        cout << "Director: " << director << endl;
    }

    void publicar() {
        Electronicos::publicar();
        cout << "Publicando película." << endl;
    }
};

// Clase Radio
class Radio : public Electronicos {
private:
    string frecuencia;
    string locutor;

public:
    Radio(string _nombre, string _tipo, string _frecuencia, string _locutor) : Electronicos(_nombre, _tipo), frecuencia(_frecuencia), locutor(_locutor) {}

    void mostrarInformacion() {
        Electronicos::mostrarInformacion();
        cout << "Frecuencia: " << frecuencia << endl;
        cout << "Locutor: " << locutor << endl;
    }

    void publicar() {
        Electronicos::publicar();
        cout << "Transmitiendo en la radio." << endl;
    }
};

// Clase principal (main)
int main() {
    // Ejemplo de uso
    Libros libro("El Quijote", "Novela", 863, "Miguel de Cervantes");
    libro.mostrarInformacion();
    libro.publicar();

    Cinematografia pelicula("Inception", "Ciencia ficción", 148, "Christopher Nolan");
    pelicula.mostrarInformacion();
    pelicula.publicar();

    Radio radio("Radio X", "Musical", "102.5 FM", "John Doe");
    radio.mostrarInformacion();
    radio.publicar();

    return 0;
}
