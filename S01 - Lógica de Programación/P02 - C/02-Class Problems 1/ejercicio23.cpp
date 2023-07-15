/*
Ejercicio 23
Espinoza Sánchez José Luis-280676-1°C
16/oct/2022
Costo de llamada por clave de zona
*/

#include <stdio.h>

int main(){
	
	int clave=0;
	float numMin=0,cost=0;
	
	printf("Introduce el numero minutos de la llamada: ");
	scanf("%f",&numMin);
	printf("Introduce la clave de zona: ");
	scanf("%d",&clave);
	
	switch(clave){
		case 12:
			cost=numMin*2;
			break;
		case 15:
			cost=numMin*2.2;
			break;
		case 18:
			cost=numMin*4.5;
			break;
		case 19:
			cost=numMin*3.5;
			break;
		case 23:
		case 25:
			cost=numMin*6;
			break;
		case 29:
			cost=numMin*5;
	}
	
	printf("Costo total de la llamada: %.2f",cost);
	
}