/*
Valores aleatorios y while
30/sep/2022

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int num=0, total=0, valor=0;
	srand(time(NULL));
	
	printf("Valor para detener el ciclo: ");
	scanf("%d",&valor);
	
	if (valor>=0 && valor<=30){
		while (num!=valor){
			num=rand()%31;
			printf("%d \t",num);
			total++;
		}
			printf("Total de numeros generados %d", total);
	}else{
		printf("Valor fuera de rango");
	}
}