//Ejercicio 6

#include <iostream>

using namespace std;

int main()
{
	int a[5]={10,20,30,40,50};
	int *p=a, i=2;
	
	
	//printf("%d",*p[i]); //imprime 30
	printf("%d",*(p+i)); //imprime 30
	printf("%d",*++p+i); //imprime 22
	//printf("%d",*a++); //imprime 10

}