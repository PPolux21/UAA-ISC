/*
¿Es un triángulo equilatero?
22/sep/2022
Indicar si el triángulo es equilatero
*/

#include <stdio.h>

int main(){
	
	int lado1, lado2, lado3;	
	
	printf("Dame lado 1: ");
	scanf("%d",&lado1);
	printf("Dame lado 2: ");
	scanf("%d",&lado2);
	printf("Dame lado 3: ");
	scanf("%d",&lado3);
	
	if(lado1==lado2 && lado1==lado3){
		printf("El triangulo es equilatero");
	}else{
		printf("El triangulo no es equilatero");
	}
	
}