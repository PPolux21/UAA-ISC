/*
Ejercicio 24
Espinoza Sánchez José Luis-280676-1°C
09/12/2022
Escribir un programa con una función que convierta números enteros decimales (en
base 10) a sus respectivas representaciones octales (en base 8), por medio de
sucesivas divisiones
*/

#include <stdio.h>

void octal(int dec);

int main()
{
	int dec=0;
	printf("Dame un numero: ");
	scanf("%d",&dec);
	octal(dec);
	return 0;
}

void octal(int dec)
{
	int octa[20],i=0;
	for(i=0;dec>0;i++)
	{
		octa[i]=dec%8;
		dec/=8;
	}
	for(int j=i-1;j>=0;j--)
	{
		printf("%d",octa[j]);
	}
}