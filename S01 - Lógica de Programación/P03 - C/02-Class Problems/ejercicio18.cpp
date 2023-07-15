/*
Ejercicio 18
Espinoza Sánchez José Luis-280676-1°C
09/12/2022
Escribir un programa con una función que determine si una matriz es simétrica
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 3

void llenar(int mat[][TAM]);
void mostrar(int mat[][TAM]);
void transposicion(int mat[][TAM]);
void copiar(int mat[][TAM],int copia[][TAM]);
bool comparacion(int mat[][TAM],int copia[][TAM]);

int main()
{
	int mat[TAM][TAM];
	srand(time(NULL));
	llenar(mat);
	mostrar(mat);
	transposicion(mat);
}

void llenar(int mat[][TAM])
{
	for(int i=0;i<TAM;i++)
	{
		for(int j=0;j<TAM;j++)
		{
			printf("Dame un numero: ");
			scanf("%d",&mat[i][j]);
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
	printf("\n");
	mostrar(mat);
	if(comparacion(mat,copia))
	{
		printf("\nEs simetrica");
	}
	else
	{
		printf("\nNo es simetrica");
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

bool comparacion(int mat[][TAM],int copia[][TAM])
{
	bool igual=true;
	for(int i=0;i<TAM;i++)
	{
		for(int j=0;j<TAM;j++)
		{
			if(mat[i][j]!=copia[i][j])
			{
				igual=false;
			}
		}
	}
	return igual;
}