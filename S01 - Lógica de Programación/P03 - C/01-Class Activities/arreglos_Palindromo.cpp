/*
Palindromos
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void captura(char frase[]);
void quitarEspacio(char frase[],long tam,char fraseSinEs[]);

int main()
{
	char frase[30],fraseSinEs[30],copia[30];
	long tam=0;
	
	captura(frase);
	tam=strlen(frase);
	quitarEspacio(frase,tam,fraseSinEs);
	strcpy(copia,fraseSinEs);
	strrev(fraseSinEs);
	
	if(strcmp(copia,fraseSinEs)==0)
	{
		printf("Es palindromo!!\n");
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
