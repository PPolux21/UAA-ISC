
#include <iostream>

using namespace std;

struct Alumno
{
	int id;
	char nom[15];
	float calif[3];
}ana;	//declaración de ana como variable Global de tipo Alumno

void captura(Alumno *);
void mostrar(Alumno);
float promedio(Alumno);

int main()
{
	struct Alumno juan;
	float prom=0;
	captura(&juan);
	mostrar(juan);
	prom=promedio(juan);
	cout<<"Promedio: "<<prom<<endl;
}

void captura(Alumno *juan)
{
	cout<<"Captura de datos\n";
	cout<<"Id: ";
	cin>>juan->id;
	cout<<"Nombre: ";
	cin>>juan->nom;
	for(int i=0;i<3;i++)
	{
		cout<<"Calificacion "<<i+1<<" : ";
		cin>>juan->calif[i];
	}
}

void mostrar(Alumno juan)
{
	cout<<"Datos del Alumno: \n";
	cout<<juan.id<<"\t"<<juan.nom<<"\t";
	for(int i=0;i<3;i++)
	{
		cout<<juan.calif[i]<<"\t";
	}
}

float promedio(Alumno juan)
{
	float suma=0;
	for(int i=0;i<3;i++)
		suma+=juan.calif[i];
	return suma/3;
}