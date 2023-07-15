/*
Ejercicio 14
Espinoza Sánchez José Luis-280676-1°C
31/oct/2022
Escribir un programa que lea números enteros de teclado hasta que encuentre uno que cumpla las siguientes
condiciones:
	• Múltiplo de 2.
	• No múltiplo de 5.
	• Mayor que 100.
	• Menor que 10.000.
*/

#include <stdio.h>

int main()
{
	int valorUsuario,res;
	
	printf("Dame un numero entero: ");
	scanf("%d",&valorUsuario);
	
	if(valorUsuario&2==0)
	{
		printf("Es multiplo de 2\n");
	}
	
	if(valorUsuario%5!=0)
	{
		printf("No es multiplo de 5\n");
	}
	
	if(valorUsuario>100)
	{
		printf("Es mayor que 100\n");
	}
	
	if(valorUsuario<10000)
	{
		printf("Es menor que 10000\n");
	}
}