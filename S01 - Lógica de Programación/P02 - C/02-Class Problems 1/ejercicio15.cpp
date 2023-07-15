/*
Ejercicio 15
Espinoza Sánchez José Luis-280676-1°C
09/oct/2022
En un hospital existen 3 áreas: Urgencias, Pediatría y Traumatología. El presupuesto anual del hospital se
reparte de la siguiente manera:
Urgencias – 37%
Pediatría – 42%
Traumatología – 21%
Obtener la cantidad de dinero que recibirá cada área considerando cualquier monto presupuestal mayor a
cero y el área seleccionada
*/

#include <stdio.h>

int main(){
	
	float presupTotal=0,presupUrgencias=0,presupPediatria=0,presupTraumatologia=0;
	
	printf("Introduzca el presupuesto anual del hospital: ");
	scanf("%f",&presupTotal);
	
	if(presupTotal>=0){
		
		presupUrgencias=presupTotal*0.37;
		presupPediatria=presupTotal*0.42;
		presupTraumatologia=presupTotal*0.21;
		
		printf("El presupuesto correspondiente a cada area es\nUrgencias $ %.2f\nPediatria $ %.2f\nTraumatologia $ %.2f",presupUrgencias,presupPediatria,presupTraumatologia);
		
	}else{
		
		printf("Valor de presupuesto no valido");
		
	}
	
}