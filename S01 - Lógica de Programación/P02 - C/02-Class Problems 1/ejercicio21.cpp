/*
Ejercicio 21
Espinoza Sánchez José Luis-280676-1°C
16/oct/2022
Sucesion de fibonacci
*/

#include <stdio.h>

int main(){
	
	int ant=1,sig=1,cantidad=0,res=0;
	
	printf("Cantidad de valores par a la serie de fibonacci: ");
	scanf("%d",&cantidad);
	
	for(int i=1;i<=cantidad;i++){
		
		res=ant+sig;
		printf("%d ",res);
		ant=sig;
		sig=res;
		
	}
}