/*
Ejercicio 10
 Escribir una función recursiva que convierta a binario un número entero
*/
#include <iostream>

using namespace std;

void binario(int);

int main()
{
	int num;
	
	cout<<"Dame un numero: ";
	cin>>num;
	
	binario(num);
	return 0;
}

void binario(int num)
{
	if(num>1)
		binario(num/2);
	cout<<num%2;
}