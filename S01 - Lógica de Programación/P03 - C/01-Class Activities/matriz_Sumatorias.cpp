//Sumatoria en matrices y arreglos

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 200

void llenar(int datos[][MAX],int ren, int col);
void mostrar(int datos[][MAX],int ren, int col);
void sumaRen(int datos[][MAX],int ren, int col);
void mostrarVec(int vec[],int ren);
int sumaCol(int datos[][MAX],int ren, int col);

int main()
{
	srand(time(NULL));
	int datos[MAX][MAX],ren,col,total;
	printf("Dame el tamano de ren: ");
	scanf("%d",&ren);
	printf("Dame el tamano de col: ");
	scanf("%d",&col);
	if(ren>0&&ren<=MAX&&col>0&&col<=MAX)
	{
		llenar(datos,ren,col);
		mostrar(datos,ren,col);
		sumaRen(datos,ren,col);
		total=sumaCol(datos,ren,col);
		printf("\nSuma total: %d",total);
	}else
	{
		printf("Tamano no valido");
		return 1;
	}
}

void llenar(int datos[][MAX],int ren, int col)
{
	for(int i=0;i<ren;i++)
	{
		for(int j=0;j<col;j++)
		{
			datos[i][j]=rand()%11;
		}
	}
}

void mostrar(int datos[][MAX],int ren, int col)
{
	for(int i=0;i<ren;i++)
	{
		for(int j=0;j<col;j++)
		{
			printf("%d ",datos[i][j]);
		}
		printf("\n");
	}
}

void sumaRen(int datos[][MAX],int ren, int col)
{
	int vec[MAX];
	for(int i=0;i<ren;i++)
	{
		for(int j=0;j<col;j++)
		{
			vec[i]+=datos[i][j];
		}
	}
	printf("\nSuma de los renglones: \n");
	mostrarVec(vec,ren);
}

void mostrarVec(int vec[],int ren)
{
	for(int i=0;i<ren;i++)
	{
		printf("%d ",vec[i]);
	}
}

int sumaCol(int datos[][MAX],int ren, int col)
{
	int vec[MAX],suma=0;
	for(int i=0;i<ren;i++)
	{
		for(int j=0;j<col;j++)
		{
			vec[j]+=datos[j][i];
		}
	}
	printf("\nSuma de las columnas: \n");
	mostrarVec(vec,col);
	for(int i=0;i<col;i++)
	{
		suma+=vec[i];
	}
	return suma;
}