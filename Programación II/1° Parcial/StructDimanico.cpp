#include <iostream>
using namespace std;

struct Alumno{
	int id;
	char nombre[20];
	float calif[3];
};

void llenaGpo(Alumno*,int);
float *promCalif(Alumno*,int);
void mostrar(float*,Alumno*,int);
void promTot(float *,int);

int main()
{
	int alumn;
	Alumno *gpo;
	float *prom;

	cout<<"Cantidad de Alumnos: ";
	cin>>alumn;
	gpo = new Alumno [alumn];
	
	llenaGpo(gpo,alumn);
	prom = promCalif(gpo,alumn);
	
	mostrar(prom,gpo,alumn);
	
	delete[] gpo;
	delete[] prom;
	
	return 0;
}

void llenaGpo(Alumno *gpo,int alumn)
{
	for(int i=0; i<alumn; i++)
	{
		cout<<"\nAlumno "<<i+1<<":"<<endl;
		cout<<"ID: ";
		cin>>gpo[i].id;
		cout<<"Nombre: ";
		fflush(stdin);
		gets(gpo[i].nombre);
		cout<<"Calificaciones:"<<endl;
		for(int j=0; j<3; j++)
		{
			cout<<"\tParcial "<<j+1<<": ";
			cin>>gpo[i].calif[j];
		}
	}
	cout<<endl;
}

float *promCalif(Alumno *gpo,int alumn)
{
	float *prom;
	
	prom = new float [alumn];
	
	for(int i=0; i<alumn; i++)
	{
		prom[i] = 0;
		for(int j=0; j<3; j++)
		{
			prom[i] += gpo[i].calif[j];
		}
		prom[i] /= 3;
	}
	
	return prom;
}

void mostrar(float *prom,Alumno *gpo,int alumn)
{
	for(int i=0; i<alumn; i++)
	{
		cout<<"\nAlumno "<< i+1 <<":"<<endl;
		cout<<"\tID: "<< gpo[i].id <<endl;
		cout<<"\tNombre: "<< gpo[i].nombre <<endl;
		cout.precision(2);
		cout<<"\tPromedio: "<< prom[i] <<endl;
	}		
	promTot(prom,alumn);
}

void promTot(float *prom,int alumn)
{
	float promMin=0,promMax=0,promGpo=0;
	for(int i=0; i<alumn; i++)
	{
		if(i==0)
		{
			promMin = prom[i];
			promMax = prom[i];
		}
		else
		{
			if(promMin > prom[i])
			{
				promMin = prom[i];
			}
			if(promMax < prom[i])
			{
				promMax = prom[i];
			}
		}
		promGpo += prom[i];
	}
	promGpo /= alumn;
	
	cout<<"\n\nPromedio total del grupo: "<< promGpo <<endl;
	cout<<"\tPromedio menor: "<< promMin <<endl;
	cout<<"\tPromedio mayor: "<< promMax <<endl;
}
