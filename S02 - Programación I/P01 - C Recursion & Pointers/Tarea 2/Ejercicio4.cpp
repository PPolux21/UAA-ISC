/*
Ejercicio 4
Espinoza Sánchez José Luis-280676-2°C
24/02/2023
Implementa una función recursiva que devuelva el numero de dígitos de un numero natural
*/

#include <iostream>

int digitos(int);

using namespace std;

int main()
{
	int num;
	cout<<"Dame un numero entero: ";
	cin>>num;
	if(num<0)
	{
		num*=(-1);
	}
	cout<<"La cantidad de los digitos de "<<num<<" es: "<<digitos(num)<<endl;
}

int digitos(int numero)
{
	int total=1;
	if(numero/10<=0)
	{
		return 1;
	}
	else
	{
		total+=digitos(numero/10);
	}
	return total;
}