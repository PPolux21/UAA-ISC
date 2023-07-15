/*
Ejercicio 19
Espinoza Sánchez José Luis-280676-1°C
09/12/2022
Escribir un programa con una función que lea en un array N números reales y
determine el mayor, el menor y la media de los números leídos
*/

#include <stdio.h>
#include <limits.h>
#define TAM 10

void llenado(float array[]);
void mayorMenorMedia(float array[]);

int main()
{
	float array[TAM];
	llenado(array);
	mayorMenorMedia(array);
}

void llenado(float array[])
{
	for(int i=0;i<TAM;i++)
	{
		printf("Dame un numero: ");
		scanf("%f",&array[i]);
	}
}

void mayorMenorMedia(float array[])
{
	float mayor=INT_MIN,menor=INT_MAX,media=0;
	for(int i=0;i<TAM;i++)//mayor
	{
		if(array[i]>mayor)
		{
			mayor=array[i];
		}
	}
	printf("Mator: %.4f\n",mayor);
	
	for(int i=0;i<TAM;i++)//menor
	{
		if(array[i]<menor)
		{
			menor=array[i];
		}
	}
	printf("Menor: %.4f\n",menor);
	
	for(int i=0;i<TAM;i++)//media
	{
		media+=array[i];
	}
	media/=TAM;
	printf("Media: %.4f\n",media);
}