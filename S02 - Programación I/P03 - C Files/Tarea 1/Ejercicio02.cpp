/*
José Luis Espinoza Sánchez - ISC - 2° C
Ejercicio 2
 Se tiene un archivo cuyos registros poseen la siguiente estructura: 
 Nombre, Edad, Sexo. Se desea elaborar un programa que liste todas las 
 mujeres que sean mayores de una edad X. Dichos datos se encuentran
 dentro del archivo. El nombre del archivo es dado por el usuario
*/

#include <iostream>
using namespace std;

void mostrarMujeres(char [], int);

int main()
{
	char nombreArch[19];
	int edadMin;
	
	cout<<"Dame el nombre del archivo con la extension .txt: ";
	cin>>nombreArch;
	cout<<"Dame la edad minima a mostrar: ";
	cin>>edadMin;
	
	mostrarMujeres(nombreArch,edadMin);
	
	return 0;
}

void mostrarMujeres(char nomArch[], int edadMin)
{
	FILE *archTxt;
	char nombre[25];
	int edad;
	char sexo; //H o M , para Hombre y Mujer
	
	archTxt = fopen(nomArch,"r");
	
	while(!feof(archTxt))
	{
		fscanf(archTxt,"%s %d %c\n",nombre,&edad,&sexo);
		if(sexo == 'M' && edad >= edadMin)
		{
			cout<<nombre<<"\t"<<edad<<"\t"<<sexo<<endl;
		}
	}
	
	fclose(archTxt);
}