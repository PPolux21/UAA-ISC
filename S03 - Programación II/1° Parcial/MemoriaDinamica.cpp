//Ejemplo Memoria dinámica

#include <iostream>

using namespace std;

int main(int argC, char *argV[])
{
	char *c;
	int *i=NULL;
	float **f;
	int n;
	
//	Cadena de 122 más el nulo
	c = new char [123];
	
	i = new int;
	
//	Array de 10 punteros a float
	n = 10;
	f = new float *[n];
//	Cada elemento del array es un array de 10 float
	for(n=0; n<10; n++)
	{
		f[n] = new float [10];
	}
//	f es un array de 10*10

	f[0][0] = 10.32;
	f[9][9] = 21.39;
	c[0] = 'a';
	c[1] = 0;
	
//	liberción de memoria
	for(n=0; n<10; n++)
	{
		delete[] f[n];
	}
	delete[] f;
	delete[] c;
	delete i;
	
	system("pause");
	
	return 0;
}