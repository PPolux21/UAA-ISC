/*
José Luis Espinoza Sánchez - ISC - 2° C
Ejercicio 10
 Los datos mensuales que maneja un sistema de nómina están almacenados en un archivo de texto de la
 siguiente manera:
	NombreEmpleado		HorasTrabajadas		SueldoPorHora
 El archivo se llama “master.dat”. Escribir un programa que calcule el promedio de horas trabajadas en el mes
 y la cantidad de dinero total a pagar en el mes
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
float promHrs(int);
float totDinero();

int main()
{
	int num;
	
	cout<<"Cantidad de empleados: ";
	cin>>num;
	
	llenadoArch(num);
	cout<<"\nEl promedio de horas trabajadas es: "<<promHrs(num)<<endl;
	cout<<"Cantidad total de dinero a pagar: "<<totDinero()<<endl;
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

float promHrs(int cant)
{
	FILE *archB;
	Empleados reg;
	float totHoras=0;
	
	archB=fopen("master.dat","rb");
	
	if(archB==NULL)
	{
		cout<<"Error de I/O\n";
		exit(1);
	}
	
	fread(&reg,sizeof(Empleados),1,archB);
	while(!feof(archB))
	{
		totHoras+=reg.horas;
		fread(&reg,sizeof(Empleados),1,archB);
	}
	
	fclose(archB);
	
	return totHoras/cant;
}

float totDinero()
{
	FILE *archB;
	Empleados reg;
	float totSueldo=0,sueldo;
	
	archB=fopen("master.dat","rb");
	
	if(archB==NULL)
	{
		cout<<"Error de I/O\n";
		exit(1);
	}
	
	fread(&reg,sizeof(Empleados),1,archB);
	while(!feof(archB))
	{
		sueldo=reg.horas*reg.sueldo;
		totSueldo+=sueldo;
		fread(&reg,sizeof(Empleados),1,archB);
	}
	
	fclose(archB);
	
	return totSueldo;
}