/*
Tarea Unidad 1 - Colas
	José Luis Espinza Sánchez
	Reyli Uvaldo Martinez Hernandez 
*/

#include <iostream>

using namespace std;

struct Prioridad{
	int turno, priori;
};

void programa1();
void programa2();
void programa3();
void programa4();
void programa5();
//Programa1
void insertCol(int &tope,int max,char cola[], int pos);
void mostrarCola(char cola[], int tope, int pos);
void elimCola(char cola[], int &tope, int &pos);
bool colaVacia(int pos, char cola[]);
bool colaLlena(int max, int tope);
//programa2
void insertCol2(int &tope2,int max2,char cola2[], int pos2);
void mostrarCola2(char cola2[], int tope2, int pos2, int max2);
void elimCola2(char cola2[], int &tope2, int &pos2, int max2);
bool colaVacia2(int pos2, char cola2[]);
bool colaLlena2(int max2, int tope2);
//programa 3
void insertCol3(int &,int ,int [], int , int);
void elimCola3(int [], int &, int &, int);
void mostrarCola3(int [], int , int , int);
bool colaVacia3(int , int []);
//programa 4
void invertirCola(int tope, char cola[]);
//programa 5
void insertCol5(int &tope,int max,Prioridad cola[], int pos, Prioridad dat);
void elimCola5(Prioridad cola[], int &tope, int &pos, int max);
void mostrarCola5(Prioridad cola[], int tope, int pos, int max);
bool colaVacia5(int pos, Prioridad cola[]);

int main(){
	int opc=0;
	
	while(opc != 6){
		system("cls");
		cout << "\n-- MENU --\n";
		cout << "Programa 1........ 1\n";
		cout << "Programa 2........ 2\n";
		cout << "Programa 3........ 3\n";
		cout << "Programa 4........ 4\n";
		cout << "Programa 5........ 5\n";
		cout << "Salir ............ 6\n";
		cin >> opc;
		
		switch(opc){
			
			case 1:
				programa1();
			break;
			case 2:
				programa2();
			break;
			case 3:
				programa3();
			break;
			case 4:
				programa4();
			break;
			case 5:
				programa5();
			break;	
			
			
		}
		
	}
	
}


void programa1(){
	int opc=0;
	int tope=0;
	int pos=0;
	int max = 10;
	char cola[max];
	
	while(opc != 5){
		cout << endl;
		system("pause");
		system("cls");
		
		cout << "\n-- MENU --\n";
		cout << "Insertar en cola ........... 1\n";
		cout << "Eliminar en cola ........... 2\n";
		cout << "Cola vacia? ................ 3\n";
		cout << "Cola llena? ................ 4\n";
		cout << "Salir ...................... 5\n";
		cin >> opc;
		
		switch(opc){
			case 1:
				insertCol(tope, max, cola, pos);
			break;
			case 2:
				elimCola(cola, tope, pos);
			break;
			case 3:
				if(colaVacia(pos, cola)==true){
					cout << "La cola esta vacia!";
					
				}else{
					cout << "La cola no esta vacia!";
					
				}
			break;
			case 4:
				if(colaLlena(max, tope)==true){
					cout << "La cola esta llena!";
					
				}else{
					cout << "La cola no esta llena!";
					
				}
			break;	
			
		}
		
	}
	
}


void insertCol(int &tope,int max ,char cola[], int pos){
	char dat;
	
	cout << "Ingresa un dato a la cola: ";
	cin >> dat;
	
	if(colaLlena(max, tope)==true){
		cout << "La cola esta llena!";
		
	}else{
		cola[tope] = dat;
		tope++;
		
	}
	
	mostrarCola(cola, tope, pos);
	
	
}


void mostrarCola(char cola[], int tope, int pos){
	for(int i=pos; i<tope; i++){
		cout << cola[i] << "\t";
		
	}
	
}


void elimCola(char cola[], int &tope, int &pos){
	
	if(colaVacia(pos, cola)==true){
		cout << "La cola esta vacia!";
		
	}else{
		cola[pos] = 0;
		pos++;
		
	}
	
	mostrarCola(cola, tope, pos);
	
}


bool colaVacia(int pos, char cola[]){
	if(cola[pos]=='\0'){
		return(true);
		
	}else{
		return(false);
		
	}
	
}



bool colaLlena(int max, int tope){
	if(tope == max){
		return(true);
		
	}else{
		return(false);
		
	}
	
}



void programa2(){
	int opc2=0;
	int tope2=0;
	int pos2=0;
	int max2 = 10;
	char cola2[max2];
	
	while(opc2 != 5){
		cout << endl;
		system("pause");
		system("cls");
		
		cout << "\n-- MENU --\n";
		cout << "Insertar en cola ........... 1\n";
		cout << "Eliminar en cola ........... 2\n";
		cout << "Cola vacia? ................ 3\n";
		cout << "Cola llena? ................ 4\n";
		cout << "Salir ...................... 5\n";
		cin >> opc2;
		
		switch(opc2){
			case 1:
				insertCol2(tope2, max2, cola2, pos2);
			break;
			case 2:
				elimCola2(cola2, tope2, pos2, max2);
			break;
			case 3:
				if(colaVacia2(pos2, cola2)==true){
					cout << "La cola esta vacia!";
					
				}else{
					cout << "La cola no esta vacia!";
					
				}
			break;
			case 4:
				if(colaLlena2(max2, tope2)==true){
					cout << "La cola esta llena!";
					
				}else{
					cout << "La cola no esta llena!";
					
				}
			break;	
			
		}
		
	}
	
}


void insertCol2(int &tope2,int max2,char cola2[], int pos2){
	char dat2;
	
	cout << "Ingresa un dato a la cola: ";
	cin >> dat2;
	
	if((tope2+1) % max2 == pos2){
		cout << "La cola esta llena!";
		
	}else if(tope2 == max2 && pos2 > 0){
		tope2 = 0;
		cola2[tope2] = dat2;
		tope2 = (tope2 + 1) % max2;
		
	}else{
		cola2[tope2] = dat2;
		tope2 = (tope2 + 1) % max2;
		
	}
	
	mostrarCola2(cola2, tope2, pos2, max2);
	
	
}


void mostrarCola2(char cola2[], int tope2, int pos2, int max2){
	int i=pos2;
	while(i != tope2){
		
		cout << cola2[i] << "\t";
		
		i = (i + 1) % max2;
		
	}
	
	cout << endl;
	
}


void elimCola2(char cola2[], int &tope2, int &pos2, int max2){
	
	if(tope2 == pos2){
		cout << "La cola esta vacia!";
		
	}else{
		cola2[pos2] = 0;
		pos2 = (pos2 + 1) % max2;
		
	}
	
	mostrarCola2(cola2, tope2, pos2, max2);
	
}


bool colaVacia2(int pos2, char cola2[]){
	if(cola2[pos2]=='\0'){
		return(true);
		
	}else{
		return(false);
		
	}
	
}



bool colaLlena2(int max2, int tope2){
	if(tope2 == max2){
		return(true);
		
	}else{
		return(false);
		
	}
	
}

void programa3()
{
	int opc;
	int tope=0;
	int pos=0;
	int max = 10;
	int dato = 1;
	int *cola = new int [max];
	
	do
	{
		system("cls");
		
		cout << "\n-- MENU --\n";
		cout << "Nuevo cliente .............. 1\n";
		cout << "Atender cliente ............ 2\n";
		cout << "Cola vacia? ................ 3\n";
		cout << "Cola llena? ................ 4\n";
		cout << "Mostrar Cola ............... 5\n";
		cout << "Salir ...................... 6\n";
		cin >> opc;
		
		switch(opc){
			case 1:
				insertCol3(tope, max, cola, pos, dato++);
				system("pause");
			break;
			case 2:
				elimCola3(cola, tope, pos, max);
				system("pause");
			break;
			case 3:
				if(colaVacia3(pos, cola)==true){
					cout << "La cola esta vacia!"<<endl;
					
				}else{
					cout << "La cola no esta vacia!"<<endl;
					
				}
				system("pause");
			break;
			case 4:
				if(colaLlena2(max, tope)==true){
					cout << "La cola esta llena!"<<endl;
					
				}else{
					cout << "La cola no esta llena!"<<endl;
					
				}
				system("pause");
			break;	
			case 5:
				mostrarCola3(cola,tope,pos,max);
				system("pause");
				break;
			case 6:
				break;
			default:
				cout<<"Opcion no valida"<<endl;
				system("pause");
		}
	}while(opc!=6);
	
}

void insertCol3(int &tope,int max,int cola[], int pos, int dat){
	
	
	if((tope+1) == pos){
		cout << "La cola esta llena!";
		
	}else if(tope+1 == max && pos != 0){
		tope = 0;
		cola[0] = dat;
		tope ++;
		
	}else{
		cola[tope] = dat;
		tope ++;
		
	}
	
	mostrarCola3(cola, tope, pos, max);
	
	
}

void elimCola3(int cola[], int &tope, int &pos, int max){
	
	if(tope == pos){
		cout << "La cola esta vacia!";
		
	}else{
		cola[pos] = 0;
		if(pos+1 == max)
		{
			pos=0;
		}else{
			pos ++;
		}
		
	}
	
	mostrarCola3(cola, tope, pos, max);
	
}

void mostrarCola3(int cola[], int tope, int pos, int max){
	int i=pos;
	while(i != tope){
		
		cout << cola[i] << "\t";
		if(i+1 == max)
		{
			i=0;
		}else{
			i ++;
		}
		
	}
	
	cout << endl;
	
}

bool colaVacia3(int pos, int cola[]){
	if(cola[pos]=='\0'){
		return(true);
		
	}else{
		return(false);
		
	}
	
}

void programa4()
{
	int opc3=0;
	int tope3=0;
	int pos3=0;
	int max3 = 10;
	char cola3[max3];
	
	while(opc3 != 6){
		cout << endl;
		system("pause");
		system("cls");
		
		cout << "\n-- MENU --\n";
		cout << "Insertar en cola ........... 1\n";
		cout << "Eliminar en cola ........... 2\n";
		cout << "Cola vacia? ................ 3\n";
		cout << "Cola llena? ................ 4\n";
		cout << "Invertir cola ...............5\n";
		cout << "Salir ...................... 6\n";
		cin >> opc3;
		
		switch(opc3){
			case 1:
				insertCol(tope3, max3, cola3, pos3);
			break;
			case 2:
				elimCola(cola3, tope3, pos3);
			break;
			case 3:
				if(colaVacia(pos3, cola3)==true){
					cout << "La cola esta vacia!";
					
				}else{
					cout << "La cola no esta vacia!";
					
				}
			break;
			case 4:
				if(colaLlena(max3, tope3)==true){
					cout << "La cola esta llena!";
					
				}else{
					cout << "La cola no esta llena!";
					
				}
			case 5:
				invertirCola(tope3, cola3);
			break;
				
			
		}
		
	}
}

void invertirCola(int tope, char cola[]){
	char temp;
	for(int i=0; i<tope/2; i++){
		temp = cola[i];
		cola[i] = cola[tope -i -1];
		cola[tope -i -1] = temp;
		
	}
	
}

void programa5()
{
	int opc;
	int tope=0;
	int pos=0;
	int max = 10;
	Prioridad dato;
	Prioridad *cola = new Prioridad [max];
	
	dato.turno = 1;
	do
	{
		system("cls");
		
		cout << "\n-- MENU --\n";
		cout << "Insertar en cola ........... 1\n";
		cout << "Eliminar en cola ........... 2\n";
		cout << "Cola vacia? ................ 3\n";
		cout << "Cola llena? ................ 4\n";
		cout << "Mostrar Cola ............... 5\n";
		cout << "Salir ...................... 6\n";
		cin >> opc;
		
		switch(opc){
			case 1:
				cout<<"Nivel de Prioridad: ";
				cin>>dato.priori;
				insertCol5(tope, max, cola, pos, dato);
				dato.turno++;
				system("pause");
			break;
			case 2:
				elimCola5(cola, tope, pos, max);
				system("pause");
			break;
			case 3:
				if(colaVacia5(pos, cola)==true){
					cout << "La cola esta vacia!"<<endl;
					
				}else{
					cout << "La cola no esta vacia!"<<endl;
					
				}
				system("pause");
			break;
			case 4:
				if(colaLlena2(max, tope)==true){
					cout << "La cola esta llena!"<<endl;
					
				}else{
					cout << "La cola no esta llena!"<<endl;
					
				}
				system("pause");
			break;	
			case 5:
				mostrarCola5(cola,tope,pos,max);
				system("pause");
				break;
			case 6:
				break;
			default:
				cout<<"Opcion no valida"<<endl;
				system("pause");
		}
	}while(opc!=6);
	
}

void insertCol5(int &tope,int max,Prioridad cola[], int pos, Prioridad dat){
	
	
	if((tope+1) == pos){
		cout << "La cola esta llena!";
		
	}else if(tope+1 == max && pos != 0){
		tope = 0;
		cola[0].turno = dat.turno;
		cola[0].priori = dat.priori;
		tope ++;
		
	}else{
		cola[tope].turno = dat.turno;
		cola[tope].priori = dat.priori;
		tope ++;
		
	}
	
	mostrarCola5(cola, tope, pos, max);
	
	
}

void elimCola5(Prioridad cola[], int &tope, int &pos, int max){
	
	int i=pos;
	Prioridad aux;
	
	if(tope == pos){
		cout << "La cola esta vacia!";
		
	}else{
		while(i != tope){
			if(cola[i].priori == 1)
			{
				aux.priori = cola[i].priori;
				aux.turno = cola[i].turno;
				cola[i].priori = cola[pos].priori;
				cola[i].turno = cola[pos].turno;
				cola[pos].priori = aux.priori;
				cola[pos].turno = aux.turno;
				break;
			}
			if(cola[i].priori == 2)
			{
				aux.priori = cola[i].priori;
				aux.turno = cola[i].turno;
				cola[i].priori = cola[pos].priori;
				cola[i].turno = cola[pos].turno;
				cola[pos].priori = aux.priori;
				cola[pos].turno = aux.turno;
				break;
			}
			
			if(cola[i].priori == 3)
			{
				aux.priori = cola[i].priori;
				aux.turno = cola[i].turno;
				cola[i].priori = cola[pos].priori;
				cola[i].turno = cola[pos].turno;
				cola[pos].priori = aux.priori;
				cola[pos].turno = aux.turno;
				break;
			}
			
			if(i+1 == max)
			{
				i=0;
			}else{
				i ++;
			}
		
		}
		
		cola[pos].turno = 0;
		cola[pos].priori = 0;
		if(pos+1 == max)
		{
			pos=0;
		}else{
			pos ++;
		}
		
	}
	
	mostrarCola5(cola, tope, pos, max);
	
}

void mostrarCola5(Prioridad cola[], int tope, int pos, int max){
	int i=pos;
	while(i != tope){
		
		cout << cola[i].turno << "\t";
		if(i+1 == max)
		{
			i=0;
		}else{
			i ++;
		}
		
	}
	
	cout << endl;
	
}

bool colaVacia5(int pos, Prioridad cola[]){
	if(cola[pos].turno=='\0'){
		return(true);
		
	}else{
		return(false);
		
	}
	
}