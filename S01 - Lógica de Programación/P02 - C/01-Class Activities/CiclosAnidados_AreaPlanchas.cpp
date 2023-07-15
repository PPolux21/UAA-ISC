/*
Ejercicio No.1 Ciclos anidados
20 y 21 oct de 2022
En una industria se fabrican planchas rectangulares que se venden en lotes de 10 planchas (...)

Usando la base del ejercicio hecho en clase, pero con agregados personales
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PLANCHA 10
const int LOTES=50;

void calculos();

int main()
{
	calculos();
}


void calculos()
{
	srand(time(NULL));
	int largo,ancho,loteDef=0,loteBueno=0;
	float area,sumArea,totArea,promArea;
	
	for(int i=1;i<=LOTES;i++)
	{	
		printf("No. de Lote: %d\n",i);
		for(int j=1;j<=PLANCHA;j++)
		{
			sumArea=0;
			ancho=rand()%51;
			largo=rand()%11;
			area=ancho*largo;
			
			if(area>4.4)
			{
				printf("Plancha No. %d \tTiene area de %.2f\n",j,area);
				sumArea+=area;
			}else{
				printf("----- LOTE DEFECTUOSO -----\n\n");
				loteDef++;
				sumArea=0;
				break;
			}
			
			if(j>=PLANCHA)
			{
				loteBueno++;
				sumArea/=PLANCHA;
				printf("Area promedio: %.2f\n",sumArea);
				totArea+=sumArea;
				printf("***** LOTE COMPLETO *****\n\n");
			}
		}//planchas
	}//lotes
	
	promArea=totArea/loteBueno;
	printf("\nEl promedio de area de los lotes buenos es: %.2f \nCon %d lotes buenos y %d lotes defectuosos",promArea,loteBueno,loteDef);
	
}//calculos