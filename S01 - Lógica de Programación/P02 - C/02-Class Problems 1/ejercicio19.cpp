/*
Ejercicio 19
Espinoza Sánchez José Luis-280676-1°C
16/oct/2022
Obtener multiplicacion de un numero con sumas (while)
*/

#include <stdio.h>

int main(){
	
	int numero1=0,numero2=0,mult=0,i=1;
	
	printf("Dame un numero1: ");
	scanf("%d",&numero1);
	printf("Dame un numero2: ");
	scanf("%d",&numero2);
	
	while(i<=numero2){
		
		mult+=numero1;
		i++;
	}
	
	printf("%d x %d = %d",numero1,numero2,mult);
	
}