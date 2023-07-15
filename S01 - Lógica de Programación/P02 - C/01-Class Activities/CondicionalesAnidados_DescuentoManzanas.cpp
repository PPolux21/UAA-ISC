/*
Manzanas
27/sep/2022
Precio de manzanas por kilo comprado
*/

#include <stdio.h>

int main(){
	
	float kilos=0, costoKg=0, pago;
	
	printf("Introduce el costo por kilo: ");
	scanf("%f",&costoKg);
	printf("Kilos vendidos: ");
	scanf("%f",&kilos);
	pago=costoKg*kilos;
	
	if(kilos>=0){
		if (kilos>=0 && kilos<=2){
			printf("No tienes descuento D: \n");
			printf("Debes de pagar: %f",pago);
		}else{
			if (kilos>2 && kilos<=5){
				printf("Tienes 10 en el descuento :D \n");
				printf("Debes de pagar: %f",pago*0.90);
			}else{
				if (kilos>5 && kilos<=10){
					printf("Tienes 15 en el descuento :D \n");
					printf("Debes de pagar: %f",pago*0.85);
				}else{
					printf("Tienes 20 en el descuento :D \n");
					printf("Debes de pagar: %f",pago*0.80);
				}
			}
		}
	}else{
		printf("Valor de Kilos no valido");
	}
	
	return 0;
}