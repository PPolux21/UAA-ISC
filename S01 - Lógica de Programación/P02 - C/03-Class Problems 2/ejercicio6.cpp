/*
Ejercicio 6
Espinoza Sánchez José Luis-280676-1°C
31/oct/2022
Realizar la operación de potenciación (a^b), de dos valores enteros positivos, con multiplicaciones
*/

#include <stdio.h>

int main()
{	
	int base,exponente,resultado=1;
	
	printf("Dame el numero a potenciar: ");
	scanf("%d",&base);
	printf("Dame la potencia a elevar el numero: ");
	scanf("%d",&exponente);
	
	for(int i=1;i<=exponente;i++)
	{
		resultado*=base;
	}
	printf("Resultado: %d",resultado);
}