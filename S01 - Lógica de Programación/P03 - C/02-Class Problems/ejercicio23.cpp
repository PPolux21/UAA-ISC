/*
Ejercicio 23
Espinoza Sánchez José Luis-280676-1°C
09/12/2022
Escribir un programa con una función que dado un tablero de 3x3 relleno con
números enteros, crear un programa que compruebe si todos los números están
entre 1 y 9 (ambos inclusive) y que ninguno se repite
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void llenado(int tabla[][3]);
void mostrar(int tabla[][3]);
void comparacion(int tabla[][3]);

int main()
{
	int tabla[3][3]={{0,0,0},{0,0,0},{0,0,0}};
	srand(time(NULL));
	llenado(tabla);
	mostrar(tabla);
	comparacion(tabla);
	printf("\n");
	mostrar(tabla);
	return 0;
}

void llenado(int tabla[][3])
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			tabla[i][j]=1+rand()%9;
		}
	}
}

void mostrar(int tabla[][3])
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			printf("%d ",tabla[i][j]);
		}
		printf("\n");
	}
}

void comparacion(int tabla[][3])
{
	bool rep=false;
	do{
		rep=false;
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				for(int a=0;a<3;a++)
				{
					for(int b=0;b<3;b++)
					{
				
						if(i!=a||j!=b)
						{
							while(tabla[i][j]==tabla[a][b])
							{
								tabla[i][j]=1+rand()%9;
								rep=true;
							}
						}
					}
				}
			}
		}
	}while(rep);
}