/*
Ejercicio 10
Espinoza Sánchez José Luis-280676-1°C
06/oct/2022
Identificar si un triangulo es equilatero
*/

#include <stdio.h>

int main(){

	float lado1, lado2, lado3;
	
	printf("Dame el lado 1: ");
	scanf("%f",&lado1);
	printf("Dame el lado 2: ");
	scanf("%f",&lado2);
	printf("Dame el lado 3: ");
	scanf("%f",&lado3);
	
	if (lado1 == lado2 && lado1 == lado3){
		printf("El triangulo es equilatero");
	}else{
		printf("El triangulo no es equilatero");
	}
	
}