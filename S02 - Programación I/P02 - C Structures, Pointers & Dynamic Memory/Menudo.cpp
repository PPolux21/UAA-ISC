//Menudo y notacion de punteros
#include <iostream>
#include <stdlib.h>
#include <time.h>
#define REN 4
const int COL=6;

using namespace std;

void menu(int [][COL]);
void llenarMat(int [][COL]);
void mostrarMat(int [][COL]);
int diaMas(int [][COL],int *);
void clienteTienda(int[][COL],int,int *);

int main()
{
	int menudo[REN][COL];
	
	srand(time(NULL));
	llenarMat(menudo);
	menu(menudo);
	return 0;
}

void menu(int menudo[][COL])
{
	char opc;
	int columna=0,tienda=-1,posTienda=0;
	do
	{
		cout<<"\tMENUDOS LA DONA"<<endl;
		cout<<"Mostrar matriz - - - - - - - - 1"<<endl;
		cout<<"Dia con mas clientes - - - - - 2"<<endl;
		cout<<"Tienda con menos clientes  - - 3"<<endl;
		cout<<"Total de clientes por tienda - 4"<<endl;
		cout<<"Salida - - - - - - - - - - - - 5"<<endl;
		cout<<"Opcion: ";
		cin>>opc;
		switch(opc)
		{
			case '1':
				mostrarMat(menudo);
				break;
			case '2':
				cout<<diaMas(menudo,&columna)<<" clientes en el dia "<<columna+1<<endl;
				break;
			case '3':
				
				break;
			case '4':
				cout<<"Tienda a consultar: ";
				cin>>tienda;
				clienteTienda(menudo,tienda,&posTienda);
				cout<<"Total de clientes de tienda "<<tienda<<": "<<posTienda<<endl;
				break;
		}
	}while(opc!='5');
}

void llenarMat(int menudo[][COL])
{
	for(int i=0;i<REN;i++)
	{
		for(int j=0;j<COL;j++)
		{
			*(*(menudo+i)+j)=rand()%(101);	//Notación de puntero para matrices
		}
	}
}

void mostrarMat(int menudo[][COL])
{
	int *ptrM=&menudo[0][0];	//puntero que se asigna a una matriz necesita dos '*' cuando es una matriz dinámica,
								//En este caso solo se deja uno, al ser una matriz estática
	for(int i=0;i<REN;i++)
	{
		for(int j=0;j<COL;j++)
		{
			cout<< (*(ptrM+i)+j) << "\t"; 	//Notacion de un puntero para matrices, utilizando un puntero
			//tambien se puede *(*(ptrM+i)+j)
		}
		cout<<endl;
	}
}

int diaMas(int menudo[][COL],int *columna)
{
	int max=0,sumDia=0;
	
	for(int i=0;i<REN;i++)
	{
		sumDia=0;
		for(int j=0;j<COL;j++)
		{
			sumDia+=(*(*menudo+j)+i);
		}
		
		if(sumDia>max)
		{
			max=sumDia;
			*columna=i;
		}
	}
	return max;
}

void clienteTienda(int menudo[][COL],int numTienda,int *total)
{
	for(int i=0;i<COL;i++)
	{
		*total += (*(*menudo+numTienda)+i);
	}
}