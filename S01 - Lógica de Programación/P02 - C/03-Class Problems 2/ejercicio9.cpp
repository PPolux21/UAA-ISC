/*
Ejercicio 9
Espinoza Sánchez José Luis-280676-1°C
31/oct/2022
Escribir un programa que lea valores enteros hasta que se introduzca un 0
y calcule la media de los positivos y la media de los negativos
*/

#include <stdio.h>

int main()
{
	int valorUsuario,sumPositivos=0,sumNegativos=0,promPositivos=0,promNegativos=0,positivos=0,negativos=0;
	
	do{
		printf("Introduce un numero entero: ");
		scanf("%d",&valorUsuario);
		if(valorUsuario>0)
		{
			sumPositivos+=valorUsuario;
			positivos++;
		}
		
		if(valorUsuario<0)
		{
			sumNegativos+=valorUsuario;
			negativos++;
		}
	}while(valorUsuario!=0);
	
	promNegativos=sumNegativos/negativos;
	promPositivos=sumPositivos/positivos;
	
	printf("Promedio positivos %d negativos %d",promPositivos,promNegativos);
}