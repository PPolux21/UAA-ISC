/*
III.- Tarjetas de crédito
Espinoza Sánchez José Luis - 280676 - ISC 1° C
*/

#include <stdio.h>
#define TAM 16

void llenado(int tarjeta[],int tam);
void mostrarTarjeta(int tarjeta[],int tam);
bool tarjetaValida(int tarjeta[],int tam,char tipo);

int main()
{
	int tarjeta[TAM];
	char tipo;
	llenado(tarjeta,TAM);
	switch(tarjeta[0])
	{
		case 3:
			tipo='A';
			break;
		case 4:
			tipo='V';
			break;
		case 5:
			tipo='M';
			break;
		default:
			printf("Tarjeta no valida\n");
			return 1;
	}
	
	printf("Tipo de tarjeta: %c\n",tipo);
	if(tarjetaValida(tarjeta,TAM,tipo))
	{
		printf("Tarjeta valida\n");
		return 0;
	}
	else
	{
		printf("Tarjeta no valida\n");
		return 1;
	}
}

void llenado(int tarjeta[],int tam)
{
	printf("Dame numero por numero la tarjeta de credito: \n");
	for(int i=0;i<tam;i++)
	{
		scanf("%d",&tarjeta[i]);
	}
}

void mostrarTarjeta(int tarjeta[],int tam)
{
	for(int i=0;i<tam;i++)
	{
		printf("%d ",tarjeta[i]);
	}
	printf("\n");
}

bool tarjetaValida(int tarjeta[],int tam,char tipo)
{
	bool valido=false;
	int suma=0;
	printf("Tarjeta introducida: \n");
	mostrarTarjeta(tarjeta,tam);
	for(int i=0;i<tam;i++)
	{
		if(i%2==0)
		{
			tarjeta[i]*=2;
			if(tarjeta[i]>9)
			{
				tarjeta[i]-=9;
			}
		}
		suma+=tarjeta[i];
	}
	
	printf("Nueva tarjeta: \n");
	mostrarTarjeta(tarjeta,tam);
	
	if(suma%10==0&&suma<=150)
	{
		valido=true;
	}
	return valido;
}
