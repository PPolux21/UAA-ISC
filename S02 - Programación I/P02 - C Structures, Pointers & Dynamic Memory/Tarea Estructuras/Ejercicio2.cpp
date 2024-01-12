/*
Ejercicio 2
 Un programa que capture el id, nombre y 5 calificaciones en un 
 struct y luego muestre los datos del alumno con las calificaciones 
 ordenadas de menor a mayor
*/

#include <iostream>

#define TAM 5

using namespace std;

struct Alumno{
	int id;
	char name[25];
	float calif[TAM];
};

void captura(Alumno *);
void mostrar(Alumno);
void orden(Alumno *);

int main()
{
	Alumno student;
	captura(&student);
	mostrar(student);
}

void captura(Alumno *stu)
{
	cout<<"\tCaptura de Datos\n";
	cout<<"Id: ";
	cin>>stu->id;
	cout<<"Nombre: ";
	fflush(stdin);
	gets(stu->name);
	for(int i=0;i<TAM;i++)
	{
		cout<<"Calificacion "<<i+1<<" : ";
		cin>>stu->calif[i];
	}
}

void mostrar(Alumno stu)
{
	cout<<"\n\tDatos\n";
	cout<<stu.id<<"\t"<<stu.name<<endl;
	orden(&stu);
	for(int i=0;i<TAM;i++)
	{
		cout<<stu.calif[i]<<"\t";
	}
}

void orden(Alumno *stu)
{
	float aux=0;
	for(int i=0;i<TAM-1;i++)
	{
		for(int j=0;j<TAM-i-1;j++)
		{
			if(stu->calif[j] > stu->calif[j+1])
			{
				aux = stu->calif[j];
				stu->calif[j] = stu->calif[j+1];
				stu->calif[j+1] = aux;
			}
		}
	}
}