/*
Menú de 5 opciones 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menuOpciones();
void eleccion(int opc);
bool comparar();
void asignar();
void invertir(char cad[]); //En en prototipo de la funcion no se pone el tamaño de cadena
int longitud(char cad[]);
void unir(char cadA[],char cadB[]);

int main()
{	
	menuOpciones();	
}

void menuOpciones()
{	
	int opc;
	
	do
	{
		system("cls");
		printf("FUNCIONES DE STRING.H \n");
		printf("Comparar cadenas - - - - - - - - 1 \n");
		printf("Copiar/Asignar - - - - - - - - - 2 \n");
		printf("Invertir cadena  - - - - - - - - 3 \n");
		printf("Obtener longitud - - - - - - - - 4 \n");
		printf("Unir cadenas - - - - - - - - - - 5 \n");
		printf("Salir  - - - - - - - - - - - - - 6 \n");
		printf("\nSelecciona tu opcion: ");
		scanf("%d",&opc);
		
		eleccion(opc);
	
	}while(opc!=6);
	
} 

void eleccion(int opc)
{
	bool res=false;
	char cadena[15],cadA[10]={"sistemas"},cadB[15];
	
	switch(opc)
	{
			case 1:
				res=comparar();
				if(res)
				{
					printf("Cadenas iguales\n");
				}
				else
				{
					printf("Cadenas diferentes\n");
				}
				system("pause");
				break;
			case 2:
				asignar();
				system("pause");
				break;
			case 3:
				printf("Invertir cadena: ");
				scanf("%s",cadena);
				invertir(cadena);
				system("pause");
				break;
			case 4:
				printf("Cadena: ");
				scanf("%s",cadena);
				printf("Longitud de %s es: %d\n",cadena,longitud(cadena));
				system("pause");
				break;
			case 5:
				printf("Cadena B: ");
				scanf("%s",cadB);
				unir(cadA,cadB);
				system("pause");
				break;
	}
	
}

bool comparar()
{	
	char cadA[15],cadB[15];
	bool comp=false;
	
	puts("Dame la primer cadena: ");
	fflush(stdin);
	gets(cadA);
	puts("Dame la segunda cadena: ");
	fflush(stdin);
	gets(cadB);	
	comp=(strcmp(cadA,cadB)==0)?true:false;
	return comp;
}

void asignar()
{
	char origen[20],destino[20];
	puts("Cadena origen: ");
	fflush(stdin);
	gets(origen);
	strcpy(destino,origen);
	puts(destino);
}

void invertir(char cad[])
{
	puts(strrev(cad));
}

int longitud(char cad[])
{
	int tam;
	tam=strlen(cad);
	return tam;
}

void unir(char cadA[],char cadB[])
{
	char resultado[26]={""};
	strcat(resultado,cadA);
	strcat(resultado," ");
	strcat(resultado,cadB);
	printf("%s\n",resultado);
}