// Mem dinamica

#include <iostream>

using namespace std;

void reservaMem(int*,int);
void llenarVec(int*,int);
void mostrarVec(int*,int);

int main()
{
	int *vec,tam;
	
	cout<<"Tamaño para el arreglo dinamico: ";
	cin>>tam;
	
	reservaMem(vec,tam);
	/*
	llenarVec(vec,tam);
	mostrarVec(vec,tam);
	*/
}

void reservaMem(int *vec,int tam)
{
	//Reservación del espacio
	vec=(int *)malloc(tam*sizeof(int));		//vec=(int *)calloc(tam , sizeof(int));
	//comprobar si se pudo reservar la memoria
	if(vec==NULL)
	{
		cout<<"No hay espacio suficiente en la memoria\n";
		exit(0);
	}
	
	llenarVec(vec,tam);
	mostrarVec(vec,tam);
}

void llenarVec(int *vec,int tam)
{
	for(int i=0;i<tam;i++)
	{
		cout<<"Valor "<<i+1<<": ";
		cin>>vec[i];
	}
}

void mostrarVec(int *vec,int tam)
{
	for(int i=0;i<tam;i++)
	{
		cout<<*(vec+i)<<"\t";
	}
}