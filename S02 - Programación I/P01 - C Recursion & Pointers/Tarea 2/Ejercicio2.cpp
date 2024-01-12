/*
Ejercicio 2
Espinoza Sánchez José Luis-280676-2°C
24/02/2023
Implementa una función recursiva que imprima por pantalla los valores desde 1 hasta un
numero introducido por el usuario
*/

#include <iostream>

void desdeUno(int,int);

using namespace std;

int main()
{
	int limit;
	cout<<"Dame el numero en el cual detenerme: ";
	cin>>limit;
	desdeUno(limit,1);
}

void desdeUno(int limit,int num)
{
	if(num<=limit)
	{
		cout<<num<<" ";
		desdeUno(limit,num+1);
	}
}