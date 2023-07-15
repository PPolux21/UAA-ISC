/*
Ejercicio 16
Espinoza Sánchez José Luis-280676-1°C
16/oct/2022
Capture 3 valores enteros y muestre en pantalla los valores ordenados de mayor a menor
*/

#include <stdio.h>

int main(){
	
	int num1=0,num2=0,num3=0;
	
	printf("Introduce un numero: ");
	scanf("%d",&num1);
	printf("Introduce un numero: ");
	scanf("%d",&num2);
	printf("Introduce un numero: ");
	scanf("%d",&num3);
	
	if(num1>num2){
		
		if(num2>num3){
			
			printf("Orden de los numeros: %d, %d, %d",num1,num2,num3);
			
		}else{
			
			if(num1>num3){
				
				printf("Orden de los numeros: %d, %d, %d",num1,num3,num2);
				
			}else{
				
				printf("Orden de los numeros: %d, %d, %d",num3,num1,num2);
				
			}
		}
	}else{
		
		if(num1>num3){
			
			printf("Orden de los numeros: %d, %d, %d",num2,num1,num3);
			
		}else{
			
			if(num2>num3){
				
				printf("Orden de los numeros: %d, %d, %d",num2,num3,num1);
				
			}else{
				
				printf("Orden de los numeros: %d, %d, %d",num3,num2,num1);
				
			}
		}
		
	}	
}