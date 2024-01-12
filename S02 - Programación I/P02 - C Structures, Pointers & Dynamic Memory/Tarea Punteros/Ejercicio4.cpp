//Ejercicio 4

#include <iostream>

using namespace std;

int main()
{
	char a[]="Examen de programacion"; 
	char *p= "Examen de mayo";
	
	*(a+1)=p[3];
	cout<< a<<endl;
	*(a+2)='A';
	cout<< a<<endl;
	/*
	a=p++;
	cout<< a<<endl;
	p++=a;
	cout<< *p<<endl;
	*/

}