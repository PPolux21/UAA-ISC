/*
José Luis Espinoza Sánchez - ISC - 2° C
Ejercicio 1
 Escribir un programa que dados los nombres de dos archivos de caracteres
 haga una mezcla de los dos en uno nuevo archivo, con la condición de que se
 intercalen las líneas. El nombre del nuevo archivo es dado como parámetro
*/

#include <iostream>
using namespace std;

void combinacion(char [],char [],char []);
int tamano(char[]);

int main()
{
	char nomArch1[24], nomArch2[24], combinado[24];
	
	cout<<"\tRellene lo  siguiente con .txt y sin espacios\n";
	cout<<"\nDame el nombre del primer archivo: ";
	cin>>nomArch1;
	cout<<"Dame el nombre del segundo archivo: ";
	cin>>nomArch2;
	cout<<"Dame el nombre que tendra el archivo combinado: ";
	cin>>combinado;
	
	combinacion(nomArch1,nomArch2,combinado);
	
	return 0;
}

void combinacion(char nomArch1[],char nomArch2[],char combinado[])
{
	FILE *archText1,*archText2,*archCombo;
	//se inicializan los tamaños con la longitud de renglones de los archivos
	int tamArch1=tamano(nomArch1), tamArch2=tamano(nomArch2);	
	char caracteres[15];
	
	archText1=fopen(nomArch1,"r");
	archText2=fopen(nomArch2,"r");
	archCombo=fopen(combinado,"w");
	
	for(int i=0; i<tamArch1+tamArch2; i++)
	{
		//Condicional sobre par o impar
		if(i%2!=0)
		{
			//se copia el renglón del primer archivo al archivo combinado
			fscanf(archText1,"%s\n",caracteres);
			fprintf(archCombo,"%s\n",caracteres);
		}
		else
		{
			//se copia el renglón del segundo archivo al archivo combinado
			fscanf(archText2,"%s\n",caracteres);
			fprintf(archCombo,"%s\n",caracteres);
		}
	}
	
	fclose(archText1);
	fclose(archText2);
	fclose(archCombo);
}

int tamano(char nombre[])
{
	FILE *archTexto;
	char caracteres[15];
	int cant=0;
	
	archTexto=fopen(nombre,"r");
	
	while(!feof(archTexto))
	{
		fscanf(archTexto,"%s\n",caracteres);
		cant++;	//contador de renglones
	}
	
	fclose(archTexto);
	
	return cant;
}