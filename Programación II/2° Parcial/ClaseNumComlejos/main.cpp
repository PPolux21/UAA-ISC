// Espinoza Sanchez Jose Luis - 280676 - 3°C ISC

#include "CComplejos.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	//constructores
	CComplejos comp1;
	CComplejos comp2(5,10);
	CComplejos comp3(comp2);
	CComplejos res;
	CComplejos vector[5]; 
	
	//operadores << >> y método .toString()
	cout<<comp1.toString()<<endl;
	cout<<comp2<<endl;
	cout<<comp3<<endl;
	
	cout<<endl;
	cin>>comp1;
	
	//operadores aritméticos
	res=comp1+comp2;	
	cout<<endl<<comp1<<" + "<<comp2<<" = "<<res<<endl;
	
	res=comp1-comp2;	
	cout<<comp1<<" - "<<comp2<<" = "<<res<<endl;
	
	res=comp1*comp2;	
	cout<<comp1<<" * "<<comp2<<" = "<<res<<endl;
	
	res=comp1/comp2;	
	cout<<comp1<<" / "<<comp2<<" = "<<res<<endl<<endl;
	
	//operadores lógicos
	if(comp2==comp1)// ==
		cout<<comp2<<" es igual que " <<comp1<<endl;
	else
		cout<<comp2<<" no es igual que " <<comp1<<endl;
	
	
	if(comp2!=comp1)// !=
		cout<<comp2<<" es diferente de " <<comp1<<endl;
	else
		cout<<comp2<<" no es diferente de " <<comp1<<endl;
	
	
	if(comp2<comp1)// <
		cout<<"La magnitud de "<<comp2<<" es menor que " <<comp1<<endl;
	else
		cout<<"La magnitud de "<<comp2<<" no es menor que " <<comp1<<endl;
	
	
	if(comp2>comp1)// >
		cout<<"La magnitud de "<<comp2<<" es mayor que " <<comp1<<endl;
	else
		cout<<"La magnitud de "<<comp2<<" no es mayor que " <<comp1<<endl;
	
	
	if(comp2<=comp1)// <=
		cout<<"La magnitud de "<<comp2<<" es menor o igual que " <<comp1<<endl;
	else
		cout<<"La magnitud de "<<comp2<<" no es menor o igual que " <<comp1<<endl;
	
	
	if(comp2>=comp1)// >=
		cout<<"La magnitud de "<<comp2<<" es mayor o igual que " <<comp1<<endl;
	else
		cout<<"La magnitud de "<<comp2<<" no es mayor o igual que " <<comp1<<endl;
		
	//vector de CComplejos
	
	cout<<endl<<"Vector de numeros complejos: "<<endl<<endl;
	for(int i=0;i<5;i++)
		cin>>vector[i];
	
	for(int i=0;i<5;i++)
		cout<<vector[i]<<endl;
		
	return 0;
}