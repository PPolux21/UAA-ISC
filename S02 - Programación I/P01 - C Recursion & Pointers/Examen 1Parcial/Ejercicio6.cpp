/*
Ejercicio 6
 Escribir una función que reciba de la línea de comandos dos cadenas 
 como parámetros y obtenga una nueva cadena formada por los caracteres comunes a ambas 
*/
#include <iostream>
#include <string.h>

using namespace std;

int main(int argc,char *argv[])
{
	char cadA[25],cadB[25],cadC[25];
	int aux=0;
	
	strcpy(cadA,argv[1]);
	strcpy(cadB,argv[2]);
	
	for(int i=0;i<strlen(cadA);i++)
		for(int j=0;j<strlen(cadB);j++)
			if(cadA[i]==cadB[j])
			{
			cadC[aux++]=cadA[i];
			}
	
	cout<<cadC;			
	return 0;
}