//Decimal a Binario - Recursivo
#include <iostream>

using namespace std;

void binario(int);

int main()
{
	int num;
	cout<<"Dame el numero: ";
	cin>>num;
	cout<<"El numero "<<num<<" en binerio es: ";
	binario(num);
}

void binario(int num)
{
	if(num>1)
		binario(num/2);
	cout<<num%2;
}