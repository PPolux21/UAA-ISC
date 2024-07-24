// Espinoza Sanchez Jose Luis - 280676 - 3°C ISC

#include "CFraccion.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	CFraccion f1;
	CFraccion f2(1,2);
	CFraccion f3(f2);
	CFraccion f4;
	
	f3.setNumer(3);
	
	cout<<f1.toString()<<endl;
	cout<<f2.toString()<<endl;
	cout<<f3.toString()<<endl;
	
	//operaciones con operadores aritemeticos
	cout<<endl<<"Operaciones con operadores aritemeticos:"<<endl;
	
	f4=f2+f3;
	
	cout<<f2<<" + "<<f3<<" = "<<f4<<endl;
	
	f4=f2-f3;
	
	cout<<f2<<" - "<<f3<<" = "<<f4<<endl;
	
	f4=f2*f3;
	
	cout<<f2<<" * "<<f3<<" = "<<f4<<endl;
	
	f4=f2/f3;
	
	cout<<f2<<" / "<<f3<<" = "<<f4<<endl;
	
	
	//operaciones con metodos
	cout<<endl<<"Operaciones con metodos:"<<endl;
	
	f4=f2.suma(f3);
	
	cout<<f2<<" + "<<f3<<" = "<<f4<<endl;
	
	f4=f2.resta(f3);
	
	cout<<f2<<" - "<<f3<<" = "<<f4<<endl;
	
	f4=f2.mult(f3);
	
	cout<<f2<<" * "<<f3<<" = "<<f4<<endl;
	
	f4=f2.div(f3);
	
	cout<<f2<<" / "<<f3<<" = "<<f4<<endl<<endl;
	
	//operadores logicos
	cin>>f1;
	
	if(f2==f1)// ==
	{
		cout<<f2<<" es igual que "<<f1<<endl;
	}else{
		cout<<f2<<" no es igual que "<<f1<<endl;
	}
	
	if(f2!=f1)// !=
	{
		cout<<f2<<" es diferente de "<<f1<<endl;
	}else{
		cout<<f2<<" no es diferente de "<<f1<<endl;
	}
	
	if(f2<f1)// <
	{
		cout<<f2<<" es menor que "<<f1<<endl;
	}else{
		cout<<f2<<" no es menor que "<<f1<<endl;
	}
	
	if(f2>f1)// >
	{
		cout<<f2<<" es mayor que "<<f1<<endl;
	}else{
		cout<<f2<<" no es mayor que "<<f1<<endl;
	}
	
	if(f2<=f1)// <=
	{
		cout<<f2<<" es menor o igual que "<<f1<<endl;
	}else{
		cout<<f2<<" no es menor o igual  que "<<f1<<endl;
	}
	
	if(f2>=f1)// >=
	{
		cout<<f2<<" es mayor o igual que "<<f1<<endl;
	}else{
		cout<<f2<<" no es mayor o igual que "<<f1<<endl;
	}
	
	return 0;
}