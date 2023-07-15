/*
Ejercicio 9
Espinoza Sánchez José Luis-280676-1°C
07/12/2022
Escribir un programa con una función que rote una matriz 90 grados
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int TAM=5;//tamaño de la matriz
const int LIM=10;//limite para los numeros aleatorios

void llenar(int mat[][TAM]);
void mostrar(int mat[][TAM]);
void rotar(int mat[][TAM]);
void copiar(int mat[][TAM],int copia[][TAM]);

int main()
{
	int mat[TAM][TAM];
	srand(time(NULL));
	llenar(mat);
	mostrar(mat);
	rotar(mat);
	printf("\n");
	mostrar(mat);
}

void llenar(int mat[][TAM])
{
	for(int i=0;i<TAM;i++)
	{
		for(int j=0;j<TAM;j++)
		{
			mat[i][j]=rand()%LIM;
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

void rotar(int mat[][TAM])
{
	int copia[TAM][TAM],i=0,j=0;
	copiar(mat,copia);
	for(int k=TAM-1;k>=0;k--)
	{
		i=0;
		for(int h=0;h<TAM;h++)
		{
			mat[i][j]=copia[h][k];
			j++;
		}
		i++;
	}
}

void copiar(int mat[][TAM],int copia[][TAM])
{
	for(int i=0;i<TAM;i++)
	{
		for(int j=0;j<TAM;j++)
		{
			copia[i][j]=mat[i][j];
		}
	}
}