//Modificar y eliminar registros de un archivo de texto
//uso de funciones para renombrear y borrar archivos

#include <iostream>
using namespace std;

void bajas(FILE *,int);

int main()
{
	FILE *archAl;
	int codigo;
	
	//bajas de productos
	cout<<"Codigo del producto a eliminar: ";
	cin>>codigo;
	bajas(archAl,codigo);
}

void bajas(FILE *archAl,int codigo)
{
	FILE *temporal;	//archivo para almacenar datos de forma temporal
	int numSerie,cant;
	char nombre[15];
	float precio;
	
	archAl = fopen("ArchTexto03_almacen.txt","r");
	temporal = fopen("temporal.txt","w");
	
	while(!feof(archAl))
	{
		cout<<"Entre a while";
		fscanf(archAl,"%d %s %d %f\n",&numSerie,nombre,&cant,&precio);
		if(numSerie!=codigo)
		{
			fprintf(temporal,"%d %s %d %f\n",numSerie,nombre,cant,precio);
		}
	}
	
	fclose(archAl);
	fclose(temporal);
	remove("ArchTexto03_almacen.txt");
	rename("temporal.txt","ArchTexto03_almacen.txt");
}