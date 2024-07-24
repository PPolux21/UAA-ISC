//Arbol Binario de Busqueda

#include <iostream>

using namespace std;

struct TNodo
{
	int info;
	TNodo *izq,*der;
};

TNodo *crea();
void quita(TNodo*);

TNodo *creaArbol(TNodo*);
void preorden(TNodo*);
void inorden(TNodo*);
void postorden(TNodo*);
void buscar(TNodo*,int);

void insercion(TNodo*,int);
void eliminacion(TNodo*,int);

//main
int main()
{
	int opc,num;
	TNodo *raiz=crea();
	do
	{
		system("cls");
		cout<<"\tMENU"<<endl;
		cout<<"Crea Arbol  - - - - 1"<<endl;
		cout<<"Mostrar Preorden  - 2"<<endl;
		cout<<"Mostrar Inorden - - 3"<<endl;
		cout<<"Mostrar Postorden - 4"<<endl;
		cout<<"Busca Elemento  - - 5"<<endl;
		cout<<"Salir - - - - - - - 8"<<endl;
		cout<<endl<<"Opcion: ";
		cin>>opc;
		switch(opc)
		{
			case 1:
				raiz=creaArbol(raiz);
				system("pause");
				break;
			case 2:
				preorden(raiz);
				cout<<endl;
				system("pause");
				break;
			case 3:
				inorden(raiz);
				cout<<endl;
				system("pause");
				break;
			case 4:
				postorden(raiz);
				cout<<endl;
				system("pause");
				break;
			case 5:
				cout<<"Dato a buscar: ";
				cin>>num;
				buscar(raiz,num);
				system("pause");
				break;
			case 8:
				break;
			default:
				cout<<"Opcion no valida"<<endl;
				system("pause");
				break;
		}
	}while(opc!=8);
}

//funciones
TNodo *crea()
{
	return (new TNodo);
}

void quita(TNodo *aux)
{
	delete aux;
}

TNodo *creaArbol(TNodo *raiz)
{
	int dato,resp;
	TNodo *otro=NULL;
	cout<<endl<<"Dame dato para el arbol: ";
	cin>>dato;
	raiz->info=dato;
	
	cout<<endl<<"\tExiste nodo por la IZQUIERDA de "<<raiz->info<<"? (1=si) ";
	cin>>resp;
	if(resp==1)
	{
		otro=crea();
		raiz->izq=otro;
		creaArbol(raiz->izq);
	}else{
		raiz->izq=NULL;
	}
	
	cout<<endl<<"\tExiste nodo por la DERECHA de "<<raiz->info<<"? (1=si)";
	cin>>resp;
	if(resp==1)
	{
		otro=crea();
		raiz->der=otro;
		creaArbol(raiz->der);
	}else{
		raiz->der=NULL;
	}
	
	return (raiz);
}

void preorden(TNodo *raiz)
{
	//raiz-izq-der
	if(raiz!=NULL)
	{
		cout<<"{"<<raiz->info<<"}";
		preorden(raiz->izq);
		preorden(raiz->der);
	}
}

void inorden(TNodo *raiz)
{
	//izq-raiz-der
	if(raiz!=NULL)
	{
		inorden(raiz->izq);
		cout<<"{"<<raiz->info<<"}";
		inorden(raiz->der);
	}
}

void postorden(TNodo *raiz)
{
	//izq-der-raiz
	if(raiz!=NULL)
	{
		postorden(raiz->izq);
		postorden(raiz->der);
		cout<<"{"<<raiz->info<<"}";
	}
}

void buscar(TNodo *raiz,int dato)
{
	if(raiz!=NULL)
	{
		if(dato<raiz->info)
		{
			buscar(raiz->izq,dato);
		}else{
			if(dato>raiz->info)
			{
				buscar(raiz->der,dato);
			}else{
				cout<<endl<<"Dato encontrado"<<endl<<endl;
			}
		}
	}else{
		cout<<endl<<"Dato no encontrado"<<endl<<endl;
	}
}