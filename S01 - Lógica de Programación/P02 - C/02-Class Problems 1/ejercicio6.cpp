/*
Ejercicio 6
Espinoza Sánchez José Luis-280676-1°C
06/oct/2022
Una persona asiste a un supermercado y desea conocer la suma final 
que debe pagar después de capturar los productos que desea comprar
*/

#include <stdio.h>

int main(){
	
	int precio=0,precioTotal=0,cantidad=0;
	char i='s';
	
	while(i=='s'){
		
		printf("Introducir un precio del producto: ");
		scanf("%d",&precio);
		precioTotal+=precio;
		
		printf("Introducir otro producto (s/n) ");
		getchar();
		scanf("%c",&i);
		
		cantidad++;
		
	}
		
	printf("El total a pagar es $ %d, con un un total de %d productos",precioTotal,cantidad);
	
}