/*
Ejercicio 8
 Escribir una función que reciba una matriz flotante y un valor entero, 
 devuelve la sumatoria de la fila que representa el valor entero
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
#define REN 4
#define COL 5

using namespace std;

float sumatoria(float [][COL],int);	//funcion del ejercicio
void llenar(float [][COL]);
void mostrar(float [][COL]);

int main()
{
	float mat[REN][COL];
	int fila;
	
	srand(time(NULL));
	
	llenar(mat);
	mostrar(mat);
	
	cout<<"Dame le fila a sumar: ";
	cin>>fila;
	
	cout<<"Suma de la fila: "<<sumatoria(mat,fila);
}

//funcion del ejercicio
float sumatoria(float mat[][COL],int ren)
{
	float sum=0;
	
	for(int i=0;i<COL;i++)
		sum+=mat[ren][i];
		
	return sum;
}

void llenar(float mat[][COL])
{
	for(int i=0;i<REN;i++)
		for(int j=0;j<COL;j++)
		{
			mat[i][j] = rand()%10001;
			mat[i][j] /= 100;
		}
}

void mostrar(float mat[][COL])
{
	for(int i=0;i<REN;i++)
	{
		for(int j=0;j<COL;j++)
			cout<<mat[i][j]<<"\t";
		cout<<endl;
	}
}