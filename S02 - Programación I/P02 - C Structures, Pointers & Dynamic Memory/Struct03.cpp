//usar una variable dinámica de tipo struct

#include <iostream>

using namespace std;

struct Alumno
{
	int id;
	char nom[15];
	float prom;
};	//declaración de ana como variable Global de tipo Alumno

void captura(Alumno *);
void mostrar(Alumno *);
float promedio(Alumno *);

int main()
{
	struct Alumno *juan;
	float prom=0;
	captura(juan);
	mostrar(juan);
}

void captura(Alumno *juan)
{
	cout<<"Captura de datos\n";
	cout<<"Id: ";
	cin>>juan->id;
	cout<<"Nombre: ";
	cin>>juan->nom;
	cout<<"Promedio: ";
	cin>>juan->prom;

}

void mostrar(Alumno *juan)
{
	cout<<"Datos del Alumno: \n";
	cout<<juan->id<<"\t"<<juan->nom<<"\t"<<juan->prom;
}