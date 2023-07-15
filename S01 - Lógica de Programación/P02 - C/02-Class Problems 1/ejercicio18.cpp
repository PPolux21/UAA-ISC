/*
Ejercicio 18
Espinoza Sánchez José Luis-280676-1°C
16/oct/2022
Obtener multiplicacion de un numero con sumas (for)
*/

#include <stdio.h>

int main(){
	
	int numero1=0,numero2=0,mult=0;
	
	printf("Dame un numero1: ");
	scanf("%d",&numero1);
	printf("Dame un numero2: ");
	scanf("%d",&numero2);
	
	for(int i=1;i<=numero2;i++){
		
		mult+=numero1;
		
	}
	
	printf("%d x %d = %d",numero1,numero2,mult);
}