/*
José Luis Espinoza Sánchez - ISC - 2° C
Ejercicio Tipo Examen
*/

#include <iostream>
#include <ctype.h>
using namespace std;

void recorreArch();
void guardaISBN(int *,int);
int verificaISBN(int *);
void creaValidos();

int main()
{
	recorreArch();
}

void recorreArch()
{
	FILE *archTxt;
	char caracter;
	int isbn[13];
	
	creaValidos();
	
	archTxt=fopen("codigos.txt","r");
	
	if(archTxt==NULL)
	{
		cout<<"Error I/O \n";
		exit(1);
	}
	
	while(!feof(archTxt))
	{
		caracter='1';
		for(int i=0; caracter!='\n'; i++)
		{
			caracter=fgetc(archTxt);
			if(isdigit(caracter))
			{
				isbn[i]=(caracter);
			}
			cout<<caracter;
		}
		//guardaISBN(isbn,verificaISBN(isbn));
		cout<<endl;
	}
	
	fclose(archTxt);
}

void guardaISBN(int *vec,int cant)
{
	FILE *archTxt;
	
	archTxt=fopen("codigosValidos.txt","a");
	
	if(archTxt==NULL)
	{
		cout<<"Error I/O \n";
		exit(1);
	}
	
	for(int i=0; i<cant; i++)
	{
		fprintf(archTxt,"%d\n",vec);
	}
	
	fclose(archTxt);
}

void creaValidos()
{
	FILE *archTxt;
	
	archTxt=fopen("codigosValidos.txt","w");
	
	if(archTxt==NULL)
	{
		cout<<"Error I/O \n";
		exit(1);
	}
	
	fclose(archTxt);
}

int verificaISBN(int *vec)
{
	int cant=0;
	
	return cant;
}