#include <iostream>
#include "CVehiculo.h"
#include <string.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	cout<<"Hello World\n";
	
	CVehiculo v1;	//Nuevo objeto creado
	
	CVehiculo v2((char*)"marca",(char*)"submarca",(char*)"modelo",10000,10,(char*)"rojo");
//	CVehiculo v3("marca2","submarca2","modelo2",20000,8,"amarillo");
	
	cout<<"Vehiculos";
	cout<<v1.toString()<<endl;
	cout<<v2.toString()<<endl;
	
	cout<<"Fin";
	
	return 0;
}