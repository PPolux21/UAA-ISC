/*
Tarea Unidad 1 - Pilas
	José Luis Espinza Sánchez
	Reyli Uvaldo Martinez Hernandez 
*/

#include <iostream>
#include <ctype.h>
#include <math.h>
#define MAX 50

using namespace std;

void algoritmosPilas(int &, int, char *);
bool pila_vacia(int);
bool pila_llena(int, int);
void push(int &, int, char, char *);
char pop(int &, char *);
void mostrar(char *, int);
void infijaPosfija();
int leerTamCad(char *);
void transformarPos(char *, int , char *);
int priori(char);
void infijaPrefija();
void transformarPre(char *, int , char *);
void invertArray(char*,int);
void evaluaPos();
void evaluaPre();
void elimRep(int &, char *);
void invertirPila(int &, char *);


int main()
{
	int tope=-1, max, opc;
	char *pila=NULL,reset;
	
	do
	{
		system("cls");
		cout<<"\tEjercicios Pilas"<<endl;
		cout<<"Algoritmos - - - - - - - - - - -  1"<<endl;
		cout<<"De notacion Infija a Posfija  - - 2"<<endl;
		cout<<"De notacion Infija a Prefija - -  3"<<endl;
		cout<<"Evaluar expresion Prefija - - - - 4"<<endl;
		cout<<"Evaluar expresion Posfija  - - -  5"<<endl;
		cout<<"Eliminar repetidos  - - - - - - - 6"<<endl;
		cout<<"Invertir Pila  - - - - - - - - -  7"<<endl;
		cout<<"Salir - - - - - - - - - - - - - - 8"<<endl;
		cout<<"\nOpcion: ";
		cin>>opc;
		switch(opc)
		{
			case 1://algoritmos (pila llena, pila vacia, pop, push)
				cout<<"Reiniciar pila: (s/n) ";
				cin>>reset;
				if(reset=='s' || reset=='S')
				{
					cout<<"Tamano de la pila: ";
					cin>>max;
					pila = new char [max];
					tope=-1;
				}
				algoritmosPilas(tope,max,pila);	
				system("pause");
				break;
			case 2://Pasar de Notacion Infija a Posfija
				infijaPosfija();
				system("pause");
				break;
			case 3://Pasar de Notacion Infija a Prefija
				infijaPrefija();
				system("pause");
				break;
			case 4://Evaluar una expresion Prefija
				evaluaPre();
				system("pause");
				break;
			case 5://Evaluar una expresion Posfija
				evaluaPos();
				system("pause");
				break;
			case 6://Elimina los elementos repetidos en una pila
				elimRep(tope,pila);
				system("pause");
				break;
			case 7://Invertir el orden de la pila
				invertirPila(tope,pila);
				system("pause");
				break;
			case 8://salida
				break;
			default:
				cout<<"\nOpcion no valida"<<endl;
				break;
		}
	}while(opc!=8);
	
	return 0;
}

//funciones Pilas

void algoritmosPilas(int &tope, int max, char *pila)
{
	int opc=0;
	char dato;
	
	if(pila==NULL)
	{
		cout<<"Tamano de la pila: ";
		cin>>max;
		pila = new char [max];
		tope=-1;
	}
	
	while(opc != 6){
		system("cls");
		cout << "\t--Menu--" << endl;
		cout << "Pila vacia? .........1\n";
		cout << "Pila llena? .........2\n";
		cout << "Pone (push) .........3\n";
		cout << "Quita (pop) .........4\n";
		cout << "Mostrar pila ........5\n";
		cout << "Salir ...............6\n";
		cout << "\nOpcion: ";
		cin >> opc;
		
		switch(opc){
			case 1://pila vacía?
				if(pila_vacia(tope)){
					cout << "La pila esta vacia";
				}else{
					cout << "La pila no esta vacia";
				}
				cout << endl;
				system("pause");
			break;
			case 2://pila llena?
				if(pila_llena(tope, max)){
					cout << "La pila esta llena";
				}else{
					cout << "La pila no esta llena";
				}
				cout << endl;
				system("pause");
			break;
			case 3://pone (push) 
				cout << "Ingrese un caracter: ";
				fflush(stdin);
				cin.get(dato);
				push(tope, max, dato, pila);
				cout << endl;
				system("pause");
			break;
			case 4://quita (pop)
				dato=pop(tope, pila);
				cout<<endl;
				system("pause");
			break;
			case 5://mostrar pila
				cout << endl;
				mostrar(pila, tope);
				system("pause");
			break;
			case 6://salir
			break;		
			default:
				cout << "Opcion no valida\n";
				system("pause");
		}	
	}
}

bool pila_vacia(int tope)
{
	if(tope==-1){
		return true;
	}else{
		return false;
	}
}

bool pila_llena(int tope, int max)
{
	if(tope == max-1){
		return true;
	}else{
		return false;
	}
}

void push(int &tope ,int max, char dato, char *pila)
{
	if(pila_llena(tope, max)){
		cout << "Desordamiento, pila llena\n";
	}else{
		tope++;
		pila[tope]=dato;
	}
}

char pop(int &tope, char *pila)
{
	char dato;
	if(pila_vacia(tope)){
		cout << "Subdesbordamiento, pila vacia";
	}else{
		dato=pila[tope];
		tope--;
	}
	
	return dato;
}

void mostrar(char *pila, int tope)
{
	for(int i=0; i<=tope; i++){
		cout << pila[i] << "\t";
	}
	cout << endl;
}

void infijaPosfija()
{
	char eI[MAX];
    char ePOS[MAX];
    int len;

    cout << "Escribe la expresion en notacion infija: ";
    fflush(stdin);
    cin.getline(eI,50,'\n');

    len = leerTamCad(eI);

    cout << endl;

    transformarPos(eI, len, ePOS);

    cout << "Notacion Posfija: " << ePOS <<endl;
}

int leerTamCad(char *eI){
    int i = 0;
    while(eI[i] != '\0'){
        i++;
    }   
    return i;
}

void transformarPos(char *eI, int tam, char *ePOS)
{
	int tope=-1, max=MAX;
	char *pila = new char [tam];
    char simb, dato;
    int i=0, pos=0;

    while(eI[i] != '\0'){

        simb=eI[i];

        if(simb == '('){

            push(tope, max, simb, pila);

        }else if(simb == ')'){
            while (pila[tope] != '('){

                dato = pop(tope, pila);
                ePOS[pos]=dato;
                pos++;

            }

            tope--;

        }else if(simb == '+' || simb == '*' || simb == '-' || simb == '/' || simb == '^'){

            while(!pila_vacia(tope) && priori(pila[tope]) >= priori(simb)){
            	
                dato = pop(tope, pila);
                ePOS[pos] = dato;
                pos++;

            }

            push(tope, max, simb, pila);

        }else{

            ePOS[pos]=simb;
            pos++;

        }

        i++;

    }

    while(!pila_vacia(tope)){
        dato = pop(tope, pila);
        ePOS[pos] = dato;
        pos++;

    }

    ePOS[pos] = '\0';
}

int priori(char operador)
{
	if(operador == '^')
		return 3;
		
    if(operador == '*' || operador == '/')
        return 2;

	if(operador == '+' || operador == '-')
        return 1;
    
    return 0;
}

void infijaPrefija()
{
	char eI[MAX];
    char ePRE[MAX];
    int len;

    cout << "Escribe la expresion en notacion infija: ";
    fflush(stdin);
    cin.getline(eI,50,'\n');

    len = leerTamCad(eI);

    cout << endl;

    transformarPre(eI, len, ePRE);

    cout << "Notacion Prefija: " << ePRE <<endl;
}

void transformarPre(char *eI, int tam, char *ePRE)
{
	int tope=-1, max=MAX;
	char *pila = new char [tam];
    char simb, dato;
    int pos=0;
    
    while(tam>=0)
    {
    	simb = eI[tam];
    	
    	if(simb == ')')
    	{
    		push(tope,max,simb,pila);
		}else if(simb == '(')
			{
				while(pila[tope] != ')')
				{
					dato = pop(tope,pila);
					ePRE[pos] = dato;
					pos++;
				}
				tope--;
			}else if(simb == '+' || simb == '*' || simb == '-' || simb == '/' || simb == '^')
				{
					while(!pila_vacia(tope) && priori(simb)<priori(pila[tope]))
					{
						dato = pop(tope,pila);
						ePRE[pos] = dato;
						pos++;
					}
					push(tope,max,simb,pila);
				}else{
					ePRE[pos] = simb;
					pos++;
				}
		
		tam--;
	}
	
	while(!pila_vacia(tope))
	{
		dato = pop(tope,pila);
		ePRE[pos] = dato;
		pos++;
	}
	
	ePRE[pos] = '\0';
	
	invertArray(ePRE,pos);
}

void invertArray(char *array,int max)
{
	int aux=max-1;
	char *invertido = new char [max];
	for(int i=0;i<max;i++)
	{
		invertido[i] = array[aux];
		aux--;
	}
	
	for(int i=0;i<max;i++)
	{
		array[i] = invertido[i];
	}
}

void evaluaPre()
{
	int pila[10];
	char cad[MAX];
	int j=0, a, b;
	int tam;
	
	cout << "Notacion prefija: ";
	fflush(stdin);
	cin.getline(cad, MAX,'\n');
	
	cout << endl << cad << endl;
	
	tam = strlen(cad);
	
	for(int i=tam-1; i>=0; i--){
		if(isdigit(cad[i])){
			pila[j] = cad[i] -'0';
			j++;
			
		}else if(cad[i] == '+' || cad[i] == '-' || cad[i] == '*' || cad[i] == '/' || cad[i] == '^'){
			b = pila[j-1];
			a = pila[j-2];
			
			if(cad[i]=='+'){
				pila[j-2] = b+a;
				j--;
				
			}else if(cad[i]=='-'){
				pila[j-2] = b-a;
				j--;
				
			}else if(cad[i]=='*'){
				pila[j-2] = b*a;
				j--;
				
			}else if(cad[i] == '/'){
				pila[j-2] = b/a;
				j--;
				
			}else if(cad[i] == '^'){
				pila[j-2] = pow(b,a);
				j--;
			}
		}
		
	}
	
	cout <<"\tReultado: "<< pila[j-1]<<endl;
}

void evaluaPos()
{
	int pila[10];
	char cad[MAX];
	int j=0, a, b;
	int tam;
	
	cout << "Notacion posfija: ";
	fflush(stdin);
	cin.getline(cad, MAX,'\n');
	
	cout << endl << cad << endl;
	
	tam = strlen(cad);
	
	for(int i=0; i<tam; i++){
		if(isdigit(cad[i])){
			pila[j] = cad[i] -'0';
			j++;
			
		}else if(cad[i] == '+' || cad[i] == '-' || cad[i] == '*' || cad[i] == '/' || cad[i] == '^'){
			b = pila[j-1];
			a = pila[j-2];
			
			if(cad[i]=='+'){
				pila[j-2] = a+b;
				j--;
				
			}else if(cad[i]=='-'){
				pila[j-2] = a-b;
				j--;
				
			}else if(cad[i]=='*'){
				pila[j-2] = a*b;
				j--;
				
			}else if(cad[i] == '/'){
				pila[j-2] = a/b;
				j--;
				
			}else if(cad[i] == '^'){
				pila[j-2] = pow(a,b);
				j--;
			}
		}
		
	}
	
	cout <<"\tReultado: "<< pila[j-1]<<endl;
	
}

void elimRep(int &tope, char *pila)
{
	char aux;
	
	if(pila_vacia(tope)){
		cout<<"Pila vacia"<<endl;
	}else{
		for(int i=0;i<tope-1;i++)
		{
			for(int j=i+1;j<tope;j++)
			{
				if(pila[i] > pila[j])
				{
					aux=pila[i];
					pila[i]=pila[j];
					pila[j]=aux;
				}
			}
		}
		mostrar(pila,tope);
	}
	
}

void invertirPila(int &tope, char *pila)
{
	if(pila_vacia(tope)){
		cout<<"Pila vacia"<<endl;
	}else{
		invertArray(pila,tope+1);
		mostrar(pila,tope);
	}
}
