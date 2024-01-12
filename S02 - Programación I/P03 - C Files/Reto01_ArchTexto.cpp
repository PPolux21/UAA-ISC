//Reto 1 - Archivos de texto

#include <iostream>
using namespace std;

int cantidad(FILE *);
void copiaNum(FILE *,int *);
void ordenaVec(int *,int);
void mostrarVec(int *,int);
void creaArchivo(int *,int);

int main()
{
	FILE *archNum;
	int *vec,cant=cantidad(archNum);
	
	cout<<"Cantidad de numeros: "<<cant<<endl;
	vec = new int [cant];
	
	copiaNum(archNum,vec);	//copia los numeros del archivo al vector
	ordenaVec(vec,cant);	//Ordena el vector
	mostrarVec(vec,cant);	//muestra el vector en pantalla
	creaArchivo(vec,cant);	//crea un nuevo archivo, guardando los numeros ordenados (menor a mayor)
	
	return 0;
}

int cantidad(FILE *archNum)
{
	int num,cant=0;
	
	archNum = fopen("Reto01_numeros.txt","r");	//abre el archivo en modo lectura (r)
	
	//recorre el archivo hasta el final de este mientras cuenta cuantos renglones hay
	while(!feof(archNum))
	{
		fscanf(archNum,"%d\n",&num);
		cant++;
	}
	
	fclose(archNum);	//cierra el archivo
	
	return cant;
}

void copiaNum(FILE *archNum,int *vec)
{
	int num,cant=0;
	
	archNum = fopen("Reto01_numeros.txt","r");	//abre el archivo en modo lectura (r)
	
	//recorre el archivo hasta el final de este mientras guarda los numeros en el vector
	while(!feof(archNum))
	{
		fscanf(archNum,"%d\n",&num);
		vec[cant++]=num;
	}
	
	fclose(archNum);	//cierra el archivo
}

void ordenaVec(int *vec,int cant)	//ordenamiento por Bubble Sort
{
	int aux;
	
	for(int i=0; i<cant; i++)
	{
		for(int j=0; j<cant-1; j++)
		{
			if(vec[j]>vec[j+1])
			{
				aux=vec[j];
				vec[j]=vec[j+1];
				vec[j+1]=aux;
			}
		}
	}
}

void mostrarVec(int *vec,int cant)
{
	//recorre el vector para mostrarlo en pantalla
	for(int i=0; i<cant; i++)
	{
		cout<<vec[i]<<"\t";
	}
}

void creaArchivo(int *vec,int cant)
{
	FILE *archOrden;
	
	archOrden = fopen("Reto01_orden.txt","w");	//crea un nuevo archivo (w)
	
	//recorre en la cantidad de numeros (cant) para asignarlos al archivo
	for(int i=0; i<cant; i++)
	{
		fprintf(archOrden,"%d\n",vec[i]);
	}
	
	fclose(archOrden);	//cierra el archivo
	
	//comentario de control para saber que se ha creado y guardado correctamente el archivo
	cout<<"\nArchivo con numeros ordenados creado correctamente :D"<<endl;
}