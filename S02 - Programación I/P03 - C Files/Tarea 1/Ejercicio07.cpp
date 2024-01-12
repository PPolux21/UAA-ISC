/*
José Luis Espinoza Sánchez - ISC - 2° C
Ejercicio 7
 Tomar dos archivos de texto y hacer una mezcla de los dos en un nuevo archivo, con la condición de que
se intercalen las líneas
*/

#include <iostream>
using namespace std;

void combinacion();
int tamano(char*);

int main()
{

	combinacion();

}

void combinacion()
{
	FILE *archText1,*archText2,*archCombo;
	
	int tamArch1=tamano("texto1.txt"), tamArch2=tamano("texto2.txt");
	char caracteres[15];
	
	archText1=fopen("texto1.txt","r");
	archText2=fopen("texto2.txt","r");
	archCombo=fopen("combinado.txt","w");
	
	for(int i=0; i<tamArch1+tamArch2; i++)
	{
		if(i%2!=0)
		{	
			fscanf(archText1,"%s\n",caracteres);
			fprintf(archCombo,"%s\n",caracteres);
		}
		else
		{
			fscanf(archText2,"%s\n",caracteres);
			fprintf(archCombo,"%s\n",caracteres);
		}
	}
	
	fclose(archText1);
	fclose(archText2);
	fclose(archCombo);
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