/*
Ejercicio 1
 Escribir una función que reciba un arreglo float con el registro de las 
 temperaturas del mes de diciembre en Aguascalientes y muestre en pantalla 
 sus valores de forma horizontal separado cada valor pon un tabulador 
*/
#include <iostream>
#define TAM 31

using namespace std;

void mostrarTemp(float []);

int main()
{
	float temp[TAM];
	
	//ciclo para llenar de datos el arreglo
	for(int i=0;i<TAM;i++)
	{
		cout<<"Introduce la temperatura del dia "<<i+1<<" : ";
		cin>>temp[i];
	}
	
	mostrarTemp(temp);
}

//función del ejercicio
void mostrarTemp(float temp[])
{
	for(int i=0;i<TAM;i++)
	{
		cout<<temp[i]<<"\t";
	}
}