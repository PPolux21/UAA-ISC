/*
Tarea 1 - Ejercicio 1
Espinoza Sánchez José Luis-280676-2°C
05/feb/2023
Leer un arreglo de cualquier tipo (entero, flotante, char). El usuario debe indicar el tipo del
arreglo. El tamaño del arreglo será un valor constante (el mismo valor para cualquier tipo).
Realice la búsqueda de un dato en el arreglo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10

void menu();
void arregloChar(char[]);
void arregloInt(int[]);
void arregloFloat(float[]);
void llenadoInt(int[]);
void llenadoFloat(float[]);
void llenadoChar(char[]);
void mostrarInt(int[]);
void mostrarFloat(float[]);
void mostrarChar(char[]);
	//falta implementacion
bool buscadorInt(int[],int);
bool buscadorFloat(float[],float);
bool buscadorChar(char[],char);

int main()
{
	srand(time(NULL));
	menu();
	return 0;
}

void menu()
{
	int opc=0,enteros[TAM];
	float flotantes[TAM];
	char caracteres[TAM];
	do
	{
		system("cls");
		printf("  ELIGE EL TIPO DE ARREGLO  \n");
		printf("Enteros ------------------ 1\n");
		printf("Flotantes ---------------- 2\n");
		printf("Char --------------------- 3\n"); 
		printf("Salir -------------------- 4\n"); 
		printf("Elige tu opcion: ");
		scanf("%d",&opc);
		switch(opc)
		{
			case 1:
				printf("Opcion 1: Arreglo de enteros\n");
				arregloInt(enteros);
				system("pause");
				break;
			case 2:
				printf("Opcion 2: Arreglo de flotantes\n");
				arregloFloat(flotantes);
				system("pause");
				break;
			case 3:
				printf("Opcion 3: Arreglo de caracteres\n");
				arregloChar(caracteres);
				system("pause");
				break;
			case 4:
				printf("Opcion 4: Salir\n");
				system("pause");
				break;
			default:
				printf("Opcion no valida, vuelve a intentar\n");
				system("pause");
				break;
		}
	}while(opc!=4);
}

void arregloInt(int vec[])
{
	int num;
	llenadoInt(vec);
	mostrarInt(vec);
	printf("Dame el numero a buscar: ");
	scanf("%d",&num);
	if(buscadorInt(vec,num))
	{
		printf("Numero encontrado\n");
	}else
	{
		printf("Numero no encontrado\n");
	}
}

void arregloFloat(float vec[])
{
	float num;
	llenadoFloat(vec);
	mostrarFloat(vec);
	printf("Dame el numero a buscar: ");
	scanf("%f",&num);
	if(buscadorFloat(vec,num))
	{
		printf("Numero encontrado\n");
	}else
	{
		printf("Numero no encontrado\n");
	}
}

void arregloChar(char vec[])
{
	char caracter;
	llenadoChar(vec);
	mostrarChar(vec);
	printf("Dame el caracter a buscar: ");
	fflush(stdin);
	scanf("%c",&caracter);
	if(buscadorChar(vec,caracter))
	{
		printf("Caracter encontrado\n");
	}else
	{
		printf("Caracter no encontrado\n");
	}
}

void llenadoInt(int vec[])
{
	for(int i=0;i<TAM;i++)
	{
		vec[i]=rand()%101;
	}
}

void llenadoFloat(float vec[])
{
	for(int i=0;i<TAM;i++)
	{
		vec[i]=1000+rand()%10001;
		switch(rand()%5)
		{
			case 0:
				vec[i]/=10;
				break;
			case 1:
				vec[i]/=100;
				break;
			case 2:
			case 3:
			case 4:
			case 5:
				vec[i]/=1000;
				break;
		}
	}
}

void llenadoChar(char vec[])
{
	for(int i=0;i<TAM;i++)
	{
		vec[i]=33+rand()%(127-33);
	}
}

void mostrarInt(int vec[])
{
	for(int i=0;i<TAM;i++)
	{
		printf("%d ",vec[i]);
	}
	printf("\n");
}

void mostrarFloat(float vec[])
{
	for(int i=0;i<TAM;i++)
	{
		printf("%.3f ",vec[i]);
	}
	printf("\n");
}

void mostrarChar(char vec[])
{
	for(int i=0;i<TAM;i++)
	{
		printf("%c ",vec[i]);
	}
	printf("\n");
}

bool buscadorInt(int vec[],int num)
{
	for(int i=0;i<TAM;i++)
	{
		if(vec[i]==num)
		{
			return true;
		}
	}
	return false;
}

bool buscadorFloat(float vec[],float num)
{
	for(int i=0;i<TAM;i++)
	{
		if(vec[i]==num)
		{
			return true;
		}
	}
	return false;
}

bool buscadorChar(char vec[],char caracter)
{
	for(int i=0;i<TAM;i++)
	{
		if(vec[i]==caracter)
		{
			return true;
		}
	}
	return false;	
}