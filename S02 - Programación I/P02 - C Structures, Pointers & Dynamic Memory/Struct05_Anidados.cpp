//Estructuras Anidadas

#include <iostream>

#define TOT 6
/*
Otra forama de declaración de una estructura anidada

struct Fecha{
	int dd,mm,yy;
};

struct Estudiante{
	int id;
	char nom[25];
	float caliFin[6];
	Fecha fecCurso;
};
*/

using namespace std;

struct Estudiante{
	int id;
	char nom[25];
	float caliFin[TOT];
	struct Fecha{
		int dd,mm,yy;
	}fecCurso;
};

void captura(Estudiante *);
void mostrar(Estudiante);
float prom(Estudiante);

int main()
{
	Estudiante alumno;
	captura(&alumno);
	mostrar(alumno);
	cout<<"Promedio final: "<<prom(alumno)<<endl;
	
	return 0;
}

void captura(Estudiante *alum)
{
	cout<<"Entrega de datos:\n";
	cout<<"Id: ";
	cin>>alum->id;
	cout<<"Nombre: ";
	fflush(stdin);
	gets(alum->nom);
	for(int i=0;i<TOT;i++)
	{
		cout<<"Calificacion "<< i+1<<" : ";
		cin>>alum->caliFin[i];
	}
	
	cout<<"Fecha fin de curso: \n";
	cout<<"Dia: ";
	cin>>alum->fecCurso.dd;
	cout<<"Mes: ";
	cin>>alum->fecCurso.mm;
	cout<<"Ano: ";
	cin>>alum->fecCurso.yy;
}

void mostrar(Estudiante alum)
{
	cout<<"\nMuestra de datos:\n";
	cout<<alum.id<<"\t"<<alum.nom<<"\n";
	for(int i=0;i<TOT;i++)
	{
		cout<<alum.caliFin[i]<<"\t";
	}
	cout<<"\nFecha fin de curso: \n";
	cout<<alum.fecCurso.dd<<"/"<<alum.fecCurso.mm<<"/"<<alum.fecCurso.yy<<endl;
}

float prom(Estudiante alum)
{
	float suma=0;
	for(int i=0;i<TOT;i++)
	{
		suma+=alum.caliFin[i];
	}
	return suma/TOT;
}