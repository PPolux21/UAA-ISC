/*
Ejercicio 15
Espinoza Sánchez José Luis-280676-1°C
07/12/2022
Escribir un programa con una función que dado un número entero lo descomponga
dígito a dígito, lo vuelva a componer al revés y lo muestre
*/

#include <stdio.h>

void reversa(int num);

int main()
{
	int num;
	printf("Dame un numero: ");
	scanf("%d",&num);
	reversa(num);
}

void reversa(int num)
{
	int res=0;
	while(num>0)
	{
		res=num%10;
		printf("%d",res);
		num=(num-res)/10;
	}
}