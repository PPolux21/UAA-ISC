/*
Ejercicio 4
Espinoza Sánchez José Luis-280676-1°C
07/12/2022
Escribir un programa con una función que devuelva la primera letra de una cadena de
texto
*/

#include <stdio.h>
#include <ctype.h>
#define TAM 50

char primerLetra(char cadena[]);

int main()
{
	char cadena[TAM],letra;
	printf("Escribe cadena(no mayor a 50): ");
	fflush(stdin);
	scanf("%s",cadena);
	letra=primerLetra(cadena);
	printf("%c",letra);
}

char primerLetra(char cadena[])
{
	char letra;
	int i=0;
	for(i=0;i<TAM;i++)
	{
		if(isalpha(cadena[i]))
		{
			letra=cadena[i];
			break;
		}
	}
	return letra;
}
