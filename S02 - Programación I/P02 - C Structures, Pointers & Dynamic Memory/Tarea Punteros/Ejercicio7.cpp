// Ejercicio 7

#include <iostream>

using namespace std;

int main()
{
	int x[]={3,2,8,7,5}, *p=x;
	
	printf("%d", *x+3); //imprime 6
	printf("%d", (*x)++); //imprime 3
	printf("%d", *(x+3)); //imprime 7
	printf("%d", *p++); //imprime 3

}