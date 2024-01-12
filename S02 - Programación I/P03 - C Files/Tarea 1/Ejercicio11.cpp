/*
José Luis Espinoza Sánchez - ISC - 2° C
Ejercicio 11
 Con el mismo formato de archivo del problema anterior el gerente quiere obtener un archivo
 “master2.dat” que contenga solamente los empleados que hayan trabajado más de 20 horas y ganen
 menos de 1500 dolares por hora
*/

#include <iostream>
using namespace std;

struct Empleados{
	char nombre[25];
	float horas;
	float sueldo;
};

void llenadoArch(int);
void llenadoReg(Empleados *);
void veintes();

int main()
{
	int num;
	
	cout<<"Cantidad de empleados: ";
	cin>>num;
	
	llenadoArch(num);
	veintes();
}

void llenadoArch(int num)
{
	FILE *archB;
	Empleados reg;
	
	archB=fopen("master.dat","wb");
	
	if(archB==NULL)
	{
		cout<<"Error de I/O\n";
		exit(1);
	}
	
	for(int i=0; i<num; i++)
	{
		llenadoReg(&reg);
		fwrite(&reg,sizeof(Empleados),1,archB);
	}
	
	fclose(archB);
}

void llenadoReg(Empleados *reg)
{
	cout<<"\nLlenado de datos\n";
	cout<<"Nombre: ";
	fflush(stdin);
	gets(reg->nombre);
	cout<<"Horas Trabajadas: ";
	cin>>reg->horas;
	cout<<"Sueldo por hora: ";
	cin>>reg->sueldo;
}

void veintes()
{
	FILE *archB,*archNuevo;
	Empleados reg;
	
	archB=fopen("master.dat","rb");
	archNuevo=fopen("master2.dat","wb");
	
	if(archB==NULL || archNuevo==NULL)
	{
		cout<<"Error de I/O\n";
		exit(1);
	}
	
	fread(&reg,sizeof(Empleados),1,archB);
	while(!feof(archB))
	{
		if(reg.horas>20 && reg.sueldo<1500)
		{
			cout<<reg.nombre<<endl;
			fwrite(&reg,sizeof(Empleados),1,archNuevo);
		}
		fread(&reg,sizeof(Empleados),1,archB);
	}
	
	fclose(archB);
}