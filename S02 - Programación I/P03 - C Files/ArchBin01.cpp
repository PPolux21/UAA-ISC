//Manejo de archivos binarios

#include <iostream>
#include <ctype.h>
#include <string.h>
#define TOTOPC 6
#define SALDO 35000
using namespace std;

enum { CREAR, ALTAS, BAJAS, CAMBIOS, CONSULTA, SALIR };

struct Banco{
	int numCte;
	char nombre[25];
	char passw[8];
	float saldo;
	bool status;
};

void menu();
void crearArch();
void altas();
void marcarBajas();
void bajas();
Banco capturaDatos();
void consultas();
void consultaGral();
void mostrarReg(Banco);
int capturaNum();
void consultaNumCte(int);
char *buscaNombre();
void cambios();

int main(){
	menu();
}

void menu()
{
	char opcMenu[][10]={"Crear","Altas","Bajas","Cambios","Consulta","Salir"};
	int opc;
	do
	{
		cout << "\nMANEJO DE ARCHIVOS DE TEXTO\n";
		//muestra el menu de opciones
		for(int i=0;i<TOTOPC;i++){
			cout << opcMenu[i] <<"\t...."<<i<< endl;
		}
		cout << "Selecciona una opcion: ";
		cin >> opc;
		switch(opc)
		{
			case CREAR: 
				crearArch();
					break;
			case ALTAS: 
				altas();
					break;
			case BAJAS: 
				marcarBajas();
				bajas();
					break;
			case CAMBIOS: 
				cambios();
					break;
			case CONSULTA: 
				consultas();
					break;
			default:  //instrucciones
					break;
		}//switch
	}while(opc != SALIR);
}//menu

void crearArch()
{
	FILE *archB;
	archB=fopen("banco.dat","wb");
	if(archB==NULL)
	{
		cout<<"Error al crear un archivo\n";
		exit(1);
	}
	cout<<"Archivo creado con exito!\n";
	system("pause");
	system("cls");
	fclose(archB);
}

void altas()
{
	FILE *archB;
	Banco reg;
	
	archB = fopen("banco.dat","ab");	//todo archivo binario tiene extension .dat
	
	if(archB!=NULL)	//si se crea el archivo se puede trabajar
	{
		reg = capturaDatos();
		fwrite(&reg,sizeof(Banco),1,archB);
		fclose(archB);
	}
	else
	{
		exit(1);	//sale de la ejecución y marca un error
	}
}

Banco capturaDatos()
{
	Banco aux;
	cout<<"Alta de usuarios\n";
	cout<<"Num.Cuenta: ";
	cin>>aux.numCte;
	cout<<"Nombre del cliente: ";
	fflush(stdin);
	gets(aux.nombre);
	cout<<"Password: ";
	cin>>aux.passw;
	cout<<"Saldo: ";
	cin>>aux.saldo;
	aux.status=true;
	return aux;
}

void marcarBajas()
{
	FILE *archB,*archTemp;
	Banco reg;
	int posi=0;
	
	archB=fopen("banco.dat","rb");
	archTemp=fopen("temporal.dat","wb");
	
	if(archB==NULL || archTemp==NULL)
	{
		cout<<"Error de I/O\n";
		exit(1);
	}
	
	//eliminar a los que tengan saldo menor que 35000
	fread(&reg,sizeof(Banco),1,archB);
	while(!feof(archB))
	{
		if(reg.saldo<=SALDO)
		{
			reg.status=false;
			fwrite(&reg,sizeof(Banco),1,archTemp);
		}
		fread(&reg,sizeof(Banco),1,archB);
	}
	
	fclose(archB);
	fclose(archTemp);
	cout<<"\tUsuarios marcados"<<endl;
}

void bajas()
{
	remove("banco.dat");
	rename("temporal.dat","banco.dat");
	cout<<"\tUsuarios eliminados"<<endl<<endl;
}

void consultas()
{
	char opc;
	do
	{
		cout<<"\nMENU DE CONSULTA\n";
		cout<<"General ........ A\n";
		cout<<"Num.Cliente .... B\n";
		cout<<"Salir .......... Z\n";
		fflush(stdin);
		cin>>opc;
		switch(opc)
		{
			case 'A':
			case 'a':
				consultaGral();
				break;
			case 'B':
			case 'b':
				consultaNumCte(capturaNum());
				break;
		}
	}while(toupper(opc)!='Z');
}

void consultaGral()
{
	FILE *archB;
	Banco reg;
	
	archB=fopen("banco.dat","rb");
	
	fread(&reg,sizeof(Banco),1,archB);
	
	while(!feof(archB))
	{
		if(reg.status)
		{
			mostrarReg(reg);
		}
		fread(&reg,sizeof(Banco),1,archB);
	}
	cout<<endl;
	fclose(archB);
}

void mostrarReg(Banco reg)
{
	cout<<"\nDatos del usuario: \n";
	cout<<"Num.Cliente: "<<reg.numCte<<endl;
	cout<<"Nombre: "<<reg.nombre<<endl;
	cout<<"Password: "<<reg.passw<<endl;
	cout<<"Saldo: "<<reg.saldo<<endl;
}

int capturaNum()
{
	int numero=0;
	cout<<"Numero de Cliente a consultar: ";
	cin>>numero;
	return numero;
}

void consultaNumCte(int numBusca)
{
	FILE *archB;
	Banco reg;
	bool ban=false;
	
	archB=fopen("banco.dat","rb");
	
	if(archB==NULL)
	{
		cout<<"Error en el archivo\n";
		exit(1);
	}
	
	fread(&reg,sizeof(Banco),1,archB);
	while(!feof(archB))
	{
		if(reg.status==true && reg.numCte==numBusca)
		{
			mostrarReg(reg);
			ban=true;
			break;
		}
		fread(&reg,sizeof(Banco),1,archB);
	}
	
	if(!ban)
	{
		cout<<"El Cliente no existe\n";
	}
	
	fclose(archB);
	
	cout<<endl;
}

char *buscaNombre()
{
	char *nombre=new char [25];
	cout<<"Ususario a localizar: ";
	cin>>nombre;
	cout<<endl;
	return nombre;
}

//hacer tambien un cambios pero con numCte
void cambios()
{
	char nomBuscar[25];
	FILE *archB;
	Banco reg;
	int numCteAux,posi=0;
	bool ban=false;
	
	cout<<"\nACTUALIZACION DE DATOS\n";
	strcpy(nomBuscar,buscaNombre());
	
	archB=fopen("banco.dat","r+b");
	
	if(archB==NULL)
	{
		cout<<"Error de I/O\n";
		exit(1);
	}
	
	fread(&reg,sizeof(Banco),1,archB);
	while(!feof(archB))
	{
		if(strcmp(reg.nombre,nomBuscar)==0 && reg.status)
		{
			numCteAux = reg.numCte;
			reg = capturaDatos();
			reg.numCte = numCteAux;
			
			posi=ftell(archB)-sizeof(Banco);
			fseek(archB,posi,SEEK_SET);
			fwrite(&reg,sizeof(Banco),1,archB);
			ban=true;
			break;
		}
		fread(&reg,sizeof(Banco),1,archB);
	}
	
	fclose(archB);
	
	if(!ban)
	{
		cout<<"El cliente no existe\n";
	}
}
