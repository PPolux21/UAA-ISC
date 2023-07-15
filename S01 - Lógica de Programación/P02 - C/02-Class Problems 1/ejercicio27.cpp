/*
Ejercicio 27
Espinoza Sánchez José Luis-280676-1°C
18/oct/2022
Numero positivo, negativo o cero
*/

#include <stdio.h>

int main(){
	
	float num=0;
	
	printf("Introduce un numero: ");
	scanf("%f",&num);
	
	if(num>0){
		printf("El numero es positivo");
	}else{
		if(num<0){
			printf("El numero es negativo");
		}else{
			printf("El numero es cero");
		}
	}
}