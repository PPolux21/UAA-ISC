/*
Ejercicio 22
Espinoza Sánchez José Luis-280676-1°C
16/oct/2022
Mostrar los numeros pares entre 1 al 100
*/

#include <stdio.h>

int main(){
	
	for(int i=1;i<=100;i++){
		
		if(i%2==0){
			
			printf("%d ",i);
			
		}
	}
}