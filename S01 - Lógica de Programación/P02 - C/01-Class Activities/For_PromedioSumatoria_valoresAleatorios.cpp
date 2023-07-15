/*
Promedio con valores aleatorios
29/sep/2022
Hacer una sumatoria y luego obtner promedio con valores aleatorios
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int numero=0, cantidad=0;
	srand(time(NULL));
	printf("cantidad de valores a generar: ");
	scanf("%d",&cantidad);
	for(int i=1; i<=cantidad; i++){
		numero=rand() % 51;
		printf("%d \n",numero);
	}
}