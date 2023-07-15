/*
Ejercicio 28
Espinoza Sánchez José Luis-280676-1°C
18/oct/2022
Numero par o impar
*/

#include <stdio.h>

int main(){
	
	int num=0;
	
	printf("Introduce un numero: ");
	scanf("%d",&num);
	
	if(num%2==0){
		printf("El numero es par");
	}else{
		printf("El numero es impar");
	}
}