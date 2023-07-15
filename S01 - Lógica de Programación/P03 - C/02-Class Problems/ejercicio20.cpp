/*
Ejercicio 20
Espinoza Sánchez José Luis-280676-1°C
09/12/2022
Escribir un programa con una función indique si los dos arrays dados como entrada
son iguales o no.
*/

#include <stdio.h>
#define TAM 5

void llenado(int array[]);
void mostrar(int array[]);
bool comparacion(int array1[],int array2[]);

int main()
{
	int array1[TAM],array2[TAM];
	llenado(array1);
	mostrar(array1);
	llenado(array2);
	mostrar(array2);
	if(comparacion(array1,array2))
	{
		printf("Son iguales");
	}
	else
	{
		printf("No son iguales");
	}
}

void llenado(int array[])
{
	for(int i=0;i<TAM;i++)
	{
		printf("Dame un numero: ");
		scanf("%d",&array[i]);
	}
}

void mostrar(int array[])
{
	for(int i=0;i<TAM;i++)
	{
		printf("%d ",array[i]);
	}
	printf("\n");
}

bool comparacion(int array1[],int array2[])
{
	bool iguales=true;
	for(int i=0;i<TAM;i++)
	{
		if(array1[i]!=array2[i])
		{
			iguales=false;
		}
	}
	return iguales;
}