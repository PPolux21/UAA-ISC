/*
Ejercicio 14
Espinoza Sánchez José Luis-280676-1°C
08/oct/2022
Calcular lo que hay que pagarle a un trabajador teniendo en cuenta su sueldo y las horas extras trabajadas.
Para el pago de horas extras se toma en cuenta la categoría del trabajador.
	CATEGORIA 	HORA EXTRA
	1 			$30
	2 			$38
	3 			$50
	4 			$70
Cada trabajador puede tener como máximo 30 horas extras, si tienen más sólo se les pagarán 30. A los
trabajadores con categoría mayor a 4 no debemos pagarle horas extras
*/

#include <stdio.h>

int main(){
	
	int categoria=0,sueldo=0,horasExtra=0,sueldoFinal=0;
	
	printf("Introduce el sueldo con el que se cuenta: ");
	scanf("%d",&sueldo);
	printf("Introduce la categoria en la que se trabaja: ");
	scanf("%d",&categoria);
	printf("Introduce las horas extra trabajadas: ");
	scanf("%d",&horasExtra);
	
	switch(categoria){
		case 1: 
			if(horasExtra>=30){
				sueldoFinal=900+sueldo;
			}else{
				sueldoFinal=horasExtra*30+sueldo;
			}
			break;
		case 2: 
			if(horasExtra>=30){
				sueldoFinal=1140+sueldo;
			}else{
				sueldoFinal=horasExtra*38+sueldo;
			}
			break;
		case 3: 
			if(horasExtra>=30){
				sueldoFinal=1500+sueldo;
			}else{
				sueldoFinal=horasExtra*50+sueldo;
			}
			break;
		case 4: 
			if(horasExtra>=30){
				sueldoFinal=2100+sueldo;
			}else{
				sueldoFinal=horasExtra*70+sueldo;
			}
			break;
		default:
			sueldoFinal=sueldo;
			break;
	}
	
	printf("El pago total del sueldo es de $ %d",sueldoFinal);
	
}