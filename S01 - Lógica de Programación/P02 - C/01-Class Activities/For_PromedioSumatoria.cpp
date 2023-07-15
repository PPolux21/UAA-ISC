/*
Promedio 
29/sep/2022
Hacer una sumatoria y luego obtner promedio con valores aleatorios
*/

#include <stdio.h>

int main(){
	
	float precio=0, sumatoria=0, promedio=0;
	int total=0;
	
	printf("Cuantos precios se van a capturar: ");
	scanf("%d",&total);
	
	for(int i=1; i<=total; i++){
		printf("Dane un precio %d: ",i);
		scanf("%f",&precio);
		sumatoria += precio; //sumatoria = sumatoria + precio;
	}
	
	promedio=sumatoria/total;
	printf("El promedio es $%.2f",promedio);	
}