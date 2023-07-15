/*
Ejercicio 14
Espinoza Sánchez José Luis-280676-1°C
07/12/2022
Escribir un programa con una función que imprima una pirámide de dígitos como la de
la figura, tomando como entrada el número de filas de la misma
*/

#include <stdio.h>

void triangulo(int filas);

int main(){
	int filas;
	printf("Dame el numero de filas: ");
	scanf("%d",&filas);
	triangulo(filas);
}

void triangulo(int filas)
{
	int num;
	for(int i=1;i<=filas;i++)
	{
		num=1;
		for(int j=filas;j>i;j--)
		{
			printf("  ");
		}
		for(int j=1;j<=i;j++)
		{
			printf("%d ",num++);
		}
		num--;
		for(int j=1;j<=i-1;j++)
		{
			printf("%d ",--num);
		}
		printf("\n");
	}
}