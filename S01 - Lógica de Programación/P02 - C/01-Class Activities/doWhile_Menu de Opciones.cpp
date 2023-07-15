/*
Menú de opciones
11/oct/2022
Ejercicio de menú de opciones (pow, evaluación de caracteres, system)
*/

#include <stdio.h>	//funciones de Entrada-Salida
#include <math.h>	//pow
#include <ctype.h>	//manejo de caracteres
#include <string.h>	//manejo de cadenas
#include <stdlib.h>	//system

int main(){
	
	int opc,exp;
	float base,potencia;
	char caracter,cad1[20],cad2[20];
	
	do{
		system("cls");
		printf("MENU DE OPCIONES \n");
		printf("Elevar n a la x - - - 1 \n");
		printf("Evaluar un caracter - 2 \n");
		printf("Comparar cadenas- - - 3 \n");
		printf("Salir - - - - - - - - 4 \n");
		printf("Selecciona tu opcion: ");
		scanf("%d",&opc);
		
		switch(opc){
			case 1:
				
				printf("\nDame la base: ");
				scanf("%f",&base);
				printf("Exponente: ");
				scanf("%d",&exp);
				potencia = pow(base,exp);
				printf("La potencia es: %.3f \n", potencia);
				system("pause");
				break;
				
			case 2:
				
				printf("Dame un caracter: ");
				fflush(stdin); //para limpiar el buffer
				scanf("%c",&caracter);
				if(isalpha(caracter)){
					printf("Es una letra \n");
				}else{
					if(isdigit(caracter)){
						printf("Es un numero \n");
					}else{
						if(isgraph(caracter)){
							printf("Es un simbolo \n");
						}
					}
				}
				system("pause");
				break;
				
			case 3:
				
			case 4:
				break;
				
			default:
				
				printf("\nOpción no valida");
				break;
		}
	}while(opc!=4);
}