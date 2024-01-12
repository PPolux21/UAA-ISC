//Notación de vectores y punteros para mostrar arreglos

#include <iostream>
#define TAM 10

using namespace std;

void mostrar(int[]);
void mostrarDos(int[]);

int main()
{
	int vec[]={1,2,3,4,5,6,7,8,9,10};
	
	//El nombre de la variable representa la dircción de memoria de la primera posición del arreglo
	cout<<"Contenido de vec: "<<vec<<endl;
	
	//Mostrar el contenido de una posicion del arreglo con la notación de vectores
	cout<<"Contenido de vec[0]: "<<vec[0]<<endl;
	
	//Mostrar el contenido de una posicion del arreglo con la notación de punteros
	cout<<"Contenido de *vec: "<<*vec<<endl;
	
	mostrar(vec);
	
	mostrarDos(vec);
}

void mostrar(int vec[])	//Usando el arreglo para mostrar el contenido
{
	cout<<"contenido del arreglo con notacion vec[]:"<<endl;	//Notación de vector
	for(int i=0;i<TAM;i++)
	{
		cout<< vec[i] <<" ";
	}
	cout<<endl;
	
	cout<<"contenido del arreglo con notacion *(vec):"<<endl;	//Notación de puntero
	for(int i=0;i<TAM;i++)
	{
		cout<< *(vec+i) <<" ";
	}
	cout<<endl;
}

void mostrarDos(int vec[])	//Usando un puntero para mostrar el contenido del arreglo
{
	/*
	Hay varias formas de apuntar a un arreglo:
		1. int *ptr;	ptr=vec;
		2. int *ptr=&vec[0];
		3. int *ptr;	ptr=&vec[0];
	*/
	int *ptr; 	//puntero para apuntar al arreglo
	
	ptr=&vec[0]; 	//hacer que ptr apunte a la primer posición del vector
	
	cout<<"contenido del arreglo con notacion ptr[]:"<<endl;	//Notación de vector
	for(int i=0;i<TAM;i++)
	{
		cout<< ptr[i] <<" ";
	}
	cout<<endl;
	
	cout<<"contenido del arreglo con notacion *(ptr):"<<endl;	//Notación de puntero
	for(int i=0;i<TAM;i++)
	{
		cout<< *(ptr+i) <<" ";
	}
	cout<<endl;
}

