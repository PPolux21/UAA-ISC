#ifndef RoundRobin_hpp
#define RoundRobin_hpp

void mostrarPros(Proceso* pross)//Muestra los procesos (recursivo)
{
    if(pross == NULL)
    {
        cout << "Cola de procesos vacia"<< endl;
    }else{
        Proceso* aux;
        aux = pross;

        cout<<"["<<aux->id <<","<< aux->tam<<","<<aux->cuanto ;

		if(aux->inside)
		{
			cout<<",LISTO";
		}else{
			cout<<",ESPERA";
		}

		cout<<"]";

		aux = aux->sig;

        while(aux != pross)
        {
            cout<<"["<<aux->id <<","<< aux->tam<<","<<aux->cuanto ;

            if(aux->inside)
            {
                cout<<",LISTO";
            }else{
                cout<<",ESPERA";
            }

            cout<<"]";

            aux = aux->sig;
        }
    }
}

void mostrarCola()
{
    if(exe == NULL)
    {
        cout << "Cola de procesos vacia"<< endl;
    }else{
        Proceso* aux;
        aux = exe;

		if(aux->inside)
		{
            cout<<"["<<aux->id <<","<< aux->tam<<","<<aux->cuanto<<"]";
		}

		aux = aux->sig;

        while(aux != exe)
        {

            if(aux->inside)
            {
                cout<<"["<<aux->id <<","<< aux->tam<<","<<aux->cuanto<<"]";
            }

            aux = aux->sig;
        }
    }
}

int cuentaPros(Proceso* pross)
{
    int cant=0;

    if(pross == NULL)
    {
        return 1;
    }else{
        Proceso* aux;

        aux = pross;
        cant++;
        aux = aux->sig;

        while(aux != pross)
        {
            cant++;
            aux = aux->sig;
        }
    }

    return cant;
}

int generaPros(Proceso* pross)//determina si hay un proceso que no está en memoria
{

    if(pross == NULL)
    {
        return 1;
    }else{
        Proceso* aux;

        aux = pross;
        if(aux->inside == false)
        {
            return 0;
        }
        aux = aux->sig;

        while(aux != pross)
        {
            if(aux->inside == false)
            {
                return 0;
            }
            aux = aux->sig;
        }
    }

    return 1;
}

Proceso* agregaPro(Proceso* pross,int i)//Genera los procesos nuevos y los concatena en la lista de procesos
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	Proceso* aux,* nuevo;
	if(pross == NULL)
	{
		pross = creaPro();
		
		nuevo = pross;
		
        nuevo->ant = pross;
		nuevo->sig = pross;
		nuevo->id = i;
		nuevo->inside = false;
		nuevo->asing = NULL;
	}else{
		aux = pross;
	
		while(aux->sig != pross)
		{
			aux = aux->sig;
		}
	
		nuevo = creaPro();
		aux->sig = nuevo;
        nuevo->ant = aux;
		nuevo->sig = pross;
        pross->ant = nuevo;
		nuevo->id = i;
		nuevo->inside = false;
		nuevo->asing = NULL;
        pross = nuevo;
	}

	nuevo->tam = (rand()%maxTamProceso) + 1;
	nuevo->cuanto = (rand()% maxCuantoProceso) + 1;
    nuevoPros = nuevo;
    gotoxy(2,7);
    cout << "Entra ";
    SetConsoleTextAttribute(h,178);
    cout<<"["<<nuevo->id <<","<< nuevo->tam<<","<<nuevo->cuanto <<"]";
    SetConsoleTextAttribute(h,176);
	
	return pross;
}

Proceso* roundRobin(Proceso* pross,NodoMem* raiz)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    Proceso* aux;

    if(pross == NULL)
    {
        cout << "Cola de procesos vacía"<< endl;
        exe = NULL;
    }
    else
    {
        Proceso* ancla,* elimina;
        NodoMem* ref;//referencia al espacio que ocupa en el arbol
        
        if(exe == NULL)
        {
            exe = pross;
        }

        if(exe->inside)
        {
            gotoxy(2,16);
            SetConsoleTextAttribute(h,189);
            cout << "Atendiendo [" << exe->id << "," << exe->tam << ","<< exe->cuanto<<"]";
            SetConsoleTextAttribute(h,176);
            exe->cuanto -= cuantoSistema;
            evalua = true;
            
            ejecucion_procesos++;

            if (exe->cuanto <= 0)
            {//Entra cuando el proceso termina
                procesos_terminados++;
                evalua = false;
                if(exe->sig == exe) // Caso 1: Solo hay un elemento
                {
                    ref = exe->asing;
                    ref->pro = NULL;
                    eliminaPro(exe);
                    exe = NULL;
                    pross = NULL;
                }else{// Caso 2: Cuando hay más de un elemento
                
                    elimina = exe; // Auxiliar para eliminar
                
                    ancla = exe->ant;// Auxiliar para antes del proceso eliminado
                    aux = exe->sig;// Auxiliar para despues del proceso terminado

                    ancla->sig = aux;
                    aux->ant = ancla;

                    exe = exe->sig;//avanza al siguiente proceso

                    if(pross == elimina)// si el proceso a aliminar el la cabecera de la lista
                    {
                        pross = pross->sig;
                    }
                    
                    gotoxy(2,17);
                    SetConsoleTextAttribute(h,180);
                    cout <<"Descargando ["<< elimina->id << "," << elimina->tam << ","<< elimina->cuanto<<"]";
                    SetConsoleTextAttribute(h,176);

                    ref = elimina->asing;// elimina la referencia al espacio en memoria
                    ref->pro = NULL;
                    eliminaPro(elimina);
                }
            }else{
                if(exe != NULL)
                {
                    exe = exe->sig;
                }
            }
            gotoxy(2,19);
            cout<<"Memoria:";
            gotoxy(4,20);
            mostrarMem(raiz);
        }else{
            exe = exe->sig;
        }
    }
    if(exe!= NULL)
    {
        aux = exe;
        while(aux->inside == false)
        {
            if(aux->sig == exe)
            {
                break;
            }
            aux = aux->sig;
        }
        exe = aux;

    }
    
    return (pross);
}


#endif