/*
Tarea 1 - Ejercicio 3
Espinoza Sánchez José Luis-280676-2°C
05/feb/2023
Leer un texto hasta el fin-de-datos (enter) y mostrar una estadística de las longitudes de las
palabras, esto es, el número total de palabras de longitud 1 que hayan ocurrido, el total de
longitud 2 y así sucesivamente.
Define una palabra como una secuencia de caracteres alfabéticos. Se deberán permitir
palabras hasta de una longitud de 25 letras
*/

#include <stdio.h>
#define TAM 25

void captura(char[]);
void estadistica(char[]);
void limpiar(int[]);
void longPalabra(int[],int);
void datos(int[]);

int main()
{
	char texto[TAM];
	captura(texto);
	estadistica(texto);
	return 0;
}

void captura(char array[])
{
	printf("Dame el texto:\n");
	gets(array);
}

void estadistica(char array[])
{
	int cont=0;
	int longitud[25];
	limpiar(longitud);
	for(int i=0;i<TAM;i++)
	{
		printf("%c",array[i]);
		if((array[i]>=65 && array[i]<=90)||(array[i]>=97 && array[i]<=122))
		{
			cont++;
		}
		else
		{
			if(array[i]==32 || array[i]=='\0')
			{
				//mandar un vector que guarde el numero de palabras por longitud en cada posicion del vector
				longPalabra(longitud,cont);
				cont=0;
			}
		}
	}
	printf("\n");
	datos(longitud);
}

void limpiar(int vec[])
{
	for(int i=0;i<25;i++)
	{
		vec[i]=0;
	}
}

void longPalabra(int vec[],int num)
{
	switch(num)
	{
		case 1:
			vec[0]++;
			break;
		case 2:
			vec[1]++;
			break;
		case 3:
			vec[2]++;
			break;
		case 4:
			vec[3]++;
			break;
		case 5:
			vec[4]++;
			break;
		case 6:
			vec[5]++;
			break;
		case 7:
			vec[6]++;
			break;
		case 8:
			vec[7]++;
			break;
		case 9:
			vec[8]++;
			break;
		case 10:
			vec[9]++;
			break;
		case 11:
			vec[10]++;
			break;
		case 12:
			vec[11]++;
			break;
		case 13:
			vec[12]++;
			break;
		case 14:
			vec[13]++;
			break;
		case 15:
			vec[14]++;
			break;
		case 16:
			vec[15]++;
			break;
		case 17:
			vec[16]++;
			break;
		case 18:
			vec[17]++;
			break;
		case 19:
			vec[18]++;
			break;
		case 20:
			vec[19]++;
			break;
		case 21:
			vec[20]++;
			break;
		case 22:
			vec[21]++;
			break;
		case 23:
			vec[22]++;
			break;
		case 24:
			vec[23]++;
			break;
		case 25:
			vec[24]++;
			break;
	}
}

void datos(int vec[])
{
	for(int i=0;i<25;i++)
	{
		printf("Longitud %d: %d ocurrencias\n",i+1,vec[i]);
	}
}