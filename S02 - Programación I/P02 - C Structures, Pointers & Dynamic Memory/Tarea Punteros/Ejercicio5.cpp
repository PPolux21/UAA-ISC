//Ejercicio 5

#include <iostream>

using namespace std;

void fun(char *);

int main()
{
	fun("EUP");
}

void fun(char *cad)
{ 
	int n; 
	char *p=cad; 
	while (*cad++); 
	n=cad-p; 
	printf("%d%s",n,p);
}
