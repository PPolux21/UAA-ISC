/*
Ejercicio 4
 Escribir una función que reciba una matriz de tipo entero y un valor escalar.
 Obtenga la multiplicación de la matriz por el escalar 
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
#define REN 4
#define COL 5

using namespace std;

void mult(int[][COL],int);	//funcion del ejercicio
void mostrar(int[][COL]);
void llenar(int[][COL]);

int main()
{
	int escalar,mat[REN][COL];
	
	srand(time(NULL));
	//primero se llena la matriz para luego poder aplicar la multiplicación escalar
	llenar(mat);
	//luego se muestra la matriz para obcervar como se veía la matriz antes de la multiplicacion
	mostrar(mat);	
	
	cout<<"Dame el valor del escalar: ";
	cin>>escalar;
	
	//llamada a la funcion del ejercicio
	mult(mat,escalar);
	//se vuelve a mostrar la matri< para comprobar que se ha efectuado correctamente la multiplicacion
	mostrar(mat);
	
	return 0;
}

//funcion del ejercicio
void mult(int mat[][COL],int esc)
{
	for(int i=0;i<REN;i++)
		for(int j=0;j<COL;j++)
			mat[i][j] *= esc;
}
	
void mostrar(int mat[][COL])
{
	for(int i=0;i<REN;i++)
	{
		for(int j=0;j<COL;j++)
			cout<<mat[i][j]<<"\t";
		cout<<endl;
	}

}

void llenar(int mat[][COL])
{
	for(int i=0;i<REN;i++)
		for(int j=0;j<COL;j++)
			mat[i][j] = 1+rand()%10;
}