//Ejercicio 2

#include <iostream>

using namespace std;

int main()
{
	int x[]={3,88,6,67,99};
	while(*x<=90)
		printf("%d ",*x++); //Marca [Error] lvalue required as increment operand
	
	return 0;
}