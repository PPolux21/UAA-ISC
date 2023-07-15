/*
Ejercicio 17
Espinoza Sánchez José Luis-280676-1°C
07/12/2022
Escribir un programa con una función que calcule la matriz transpuesta de una matriz
bidimensional cuadrada de tamaño M. El tamaño de la matriz y su contenido se leerá
por teclado.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 5

void llenar(int mat[][TAM]);
void mostrar(int mat[][TAM]);
void transposicion(int mat[][TAM]);
void copiar(int mat[][TAM],int copia[][TAM]);

int main()
{
	int mat[TAM][TAM];
	srand(time(NULL));
	llenar(mat);
	mostrar(mat);
	transposicion(mat);
	printf("\n");
	mostrar(mat);
}

void llenar(int mat[][TAM])
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

void transposicion(int mat[][TAM])
{
	int copia[TAM][TAM],i=0,j=0;
	copiar(mat,copia);
	for(int k=0;k<TAM;k++)
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