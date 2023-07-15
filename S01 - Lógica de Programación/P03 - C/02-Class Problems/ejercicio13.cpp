/*
Ejercicio 13
Espinoza Sánchez José Luis-280676-1°C
07/12/2022
Escribir un programa con una función que calcule el factorial de un número entero
positivo. Si el número introducido no está en el rango 1...20, el programa deberá
indicarlo y volver a pedir otro número hasta que sea válido para realizar el cálculo
*/

#include <stdio.h>
#include <stdlib.h>

void factorial(int num);

int main()
{
	int num;
	bool condicion;
	do
	{
		condicion=false;
		system("cls");
		printf("Dame el numero: ");
		scanf("%d",&num);
		if(num<1)
		{
			condicion=true;
		}
		if(num>20)
		{
			condicion=true;
		}
	}while(condicion);
	factorial(num);
	return 0;
}

void factorial(int num)
{
	int fact=1;
	for(int i=1;i<=num;i++)
	{
		fact*=i;
	}
	printf("%d",fact);
}