/*
Ejercicio 7
 Escribir una función que reciba una cadena por la línea de comandos 
 e invierta su contenido mostrándolo en pantalla. No es válido usar la función strrev
*/
#include <iostream>
#include <string.h>

using namespace std;

int main(int argc,char *argv[])
{
	char cadA[25];
	
	strcpy(cadA,argv[1]);
	
	for(int i=strlen(cadA)-1;i>=0;i--)
		cout<<cadA[i];
	
	return 0;
}