// Espinoza Sanchez Jose Luis - 280676 - 3°C ISC

#include "CFloat.h"
#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	CFloat flotante1;
	CFloat flotante2(21.33);
	CFloat flotante3(472);
	CFloat flotante4(82.431293);
	CFloat flotante5(flotante3);
	
	//operadores de flujo
	cout<<flotante1<<endl;
	cout<<flotante2<<endl;
	cout<<flotante3<<endl;
	cout<<flotante4<<endl;
	cout<<flotante5<<endl;
	
	cin>>flotante1;
	
	// operadores aritmeticos
	flotante5 = flotante1 + flotante4;
	
	cout<<endl<<flotante1<<" + "<<flotante4<<" = "<<flotante5<<endl;
	
	flotante5 = flotante1 - flotante4;
	
	cout<<flotante1<<" - "<<flotante4<<" = "<<flotante5<<endl;
	
	flotante5 = flotante1 * flotante4;
	
	cout<<flotante1<<" * "<<flotante4<<" = "<<flotante5<<endl;
	
	flotante5 = flotante1 / flotante4;
	
	cout<<flotante1<<" / "<<flotante4<<" = "<<flotante5<<endl<<endl;
	
	// métodos to_______
	cout<<"Metodo toInt: "<<flotante1.toInt()<<endl;
	cout<<"Metodo toDouble: "<<flotante1.toDouble()<<endl;
	cout<<"Metodo toString: "<<flotante1.toString()<<endl;
	
	return 0;
}