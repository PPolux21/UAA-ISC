/*
José Luis Espinoza Sánchez - ISC - 2° C
Ejercicio 9
 Escribir un programa que reciba como entrada el nombre de un archivo y cree un archivo copia.dat con
 el contenido del mismo
*/

#include <iostream>
using namespace std;

void copia(char*);

int main()
{
	char nombre[24];
	
	cout<<"Dame el nombre del archivo con la extension .txt: ";
	cin>>nombre;
	
	copia(nombre);
	
	return 0;
}

void copia(char *nombre)
{
	FILE *archTxt, *archB;
	char content[50];
	
	archTxt=fopen(nombre,"r");
	archB=fopen("copia.dat","w");
	
	if(archB==NULL || archTxt==NULL)
	{
		cout<<"Error de I/O\n";
		exit(1);
	}
	
	while(!feof(archTxt))
	{
		fscanf(archTxt,"%s\n",content);
		fwrite(nombre,sizeof(char[50]),1,archB);
	}
	
	fclose(archTxt);
	fclose(archTxt);
}