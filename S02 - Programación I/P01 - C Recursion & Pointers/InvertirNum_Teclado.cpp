//Invertir un numero de forma recursiva
#include <iostream>

void invertir(int);

using namespace std;

int main()
{
	int num;
	cout<<"Dame un numero entero: ";
	cin>>num;
	if(num<0)
	{
		num*=(-1);
	}
	cout<<"El numero invertido es: ";
	invertir(num);
	cout<<endl;
}

void invertir(int numero)
{
	if(numero/10<=0)
	{
		cout<<numero;
	}
	else
	{
		cout<<numero%10;
		invertir(numero/10);
	}
}