//Menú con Enum
#include <iostream>
#define TOTOPC 5

using namespace std;

//Se puede eliminar el nombre de la Enum si no existen variables de este tipo
enum { ALTAS=1, BAJAS, CAMBIOS, CONSULTA, SALIR };

void menu();

int main()
{
	menu();
	return 0;
}//main

void menu()
{
	char opcMenu[][10]={"Altas","Bajas","Cambios","Consulta","Salir"};
	int opc;
	do
	{
		cout<<"\nMANEJO DE ARCHIVOS DE TEXTO\n";
		
		for(int i=0; i<TOTOPC; i++)
		{
			cout<<opcMenu[i]<<"   \t"<<i+1<<endl;
		}
		
		cout<<"Selecciona una opcion: ";
		cin>>opc;
		
		switch(opc)
		{
			case ALTAS:
				cout<<"\nALTAS\n";
				break;
			case BAJAS:
				cout<<"\nBAJAS\n";
				break;
			case CAMBIOS:
				cout<<"\nCAMBIOS\n";
				break;
			case CONSULTA:
				cout<<"\nCONSULTA\n";
				break;
			case SALIR:
				cout<<"\nSALIR\n";
				break;
			default:
				cout<<"\ndefault\n";
				break;
		}
		
	}while(opc!=SALIR);
}//menu