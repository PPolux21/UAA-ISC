//Factorial Iterativo
#include <iostream>

int factorial(int num);

using namespace std;

int main()
{
	int num,res=0;
	cout<<"Dame el valor del numero: ";
	cin>>num;
	res=factorial(num);
	cout<<"Resultado final: "<<res<<endl;
}

int factorial(int num)
{
	int fact=1;
	for(int i=1;i<=num;i++)
	{
		fact*=i;
	}
	return fact;
}