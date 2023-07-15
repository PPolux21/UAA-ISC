/*
Ejercicio 10
Espinoza Sánchez José Luis-280676-1°C
07/12/2022
Escribir un programa con una función que sume los elementos de la diagonal principal
de una matriz de tamaño n x n
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 5

void llenado(int mat[][TAM]);
void mostrar(int mat[][TAM]);
int sumaDiagonal(int mat[][TAM]);

int main()
{
	int mat[TAM][TAM],suma=0;
	srand(time(NULL));
	llenado(mat);
	mostrar(mat);
	suma=sumaDiagonal(mat);
	printf("Suma de la diagonal: %d",suma);
}

void llenado(int mat[][TAM])
{
	for(int i=0;i<TAM;i++)
	{
		for(int j=0;j<TAM;j++)
		{
			mat[i][j]=rand()%10;
		}
	}
}

void mostrar(int mat[][TAM])
{
	for(int i=0;i<TAM;i++)
	{
		for(int j=0;j<TAM;j++)
		{
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}
}

int sumaDiagonal(int mat[][TAM])
{
	int suma=0;
	for(int i=0;i<TAM;i++)
	{
		suma+=mat[i][i];
	}
	return suma;
}