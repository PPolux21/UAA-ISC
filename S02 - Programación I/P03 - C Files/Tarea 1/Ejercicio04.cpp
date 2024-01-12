/*
José Luis Espinoza Sánchez - ISC - 2° C
Ejercicio 4
 Elabore un programa que tome todos los múltiplos de 4 hasta un N dado,
 y los almacene en un archivo de caracteres
*/

#include <iostream>
#define MULT 4
using namespace std;

void guardaDatos(int);

int main()
{
	int cant;
	
	cout<<"Dame la cantidad de veces a repetir la multiplicacion: ";
	cin>>cant;
	
	guardaDatos(cant);
}

void guardaDatos(int cant)
{
	FILE *archTxt;
	
	archTxt = fopen("Multiplos4.txt","w");
	
	for(int i=1; i<=cant; i++)
	{
		fprintf(archTxt,"%d\n",i*MULT);
	}
	
	fclose(archTxt);
}