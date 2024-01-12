/*
Calculadora de Matrices
Capturar A y B
Sumar y resta
Mostrar A
Mostrar B 
Mostrar C	*/


#include <iostream>

using namespace std;

void llenaMat(int**,int,int);
void mostrarMat(int**,int,int);
void suma(int**,int**,int**,int,int);
void resta(int**,int**,int**,int,int);
void multMatriz(int**,int**,int**,int,int);
void multEscalar(int**,int**,int,int,int);


int main()
{
	int **matA,**matB,**matC,fila,col,escl;

	cout<<"Cantidad de filas de las matrices: ";
	cin>>fila;
	cout<<"Cantidad de columnas de las matrices: ";
	cin>>col;
	
//	Inicializacion de espacios en las Matrices A, B y C
	matA = new int *[fila];
	matB = new int *[fila];
	matC = new int *[fila];
	for(int i=0;i<fila;i++)
	{
		matA[i] = new int [col];
		matB[i] = new int [col];
		matC[i] = new int [col];
	}
	
	cout<<"\n \tMatriz A: "<<endl;
	llenaMat(matA,fila,col);	//llena la Matriz A
	cout<<"\n \tMatriz B: "<<endl;
	llenaMat(matB,fila,col);	//llena la Matriz B
	
//	Mostrar las matrices A y B
	cout<<"\n \tMatriz A: "<<endl;
	mostrarMat(matA,fila,col);
	cout<<"\n \tMatriz B: "<<endl;
	mostrarMat(matB,fila,col);
	
//	Suma
	suma(matA,matB,matC,fila,col);
	cout<<"\n \tSuma A+B: "<<endl;
	mostrarMat(matC,fila,col);
	
//	Resta
	resta(matA,matB,matC,fila,col);
	cout<<"\n \tResta A-B: "<<endl;
	mostrarMat(matC,fila,col);
	
//	Multiplicación entre matrices
	
	
//	Multiplicación escalar
	cout<<"\n \tMultiplicacion por un escalar"<<endl;
	cout<<"Escalar a multiplicar las matrices: ";
	cin>>escl;
	multEscalar(matA,matC,fila,col,escl);
	cout<<"\n A*escalar: "<<endl;
	mostrarMat(matC,fila,col);
	
	multEscalar(matB,matC,fila,col,escl);
	cout<<"\n B*escalar: "<<endl;
	mostrarMat(matC,fila,col);
	
//	Libera espacio en la memoria de las Matrices A, B y C
	for(int i=0;i<fila;i++)
	{
		delete[] matA[i];
		delete[] matB[i];
		delete[] matC[i];
	}
	delete[] matA;
	delete[] matB;
	delete[] matC;
	
	system("pause");
	
	return 0;
}



//Funciones

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
			cout<<"\t"<<mat[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
}

void suma(int **matA,int **matB,int **matC,int fila,int col)
{	
	for(int i=0; i<fila; i++)
	{
		for(int j=0; j<col; j++)
		{
			
			matC[i][j] = matA[i][j] + matB[i][j];
		}
	}
}

void resta(int **matA,int **matB,int **matC,int fila,int col)
{
	for(int i=0; i<fila; i++)
	{
		for(int j=0; j<col; j++)
		{
			
			matC[i][j] = matA[i][j] - matB[i][j];
		}
	}
}

void multMatriz(int **matA,int **matB,int **matC,int fila,int col)
{
	if(fila==col)
	{
		for(int i=0;i<fila;i++)
		{
			for(int j=0;i<col;j++)
			{
			
			}
		}
	}
	else
	{
		cout<<"Las matrices no cumples las reglas de dimensión"<<endl;
	}
}

void multEscalar(int **mat,int **res,int fila,int col,int escl)
{	
	for(int i=0; i<fila; i++)
	{
		for(int j=0; j<col; j++)
		{
			res[i][j] = mat[i][j] * escl;
		}
	}
}