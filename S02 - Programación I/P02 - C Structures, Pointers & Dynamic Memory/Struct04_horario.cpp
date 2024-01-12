//Estructura horario
//horario estándar y militar
//funciones captura y mostrar en un menu
#include <iostream>

using namespace std;

struct Horario
{
	int hora;
	int min;
	int seg;
};

void menu();
void captura(Horario *);
void mostrar(Horario);

int main()
{
	menu();
	
	return 0;
}

void menu()
{
	struct Horario hora={0,0,0};
	int opc=0;
	
	do
	{
		cout<<"\tHORARIO"<<endl;
		cout<<"Captura . . . . 1"<<endl;
		cout<<"Mostrar . . . . 2"<<endl;
		cout<<"Salir . . . . . 3"<<endl;
		cout<<"Elige tu opcion: ";
		cin>>opc;
		switch(opc)
		{
			case 1:
				captura(&hora);
				break;
			case 2:
				mostrar(hora);
				break;
			case 3:
				break;
			default:
				cout<<"Opcion no valida :c"<<endl;
				break;
		}
	}while(opc!=3);
	
}

void captura(Horario *hora)
{
	int horaExtra=0,minExtra=0;
	
	cout<<"Camputa del horario: \n";
	cout<<"Dame la hora: ";
	cin>> hora->hora;
	cout<<"Dame los minutos: ";
	cin>> hora->min;
	cout<<"Dame los segundos: ";
	cin>> hora->seg;
	
	if(hora->seg >= 60)
	{
		minExtra = hora->seg / 60;
		hora->min += minExtra;
		hora->seg %= 60;
	}
	
	if(hora->min >= 60)
	{
		horaExtra = hora->min / 60;
		hora->hora += horaExtra;
		hora->min %= 60;
	}
	
	hora->hora %= 24;
}

void mostrar(Horario hora)
{
	cout<<"\nHora cotidiana:"<<endl;
	cout<<hora.hora<<":"<<hora.min<<":"<<hora.seg<<endl;
	
	cout<<"\nHora militar:"<<endl;
	cout<<hora.hora<<hora.min<<endl;
}