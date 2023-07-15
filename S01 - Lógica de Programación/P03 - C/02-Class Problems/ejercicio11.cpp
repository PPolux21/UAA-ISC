/*
Ejercicio 11
Espinoza Sánchez José Luis-280676-1°C
07/12/2022
Escribir un programa con una función que muestre la tabla de multiplicar de cualquier
numero de dos dígitos
*/

#include <stdio.h>

void tablaMult(int num);

int main()
{
	int num;
	printf("Dame el numero: ");
	scanf("%d",&num);
	if(num>=10&&num<=99)
	{	
		tablaMult(num);
		return 0;
	}
	else
	{
		return 1;
	}
}

void tablaMult(int num)
{
	for(int i=1;i<=10;i++)
	{
		printf("%d x %d = %d\n",num,i,num*i);
	}
}