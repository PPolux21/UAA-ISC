//Ejercicio escribir una funcion recursiva que devuelva de la suma de los n primeros enteros positivos

#include <iostream>

using namespace std;

int sumaRec(int);

int main()
{
	int cant;
	
	cout<<"Cantidad de numeros: ";
	cin>>cant;
	
	cout<<"La suma de los "<<cant<<" primeros enteros positivos: "<<sumaRec(cant);
	
	return 0;
}

int sumaRec(int num)
{
	if(num==1)
	{
		return 1;
	}
	else
	{
		return (num + sumaRec(num-1));
	}
}