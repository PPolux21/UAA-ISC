//Manejo de Enumeraciones ~Enum~

#include <iostream>

using namespace std;

//Declaración de un tipo enumerado
enum Estaciones{		//Por default valores ordinales 0,1,2,3 ...
	PRIMEVERA=5,
	VERANO,
	OTONO=9,	
	INVIERNO	//Afecta al siguiente, si este no se le asigna un valor
};

/*
enum Estaciones{ PRIMEVERA, VERANO, OTONO, INVIERNO };
*/

int main()
{
	Estaciones mes;
	mes=INVIERNO;
	cout<<mes<<endl;
}