/*
Ejercicio 26
Espinoza Sánchez José Luis-280676-1°C
18/oct/2022
Pago total por kilos vendidos en relación de su cantidad de venta
*/

#include <stdio.h>

int main(){
	
	float costoKg=0,kilos=0,pagoFinal=0;
	
	printf("Ingrese el valor del kg: ");
	scanf("%f",&costoKg);
	printf("Ingrese el total de kilos vendidos: ");
	scanf("%f",&kilos);
	
	if(kilos>=0){
		
		if(kilos>0 && kilos<=2){
			pagoFinal=kilos*costoKg;
			printf("%.2f",pagoFinal);
		}else{
			
			if(kilos>2 && kilos<=5){
				pagoFinal=kilos*costoKg*90;
				printf("%.2f",pagoFinal);
			}else{
				if(kilos>5 && kilos<=10){
					pagoFinal=kilos*costoKg*85;
					printf("%.2f",pagoFinal);
				}else{
					pagoFinal=kilos*costoKg*80;
					printf("%.2f",pagoFinal);
				
				}	
				
			}
			
		}
		
	}else{
		
		printf("Valor de Kilos no valido!");
		
	}
	
}