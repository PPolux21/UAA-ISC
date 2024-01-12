//Listas doblemente ligadas

#include <iostream>

using namespace std;

struct TNodo{
	int info;
	TNodo *izq,*der;
};

TNodo* crea();
void quita(TNodo *aux);
//inserta
TNodo* insertaInicio(TNodo *p, int dato);
TNodo* insertaFinal(TNodo *p, int dato);
TNodo * insertaAntes(TNodo *p, int dato,int ref);
TNodo * insertaDespues(TNodo *p, int dato,int ref);

//Elimina
TNodo *eliminaInicio(TNodo *p);
TNodo *eliminaFinal(TNodo *p);
TNodo *eliminaAntes(TNodo *p,int ref);
TNodo *eliminaDespues(TNodo *p,int ref);
TNodo *eliminaReferencia(TNodo *p,int ref);

void recorre(TNodo *p);
TNodo *buscar(TNodo *p);

int main(){
	int op,dato,ref;
	TNodo *p=NULL;
	do{
		system("cls");
		cout<<"1...Inserta al inicio"<<endl;
		cout<<"2...Inserta al final"<<endl;
		cout<<"3...Inserta antes de una referencia"<<endl;
		cout<<"4...Inserta despues de una referencia"<<endl;
		cout<<"5...Recorre la lista"<<endl;
		cout<<"6...Elimina primero"<<endl;
		cout<<"7...Elimina final"<<endl;
		cout<<"8...Elimina nodo con informacion x"<<endl;
		cout<<"9...Elimina nodo antes de una referencia"<<endl;
		cout<<"10...Elimina nodo despues de una referencia"<<endl;
		cout<<"11...Busca un dato en la lista"<<endl;
		cout<<"12...Salir"<<endl;
		cout<<"Selecciona tu opcion: ";
		cin>>op;
		switch(op){
			case 1:
				cout<<"Dato a insertar: ";
				cin>>dato;
				p=insertaInicio(p,f,dato);
				cout<<endl<<"Dato insertado"<<endl;
				system("pause");
				break;
			case 2:
				cout<<"Dato a insertar: ";
				cin>>dato;
				p=insertaFinal(p,dato);
				cout<<endl<<"Dato insertado"<<endl;
				system("pause");
				break;
			case 3:
				cout<<"Dato a insertar: ";
				cin>>dato;
				cout<<"Antes de cual referencia: ";
				cin>>ref;
				p=insertaAntes(p,dato,ref);
				system("pause");
				break;
			case 4:
				break;
			case 5:
				cout<<endl<<"Datos de la lista"<<endl;
				recorre(p);
				cout<<endl;
				system("pause");
				break;
			case 6:
				p=eliminaInicio(p);
				system("pause");
				break;
			case 7:
				p=eliminaFinal(p);
				system("pause");
				break;
			case 8:
				cout<<"cual referencia: ";
				cin>>ref;
				p=eliminaReferencia(p,ref);
				system("pause");
				break;
			case 9:
				cout<<"Antes de cual referencia: ";
				cin>>ref;
				p=eliminaAntes(p,ref);
				system("pause");
				break;
			case 10:
				break;
			case 11:
				break;
			default:
				break;	
		}
		
	}while(op!=12);
}

TNodo* crea()
{
	return (new TNodo);
}

void quita(TNodo *aux)
{
	delete aux;
}

//inserta
TNodo* insertaInicio(TNodo *p, int dato)
{
	TNodo *q=NULL;
	
	if(p==NULL)
	{
		p=crea();
		p->info = dato;
		p->der = NULL;
		p->izq = NULL;
	}else{
		q=crea();
		q->info = dato;
		q->izq = NULL;
		q->der = p;
		p->izq = q;
		p = q;
	}
	return p;
}

TNodo* insertaFinal(TNodo *p, int dato)
{
	
}

TNodo * insertaAntes(TNodo *p, int dato,int ref)
{
	TNodo *q=p,*t=NULL,*r=NULL;	//"q" busca la referencia, "t" es el nuevo nodo, "r" es el nodo anterior a la referencia
	
	if(p==NULL)
	{
		cout<<"Lista vacía"<<endl;
	}else{
		while(q->der != NULL && q->info != ref)
			q = q->der;
			
		if(q->info == ref)
		{
			r = q->izq;
			
			t=crea();
			t->info = dato;
			
			t->der = q;
			q->izq = t;
			
			if(q==p)
			{
				p=t;
				t->izq = NULL;
			}else{
				r->der = t;
				t->izq = r;
			}
			
		}else
		{
			cout<<"Refeencia no encoantrada, nodo no insertado D:"<<endl;
		}
	}
	return p;
}

TNodo * insertaDespues(TNodo *p, int dato,int ref)
{
	
}

//Elimina
TNodo *eliminaInicio(TNodo *p)
{
	TNodo *t=p;
	
	if(p==NULL)
	{
		cout<<"Lista vacia, no hay nodo a eliminar";
	}else{
		if(t->der!=NULL)
		{
			p=p->der;
			p->izq=NULL;	
		}
		quita(t);
		cout<<"\n\t- Nodo eliminado -"<<endl;
	}
	
	return p;
}

TNodo *eliminaFinal(TNodo *p)
{
	TNodo *t=p, *r;
	
	if(p==NULL)
	{
		cout<<"Lista vacia, no hay nodo a eliminar";
	}else{
		while(t->der!=NULL)
			t=t->der;
			
		if(t->izq!=NULL)
		{
			r=t->izq;
			r->der=NULL;
		}
		quita(t);
		cout<<"\n\t- Nodo eliminado -"<<endl;
	}
	
	return p;
}

TNodo *eliminaAntes(TNodo *p,int ref)
{
	
}

TNodo *eliminaDespues(TNodo *p,int ref)
{
	
}

TNodo *eliminaReferencia(TNodo *p,int ref)
{
	
}


void recorre(TNodo *p)
{
	TNodo *q=p;
	if(q==NULL)
	{
		cout<<"Lista vacia"<<endl;
	}else{
		do
		{
			cout<<" ["<<q->info<<"] ";
			q = q->der;
		}while(q->der==NULL);
	}
}

TNodo *buscar(TNodo *p)
{
	
}
