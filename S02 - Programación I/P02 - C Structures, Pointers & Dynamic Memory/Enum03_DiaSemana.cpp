//Mostrar el día de la semana que corresponda a un num

#include <iostream>

using namespace std;

enum DiasSemana{ LUNES=1, MARTES, MIERCOLES, JUEVES, VIERNES, SABADO, DOMINGO };

int main()
{
	int dia;
	char semana[][10]={"LUNES","MARTES","MIERCOLES","JUEVES","VIERNES","SABADO","DOMINGO"};
	cout<<"Dia de la semana: ";
	cin>>dia;
	if(dia>=1 && dia<=7)
	{
		cout<<"\n"<<semana[dia-1]<<endl;
	}
	else
	{
		cout<<"Numero del dia no valido"<<endl;
	}
	
	for(int i=0; i<7; i++)
	{
		cout<<semana[i]<<" - "<<  <<endl;
	}
}