/*
Ejercicio 22
Espinoza Sánchez José Luis-280676-1°C
09/12/2022
Escribir un programa con una función a la que se le de como entrada dos arrays de
enteros ordenados de forma creciente, y devuelva como salida un array ordenado de
forma creciente formado por los elementos de las entradas y sin incluir los
elementos repetidos
*/

#include <stdio.h>
#define TAM1 5
#define TAM2 3
#define TAM TAM1+TAM2

void llenado(int array[],int tam);
void mostrar(int array[],int tam);
void ordenado(int array[],int tam);
void combinacion(int array1[],int array2[],int tam1,int tam2);
void mostrarCombo(int array[],int tam);

int main()
{
	int array1[TAM1],array2[TAM2];
	llenado(array1,TAM1);
	ordenado(array1,TAM1);
	mostrar(array1,TAM1);
	llenado(array2,TAM2);
	ordenado(array2,TAM2);
	mostrar(array2,TAM2);
	combinacion(array1,array2,TAM1,TAM2);
}


void llenado(int array[],int tam)
{
	for(int i=0;i<tam;i++)
	{
		printf("Dame un numero: ");
		scanf("%d",&array[i]);
	}
}

void mostrar(int array[],int tam)
{
	for(int i=0;i<tam;i++)
	{
		printf("%d ",array[i]);
	}
	printf("\n");
}

void ordenado(int array[],int tam)
{
	int aux=0;
	for(int i=0;i<tam;i++)
	{
		for(int j=0;j<tam-1;j++)
		{
			if(array[j]>array[j+1])
			{
				aux=array[j];
				array[j]=array[j+1];
				array[j+1]=aux;
			}
		}
	}
}

void combinacion(int array1[],int array2[],int tam1,int tam2)
{
	int i=0,array[TAM],fin=0,rep=0;
	for(int j=0;j<tam1;j++)
	{
		array[i]=array1[j];
		i++;
	}
	for(int j=0;j<tam2;j++)
	{
		array[i]=array2[j];
		i++;
	}
	ordenado(array,TAM);
	mostrar(array,TAM);
	for(int j=0;j<TAM;j++)
	{
		for(int k=0;k<TAM-2;k++)
		{	
			if(array[k]==array[k+1])
			{
				array[k+1]=array[k+2];
			}
		}
	}
	mostrar(array,TAM);
	mostrarCombo(array,TAM);
}

void mostrarCombo(int array[],int tam)
{
	for(int i=0;i<tam-1;i++)
	{
		printf("%d ",array[i]);
		if(array[i]==array[i+1])
		{
			break;
		}
	}
	printf("\n");
}