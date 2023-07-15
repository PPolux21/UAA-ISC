/*
Ejercicio 7
Espinoza Sánchez José Luis-280676-1°C
07/12/2022
*/

#include <stdio.h>
#include <string.h>

void grafico(char frase[],int rep,int tam);

int main()
{
	int tam,rep;
	char frase[15];
	printf("Escribe la frase: ");
	fflush(stdin);
	scanf("%s",frase);
	printf("Dame las veces a repetir la frase: ");
	scanf("%d",&rep);
	tam=strlen(frase);
	grafico(frase,rep,tam);
}

void grafico(char frase[],int rep,int tam)
{
	for(int i=0;i<tam;i++)
	{
		for(int j=i;j<tam;j++)
		{
			printf("%c",frase[j]);
		}
		for(int j=1;j<rep;j++)
		{
			printf("%s",frase);
		}
		for(int j=0;j<i;j++)
		{
			printf("%c",frase[j]);
		}
		printf("\n");
	}
}