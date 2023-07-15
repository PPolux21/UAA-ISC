/*
Ejercicio 3
Espinoza Sánchez José Luis-280676-1°C
6/oct/2022
Imprimir la tabla de multiplicar de un numero N desde 1 hasta 10
*/

#include <stdio.h>

int main(){
	
	int num=0, mult=0;
	
	printf("Introduzca el valor del cual oobtener su tabla de multiplicar: ");
	scanf("%d",&num);
	
	for(int i=1;i<=10;i++){
		
		mult=i*num;
		printf("%d x %d = %d \n",num,i,mult);
		
	}
}