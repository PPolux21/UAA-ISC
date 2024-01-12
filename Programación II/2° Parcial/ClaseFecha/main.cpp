// Espinoza Sanchez Jose Luis - 280676 - 3°C ISC

#include "CFecha.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) 
{
	CFecha fecha1;
	CFecha fecha2(1,5,2080);
	CFecha fecha3(fecha2);
	
	cout<<fecha1.mostrarFecha()<<endl;
	cout<<fecha2.mostrarFecha()<<endl;
	cout<<fecha3.mostrarFecha()<<endl;
	
	cin>>fecha1;
	
	cout<<endl<<fecha1;
	
	return 0;
}
