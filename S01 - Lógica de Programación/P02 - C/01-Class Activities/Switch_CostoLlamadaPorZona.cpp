// Costo llamada por zona global

#include <stdio.h>

int main(){
	
	int zona=0, numMin=0;
	float costo=0;
	printf("Zona: ");
	scanf("%d",&zona);
	printf("Numero de llamada: ");
	scanf("%d",&numMin);
	switch(zona){
		case 12: costo = numMin * 2; 
				break;
		case 15: costo = numMin * 4.5; 
				break;
		case 18: costo = numMin * 5.5; 
				break;
		case 19: costo = numMin * 13.9; 
				break;
		case 23:
		case 25:
		case 29: costo = numMin * 0.9; 
				break;
		default: printf("Zona no valida \n");
	}
	printf("El total a pagar es %.2f MXN \n",costo);
}