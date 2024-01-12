/*
Estructura Alumno
*/

#include <iostream>

#define TAM 50
#define TOT 25

using namespace std;

struct Materias{
	char nomMat[25];
	float calif[3];
};

struct Alumno{
	int id;
	char nom[25];
	Materias materias[4];
};

void menu();
void captura(Alumno []);
void mostrar(Alumno []);
void busca(Alumno []);

int main()
{
	menu();
}

void menu()
{
	Alumno gpo[TAM];
	int opc=0;
	
	do{
		cout<<"\tMENU DE OPCIONES"<<endl;
		cout<<"Capturar - - - - - - - 1"<<endl;
		cout<<"Mostrar  - - - - - - - 2"<<endl;
		cout<<"Buscar - - - - - - - - 3"<<endl;
		cout<<"Salir  - - - - - - - - 4"<<endl;
		cout<<"Elige tu opcion: ";
		cin>>opc;
		
		switch(opc)
		{
			case 1:
				captura(gpo);
				break;
			case 2:
				mostrar(gpo);
				break;
			case 3:
				busca(gpo);
				break;
			case 4:
				break;
			default:
				cout<<"Opcion no valida :C"<<endl;
				break;
		}
		
	}while(opc!=4);
	
}

void captura(Alumno gpo[])
{
	cout<<"\tCaptura de Datos\n";
	for(int i=0;i<TAM;i++)
	{
		cout<<"\nDatos Alumno "<<i+1<<endl;
		cout<<"Id: ";
		cin>>gpo[i].id;
		cout<<"Nombre: ";
		fflush(stdin);
		gets(gpo[i].nom);
		for(int j=0;j<4;j++)
		{
			cout<<endl;
			cout<<"Materia "<<j+1<<endl;
			cout<<"Nombre: ";
			cin>>gpo[i].materias[j].nomMat;
			for(int k=0;k<3;k++)
			{
				cout<<"Calificacion "<<k+1<<" : ";
				cin>>gpo[i].materias[j].calif[k];
			}
		}
	}
	cout<<endl;
}

void mostrar(Alumno gpo[])
{
	cout<<"\tDatos de los Alumnos\n";
	for(int i=0;i<TAM;i++)
	{
		cout<<"\nAlumno "<<i+1<<endl;
		cout<<gpo[i].id<<"\t"<<gpo[i].nom<<endl;
		for(int j=0;j<4;j++)
		{
			cout<<gpo[i].materias[j].nomMat<<" : ";
			for(int k=0;k<3;k++)
			{
				cout<<gpo[i].materias[j].calif[k]<<"\t";
			}
			cout<<endl;
		}
	}
	cout<<endl;
}

void busca(Alumno gpo[])
{
	int busca;
	float suma=0;
	cout<<"Dame el Id a buscar: ";
	cin>>busca;
	for(int i=0;i<TAM;i++)
	{
		if(gpo[i].id==busca)
		{
			cout<<"\nAlumno "<<i+1<<endl;
			cout<<gpo[i].id<<"\t"<<gpo[i].nom<<endl;
			for(int j=0;j<4;j++)
			{
				suma=0;
				cout<<gpo[i].materias[j].nomMat<<": ";
				for(int k=0;k<3;k++)
				{
					cout<<gpo[i].materias[j].calif[k]<<"\t";
					suma += gpo[i].materias[j].calif[k];
				}
				
				cout<<"Promedio: "<<suma/3<<endl;
			}	
			break;
		}
	}
}