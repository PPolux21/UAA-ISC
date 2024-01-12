/*
Ejercicio 9
 Escribir una función recursiva que obtenga la sumatoria de los elementos de un arreglo
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
#define TAM 10

using namespace std;

int suma(int[],int);	//funcion del ejercicio
void llenar(int[]);
void mostrar(int[]);

int main()
{
	int vec[TAM];
	
	srand(time(NULL));
	
	llenar(vec);
	mostrar(vec);
	cout<<"La suma del vector es: "<<suma(vec,TAM-1);
	
	return 0;
}

//funcion del ejercicio
int suma(int vec[],int tam)
{
	if(tam==0)
	{
		return vec[0];
	}
	else
	{
		return suma(vec,tam-1) + vec[tam];
	}
}

void llenar(int vec[])
{
	for(int i=0;i<TAM;i++)
		vec[i]=rand()%11;
}

void mostrar(int vec[])
{
	for(int i=0;i<TAM;i++)
		cout<<vec[i]<<"\t";
	cout<<endl;
}