/*
Ejercicio 7
Espinoza Sánchez José Luis-280676-1°C
06/oct/2022
Crear un programa que dados los valores de P y Q determinen el resultado de la siguiente expresión:
	P3 + Q4 – 2 * P2 < 680
En caso afirmativo mostrar el valor de P y en caso negativo el valor de Q.
Si el resultado es falso debe mostrar un valor 0 y si es veradero un valor 1
*/

#include <stdio.h>

int main(){
	
	int P=0,Q=0;
	
	printf("Para completar la expresion: P3 + Q4 - 2 * P2 \n");
	printf("Introducir el valor de P: ");
	scanf("%d",&P);
	printf("Introducir el valor de Q: ");
	scanf("%d",&Q);
	
	if(P*3+Q*4-2*P*2<680){
		
		printf("El valor de P es %d \n1",P);
		
	}else{
		
		printf("El valor de Q es %d \n0",Q);
		
	}
	
}