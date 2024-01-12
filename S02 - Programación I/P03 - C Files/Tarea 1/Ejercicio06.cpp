/*
José Luis Espinoza Sánchez - ISC - 2° C
Ejercicio 6
 Se desea hacer una copia de un archivo de caracteres con la condición de que sólo se 
 almacenen (en un nuevo archivo) las líneas que se encuentran en posición par
*/

#include <iostream>
using namespace std;

void soloPar(char *,char *);
int tamano(char*);

int main()
{
	char nomArch[24], nuevoArch[24];
	
	cout<<"Dame el nombre del archivo con la extrension .txt: ";
	cin>>nomArch;
	cout<<"Dame el nombre que tendra el archivo nuevo: ";
	cin>>nuevoArch;
	
	soloPar(nomArch,nuevoArch);
	
	return 0;
}

void soloPar(char *nomArch,char *nuevoArch)
{
	FILE *archText,*archNuevo;
	char caracteres[15];
	
	archText=fopen(nomArch,"r");
	archNuevo=fopen(nuevoArch,"w");
	
	for(int i=0; i<tamano(nomArch); i++)
	{
		if(i%2!=0)
		{
			fscanf(archText,"%s\n",caracteres);
			fprintf(archNuevo,"%s\n",caracteres);
		}
		else
		{
			fscanf(archText,"%s\n",caracteres);
		}
	}
	
	fclose(archText);
	fclose(archNuevo);
}

int tamano(char *nombre)
{
	FILE *archTexto;
	char caracteres[15];
	int cant=0;
	
	archTexto=fopen(nombre,"r");
	
	while(!feof(archTexto))
	{
		fscanf(archTexto,"%s\n",caracteres);
		cant++;	
	}
	
	fclose(archTexto);
	
	return cant;
}