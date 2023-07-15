/*
Ejercicio 4
Espinoza Sánchez José Luis-280676-1°C
06/oct/2022
Obtener el mayor valor de una serie de números
*/

#include <stdio.h>

int main(){
	
	int num=0,comp=0;
	char i='s';
	
	printf("Introduce un numero: ");
	scanf("%d",&num);
	
	while(i=='s'){
				
		printf("Introduce un numero: ");
		scanf("%d",&comp);
		
		if(comp>num){
			num=comp;
		}

		printf("Introducir otro numero (s/n) ");
		getchar();
		scanf("%c",&i);

	}

	printf("El numero mayor fue %d",num);

}