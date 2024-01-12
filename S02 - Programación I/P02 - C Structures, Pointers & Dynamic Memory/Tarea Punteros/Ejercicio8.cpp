//Ejercicio 8

#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	char cad[40]="escuela", otro[40], *p=otro, *q=cad;
	
	strcpy(otro, cad);
	cout<< otro <<endl;
	
	strcpy(p, q);
	cout<< *p <<endl;
	
	strcpy(otro, "politecnica");
	cout<< otro <<endl;
	
	strcpy(p, &cad[0]);
	cout<< *p << endl;

}