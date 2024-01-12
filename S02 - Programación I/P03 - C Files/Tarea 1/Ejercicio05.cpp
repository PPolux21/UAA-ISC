/*
José Luis Espinoza Sánchez - ISC - 2° C
Ejercicio 5
 Se tiene un archivo de enteros. Se desea elaborar un programa que nos 
 indique la posición del máximo y la del mínimo de dicha lista de enteros
*/

#include <iostream>
using namespace std;

int maximoPos(char*);
int minimoPos(char*);
int cantidad(char*);

int main()
{
	char *nombre=new char [29];
	
	cout<<"Dame el nombre del archivo con la extension .txt: ";
	cin>>nombre;
	
	cout<<"Posicion del maximo: \n\t"<<maximoPos(nombre)<<" renglon"<<endl;
	cout<<"Posicion del minimo: \n\t"<<minimoPos(nombre)<<" renglon"<<endl;
}

int maximoPos(char *nomArch)
{
	FILE *archTxt;
	int num,max,posMax=0,tot=cantidad(nomArch);
	
	archTxt = fopen(nomArch,"r");
	
	for(int i=0; i<tot; i++)
	{
		fscanf(archTxt,"%d\n",&num);
		
		if(i==0)
		{
			max=num;
		}
		else
		{
			if(num>max)
			{
				max=num;
				posMax=i;
			}
		}
	}
	
	fclose(archTxt);
	
	return posMax+1;
}

int minimoPos(char *nomArch)
{
	FILE *archTxt;
	int num,min,posMin=0,tot=cantidad(nomArch);
	
	archTxt = fopen(nomArch,"r");
	
	for(int i=0; i<tot; i++)
	{
		fscanf(archTxt,"%d\n",&num);
		if(i==0)
		{
			min=num;
		}
		else
		{
			if(num<min)
			{
				min=num;
				posMin=i;
			}
		}
	}
	
	fclose(archTxt);
	
	return posMin+1;
}

int cantidad(char *nomArch)
{
	FILE *archTxt;
	int num, tot=0;
	
	archTxt = fopen(nomArch,"r");
	
	while(!feof(archTxt))
	{
		fscanf(archTxt,"%d\n",&num);
		tot++;
	}
	
	fclose(archTxt);
	
	return tot;
}