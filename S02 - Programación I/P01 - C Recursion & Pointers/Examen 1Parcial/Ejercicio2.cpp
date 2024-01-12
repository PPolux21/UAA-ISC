/*
Ejercicio 2
 Escribir una función que reciba un arreglo int con los id de los 
 alumnos de tu grupo, más un valor entero que indique el total de 
 elementos y ordene su contenido por el método de la burbuja
*/
#include <iostream>
#define TAM 10

using namespace std;

void ordenId(int []);

int main()
{
	int id[TAM];
	
	//ciclo para llenar de datos el arreglo
	for(int i=0;i<TAM;i++)
	{
		cout<<"Introduce el id del estudiante "<<i+1<<" : ";
		cin>>id[i];
	}
	
	ordenId(id);
	
	//ciclo para mostrar arreglo
	for(int i=0;i<TAM;i++)
		cout<<id[i]<<endl;
}

//función del ejercicio
void ordenId(int id[])
{
	int aux=0;
	
	for(int i=0;i<TAM-1;i++)
		for(int j=0;j<TAM-i-1;j++)
			if(id[j]>id[j+1])
			{
				aux=id[j];
				id[j]=id[j+1];
				id[j+1]=aux;
			}
}