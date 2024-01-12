/*
Tarea 1 - Ejercicio 2
Espinoza Sánchez José Luis-280676-2°C
05/feb/2023
Capturar una línea de texto, un caracter a la vez y muestre la línea invertida. Leer hasta que
se encuentre un punto
*/

#include <stdio.h>
#define TAM 10

void captura(char[]);
void mostrar(char[]);
void limpiaArray(char[]);

int main()
{
	char texto[TAM];
	limpiaArray(texto);	//presentacion
	captura(texto);
	mostrar(texto);
	return 0;
}

void captura(char array[])
{
	int i=TAM-1;
	while(i>=0 && array[i+1]!='.')
	{
		printf("Dame un caracter: ");
		fflush(stdin);
		scanf("%c",&array[i]);
		i--;
	}
}

void mostrar(char array[])
{
	for(int i=0;i<TAM;i++)
	{
		printf("%c ",array[i]);
	}
}

void limpiaArray(char array[])
{
	for(int i=0;i<TAM;i++)
	{
		array[i]=' ';
	}
}