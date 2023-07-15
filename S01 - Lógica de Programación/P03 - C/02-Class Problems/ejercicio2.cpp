/*
Ejercicio 2
Espinoza Sánchez José Luis-280676-1°C
25/11/2022
Escribir un programa con una función que calcule cual es el menor de dos números
enteros que se reciben como parámetros. El resultado será otro número entero que se
retorna
*/

#include <stdio.h>

int mayorMenor(int num1,int num2);

int main()
{
	int num1,num2,res=0;
	printf("Dame un numero: ");
	scanf("%d",&num1);
	printf("Dame un numero: ");
	scanf("%d",&num2);
	res=mayorMenor(num1,num2);
	printf("%d es mayor",res);
	return 0;
}

int mayorMenor(int num1,int num2)
{
	int res;
	if(num1>num2)
	{
		res=num1;
	}
	else
	{
		res=num2;
	}
	return res;
}