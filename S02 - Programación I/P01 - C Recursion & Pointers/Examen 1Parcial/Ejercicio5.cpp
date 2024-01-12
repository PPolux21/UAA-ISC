/*
Ejercicio 5
 Escribir una función que reciba de la línea de comandos un conjunto 
 de valores (la sucesión de números termina con un punto) y obtenga 
 la sumatoria de aquellos valores que sean dígitos
*/
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main(int argc,char *argv[])
{
	int suma=0;
	char num[10];
	
	for(int i=1;i<argc;i++)
	{
		strcpy(num,argv[i]);
		suma+=strtol(num,NULL,10);
	}
	
	cout<<"Suma de la entrada: "<<suma<<endl;
}