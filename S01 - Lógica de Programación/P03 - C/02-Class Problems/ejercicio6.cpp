/*
Ejercicio 6
Espinoza Sánchez José Luis-280676-1°C
07/12/2022
Escribir un programa con una función que regrese un true si una cadena de caracteres
que ha recibido como parámetro es simétrica (un palíndromo).
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM 30

void captura(char frase[]);
void quitarEspacio(char frase[],long tam,char fraseSinEs[]);
bool palindromo(char fraseSinEs[],char copia[]);

int main()
{
	char frase[TAM],fraseSinEs[TAM],copia[TAM];
	long tam=0;
	bool simetria;
	
	captura(frase);
	tam=strlen(frase);
	quitarEspacio(frase,tam,fraseSinEs);
	simetria=palindromo(fraseSinEs,copia);
	
	if(simetria)
	{
		printf("Es palindromo!!\n");
	}
	else
	{
		printf("No es palindromo\n");
	}
}

void captura(char frase[])
{
	printf("Introduce la frase: ");
	fflush(stdin);
	gets(frase);
}

void quitarEspacio(char frase[],long tam,char fraseSinEs[])
{
	int j=0;
	for(int i=0;i<tam;i++)
	{
		if(!isspace(frase[i]))
		{
			fraseSinEs[j]=frase[i];
			j++;
		}
	}
}

bool palindromo(char fraseSinEs[],char copia[])
{
	bool simetria=false;
	strcpy(copia,fraseSinEs);
	strrev(fraseSinEs);
	simetria=(copia,fraseSinEs);
	return simetria;
}