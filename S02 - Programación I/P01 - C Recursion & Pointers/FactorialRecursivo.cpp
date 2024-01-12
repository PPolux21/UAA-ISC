//Factorial Recursivo
#include <iostream>

unsigned long factorial(long num);

using namespace std;

int main()
{
	long num;
	cout<<"Dame el valor del numero: ";
	cin>>num;
	cout<<"Resultado final: "<<factorial(num)<<endl;
}

unsigned long factorial(long num)
{
	long res;
	if(num<=1)
	{
		return 1;
	}
	else
	{
		return num*factorial(num-1);
	}
}