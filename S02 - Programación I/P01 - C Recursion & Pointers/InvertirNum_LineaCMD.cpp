/*Invertir un numero de forma recursiva
El numero se debe recibir por la línea de comandos.
*/
#include <iostream>
#include <string.h>
#include <ctype.h>

bool invertir(char[],int);

using namespace std;

int main(int cant,char *vec[])
{
	char numero[25];
	if(cant==2)
	{
		strcpy(numero,vec[1]);
		cout<<"El numero invertido es: ";
		if(invertir(numero,strlen(numero)-1))
		{
			cout<<"\nSe detectaron caracteres diferentes a numeros, solo se invirtieron los numeros detectados";
		}
		cout<<endl;
		return 0;
	}
	else
	{
		cout<<"Cantidad de argumentos no validos D:"<<endl;
		return 1;
	}
}

bool invertir(char num[],int tam)
{
	bool digit=false;
	if(tam==0)
	{
		if(isdigit(num[tam]))
		{
			cout<<num[tam];
		}
		else 
		{
			return true;
		}
	}
	else
	{
		if(isdigit(num[tam]))
		{
			cout<<num[tam];
		}
		else 
		{
			digit=true;
		}
		digit=invertir(num,tam-1);
	}
	return digit;
}