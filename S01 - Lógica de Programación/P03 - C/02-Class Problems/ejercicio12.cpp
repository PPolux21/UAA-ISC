/*
Ejercicio 12
Espinoza Sánchez José Luis-280676-1°C
07/12/2022
Escribir un programa con una función que muestre por pantalla los cuadrados de los
100 primeros números enteros
*/

#include <stdio.h>

void cuadrados();

int main()
{
	cuadrados();
	return 0;
}

void cuadrados()
{
	for(int i=1;i<=100;i++)
	{
		printf("%d\n",i*i);
	}
}