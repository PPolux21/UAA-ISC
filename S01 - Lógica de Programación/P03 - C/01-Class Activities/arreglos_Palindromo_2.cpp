#include <stdio.h>
#include <ctype.h>
#define TAM 50

long longitud(char cad[]);
void copiar(char cadDest[],char cadOri[]);
void reversa(char cad[]);
void quitarEspacio(char frase[]);
void mostrar(char cad[]);

int main()
{
	char cadena[TAM],frase[TAM]={"sistemas"},otraCad[TAM],cadenaVacia[TAM];
	int tam=0;
	
	printf("Cadena: ");
	fflush(stdin);
	gets(cadena);
	printf("Longitud de la cadena %s: %ld\n",cadena,longitud(cadena));
	printf("Longitud de la cadena %s: %ld\n",frase,longitud(frase));
	copiar(otraCad,frase);
	reversa(cadena);
	//quitarEspacio(cadena);
	mostrar(cadena);
	copiar(cadenaVacia,frase);
}

long longitud(char cad[])
{
	long tam=0;
	for(int i=0;cad[i]!='\0';i++)
	{
		tam++;
	}
	return tam;
}

void copiar(char cadDest[],char cadOri[])
{
	for(int i=0;i<TAM;i++)
	{
		cadDest[i]=' ';
	}
	for(int i=0;i<longitud(cadOri);i++)
	{
		cadDest[i]=cadOri[i];
	}
	printf("Cadena origen: %s\n",cadOri);
	printf("Cadena destino: %s\n",cadDest);
}

void reversa(char cad[])
{
	char cadAux[TAM];
	int j=0;
	for(int i=longitud(cad)-1;i>=0;i--)
	{
		cadAux[j]=cad[i];
		j++;
	}
	copiar(cad,cadAux);
}

void quitarEspacio(char frase[])
{
	char fraseSinEs[TAM];
	int j=0;
	for(int i=0;i<TAM;i++)
	{
		if(!isspace(frase[i]))
		{
			fraseSinEs[j]=frase[i];
			j++;
		}
	}
	copiar(frase,fraseSinEs);
}

void mostrar(char cad[])
{
	int i=0;
	while(i<longitud(cad))
	{
		if(isalpha(cad[i]))
		{
			printf("%c",cad[i]);
		}
		i++;
	}
	printf("\n");
}