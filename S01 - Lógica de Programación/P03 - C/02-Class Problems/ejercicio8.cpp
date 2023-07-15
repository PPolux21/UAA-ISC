/*
Ejercicio 8
Espinoza Sánchez José Luis-280676-1°C
07/12/2022
Escribir un programa con una función que llene matriz de afuera hacia adentro
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 3

void llenar(int matriz[][MAX]);
void mostrar(int matriz[][MAX]);

int main()
{
	int matriz[MAX][MAX];
	srand(time(NULL));
	llenar(matriz);
	mostrar(matriz);
	
}

void llenar(int matriz[][MAX])
{
	int cont=0,aux=MAX-1;
	for(int i=1;i<MAX;i++)
	{
		for(int j=i-1;j<aux;j++)
		{
			matriz[MAX-(aux+1)][j]=cont++;
		}
		for(int j=i-1;j<aux;j++)
		{
			matriz[j][aux]=cont++;
		}
		for(int j=aux;j>=(i-1);j--)
		{
			matriz[aux][j]=cont++;
		}
		aux--;
		for(int j=aux;j>=i;j--)
		{
			matriz[j][MAX-(aux+2)]=cont++;
		}
	}
}

void mostrar(int matriz[][MAX])
{
	for(int i=0;i<MAX;i++)
	{
		for(int j=0;j<MAX;j++)
		{
			printf("%d\t",matriz[i][j]);
		}
		printf("\n");
	}
}