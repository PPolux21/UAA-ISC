/*
Ejercicio 11
Espinoza Sánchez José Luis-280676-1°C
Fecha
Escriba un programa que indique si un carácter capturado es una vocal
*/

#include <stdio.h>

int main(){
	
	char letra;
	
	printf("introduzca el caracter a evaluar: ");
	getchar();
	scanf("%c",&letra);
		
	switch(letra){
		case 'a':
		case 'A':
		case 'e':
		case 'E':
		case 'i':
		case 'I':
		case 'o':
		case 'O':
		case 'u':
		case 'U': 	printf("El caracter es vocal"); 
					break;
		default: 	printf("El caracter no es vocal");
					break;
	}

}