/* 
Suma de arreglos
Mostrar vectores de forma inversa
inicializar vectores y matrices
*/

#include <stdio.h>
#define TAM 10
const int REN=4;
const int COL=4;

void vectores();
void sumaVec(float vecA[],float vecB[],float vecC[]);
void mostrar(const float vecC[]); // el const hace que no se pueda modificar la variable

void matrices();
void sumaMat(int matA[][COL],int matB[][COL],int matC[][COL]);
void mostrarMat(int matriz[][COL]);

int main() 
{
	vectores();
	matrices();
}

void vectores()
{
	float vecA[TAM]={2,4,6,8,10,12,14,16,18,20},vecB[TAM]={3,6,9,12,15,18,21,24,27,30},vecC[TAM]={0,0,0,0,0,0,0,0,0,0};
	sumaVec(vecA,vecB,vecC);
	mostrar(vecC);
}

void sumaVec(float vecA[],float vecB[],float vecC[])
{
	for(int i=0;i<TAM;i++)
	{
		vecC[i]=vecA[i]+vecB[i];
	}
}

void mostrar(const float vecC[])
{
	for(int i=TAM-1;i>=0;i--)
	{
		printf("%.1f \t",vecC[i]);
	}
}

void matrices()
{
	int matA[REN][COL]={{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}};
	int matB[REN][COL]={{1,2,3,4},{5,6,7,8},{1,2,3,4},{5,6,7,8}};
	int matC[REN][COL]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	sumaMat(matA,matB,matC);
	mostrarMat(matC);
}

void sumaMat(int matA[][COL],int matB[][COL],int matC[][COL])
{
	
}

void mostrarMat(int matriz[][COL])
{
	
}