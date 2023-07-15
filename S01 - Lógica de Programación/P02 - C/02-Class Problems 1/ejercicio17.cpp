/*
Ejercicio 17
Espinoza Sánchez José Luis-280676-1°C
16/oct/2022
Obtener los digitos de un numero
*/

#include <stdio.h>

int main(){
	
	int numero=0,digito=0;
	
	printf("Dame un numero: ");
	scanf("%d",&numero);
	
	while(numero>0){
		
		digito=numero%10;
		printf("%d \t",digito);
		numero/=10;
		
	}
}