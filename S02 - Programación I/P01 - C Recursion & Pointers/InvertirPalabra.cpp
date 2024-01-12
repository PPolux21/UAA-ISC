//Invertir palabra

#include <iostream>
#include <string.h>

void invertir(char[],int);

using namespace std;

int main()
{
	char palabra[10];
	cout<<"Dame una palabra: ";
	cin>>palabra;
	invertir(palabra,strlen(palabra)-1);
}

void invertir(char palabra[],int tam)
{
	if(tam==0)
	{
		cout<<palabra[tam];
	}
	else
	{
		cout<<palabra[tam];
		invertir(palabra,tam-1);
	}
}