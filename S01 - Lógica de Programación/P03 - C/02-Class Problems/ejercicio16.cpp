/*
Ejercicio 16
Espinoza Sánchez José Luis-280676-1°C
07/12/2022
Escribir un programa con una función que lea del teclado y ordene de mayor a menor
20 números reales
*/

#include <stdio.h>

void mayorMenor(float serie[]);
void mostrar(float serie[]);

int main()
{
	float serie[20];
	mayorMenor(serie);
	mostrar(serie);
	return 0;
}

void mayorMenor(float serie[20])
{
	float aux;
	for(int i=0;i<20;i++)
	{
		printf("Dame un numero: ");
		scanf("%f",&serie[i]);
	}
	for(int i=0;i<20;i++)
	{
		for(int j=i+1;j<20;j++)
		{
			if(serie[i]<serie[j])
			{
				aux=serie[i];
				serie[i]=serie[j];
				serie[j]=aux;
			}
		}
	}
}

void mostrar(float serie[])
{
	for(int i=0;i<20;i++)
	{
		printf("%.3f ",serie[i]);
	}
}