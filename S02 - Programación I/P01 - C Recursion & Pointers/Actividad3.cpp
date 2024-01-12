/*
Actividad 3 
Espinoza Sánchez José Luis-280676-2°C
22/02/2023
Elevar un numero a una potencia. El numero y la potencia llegan por la línea de comandos, de la siguiente forma:

C:\potencia numero potencia
*/

#include <iostream>
#include <math.h>

using namespace std;

int main(int argc,char *argv[])
{
	long numero,potencia;
	if(argc==3)
	{
		numero=strtol(argv[1],NULL,10);
		potencia=strtol(argv[2],NULL,10);
		cout<<"El resultado de la potencia de "<<numero<<" elevado a "<< potencia<<" es: "<<pow(numero,potencia);
		return 0;
	}
	else
	{
		cout<<"Numero de argumentos diferente de 3 D:";
		return 1;
	}
}
