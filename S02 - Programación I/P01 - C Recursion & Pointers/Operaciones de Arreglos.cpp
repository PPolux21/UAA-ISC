//Operaciones con Arreglos

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#define TAM 20

void menu();
void llenadoManual(char letras[]);
void llenadoAleatorio(char letras[]);
void mostrar(char letras[]);
void limpiaVector(char letras[]);
int copiarSinEsp(char letras[],char copia[]);
void invertir(char letras[],char aux[]);
bool compararArreglos(char letras[],char frase[]);
void convertir(char letras[]);

int main()
{
	srand(time(NULL));
	menu();
	return 0;
}

void menu()
{
	bool cmp=false;
	int opc,num=0;
	char letras[TAM],copia[TAM],aux[TAM],frase[TAM];
	do
	{
		system("cls");
		printf("  ARREGLOS DE CARACTERES\n");
		printf("Llenado manual --------- 1\n");
		printf("Llenado aleatorio ------ 2\n");
		printf("Mostrar ---------------- 3\n");
		printf("Limpiar vector --------- 4\n");
		printf("Copiar sin espacios ---- 5\n");
		printf("Invertir --------------- 6\n");
		printf("Comparar arreglos ------ 7\n");
		printf("Convertir a numero ----- 8\n");
		printf("Salir ------------------ 9\n");
		printf("Eliga una opcion: ");
		scanf("%d",&opc);
		switch(opc){
			case 1:
				limpiaVector(letras);
				llenadoManual(letras); 
				mostrar(letras);
				system("pause");
				break;
			case 2:
				limpiaVector(letras);
				llenadoAleatorio(letras);
				mostrar(letras);
				system("pause");
				break;
			case 3:
				mostrar(letras);
				system("pause");
				break;
			case 4:
				limpiaVector(letras);
				mostrar(letras);
				system("pause");
				break;
			case 5:
				limpiaVector(copia);
				num=copiarSinEsp(letras,copia);
				printf("Espacios: %d\n",num);
				mostrar(copia);
				system("pause");
				break;
			case 6:
				invertir(letras,aux);
				mostrar(letras);
				mostrar(aux);
				system("pause");
				break;
			case 7:
				printf("Palabra a comparar: ");
				fflush(stdin);
				gets(frase);
				cmp=compararArreglos(letras,frase);
				if(cmp)
				{
					printf("Palabras iguales\n");
				}else
				{
					printf("Palabras diferentes\n");
				}
				system("pause");
				break;
			case 8:
				convertir(letras);
				system("pause");
				break;
			case 9:
				printf("Adios :) \n");
				system("pause");
				break;
			default:
				printf("Opcion no valida D: \n");
				system("pause");
		}
	}while(opc!=9);
}

void limpiaVector(char letras[])
{
	for(int i=0;i<TAM;i++)
	{
		letras[i]=32;
	}
}

void mostrar(char letras[])
{
	printf("\n");
	for(int i=0;i<TAM;i++)
	{
		printf("%c",letras[i]);
	}
	printf("\n");
}

void llenadoManual(char letras[])
{
	char opc;
	printf("Metodo de llenado A/B: ");
	fflush(stdin);
	scanf("%c",&opc);
	if(toupper(opc)=='A')
	{
		printf("Dame la cadena: ");
		fflush(stdin);
		gets(letras);
	}else
	{
		if(toupper(opc)=='B')
		{
			for(int i=0;i<TAM;i++)
			{
				printf("Dame la letra: ");
				fflush(stdin);
				scanf("%c",&letras[i]);
			}
		}else
		{
			printf("Opcion no valida");
		}
	}
}

void llenadoAleatorio(char letras[])
{
	for(int i=0;i<TAM;i++)
	{
		letras[i]=32+rand()%(128-32);
	}
}

int copiarSinEsp(char letras[],char copia[])
{
	int j=0,totSpace=0;
	for(int i=0;i<TAM;i++)
	{
		if(!isspace(letras[i]))
		{
			copia[j]=letras[i];
			j++;
		}
		else
		{
			totSpace++;
		}
	}
	return totSpace;
}

void invertir(char letras[],char aux[])
{
	int j=0;
	for(int i=strlen(letras)-1;i>=0;i--)
	{
		aux[j]=letras[i];
		j++;
	}
}

bool compararArreglos(char letras[],char frase[])
{
	bool cmp=true;
	int tamLetras=strlen(letras), tamFrase=strlen(frase);
	if(tamLetras!=tamFrase)
	{
		return false;
	}else
	{
		for(int i=0;i<strlen(letras);i++)
		{
			if(letras[i]!=frase[i])
			{
				cmp=false;
				break;
			}
		}
	}
	
	return cmp;
}

void convertir(char letras[])
{
	int vecNum[TAM];
	for(int i=0;i<strlen(letras);i++)
	{
		vecNum[i]=int(letras[i]);
		printf("%c\t%d \n",letras[i], vecNum[i]);
	}
}