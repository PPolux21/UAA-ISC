// Actividad Viernes 10/03/2023
#include <iostream>
#include <stdlib.h>
#include <time.h>
const int TAM=20;

using namespace std;

void llenado(int []);
void mostrar(int []);

int main()
{
	int vec[TAM];
	srand(time(NULL));
	
	llenado(vec);
	mostrar(vec);
}

void llenado(int array[])
{
	for(int i=0;i<TAM;i++)
	{
		*(array+i)=rand()%101;
	}
}

void mostrar(int array[])
{
	for(int i=0;i<TAM;i++)
	{
		cout<<(array+i)<<" "<<*(array+i)<<endl;
	}
}
