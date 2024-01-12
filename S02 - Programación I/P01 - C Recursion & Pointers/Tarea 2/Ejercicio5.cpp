/*
Ejercicio 5
Espinoza Sánchez José Luis-280676-2°C
24/02/2023
Implementa una función recursiva que calcule el producto de dos números naturales (se
supone que no esta disponible el operador *).
*/

#include <iostream>

int multiplicacion(int,int);

using namespace std;

int main()
{
	int multiplicando=0,multiplicador=0;
	cout<<"Dame el numero multiplicando: ";
	cin>>multiplicando;
	cout<<"Dame el numero multiplicador: ";
	cin>>multiplicador;
	cout<<"El resultado de la multiplicacion es: "<<multiplicacion(multiplicando,multiplicador)<<endl;
}

int multiplicacion(int num,int cont)
{
	if(cont!=0)
	{
		return num+multiplicacion(num,cont-1);
	}
	else
	{
		return 0;
	}
}