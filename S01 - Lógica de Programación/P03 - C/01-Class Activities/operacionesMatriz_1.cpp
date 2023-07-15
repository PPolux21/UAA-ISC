/*
Llenar una matriz con caracteres de forma aleatoria
Determinar:
	-Cuantos vocales
	-Cuantos minusculas
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#define REN 4
const int COL=4;

void llenado(char matChar[][COL]);
void mostrar(char matChar[][COL]);
int contarVocals(char matChar[][COL]);
int contarMinus(char matChar[][COL]);

int main()
{
	srand(time(NULL));
	char matChar[REN][COL];
	llenado(matChar);
	mostrar(matChar);
	printf("Total de vocales: %d\n",contarVocals(matChar));
	printf("Total de minusculas: %d\n",contarMinus(matChar));
}

void llenado(char matChar[][COL])
{
	for(int i=0;i<REN;i++)
	{
		for(int j=0;j<COL;j++)
		{
			matChar[i][j]=32+rand()%(127-32);
		}
	}
}

void mostrar(char matChar[][COL])
{
	for(int i=0;i<REN;i++)
	{
		for(int j=0;j<COL;j++)
		{
			printf("%c\t",matChar[i][j]);
		}
		printf("\n");
	}
}

int contarVocals(char matChar[][COL])
{
	int vocals=0;
	for(int i=0;i<REN;i++)
	{
		for(int j=0;j<COL;j++)
		{
			switch(matChar[i][j])
			{
				case 'a':
				case 'A':
				case 'e':
				case 'E':
				case 'i':
				case 'I':
				case 'o':
				case 'O':
				case 'u':
				case 'U':
					vocals++;
			}
		}
	}
	return vocals;
}

int contarMinus(char matChar[][COL])
{
	int minus=0,digit=0;
	for(int i=0;i<REN;i++)
	{
		for(int j=0;j<COL;j++)
		{
			if(islower(matChar[i][j]))
			{
				minus++;
			}
			
			if(isdigit(matChar[i][j]))
			{
				digit++;
			}
		}
	}
	printf("Total de digitos: %d\n",digit);
	return minus;
}