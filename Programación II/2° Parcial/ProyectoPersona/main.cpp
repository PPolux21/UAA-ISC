#include "CPersona.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	
	CPersona persona1;
//	CPersona persona2 ((char*)"CURP",(char*)"Nombre",(char*)"ApellidoP",(char*)"ApellidoM",20,'M');
	
	cout<<"Wenas"<<endl;
	
	cout<<persona1.toString()<<endl;
//	cout<<persona2.toString();
	
	return 0;
}