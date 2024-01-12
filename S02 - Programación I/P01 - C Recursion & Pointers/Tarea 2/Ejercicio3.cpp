/*
Ejercicio 3
Espinoza Sánchez José Luis-280676-2°C
24/02/2023
Implementa una función recursiva que imprima por pantalla los valores desde un numero
introducido por el usuario hasta 1
*/

#include <iostream>

void hastaUno(int);

using namespace std;

int main()
{
	int begin;
	cout<<"Dame el numero en el cual empezar: ";
	cin>>begin;
	hastaUno(begin);
}

void hastaUno(int begin)
{
	if(begin>=1)
	{
		cout<<begin<<" ";
		hastaUno(begin-1);
	}
}