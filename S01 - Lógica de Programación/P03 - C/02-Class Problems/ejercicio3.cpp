/*
Ejercicio 3
Espinoza Sánchez José Luis-280676-1°C
25/11/2022
Escribir un programa con una función llamada “signo”, que reciba un número real, y
devuelva un número entero con el valor: -1 si el número es negativo, 1 si es positivo o 0
si es cero
*/

#include <stdio.h>

void signo(int numero);

int main()
{
	int numero;
	printf("Introduce un numero: ");
	scanf("%d",&numero);
	signo(numero);
	return 0;
}

void signo(int numero)
{
	int res=0;
	if(numero>0)
	{
		res=1;
	}
	
	if(numero<0)
	{
		res=-1;
	}
	printf("%d",res);
	
}