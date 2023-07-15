/*
Ejercicio 8
Espinoza Sánchez José Luis-280676-1°C
06/oct/2022
Un comerciante compra un artículo a un determinado precio. 
Escribir un programa y DF que obtenga el precio al que debe venderlo si desea ganar el 5%
*/

#include <stdio.h>

int main(){
	
	int compra=0,venta=0;
	
	printf("Introduzca el precio del producto comprado: ");
	scanf("%d",&compra);
	
	venta=compra*1.05;
	
	printf("El precio de venta con ganancia del 5 porciento es de %d",venta);
	
}