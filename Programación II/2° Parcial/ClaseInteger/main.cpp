// Espinoza Sanchez Jose Luis - 280676 - 3°C ISC

#include "CInteger.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	CInteger integer1;
	CInteger integer2(4.5);
	CInteger integer3(9.1236721);
	CInteger integer4(6);
	CInteger integer5(integer3);
	
	//operadores de flujo
	cout<<integer1<<endl;
	cout<<integer2<<endl;
	cout<<integer3<<endl;
	cout<<integer4<<endl;
	cout<<integer5<<endl;
	
	cin>>integer1;
	
	// operadores aritmeticos
	integer5 = integer1 + integer2;
	
	cout<<endl<<integer1<<" + "<<integer2<<" = "<<integer5<<endl;
	
	integer5 = integer1 - integer2;
	
	cout<<integer1<<" - "<<integer2<<" = "<<integer5<<endl;
	
	integer5 = integer1 * integer2;
	
	cout<<integer1<<" * "<<integer2<<" = "<<integer5<<endl;
	
	integer5 = integer1 / integer2;
	
	cout<<integer1<<" / "<<integer2<<" = "<<integer5<<endl<<endl;
	
	// métodos to_______
	cout<<"Metodo toFloat: "<<integer1.toFloat()<<endl;
	cout<<"Metodo toDouble: "<<integer1.toDouble()<<endl;
	cout<<"Metodo toString: "<<integer1.toString()<<endl;
	
	return 0;
}