/*
Ejercicio Vectores (Captura vector)
*/

#include <stdio.h>
#define TAM 10

void captura();
void mostrar(int vector[]);

int main()
{
	captura();
}

void captura()
{
	int vector[TAM]; // declaración de un arreglo o vector
	for(int i=0;i<TAM;i++)
	{
		printf("Dame valor [%d]: ",i);
		scanf("%d",&vector[i]); // se escribe el vector, y para determinar la posicion se pone "i" entre corchetes
	}
	mostrar(vector);
}

void mostrar(int vector[])
{
	for(int i=0;i<TAM;i++)
	{
		printf("%d\t",vector[i]);
	}
}