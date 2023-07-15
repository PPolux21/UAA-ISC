/*
Ejercicio 5
Espinoza Sánchez José Luis-280676-1°C
06/oct/2022
Obtener la sumatoria y el promedio de un conjunto de valores
*/
#include <stdio.h>

int main(){
	
	int num=0,sum=0,cantidad=0,prom=0;
	char i='s';
	
	while(i=='s'){
		
		printf("Introducir un numero: ");
		scanf("%d",&num);
		sum+=num;
		
		printf("Introducir otro numero (s/n) ");
		getchar();
		scanf("%c",&i);
		
		cantidad++;
		
	}
	
	prom=sum/cantidad;
	
	printf("La sumatoria de los valores es %d con um promedio de %d",sum,prom);
	
}