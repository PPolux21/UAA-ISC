/*
José Luis Espinoza Sánchez - ISC - 2° C
Ejercicio 15
 Diseñar un programa que, dado un archivo de texto compuesto por frases, compruebe si la primera letra
 de cada frase es mayúscula, en caso contrario, sustituir la minúscula por la correspondiente mayúscula.
*/

#include <iostream>
#include <ctype.h>
using namespace std;

int main()
{
	FILE *archTxt,*archAux;
	char frase[50];
	
	archTxt = fopen("frase.txt","r");
	archAux = fopen("auxiliar.txt","w");
	
	
	while(!feof(archTxt))
	{
		fgets(frase,sizeof(frase),archTxt);
		if(isupper(frase[0])==0)
		{
			frase[0]=toupper(frase[0]);
		}
		cout<<frase<<endl;
		fprintf(archAux,"%s\n",frase);
	}
	
	fclose(archTxt);
	fclose(archAux);
	remove("frase.txt");
	rename("auxiliar.txt","frase.txt");
	
	cout<<"La primera letra de las frases se han cambiado correctamente!\n";
}