// Listas ligadas

#include <iostream>

using namespace std;

struct TNodo{
	int info;
	TNodo *liga;
};

TNodo *crea();
void quita(TNodo *);

TNodo *insertaInicio(TNodo *, int);
TNodo *insertaFinal(TNodo *, int);
TNodo *insertaAntes(TNodo *, int, int);
TNodo *insertaDespues(TNodo *, int, int);

void recorre(TNodo *);

TNodo *eliminaInicio(TNodo *);
TNodo *eliminaFinal(TNodo *);
TNodo *eliminaReferencia(TNodo *,int);
TNodo *eliminaAntes(TNodo *, int);
TNodo *eliminaDespues(TNodo *, int);

/*
Pilas:
	Inserta Inicio
	Elimina Inicio
Colas:
	Inserta Final
	Elimina Inicio
*/

int main()
{
	int opc,dato;
	TNodo *p=NULL;
	
	do
	{
		system("cls");
		cout<<"\tMenu"<<endl;
		cout<<"Inserta Inicio                         1"<<endl;
		cout<<"Inserta Final                          2"<<endl;
		cout<<"Inserta antes de referencia            3"<<endl;
		cout<<"Inserta despues de referencia          4"<<endl;
		cout<<"Mostrar                                5"<<endl;
		cout<<"Elimina Primero                        6"<<endl;
		cout<<"Elimina Final                          7"<<endl;
		cout<<"Elimina nodo con información x         8"<<endl;
		cout<<"Elimina nodo antes de referencia       9"<<endl;
		cout<<"Elimina nodo despues de referencia    10"<<endl;
		cout<<"Salir                                 11"<<endl;
		cout<<"\nOpcion: ";
		cin>>opc;
		
		switch(opc)
		{
			case 1:
				cout<<"Dato a insertar: ";
				cin>>dato;
				p=insertaInicio(p,dato);
				cout<<endl<<"dato insertado"<<endl;
				system("pause");
				break;
			case 2:
				cout<<"Dato a insertar: ";
				cin>>dato;
				p=insertaFinal(p,dato);
				cout<<endl<<"dato insertado"<<endl;
				system("pause");
				break;
			case 3:
				system("pause");
				break;
			case 4:
				system("pause");
				break;
			case 5:
				cout<<"Datos de la lista"<<endl;
				recorre(p);
				cout<<endl;
				system("pause");
				break;
			case 6:
				system("pause");
				break;
			case 7:
				system("pause");
				break;
			case 8:
				cout<<"Dato a aliminar: ";
				cin>>dato;
				p=eliminaReferencia(p,dato);
				system("pause");
				break;
			case 9:
				system("pause");
				break;
			case 10:
				system("pause");
				break;
			case 11:
				break;
			default:
				cout<<"Opcion no valida"<<endl;
				system("pause");
		}
		
	}while(opc!=11);
	
	return 0;
}

//funciones

TNodo *crea()
{
	TNodo *aux=NULL;
	aux = new TNodo;
	return (aux);
	//return (new TNodo); // también se puede usar
}

void quita(TNodo *aux)
{
	delete aux;
}

TNodo *insertaInicio(TNodo *p, int dato)
{
	TNodo *q=NULL;
	if(p==NULL)
	{
		p=crea();
		p->info=dato;
		p->liga=NULL;
	}else{
		q=crea();
		q->info=dato;
		q->liga=p;
		p=q;
	}
	return (p);
}

TNodo *insertaFinal(TNodo *p, int dato)
{
	TNodo *t=NULL,*q=NULL;
	if(p==NULL)
	{
		p=crea();
		p->info=dato;
		p->liga=NULL;
	}else{
		q=crea();
		q->info=dato;
		q->liga=NULL;
		t=p;
		while(t->liga!=NULL)
			t=t->liga;
		t->liga=q;
	}
	return (p);
}

TNodo *insertaAntes(TNodo *p, int dato, int ref)
{
	TNodo *t=p,*r=NULL,*q=NULL;
	if(p==NULL)
	{
		cout<<"Lista vacia"<<endl;
	}else{
		while(t->liga!=NULL && t->info!=ref)
		{
			r=t;
			t=t->liga;
		}
		if(t->info==ref)
		{
			if(t=p)
			{
				q=crea();
				q->info=dato;
				q->liga=t;
				p=q;
			}
			else
			{
				q=crea();
				q->info=dato;
				q->liga=t;
				r->liga=q;
			}
		}
		else
		{
			cout<<"Referencia no encontrada"<<endl;
		}
	}
	return (p);
}

TNodo *insertaDespues(TNodo *p, int dato, int ref)
{
	
}


void recorre(TNodo *p)
{
	TNodo *t=NULL;
	if(p==NULL)
	{
		cout<<"Lista vacía"<<endl;
	}else{
		t=p;
		do{
			cout<<"["<<t->info<<"]";
			t=t->liga;
		}while(t!=NULL);
	}
}

TNodo *eliminaReferencia(TNodo *p,int ref)
{
	TNodo *q=p,*t;
	bool ban=true;
	if(p==NULL)
	{
		cout<<"Lista vacía"<<endl;
	}else{
		while(q->info!=ref && ban)
		{
			if(q->liga==NULL)
			{
				ban=false;
			}else{
				t=q;
				q=q->liga;
			}
		}
		
		if(!ban)
		{
			cout<<"Referencia no encontrada, nodo no eliminado"<<endl;
		}else{
			if(p==q)
			{
				p=p->liga;
			}else{
				t->liga=q->liga;
			}
			quita(q);
		}
	}
	return (p);
}
