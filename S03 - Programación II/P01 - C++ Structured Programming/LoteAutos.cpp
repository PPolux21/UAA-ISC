//Lote de autos

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;

struct Autos{
	char marca[10];
	char modelo[10];
	int ano;
	int km;
	char color[10];
};

void llenaStructRand(Autos*,int);
void menuBusca();
bool buscaMarca();
bool buscaModelo();
bool buscaAno();
bool buscaKm();
bool buscaColor();
void mostrarArch();
void mostrarAuto(Autos);
void creaArch(Autos*,int);
Autos leeArch(ifstream&);

int main()
{
	srand(time(NULL));
	
	Autos *lote;
	int cant;
	
	cout<<"Cantidad de autos en el lote: ";
	cin>>cant;
	
	lote = new Autos [cant];
	
	llenaStructRand(lote,cant);
	
	creaArch(lote,cant);
	
	menuBusca();
	
	delete [] lote;
	
	return 0;
}

void llenaStructRand(Autos *lote,int cant)
{
	for(int i=0;i<cant;i++)
	{
		switch(rand()%5)
		{
			case 0:
				strcpy(lote[i].marca,"BMW");
				break;
			case 1:
				strcpy(lote[i].marca,"Audi");
				break;
			case 2:
				strcpy(lote[i].marca,"Nissan");
				break;
			case 3:
				strcpy(lote[i].marca,"Mercedes");
				break;
			case 4:
				strcpy(lote[i].marca,"Honda");
				break;
		}
		switch(rand()%3)
		{
			case 0:
				strcpy(lote[i].modelo,"Sedan");
				break;
			case 1:
				strcpy(lote[i].modelo,"Pick-Up");
				break;
			case 2:
				strcpy(lote[i].modelo,"4x4");
				break;
			case 3:
				strcpy(lote[i].modelo,"Deportivo");
				break;
		}
		lote[i].ano = 2015 + rand()%10;
		lote[i].km = 1000 * rand()%51;
		switch(rand()%5)
		{
			case 0:
				strcpy(lote[i].color,"Blanco");
				break;
			case 1:
				strcpy(lote[i].color,"Negro");
				break;
			case 2:
				strcpy(lote[i].color,"Gris");
				break;
			case 3:
				strcpy(lote[i].color,"Azul");
				break;
			case 4:
				strcpy(lote[i].color,"Rojo");
				break;
		}
	}
}

void creaArch(Autos *lote,int cant)
{
	ofstream archTxt;
	
	archTxt.open("LoteAutos.txt");
	
	if(archTxt.is_open())
	{
		for(int i=0;i<cant;i++)
		{
			archTxt << lote[i].marca<<","<<lote[i].modelo<<","<<lote[i].ano<<","<<lote[i].km<<","<<lote[i].color<<endl;
		}
		archTxt.close();
	}else{
		cout<<"No se abrio el archivo";
		exit(1);
	}
	
}

void menuBusca()
{
	int opc;
	
	do
	{
		system("cls");
		cout<<"\nBusca de Autos"<<endl;
		cout<<"Mostrar Inv  0"<<endl;
		cout<<"Marca  - - - 1"<<endl;
		cout<<"Modelo - - - 2"<<endl;
		cout<<"Ano  - - - - 3"<<endl;
		cout<<"Km - - - - - 4"<<endl;
		cout<<"Color  - - - 5"<<endl;
		cout<<"Salir  - - - 6"<<endl;
		cout<<"\nOpcion: ";
		cin>>opc;
		switch(opc)
		{
			case 0:
				mostrarArch();
				system("pause");
				break;
			case 1:
				if(!buscaMarca())
					cout<<"No hubo coincidencias"<<endl;
				system("pause");
				break;
			case 2:
				if(!buscaModelo())
					cout<<"No hubo coincidencias"<<endl;
				system("pause");
				break;
			case 3:
				if(!buscaAno())
					cout<<"No hubo coincidencias"<<endl;
				system("pause");
				break;
			case 4:
				if(!buscaKm())
					cout<<"No hubo coincidencias"<<endl;
				system("pause");
				break;
			case 5:
				if(!buscaColor())
					cout<<"No hubo coincidencias"<<endl;
				system("pause");
				break;
			case 6:
				break;
			default:
				cout<<"Opcion no valida"<<endl;
				system("pause");
				break;
		}
	}while(opc!=6);
}

bool buscaMarca()
{
	char busca[10];
	bool ban=false;
	Autos coche;
	
	ifstream archTxt("LoteAutos.txt");
	
	cout<<"Nombre de la Marca a buscar: ";
	cin>>busca;
	
	coche = leeArch(archTxt);
	while(!archTxt.eof())
	{
		if(strcmp(coche.marca,busca)==0)
		{
			mostrarAuto(coche);
			ban=true;
		}
		coche = leeArch(archTxt);
	}
	archTxt.close();
	
	return ban;
}

bool buscaModelo()
{
	char busca[10];
	bool ban=false;
	Autos coche;
	
	ifstream archTxt("LoteAutos.txt");
	
	cout<<"Nombre del Modelo a buscar: ";
	cin>>busca;
	
	coche = leeArch(archTxt);
	while(!archTxt.eof())
	{
		if(strcmp(coche.modelo,busca)==0)
		{
			mostrarAuto(coche);
			ban=true;
		}
		coche = leeArch(archTxt);
	}
	archTxt.close();
	
	return ban;
}

bool buscaAno()
{
	int busca;
	bool ban=false;
	Autos coche;
	
	ifstream archTxt("LoteAutos.txt");
	
	cout<<"Ano a buscar: ";
	cin>>busca;
	
	coche = leeArch(archTxt);
	while(!archTxt.eof())
	{
		if(coche.ano==busca)
		{
			mostrarAuto(coche);
			ban=true;
		}
		coche = leeArch(archTxt);
	}
	archTxt.close();
	
	return ban;
}

bool buscaKm()
{
	int busca;
	bool ban=false;
	Autos coche;
	
	ifstream archTxt("LoteAutos.txt");
	
	cout<<"Dsitancia de Km a buscar: ";
	cin>>busca;
	
	coche = leeArch(archTxt);
	while(!archTxt.eof())
	{
		if(coche.km==busca)
		{
			mostrarAuto(coche);
			ban=true;
		}
		coche = leeArch(archTxt);
	}
	archTxt.close();
	
	return ban;
}

bool buscaColor()
{
	char busca[10];
	bool ban=false;
	Autos coche;
	
	ifstream archTxt("LoteAutos.txt");
	
	cout<<"Color a buscar: ";
	cin>>busca;
	
	coche = leeArch(archTxt);
	while(!archTxt.eof())
	{
		if(strcmp(coche.color,busca)==0)
		{
			mostrarAuto(coche);
			ban=true;
		}
		coche = leeArch(archTxt);
	}
	archTxt.close();
	
	return ban;
}

void mostrarArch()
{
	Autos coche;
	
	ifstream archTxt("LoteAutos.txt");
	
	coche = leeArch(archTxt);
	while(!archTxt.eof())
	{
		mostrarAuto(coche);
		
		coche = leeArch(archTxt);
	}
	cout<<endl;
	archTxt.close();
}

void mostrarAuto(Autos coche)
{
	cout<<endl<<coche.marca<<endl;
	cout<<"\t"<<coche.modelo<<" "<<coche.ano<<endl;
	cout<<"\t"<<coche.km<<" km"<<endl;
	cout<<"\t"<<coche.color<<endl;
}

Autos leeArch(ifstream& archTxt)
{
	Autos coche;
	string cadena,aux;
	int i=0;
	
	getline(archTxt,cadena);
	
	for(int j=0;cadena[i]!=',';j++)
	{
		coche.marca[j]=cadena[i];
		i++;
	}
	
	i++;
	for(int j=0;cadena[i]!=',';j++)
	{
		coche.modelo[j]=cadena[i];
		i++;
	}
	
	i++;
	for(int j=0;cadena[i]!=',';j++)
	{
		aux[j]=cadena[i];
		i++;
	}
	coche.ano=stoi(aux);
	
	i++;
	for(int j=0;cadena[i]!=',';j++)
	{
		aux[j]=cadena[i];
		i++;
	}
	coche.km=stoi(aux);
	
	i++;
	for(int j=0;cadena[i]!='\n';j++)
	{
		coche.color[j]=cadena[i];
		i++;
	}
	
	return coche;
}