/*
Ejercicio 15
Espinoza Sánchez José Luis-280676-1°C
31/oct/2022
Se dispone de los datos sobre las edades y coeficientes de inteligencia (CI) de los hijos de varias familias. El siguiente
programa en C lee el número de familias y para cada familia lea el número de hijos así como la edad y el CI de cada
hijo, y calcula:
	• El número máximo, mínimo y promedio de hijos por familia.
	• El CI máximo, mínimo y promedio de todos los hijos.
	• El CI promedio de los hijos menores de 6 años.
	• El CI promedio de los hijos mayores de 6 años.
*/

#include <stdio.h>
#include <limits.h>//no me funcionaba el programa y quería agregar valores muy grandes y pequeños

int main()
{
	int coefIn,familias,hijos,edad;
	int maxCI=INT_MIN,minCI=INT_MAX,promCI=0,sumCI=0;
	int maxTotal=INT_MIN,minTotal=INT_MAX,promTotal=0,sumTotal=0;
	int sumMenores6=0,sumMayores6=0,promMenores6=0,promMayores6=0,menores6=0,mayores6=0;
	
	printf("Dame el numero de familias: ");
	scanf("%d",&familias);
	
	for(int i=1;i<=familias;i++)
	{
		maxCI=INT_MIN;
		minCI=INT_MAX;
		sumCI=0;
		
		printf("\nDame el numero de hijos: ");
		scanf("%d",&hijos);
		
		for(int j=1;j<=hijos;j++)
		{
			printf("Dame la edad del hijo: ");
			scanf("%d",&edad);
			printf("Dame el CI del hijo: ");
			scanf("%d",&coefIn);
			
			sumCI+=coefIn;
			
			if(coefIn>maxCI)
			{
				maxCI=coefIn;
			}
		
			if(coefIn<minCI)
			{
				minCI=coefIn;
			}
			
			if(edad<=6)
			{
				sumMenores6+=coefIn;
				menores6++;
			}
			else
			{
				sumMayores6+=coefIn;
				mayores6++;
			}
		
		}
		
		promCI=sumCI/hijos;
		printf("Valores de la familia:\n \tCI maximo: %d \n \tCI minimo: %d \n \tCI promedio: %d \n",maxCI,minCI,promCI);
		
		if(maxCI>maxTotal)
		{
			maxTotal=maxCI;
		}
	
		if(minCI<minTotal)
		{
			minTotal=minCI;
		}
		
		sumTotal+=promCI;
	}
	promTotal=sumTotal/familias;
	promMayores6=sumMayores6/mayores6;
	promMenores6=sumMenores6/menores6;
	
	printf("\nValores totales:\n \tCI maximo: %d \n \tCI minimo: %d \n \tCI promedio: %d \n \tCI menores 6 anos: %d \n \tCI mayores 6 anos: %d",maxTotal,minTotal,promTotal,promMenores6,promMayores6);
	
}