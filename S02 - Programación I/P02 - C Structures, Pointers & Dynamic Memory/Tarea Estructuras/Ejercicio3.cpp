/*
Ejercicio 3
 Un programa que almacene datos de tipo Complejo. 
 El programa debe permitir capturar y mostrar datos de este tipo
*/

#include <iostream>

using namespace std;

struct Complex{
	float imag;
	float real;
};

void captura(Complex *,int);
void mostrar(Complex *,int);

int main()
{
	Complex *pares;
	int cant;
	
	cout<<"Cantidad de pares de numeros complejos a introducir: ";
	cin>>cant;
	pares = new Complex [cant];
	
	captura(pares,cant);
	mostrar(pares,cant);
}

void captura(Complex *pares,int num)
{
	cout<<"\tCaptura de datos\n";
	for(int i=0;i<num;i++)
	{
		cout<<"Parte imaginaria: ";
		cin>>pares[i].imag;
		cout<<"Parte real: ";
		cin>>pares[i].real;
	}
}

void mostrar(Complex *pares,int num)
{
	cout<<"\n\tDatos\n";
	for(int i=0;i<num;i++)
	{
		cout<<pares[i].imag<<"i + "<<pares[i].real<<"\t";
	}
}