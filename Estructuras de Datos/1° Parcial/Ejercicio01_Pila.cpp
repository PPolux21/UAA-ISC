// Ejercicios Pilas y colas

#include <iostream>
#include <ctype.h>

using namespace std;

struct 

// Funciones
void menuPilas();
void menuColas();

bool pila_vacia(int);
bool pila_llena(int,int);
void push(int*,int&,int,int);
int pop(int*,int&,int);

char *posfijoInfijo(char*);
char *infijoPrefijo(char*);

int main()
{
	int opc;
	
	do
	{
		system("cls");
		cout<<"\tMenu Ejercicios"<<endl;
		cout<<"Pilas - - - - - 1"<<endl;
		cout<<"Colas - - - - - 2"<<endl;
		cout<<"Salir - - - - - 3"<<endl;
		cout<<"\nOpcion: ";
		cin>>opc;
		switch(opc)
		{
			case 1:
				menuPilas();
				break;
			case 2:
				menuColas();
				break;
			case 3:
				break;
			default:
				cout<<"\nOpcion no valida"<<endl;
				break;
		}
	}while(opc!=3);
	
	return 0;
}

//Implementacion de funciones

void menuPilas()
{
	int opc;
	
	do
	{
		system("cls");
		cout<<"\tEjercicios Pilas"<<endl;
		cout<<"Algoritmos - - - - - - - - - - -  1"<<endl;
		cout<<"De notacion Infija a Posfija  - - 2"<<endl;
		cout<<"De notacion Infija a Prefija - -  3"<<endl;//yo
		cout<<"Evaluar expresion Prefija - - - - 4"<<endl;//yo
		cout<<"Evaluar expresion Posfija  - - -  5"<<endl;
		cout<<"Eliminar repetidos  - - - - - - - 6"<<endl;//yo
		cout<<"Invertir Pila  - - - - - - - - -  7"<<endl;
		cout<<"Salir - - - - - - - - - - - - - - 8"<<endl;
		cout<<"Opcion: ";
		cin>>opc;
		switch(opc)
		{
			case 1://algoritmos (pila llena, pila vacia, pop, push)
				break;
			case 2://Pasar de Notacion Infija a Posfija
				break;
			case 3://Pasar de Notacion Infija a Prefija
				break;
			case 4://Evaluar una expresion Prefija
				break;
			case 5://Evaluar una expresion Posfija
				break;
			case 6://Elimina los elementos repetidos en una pila
				break;
			case 7://Invertir el orden de la pila
				break;
			case 8://salida
				break;
			default:
				cout<<"\nOpcion no valida"<<endl;
				break;
		}
	}while(opc!=8);
}

void menuColas()
{
	int opc;
	
	do
	{
		system("cls");
		cout<<"\tEjercicios Pilas"<<endl;
		cout<<"Algoritmos - - - - - - - - - - -  1"<<endl;
		cout<<"Algoritmos Cola circular  - - 2"<<endl;
		cout<<"Cola de Banco - -  3"<<endl;
		cout<<"Invertir Cola - - - - 4"<<endl;//yo
		cout<<"Colas de prioridad  - - -  5"<<endl;//yo
		cout<<"Salir - - - - - - - - - - - - - - 6"<<endl;
		cout<<"Opcion: ";
		cin>>opc;
		switch(opc)
		{
			case 1://algoritmos en una cola normal(cola llena, cola vacia, pop, push)
				break;
			case 2://algoritmos en una cola circular(cola llena, cola vacia, pop, push)
				break;
			case 3://aplicación de los algoritmos en un sistema bancario
				break;
			case 4://Invertir el orden de la cola
				break;
			case 5://Colas con prioridad
				break;
			case 6://salida
				break;
			default:
				cout<<"\nOpcion no valida"<<endl;
				break;
		}
	}while(opc!=6);
}

bool pila_vacia(int tope)
{
	if(tope==-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool pila_llena(int max,int tope)
{
	if(tope==(max-1))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void push(int *pila,int &tope,int max,int Dato)
{
	if(pila_llena(max,tope))
	{
		cout<<"Desbordamiento Pila Llena"<<endl;
	}
	else
	{
		tope++;
		pila[tope]=Dato;
	}
}

int pop(int *pila,int &tope,char Dato)
{
	if(pila_vacia(tope))
	{
		cout<<"Subdesbordamiento Pila Vacia"<<endl;
	}
	else
	{
		Dato=pila[tope];
		tope--;
	}
	
	return Dato;
}

char *posfijoInfijo(char *posfijo)
{
	char *infijo,*pila;
	int tope=0,max=strlen(posfijo),i=0;
	
	infijo = new char [max];
	pila = new char [max];
	
	for(int i=0;tope>1 && i<max;i++)
	{
		if(isalpha(posfijo[i]))
		{
			pila[i]=posfijo[i];
		}
		if(isgraph(posfijo[i]))
		{
			infijo[cont++] = '(';
			infijo[cont++] = pop(pila,tope);
			infijo[cont++] = posfijo[i];
			infijo[cont++] = pop(pila,tope);
			if(isalpha(posfijo[i+1]))
				infijo[cont++] = ')';
		}
	}
	
	return infijo;
}

char *infijoPrefijo(char*);