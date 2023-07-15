/* CODIGO DE UN MENU GENERICO PARA USAR EN CUALQUIER PROGRMAA -ADAPTAR SEGUN NECESIDADES- */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int TAM=15;

//Prototipo
void menu();
void llenar(int vec[]);
int captura();
void buscaDato(int dato,int vec[]);
int buscaPosi(int dato,int vec[]);
void ordenar(int vec[]);
void mostrar(int vec[]);

int main()
{
	srand(time(NULL));
    menu();   //llamada a la función
    return 0;
}

//Desarrollo de las funciones
void menu()
{
    int opc=0,vec[TAM],dato=0,posi=0;
    
    do{
        printf("OPERACIONES CON VECTORES \n");
        printf("Llenar vector ............... 1\n");
        printf("Busqueda por valor .......... 2\n");
        printf("Busqueda por posicion ....... 3\n");
        printf("Ordenar ..................... 4\n");
        printf("Mostrar ..................... 5\n");
        printf("Salir ....................... 6\n");
        printf("Selecciona una opcion: ");
        scanf("%d",&opc);
        switch(opc)
		{
			case 1: 
				llenar(vec);
				break;
			case 2:
				dato=captura();
				buscaDato(dato,vec);
				break;
			case 3:
				dato=captura();
				posi=buscaPosi(dato,vec);
				printf("Posicion: %d\n",posi);
				break;
			case 4:
				ordenar(vec);
				break;
			case 5:
				mostrar(vec);
                break;
        }//switch
        
    }while(opc != 6);
}//menu

void llenar(int vec[])
{
	for(int i=0;i<TAM;i++)
	{
		vec[i]=rand()%101;
	}
}

int captura()
{
	int valor;
	printf("Dame el valor a buscar: ");
	scanf("%d",&valor);
	return valor;
}

void buscaDato(int dato,int vec[])
{
	bool enc=false;
	for(int i=0;i<TAM;i++)
	{
		if(vec[i]==dato)
		{
			printf("Dato localizado!\n");
			enc=true;
			break;
		}
	}
	
	if(!enc)
	{
		printf("Dato no localizado!\n");
	}
}

int buscaPosi(int dato,int vec[])
{
	int posi=-1;
	for(int i=0;i<TAM;i++)
	{
		if(vec[i]==dato)
		{
			posi=i;
			break;
		}
	}
	return posi;
}

void ordenar(int vec[]) // Bubble sort 
{
	int aux;
	for(int i=0;i<TAM;i++)
	{
		for(int j=0;j<TAM-1;j++)
		{
			if(vec[j]>=vec[j+1])
			{
				aux=vec[j];
				vec[j]=vec[j+1];
				vec[j+1]=aux;
			}
		}
	}
}

void mostrar(int vec[])
{
	for(int i=0;i<TAM;i++)
	{
		printf("%d\t",vec[i]);
	}
	printf("\n");
}