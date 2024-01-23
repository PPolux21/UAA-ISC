#ifndef Manager_hpp
#define Manager_hpp

using namespace std;

//
//  Declaracion de Estructuras
//

//definicion adelantada para evitar errores
struct Proceso;
struct NodoMem;

struct Proceso//procesos entrantes en memoria
{
	Proceso* ant;	// apuntador al anterior elemento de la lista (lista ligada)
	int id;			// id del proceso
	int tam;		// tamaño en memoria del proceso
	int cuanto;		// cuanto de procesamiento del proceso
	bool inside;	// boleano que determina si está adentro de la mamoria
	Proceso* sig;	// apuntador al siguiente elemento de la lista (lista ligada)
	NodoMem* asing;	// apuntador al espacio de memoria en el que se almacena
};

struct NodoMem//arbol de memorias divididas
{
	NodoMem* der;	// hijo derecho del arbol
	Proceso* pro;	// apuntador al proceso asignado en el espacio de memoria
	int tam;		// tamaño de memoria de la particion
	NodoMem* izq;	// hijo izquirdo del arbol
};

//
//	DECLARACION DE FUNCIONES
//

//en Manager.cpp
void simulador();
void muestraVelocidad(float);
void estadisticas();
void estadisticasMemoria(Proceso*);

Proceso* creaPro();
NodoMem* creaMem();

void eliminaPro(Proceso*);
void eliminaMem(NodoMem*);

void eliminaInfP(Proceso*);
void eliminaInfM(NodoMem*);

//en BuddySystem.hpp
void mostrarMem(NodoMem*);

Proceso* buddySystem(NodoMem*,Proceso*);
NodoMem* creaParticiones(NodoMem*,Proceso*);
void unirParticiones(NodoMem*);
void asignaMem(NodoMem*,Proceso*);

//en RoundRobin.hpp
void mostrarPros(Proceso*);
void mostrarCola();
int cuentaPros(Proceso*);
int generaPros(Proceso*);
Proceso* agregaPro(Proceso*,int);

Proceso* roundRobin(Proceso*,NodoMem*);

//en interfazConfiguracion.hpp
void interfazConfiguracion();
void tipoEscenario(int,bool);
void gotoxy(int x, int y);
void cuadro(int x1,int y1,int x2,int y2);

//
//  Constantes y variables globales
//

/*
Tamaños (TAM):
	8192	Nodos maximos de 32Kb(256)		Niveles 10
	4096	Nodos maximos de 32Kb(128)		Niveles 8
	1024	Nodos maximos de 32Kb(32)		Niveles 6
*/

#define TAM 1024
#define NIVEL 6// depende del tamaño maximo de memoria (TAM)

int maxTamProceso = 0;
int maxCuantoProceso = 0;
int cuantoSistema = 0;
int idPros = 1;//Contador para los Id de los procesos
bool condens;//para indicar cuando se condensa la memoria
bool asing;//para indicar si un procesos se asignó en memoria
bool evalua = false;
Proceso* exe = NULL;//puntero que indicará el proceso en ejecucion
Proceso* nuevoPros = NULL;
//controladores de estadisticas
int ejecucion_procesos = 0;//done
int procesos_terminados = 0;//done
double procesos_ejecutados_por_segundo = 0;//done
float promedio_memoria_utilizada = 0;//done
int memoria_maxima_proceso = 0;//done
int memoria_minima_proceso = TAM;//WIP
double tiempo_total_simulacion = 0;//done

#endif