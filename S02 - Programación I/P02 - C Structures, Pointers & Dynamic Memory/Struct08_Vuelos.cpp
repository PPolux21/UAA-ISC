// Arreglos dinámicos de estructuras

#include <iostream>
#include <string.h>
#define TAM 3

using namespace std;

struct Vuelos{
	int codigo;
	char *destino;
	float costo;
};

void captura(Vuelos *);
void mostrar(Vuelos *);
float calcCosto(Vuelos *);
//mostrar (vuelos menores a una cant) 
void mostrarCosto(Vuelos *,float);
void mostrarReg(Vuelos);
//vender voletos (buscar por nombre)
Vuelos buscaDestino(Vuelos *,char[]);
void comprar(Vuelos);

int main()
{
	Vuelos vectod[TAM];	//vector estático
	Vuelos *vec=new Vuelos[TAM];	//vector dinámico
	float costo;
	char destino[15];
	Vuelos reg;
	
	captura(vec);
	mostrar(vec);
	cout<<"Costo total de los vuelos: $"<<calcCosto(vec)<<endl;
	
	cout<<"Costo a consultar: ";
	cin>>costo;
	mostrarCosto(vec,costo);
	
	cout<<"Venta de boletos: \n Destino: ";
	fflush(stdin);
	gets(destino);
	reg = buscaDestino(vec,destino);
	if(reg.codigo == -1)
	{
		cout<<"El destino no extite";
	}
	else
	{
		comprar(reg);
	}
	
	return 0;
}

void captura(Vuelos *vec)
{
	cout<<"Captura de vuelos\n";
	for(int i=0;i<TAM;i++)
	{
		cout<<"Codigo: ";
		cin>>vec[i].codigo;
		//antes de usar al destino, se debe crear
		vec[i].destino=new char[15];
		cout<<"Destino: ";
		fflush(stdin);
		gets(vec[i].destino);
		cout<<"Costo: ";
		cin>>vec[i].costo;
	}
	cout<<endl;
}

void mostrar(Vuelos *vec)
{
	int i=0;
	cout<<"Vuelos\n";
	while(vec[i].codigo != 0  && i < TAM)
	{
		cout<<vec[i].codigo<<", "<<vec[i].destino<<", "<<vec[i++].costo<<endl;
	}
	cout<<endl;
}

float calcCosto(Vuelos *vec)
{
	float suma=0;
	for(int i=0; i<TAM; i++)
	{
		suma += vec[i].costo;
	}
	return suma;
}

void mostrarCosto(Vuelos *vec,float costo)
{
	for(int i=0; i<TAM; i++)
	{
		if(vec[i].costo < costo)
		{
			mostrarReg(vec[i]);
		}
	}
	cout<<endl;
}

void mostrarReg(Vuelos reg)
{
	cout<<reg.codigo<<", "<<reg.destino<<", "<<reg.costo<<endl;
}

Vuelos buscaDestino(Vuelos *vec,char destino[])
{
	Vuelos aux;
	aux.codigo=-1;
	for(int i=0; i<TAM; i++)
	{
		if(strcmp(vec[i].destino,destino)==0)
		{
			aux = vec[i];
			break;
		}
	}
	return aux;
}

void comprar(Vuelos reg)
{
	int cantidad=0;
	float totalPago=0;
	
	cout<<"Cantidad ed boletos: ";
	cin>>cantidad;
	totalPago = reg.costo * cantidad;
	
	cout<<"Total a pagar $"<<totalPago<<endl;
}