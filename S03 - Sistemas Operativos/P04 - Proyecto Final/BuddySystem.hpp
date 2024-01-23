#ifndef BuddySystem_hpp
#define BuddySystem_hpp

void mostrarMem(NodoMem* raiz)//Muestra los espacios de memoria (recursivo)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	if(raiz!=NULL)
	{
		if(raiz->der==NULL&&raiz->izq==NULL)
		{
			

			if(raiz->pro==NULL)
			{		
				cout<<"[0,"<<raiz->tam<<",0]";
			}else{
				if(asing && nuevoPros == raiz->pro)
				{
					SetConsoleTextAttribute(h,178);
					cout<<"["<<raiz->pro->id<<","<<raiz->pro->tam<<"("<<raiz->tam<<"),"<<raiz->pro->cuanto<<"]";
					SetConsoleTextAttribute(h,176);
				}else if(evalua && exe->ant == raiz->pro)
				{
					SetConsoleTextAttribute(h,189);
					cout<<"["<<raiz->pro->id<<","<<raiz->pro->tam<<"("<<raiz->tam<<"),"<<raiz->pro->cuanto<<"]";
					SetConsoleTextAttribute(h,176);
				}else{
					cout<<"["<<raiz->pro->id<<","<<raiz->pro->tam<<"("<<raiz->tam<<"),"<<raiz->pro->cuanto<<"]";
				}
			}
		}
		mostrarMem(raiz->izq);
		mostrarMem(raiz->der);
	}
	
}

Proceso* buddySystem(NodoMem* raiz,Proceso* pross)//Ejecuta las diferentes actividades de Buddy System
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	NodoMem* auxL,* auxD;
	condens = false;
	//Primero se particiona la memoria
	//se buscan los procesos con inside==false para meterlos a la memoria (mem.tam)/2 < pros.tam
	

	raiz = creaParticiones(raiz,pross->ant);

	if (asing)
	{
		gotoxy(2,10);
		cout<<"Memoria:";
		gotoxy(4,11);
		mostrarMem(raiz);
		nuevoPros = NULL;

		if(generaPros(pross) == 1)//sólo un proceso está en espera
		{
			pross=agregaPro(pross,idPros++);
		}
		
		asing = false;
	}
	
	gotoxy(2,13);
	cout<<"Procesos:";
	gotoxy(4,14);
	mostrarPros(pross);

	//luego se ejecuta el proceso

	estadisticasMemoria(pross);
	
	pross = roundRobin(pross,raiz);

	evalua = false;

	//pross = ejecutaPros(pross);
	
	//luego condensa la memoria de los huecos contiguos
	for(int i=0;i<NIVEL;i++)//for que recorre los diferentes niveles del arbol para condensarlo
	{
		unirParticiones(raiz->izq);
		unirParticiones(raiz->der);
	
		auxD = raiz->der;
		auxL = raiz->izq;
		if(auxD!=NULL && auxL!=NULL)
		{
			if((auxD->pro == NULL && auxL->pro == NULL) && (auxL->izq == NULL && auxL->der == NULL) && (auxD->izq == NULL && auxD->der == NULL))
			{
				eliminaMem(auxL);
				eliminaMem(auxD);
				raiz->der = NULL;
				raiz->izq = NULL;
				condens = true;
			}
		}
	}

	if(condens)
	{
		gotoxy(2,21);
		SetConsoleTextAttribute(h,180);
		cout<<"Condensando . . .";
		SetConsoleTextAttribute(h,176);
	}

	return (pross);
}

NodoMem* creaParticiones(NodoMem* raiz,Proceso* pross)//Busca en donde poner el proceso en la memoria, se apoya de asigna()
{
	Proceso* auxP;
	NodoMem* auxM;
	auxP = pross;
	
	if(auxP->inside == false)
	{
		auxM = raiz;
		asignaMem(auxM,auxP);
	}
	
	auxP = auxP->ant;

	while(auxP != pross)
	{
		if(auxP->inside == false)
		{
			auxM = raiz;
			asignaMem(auxM,auxP);
		}
		
		auxP = auxP->ant;
	}
	
	return raiz;
}

void unirParticiones(NodoMem* nodo)//Condensa los huecos consiguos de memoria
{
	NodoMem* auxL,* auxD;
	if(nodo!=NULL)
	{
		if((nodo->pro == NULL))
		{
			if ((nodo->der != NULL) && (nodo->izq != NULL))
			{
				auxL = nodo->izq;
				auxD = nodo->der;
				if((auxD->pro == NULL && auxL->pro == NULL) && (auxL->izq == NULL && auxL->der == NULL) && (auxD->izq == NULL && auxD->der == NULL))
				{
					eliminaMem(auxL);
					eliminaMem(auxD);
				
					nodo->izq = NULL;
					nodo->der = NULL;
					condens = true;
				}
			}
			unirParticiones(nodo->izq);
			unirParticiones(nodo->der);
		}
	}
}

void asignaMem(NodoMem* nodo, Proceso* pros)//Asigna los procesos en la memoria correspondiente
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	NodoMem* auxL,* auxD;
	if(pros->inside==false)
	{
		if((nodo->pro == NULL))
		{
			if(((nodo->tam/2 < pros->tam) || (nodo->tam == 32)))
			{
				if ((nodo->der == NULL) && (nodo->izq == NULL))
				{
					nodo->pro = pros;
					pros->asing = nodo;
					pros->inside = true;
					asing = true;
					gotoxy(2,8);
					cout<<"En memoria"; 
					SetConsoleTextAttribute(h,178);
					cout<<"["<<pros->id<<","<<pros->tam<<","<<pros->cuanto<<"]";
					SetConsoleTextAttribute(h,176);
				}	
			}else{
				if((nodo->der == NULL) && (nodo->izq == NULL) && (nodo->tam != 32))
				{
					auxL = creaMem();
					auxD = creaMem();
				
					auxL->der = NULL;
					auxL->izq = NULL;
					auxL->pro = NULL;
					auxL->tam = nodo->tam/2;
				
					auxD->der = NULL;
					auxD->izq = NULL;
					auxD->pro = NULL;
					auxD->tam = nodo->tam/2;
				
					nodo->izq = auxL;
					nodo->der = auxD;
				}
				asignaMem(nodo->izq,pros);
				asignaMem(nodo->der,pros);
			}
		}
	}
}

#endif