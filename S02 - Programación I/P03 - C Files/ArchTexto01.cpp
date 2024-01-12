//Archivos de Texto
//Almacenamiento de palabras

#include <iostream>
#include <string.h>
using namespace std;

void mostrar(FILE *archTxt);

int main()
{
	//declaración de un archivo
	FILE *archTxt;	//variable lógica
	char palabra[25];
	
	//abrir archivo
	archTxt = fopen("ArchTexto01.txt","w");	//w = crea y escribe; a = añade; r = lectura
	cout<<"Amacenamiento de palabras\n";
	do
	{
		cout<<"Dame una palabra: ";
		fflush(stdin);
		gets(palabra);
		
		if( strcmp(palabra,"fin") != 0)
		{
			//grabar en el archivo fprintf(nombre_archivo,"%tipo_variable",nombre_variable);
			fprintf(archTxt,"%s\n",palabra);
		}		
	}while( strcmp(palabra,"fin") != 0 );
	//cerrar archivo
	fclose(archTxt);
	
	//mostrar contenido del archivo
	mostrar(archTxt);
}

void mostrar(FILE *archTxt)
{
	char aux[25];
	
	//abrir archivo de lectura
	archTxt = fopen("ArchTexto01.txt","r");
	
	while(!feof(archTxt))
	{
		//leer cotenido del archivo
		fscanf(archTxt,"%s",aux);
		cout<<aux<<"\t";
	}
	
	/*
	otra forma de leer un archivo
	
	while(!fscanf(archTxt,"%s",aux))
	{
		//leer cotenido del archivo
		fscanf(archTxt,"%s",aux);
		cout<<aux<<"\t";
	}
	*/
	
	cout<<endl;
	
	//cerrar archivo
	fclose(archTxt);
}