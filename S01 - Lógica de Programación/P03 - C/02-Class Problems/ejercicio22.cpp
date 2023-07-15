/*
Ejercicio 22
Espinoza Sánchez José Luis-280676-1°C
09/12/2022
Escribir un programa con una función que dada una matriz de dos dimensiones,
realizar un programa que obtenga cuál es la columna que tiene la mayor media.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 5

void llenado(int tabla[][TAM]);
void mostrar(int tabla[][TAM]);
void mediaColumna(int tabla[][TAM]);

int main()
{
	int tabla[TAM][TAM];
	srand(time(NULL));
	llenado(tabla);
	mostrar(tabla);
	mediaColumna(tabla);
	return 0;
}

void llenado(int tabla[][TAM])
{
	for(int i=0;i<TAM;i++)
	{
		for(int j=0;j<TAM;j++)
		{
			tabla[i][j]=rand()%10;
		}
	}
}

void mostrar(int tabla[][TAM])
{
	for(int i=0;i<TAM;i++)
	{
		for(int j=0;j<TAM;j++)
		{
			printf("%d ",tabla[i][j]);
		}
		printf("\n");
	}
}

void mediaColumna(int tabla[][TAM])
{
	float media=0;
	for(int i=0;i<TAM;i++)
	{
		media=0;
		for(int j=0;j<TAM;j++)
		{
			media+=tabla[j][i];
		}
		printf("Media de la columna %d: %.2f\n",i+1,media/TAM);
	}
}