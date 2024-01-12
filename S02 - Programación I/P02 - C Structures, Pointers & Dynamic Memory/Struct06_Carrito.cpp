//areglos de estructuras
#include <iostream>
const int TAM=3;	//Vector
const int TOT=50;	//Descipción

using namespace std;

struct Producto{
	int codigo;
	char *descrip;	//char descrip[50];
	int cant;
	float costo;
};

void captura(Producto []);
void mostrar(Producto []);
float pagar(Producto []);

int main()
{
	Producto carrito[TAM];
	captura(carrito);
	mostrar(carrito);
	cout<<"Total a pagar: "<<pagar(carrito)<<endl;
}

void captura(Producto carrito[])
{
	cout<< "\tCaptura de Datos\n";
	for(int i=0;i<TAM;i++)
	{
		cout<< "Codigo: ";
		cin>> carrito[i].codigo;
		//antes de usar la cadena se debe de instanciar
		carrito[i].descrip=new char[TOT];
		cout<<"Descripcion: ";
		fflush(stdin);
		gets(carrito[i].descrip);
		cout<<"Cantidad: ";
		cin>>carrito[i].cant;
		cout<<"Precio: ";
		cin>>carrito[i].costo;
		
		cout<<endl;
	}
}

void mostrar(Producto carrito[])
{
	cout<< "\tDatos\n";
	for(int i=0;i<TAM;i++)
	{
		cout<< "Codigo: "<<carrito[i].codigo<<endl;
		cout<<"Descripcion: "<<carrito[i].descrip<<endl;
		cout<<"Cantidad: "<<carrito[i].cant<<endl;
		cout<<"Precio: "<<carrito[i].costo<<endl<<endl;
	}	
}

float pagar(Producto carrito[])
{
	float suma=0,prod;
	for(int i=0;i<TAM;i++)
	{
		prod=0;
		prod = carrito[i].costo * carrito[i].cant;
		suma += prod;
	}
	return suma;
}