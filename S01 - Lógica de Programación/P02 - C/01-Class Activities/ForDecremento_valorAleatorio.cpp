/*
Uso de un for con decremento
30/sep/2022
Uso de un for con decremento y valores aleatorios
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int num=0, total=0;
	srand(time(NULL));
	printf("Cantidad de valores: ");
	scanf("%d",&total);
	
	for (int i=total; i>=1; i--){
		num=rand()%56;
		printf("%d \t",num);
	}
}