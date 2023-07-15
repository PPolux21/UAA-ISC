/*
Ejercicio 7
Espinoza Sánchez José Luis-280676-1°C
31/oct/2022
Realizar la división entera a/b de dos valores enteros positivos mediante restas.
*/

#include <stdio.h>

int main()
{
	int divisor,dividendo,resultado=0;
	
	printf("Dame el numero a dividir: ");
	scanf("%d",&dividendo);
	printf("Dame el numero por el cual se va a dividir: ");
	scanf("%d",&divisor);
	
	while(dividendo>0)
	{
		dividendo-=divisor;
		resultado++;
	}
	printf("Resultado: %d",resultado);
}