/*
Operaciones con Matrices: captura, mostrar, sumaotria diagonal
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int REN=5;
const int COL=5;

void captura(int matriz[][COL]);
void mostrar(int matriz[][COL]);
int sumaDiag(int matriz[][COL]);

int main()
{
	int suma=0,matriz[REN][COL];
	srand(time(NULL));
	captura(matriz);
	mostrar(matriz);
	suma=sumaDiag(matriz);
	printf("\nSuma de la diagonal: %d\n",suma);
}

void captura(int matriz[][COL])
{
	for(int i=0;i<REN;i++)
	{
		for(int j=0;j<COL;j++)
		{
			matriz[i][j]=rand()%101;
		}
	}
}

void mostrar(int matriz[][COL])
{
	for(int i=0;i<REN;i++)
	{
		for(int j=0;j<COL;j++)
		{
			printf("%d\t",matriz[i][j]);
		}
		printf("\n");
	}
}

int sumaDiag(int matriz[][COL])
{
	int suma=0;
	for(int i=0;i<REN;i++)
	{
		for(int j=0;j<COL;j++)
		{
			if(i==j)
			{
				suma+=matriz[i][j];
			}
		}
	}
	return suma;
}