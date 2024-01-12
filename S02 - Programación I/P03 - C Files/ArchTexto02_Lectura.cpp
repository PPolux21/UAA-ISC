/* Lactura de archivos
Obtener el promedio grupal
Busquedas por id
Mostrar el contenido del archivo */

#include <iostream>
using namespace std;

float promGrupal(FILE *);
bool buscaID(FILE *,int);
void mostrar(FILE *);

int main()
{
	FILE *archTxt;
	int id;
	
	cout<< "El promedio grupal: "<<promGrupal(archTxt)<<endl;
	
	cout<< "\nId a localizar: ";
	cin>>id;
	if(!buscaID(archTxt,id))
	{
		cout<<"El id que busca no exsite\n";
	}
	else
	{
		cout<<"Id localizado"<<endl;
	}
	cout<<endl;
	
	mostrar(archTxt);
}

//funciones
float promGrupal(FILE *archTxt)
{
	//se necesitan las variables de las que se compone el archivo
	int id,cont=0;
	char nombre[15];
	float calif=0,suma=0;
	
	archTxt = fopen("ArchTexto02.txt","r");
	while(!feof(archTxt))
	{
		//se tiene que recorrer todos los datos del archivo
		fscanf(archTxt,"%d\t%s\t%f\n",&id,nombre,&calif);
		suma+=calif;
		cont++;
	}
	//siempre cerrar el archivo
	fclose(archTxt);
	
	return suma/cont;
}

bool buscaID(FILE *archTxt,int idBusca)
{
	//se necesitan las variables de las que se compone el archivo
	int id;
	char nombre[15];
	float calif=0;
	bool encontrado=false;
	
	archTxt = fopen("ArchTexto02.txt","r");
	while(!feof(archTxt))
	{
		//se tiene que recorrer todos los datos del archivo
		fscanf(archTxt,"%d\t%s\t%f\n",&id,nombre,&calif);
		if(id==idBusca)
		{
			encontrado=true;
			break;
		}
	}
	//siempre cerrar el archivo
	fclose(archTxt);
	
	return encontrado;
}

void mostrar(FILE *archTxt)
{
	//se necesitan las variables de las que se compone el archivo
	int id;
	char nombre[15];
	float calif=0;
	
	archTxt = fopen("ArchTexto02.txt","r");
	while(!feof(archTxt))
	{
		//se tiene que recorrer todos los datos del archivo
		fscanf(archTxt,"%d\t%s\t%f\n",&id,nombre,&calif);
		cout<<id<<"\t"<<nombre<<"\t"<<calif<<endl;
	}
	//siempre cerrar el archivo
	fclose(archTxt);
}