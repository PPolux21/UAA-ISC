//Ejercicio 3 

#include <iostream>

int main()
{
	int x[10], *p=x;
	
	scanf("%d",&x[1]);
	scanf("%d",x+1);
	//printf("%d",*x++);  Marca [Error] lvalue required as increment operand
	scanf("%d",p++);

}