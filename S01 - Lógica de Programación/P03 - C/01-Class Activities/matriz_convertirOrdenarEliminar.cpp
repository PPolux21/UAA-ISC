//Llenar matriz, convertir a vector, ordenar y eliminar duplicados

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 3

void llenar(int mat[][MAX]);
void mostrar(int mat[][MAX]);
void convertir(int mat[][MAX],int vec[]);
void ordenar(int vec[],int tam);
void eliminar(int vec[],int tam);

int main()
{
	int mat[MAX][MAX],vec[MAX*MAX],tam=MAX*MAX;
	srand(time(NULL));
	llenar(mat);
	mostrar(mat);
	convertir(mat,vec);
	ordenar(vec,MAX*MAX);
	//eliminar(vec,MAX*MAX);
	for(int i=0;i<tam;i++)
	{
		for(int j=i+1;j<tam;j++)
		{
			if(vec[i]==vec[j])
			{
				for(int k=j;k<tam-1;k++)
				{
					vec[k]=vec[k+1];
					tam--;
					j=i;
				}
			}
		}
	}
	printf("\n");
	for(int i=0;i<tam;i++)
	{
		printf("%d ",vec[i]);
	}
}

void llenar(int mat[][MAX])
{
	for(int i=0;i<MAX;i++)
	{
		for(int j=0;j<MAX;j++)
		{
			mat[i][j]=rand()%16;
		}
	}
}

void mostrar(int mat[][MAX])
{
	for(int i=0;i<MAX;i++)
	{
		for(int j=0;j<MAX;j++)
		{
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}
}

void convertir(int mat[][MAX],int vec[])
{
	int k=0;
	for(int i=0;i<MAX;i++)
	{
		for(int j=0;j<MAX;j++)
		{
			vec[k++]=mat[i][j];
		}
	}
}

void ordenar(int vec[],int tam)
{
	int aux=0;
	for(int i=0;i<tam;i++)
	{
		for(int j=tam-1;j>=i;j--)
		{
			if(vec[j-1]>vec[j])
			{
				aux=vec[j-1];
				vec[j-1]=vec[j];
				vec[j]=aux;
			}
		}
	}
}
/*
void eliminar(int vec[],int tam)
{
	for(int i=0;i<tam;i++)
	{
		for(int j=i+1;j<tam;j++)
		{
			if(vec[i]==vec[j])
			{
				for(int k=j;k<tam-1;k++)
				{
					vec[k]=vec[k+1];
					tam--;
					j=i;
				}
			}
		}
	}
	
	printf("\n");
	for(int i=0;i<tam;i++)
	{
		printf("%d ",vec[i]);
	}
}*/