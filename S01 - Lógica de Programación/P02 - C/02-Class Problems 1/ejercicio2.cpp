/*
Ejercicio 2
Espinoza Sánchez José Luis-280676-1°C
06/oct/2022
Obtener el pago total de productos mientras exista presupuesto. 
Indicar también, la cantidad de productos comprados
*/

#include <stdio.h>

int main(){
	
	int presup=0,pagoTotal=0,prod=0,i=0;
	char continuar='s';
		
	printf("Cantidad de presupuesto con la que se cuenta para la compra: ");
	scanf("%d",&presup);
		
	if(presup>=0){
		
		printf("Inroduzca los precios de menor a mayor, para mejor funcionamiento del programa \n");
		
		while(continuar=='s'){
			
			printf("Precio del producto: ");
			scanf("%d",&prod);
			pagoTotal+=prod;
			i++;
				
			if(presup>=pagoTotal){
												
				printf("Desea agregar otro producto (s/n): ");
				getchar();
				scanf("%c",&continuar);
				
			}else{
				
				if(presup<pagoTotal){
					
					pagoTotal-=prod;
					i--;
					
				}//if
				
				printf("No queda mas presupuesto \n");
				continuar='n';
				
			}//if
			
		}//while
		
		printf("Se pudeiron comprar %d productos con un precio total de $ %d",i,pagoTotal);
		
	}else{
		
		printf("Cantidad de presupuesto no valida");
		
	}//if 
	
}//main