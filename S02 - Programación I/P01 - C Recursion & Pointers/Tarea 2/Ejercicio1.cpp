/*
Ejercicio 1
Espinoza Sánchez José Luis-280676-2°C
24/02/2023
Implementa una función recursiva que devuelva la suma de los dígitos de un numero natural,
que se le pasa por parámetro
*/

#include <iostream>

int suma(int);

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
	cout<<"La suma de los digitos de "<<num<<" es: "<<suma(num)<<endl;
}

int suma(int numero)
{
	if(numero/10<=0)
	{
		return numero;
	}
	else
	{
		return numero%10+suma(numero/10);
	}
}