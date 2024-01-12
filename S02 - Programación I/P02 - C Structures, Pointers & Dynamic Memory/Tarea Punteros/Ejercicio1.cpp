//Ejercicio 1

#include <iostream>
#include <string.h>
#define TAM 25

using namespace std;

void fun(unsigned char *, unsigned char *);

int main()
{
	unsigned char cad1[TAM],cad2[TAM];
	
	cout<<"Dame una palabra: ";
	cin>>cad1;
	cout<<"Dame otra palabra: ";
	cin>>cad2;
	cout<<"Mostrarndo cadenas: "<<endl;//para demostrar el funcionamiento del codigo
	cout<<"\t"<<cad1<<endl;
	cout<<"\t"<<cad2<<endl;
	
	fun(cad1,cad2);
	
	cout<<"Mostrarndo cadenas despues de la funcion: "<<endl;//para demostrar el funcionamiento del codigo
	cout<<"\t"<<cad1<<endl;
	cout<<"\t"<<cad2<<endl;
	
}

void fun(unsigned char *cad1, unsigned char *cad2)
{
	while (*cad2++=*cad1++);
}