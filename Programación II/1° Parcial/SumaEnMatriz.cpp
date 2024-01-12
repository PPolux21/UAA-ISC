//Suma en una matriz

#include <iostream>

using namespace std;

void llenaMat(int**,int,int);
void mostrarMat(int**,int,int);

int main()
{
	int **mat,fila,col,suma=0,sumaTot=0;

	cout<<"Cantidad de filas: ";
	cin>>fila;
	cout<<"Cantidad de columnas: ";
	cin>>col;
	
	mat = new int *[fila];
	for(int i=0;i<fila;i++)
	{
		mat[i] = new int [col];
	}
	
	llenaMat(mat,fila,col);
	
	mostrarMat(mat,fila,col);
	
	for(int i=0; i<fila; i++)
	{
		suma=0;
		for(int j=0; j<col; j++)
		{
			suma+=mat[i][j];
		}
		cout<<"La suma de la fila "<<i+1<<" es: "<<suma<<endl;
	}
	cout<<endl;
	
	for(int i=0; i<col; i++)
	{
		suma=0;
		for(int j=0; j<fila; j++)
		{
			suma+=mat[j][i];
		}
		sumaTot+=suma;
		cout<<"La suma de la columna "<<i+1<<" es: "<<suma<<endl;
	}
	cout<<endl;
	
	cout<<"La suma total de la matriz es: "<<sumaTot<<endl;
	
	for(int i=0;i<fila;i++)
	{
		delete[] mat[i];
	}
	delete[] mat;
	
	
	return 0;
}

void llenaMat(int **mat,int fila,int col)
{
	for(int i=0; i<fila; i++)
	{
		for(int j=0; j<col; j++)
		{
			cout<<"Dame un valor: ";
			cin>>mat[i][j];
		}
	}
	cout<<endl;
}

void mostrarMat(int **mat,int fila,int col)
{
	for(int i=0; i<fila; i++)
	{
		for(int j=0; j<col; j++)
		{
			cout<<mat[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl;
}