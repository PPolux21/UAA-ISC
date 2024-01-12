/*
Ejercicio 8
Espinoza Sánchez José Luis-280676-2°C
24/02/2023
Implementa una función recursiva que lea desde teclado hasta encontrar un carácter de salto
de línea (\n), y muestre por pantalla lo que ha leído, pero al revés (no utilizar vectores ni bucles).
*/
#include <iostream>
#include <string.h>

void inversor(char);

using namespace std;

int main()
{
	char letra=' ';
	printf("Dame una serie de caracteres: \n");
	inversor(letra);
}

void inversor(char letra)
{
	if(letra!='\n')
	{
		fflush(stdin);
		scanf("%c",&letra);
		inversor(letra);
		printf("%c",letra);
	}
}