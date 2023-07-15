/*
Ejercicio 24
Espinoza Sánchez José Luis-280676-1°C
18/oct/2022
Costo de llamada por clave de zona
*/

#include <stdio.h>

int main(){
	
	int clave=0;
	float numero=0,cost=0;
	
	printf("Dame la clave: ");
	scanf("%d",&clave);
	printf("Dame el numero: ");
	scanf("%f",&numero);
	
	switch(clave){
		case 12:
			cost=numero*2;
			break;
		case 15:
			cost=numero*2.2;
			break;
		case 18:
			cost=numero*4.5;
			break;
		case 19:
			cost=numero*3.5;
			break;
		case 23:
			cost=numero*6;
			break;
		case 25:
			cost=numero*6;
			break;
		case 29:
			cost=numero*5;
			break;
	}
	
	printf("Costo total de la llamada: %.2f",cost);
	
}