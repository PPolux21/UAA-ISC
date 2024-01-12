/*
Ejercicio 1
 Un programa que pida el nombre, el apellido y la edad de una persona, 
 los almacene en un “struct” y luego muestre los tres datos en una 
 misma línea, separados por comas.
*/

#include <iostream>

#define TAM 15

using namespace std;

struct Data{
	char fName[TAM];
	char lName[TAM];
	int age;
};

void captura(Data *);
void mostrar(Data);

int main()
{
	Data guy;
	captura(&guy);
	mostrar(guy);
}

void captura(Data *guy)
{
	cout<<"\tCaptura de datos\n";
	cout<<"Nombre: ";
	cin>>guy->fName;
	cout<<"Apellido: ";
	cin>>guy->lName;
	cout<<"Edad: ";
	cin>>guy->age;
}

void mostrar(Data guy)
{
	cout<<"\n\tDatos\n";
	cout<<guy.fName<<", "<<guy.lName<<", "<<guy.age<<endl;
}