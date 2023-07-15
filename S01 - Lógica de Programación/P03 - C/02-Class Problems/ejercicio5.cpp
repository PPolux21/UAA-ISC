/*
Ejercicio 5
Espinoza Sánchez José Luis-280676-1°C
07/12/2022
Escribir un programa con una función que reciba una letra y un número, y muestre en
pantalla un “triángulo” formado por esa letra, que tenga como anchura inicial la que se
ha indicado.
*/

#include <stdio.h>

void triangulo(int tam,char simbolo);

int main()
{
	int tam;
	char simbolo;
	printf("Dame el tamanno del triangulo: ");
	scanf("%d",&tam);
	printf("Dame el simbolo que formara el triangulo: ");
	fflush(stdin);
	scanf("%c",&simbolo);	
	triangulo(tam,simbolo);
}

void triangulo(int tam,char simbolo)
{
	for(int i=0; i<tam; i++)
	{
		for(int j=tam; j>i; j--)
		{
			printf("%c ",simbolo);
		}
		printf("\n");
	}
}