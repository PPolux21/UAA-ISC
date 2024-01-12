// Capturar un arreglo de caracteres y mostrarlo de forma invertida
#include <iostream>

using namespace std;

void llenar(int,char *);
void mostrar(int,char *);

int main()
{
	int cant=0;
	char *vec;
	
	cout<<"Tamano del arreglo: ";
	cin>>cant;
	vec=(char *)calloc(cant,sizeof(char));
	
	llenar(cant,vec);
	mostrar(cant,vec);
	
	return 0;
}

void llenar(int cant,char *vec)
{
	cout<<"Llena el arreglo: "<<endl;
	
	for(int i=0;i<cant;i++)
	{
		cin>> *(vec+i);
	}
}

void mostrar(int cant,char *vec)
{
	for(int i=cant-1;i>=0;i--)
	{
		cout<< *(vec+i);
	}
}