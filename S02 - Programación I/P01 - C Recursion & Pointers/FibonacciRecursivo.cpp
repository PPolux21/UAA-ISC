//fibonacci recursivo

#include <iostream>

int fibo(int);

using namespace std;

int main()
{
	int num;
	cout<<"Fibonacci Recursivo\n";
	cout<<"Introduce un numero: ";
	cin>>num;
	cout<<"El fibonacci de "<<num<<" es: "<<fibo(num)<<endl;
	return 0;
}

int fibo(int numero)
{
	if(numero==0||numero==1)
	{
		return 1;
	}
	else
	{
		return fibo(numero-1)+fibo(numero-2);
	}
}