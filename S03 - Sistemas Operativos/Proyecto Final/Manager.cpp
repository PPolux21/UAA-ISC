
//Planificador RR y BS

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <locale.h>
#include <conio.h>
#include <windows.h>
#include "Manager.hpp"
#include "interfazConfiguracion.hpp"
#include "BuddySystem.hpp"
#include "RoundRobin.hpp"

//
//  MAIN
//

int main()
{
//    setlocale(LC_ALL,"");
	srand(time(NULL));	

    interfazConfiguracion();

    auto start = chrono::high_resolution_clock::now();

    simulador();

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    tiempo_total_simulacion = duration.count();
    estadisticas();

	return 0;
}

//
//	DEFINICION DE FUNCIONES
//

void simulador()
{
    Proceso* pross=NULL;
	NodoMem* raiz=creaMem();//cabecera del arbol
	raiz->der=NULL;
	raiz->izq=NULL;
	raiz->pro=NULL;
	raiz->tam=TAM;
	
    bool flag=true;
	char key='0';
	float vel=1;

    do
	{
        Sleep(1000*vel);//modificador de tiempo entre pantallas

		system("cls");
        cuadro(1,1,109,3);
        
        gotoxy(50,2); 
        cout << "Simulador";


        gotoxy(2,4);
		cout<<"Memoria:"<<endl;
        gotoxy(4,5);
		mostrarMem(raiz);

		
		if(generaPros(pross) == 1)//sólo un proceso está en espera
		{
			pross=agregaPro(pross,idPros++);
		}

        
		
		pross = buddySystem(raiz,pross);

        gotoxy(2,23);
		cout<<"Cola de procesos:"<<endl;
        gotoxy(4,24);
		mostrarCola();

		if (_kbhit()) //detecta el input de una tecla
		{
            // Obtiene la tecla presionada
            key = _getch();

            if (key == 'S' || key == 's' || key == (char)27) //si la tecla se presiona es p sale de ejecucion
			{
				cout << endl;
                flag = false;
                key = '0';
            }

            if (key == '+' || key == (char)77) //si es + aumenta la velocidad disminuyendo el valor de vel
			{
                if(vel >= 0.0625)
                {
                    vel /= 2;
                }
                key = '0';
            }

            if (key == '-' || key == (char)75) //si es - disminuye la velocidad aumentando el valor de vel
			{
                if(vel <= 16)
                {
                    vel *= 2;
                }
                key = '0';
            }
            
        }

        muestraVelocidad(vel);

	}while(flag);

	eliminaInfP(pross);
	eliminaInfM(raiz);
}

void muestraVelocidad(float vel)
{
    int aux = vel * 100000;
    
    cout << endl << endl ;
        gotoxy(42,26);
    switch (aux)
    {
    case 3200000:
        cout << "-  I o o o o o o o o o o  +" <<endl;
        break;
    case 1600000:
        cout << "-  o I o o o o o o o o o  +" <<endl;
        break;
    case 800000:
        cout << "-  o o I o o o o o o o o  +" <<endl;
        break;
    case 400000:
        cout << "-  o o o I o o o o o o o  +" <<endl;
        break;
    case 200000:
        cout << "-  o o o o I o o o o o o  +" <<endl;
        break;
    case 100000:
        cout << "-  o o o o o I o o o o o  +" <<endl;
        break;
    case 50000:
        cout << "-  o o o o o o I o o o o  +" <<endl;
        break;
    case 25000:
        cout << "-  o o o o o o o I o o o  +" <<endl;
        break;
    case 12500:
        cout << "-  o o o o o o o o I o o  +" <<endl;
        break;
    case 6250:
        cout << "-  o o o o o o o o o I o  +" <<endl;
        break;
    case 3125:
        cout << "-  o o o o o o o o o o I  +" <<endl;
        break;
    default:
        break;
    }
    gotoxy(51,27);
    cout << "VELOCIDAD"<<endl;
    gotoxy(52,28);
    cout <<vel*1000<<" ms"<<endl;
}

void estadisticas()
{
    int key = 0;
    procesos_ejecutados_por_segundo = ejecucion_procesos / tiempo_total_simulacion;
    promedio_memoria_utilizada = (promedio_memoria_utilizada / (ejecucion_procesos*TAM)) * 100;

    system("cls");
    cuadro(1,1,109,3);
    
    gotoxy(48,2); 
    cout << "Estadisticas";

    gotoxy(3,5); 
    cout << "Ejecucion de procesos: " << ejecucion_procesos << endl;
    gotoxy(3,7); 
    cout << "Procesos terminados: " << procesos_terminados << endl;
    gotoxy(3,9); 
    cout << "Total de procesos generados: "<< idPros-1 << endl;
    gotoxy(3,11); 
    cout << "Procesos ejecutados por segundo: " << procesos_ejecutados_por_segundo << endl;
    gotoxy(3,13); 
    cout << "Promedio de memoria utilizada: " << promedio_memoria_utilizada << "%" << endl;
    gotoxy(3,15); 
    cout << "Memoria maxima del proceso solicitada: " << memoria_maxima_proceso << endl;
    gotoxy(3,17); 
    cout << "Memoria minima del proceso solicitada: " << memoria_minima_proceso << endl;
    gotoxy(3,19); 
    cout << "Tiempo total de simulacion: " << tiempo_total_simulacion << endl;

    gotoxy(49,22);
	cout << "Finalizar";
    cuadro(46, 21, 61, 23);

    while(true)
    {
        if (_kbhit()) //detecta el input de una tecla
		{
            // Obtiene la tecla presionada
            key = _getch();

            if(key == 13)
            {
                exit(0);
            }
        }
        Sleep(100); // Pequeño retraso para evitar altos consumos de CPU
    }

}

void estadisticasMemoria(Proceso* pross)
{
    if(pross != NULL)
    {
        Proceso* aux;
        aux = pross;

		if(aux->inside)
		{
            promedio_memoria_utilizada += aux->tam;

            if (memoria_maxima_proceso < aux->tam)
            {
                memoria_maxima_proceso = aux->tam;
            }
            if(memoria_minima_proceso > aux->tam)
            {
                memoria_minima_proceso = aux->tam;
            }
            
		}

		aux = aux->sig;

        while(aux != pross)
        {

            if(aux->inside)
            {
                promedio_memoria_utilizada += aux->tam;
                if (memoria_maxima_proceso < aux->tam)
                {
                    memoria_maxima_proceso = aux->tam;
                }
                if(memoria_minima_proceso > aux->tam)
                {
                    memoria_minima_proceso = aux->tam;
                }
            }

            aux = aux->sig;
        }
    }
}

Proceso* creaPro()//Crea dinámicamente procesos
{
	return (new Proceso);
}

NodoMem* creaMem()//Crea dinámicamente memoria
{
	return (new NodoMem);
}

void eliminaPro(Proceso* aux)//Elimina un proceso
{
	delete aux;
}

void eliminaMem(NodoMem* aux)//Elimina un espacio de memoria
{
	delete aux;
}

void eliminaInfP(Proceso* pross)//Elimina todos los procesos 
{
    Proceso* aux;
    int cant = cuentaPros(pross);
	for(int i = 0; i < cant; i++)
	{
        aux = pross->sig;
        eliminaPro(pross);
        pross = aux;
	}
}

void eliminaInfM(NodoMem* raiz)//Elimina toda la mamoria 
{
	if(raiz!=NULL)
	{
		eliminaInfM(raiz->izq);
		eliminaInfM(raiz->der);
		eliminaMem(raiz);
	}
}