//creo .pwd

#include <iostream>
using namespace std;

typedef struct {
	char cedula[11]; 
	char usuario[20]; 
	int contrasena;
} clienteT;

typedef struct {
	char cedula[11];
	char texto_pregunta[50]; 
	char respuesta[20];
	char imagen[20];
} preguntaT;

void reiniciaCliente();
void reiniciaPreguntas();
void creaCliente(int);
void creaPregunta(int);

int main()
{
	int tam,opc=0;
	
	cout<<"Para reiniciar el archivo escribir 1: ";
	cin>>opc;
	
	if(opc=1)
	{
		reiniciaCliente();
		reiniciaPreguntas();
	}
	
	cout<<"Cantidad de personas a añadir: ";
	cin>>tam;
	
	creaCliente(tam);
	creaPregunta(tam);
}

void creaCliente(int tam)
{
	FILE *archPwd;
	clienteT reg;
	
	cout<<"\n\nClientes.pwd\n\n";
	
	archPwd=fopen("clientes.pwd","ab");
	
	if(archPwd==NULL)
	{
		cout<<"Error I/O"<<endl;
		exit(1);
	}
	
	for(int i=0; i<tam; i++)
	{
		cout<<"Cedula: ";
		cin>>reg.cedula;
		cout<<"Usuario: ";
		cin>>reg.usuario;
		cout<<"Contrasena: ";
		cin>>reg.contrasena;
		fwrite(&reg,sizeof(clienteT),1,archPwd);
	}
	
	fclose(archPwd);
}

void creaPregunta(int tam)
{
	FILE *archPwd;
	preguntaT reg;
	
	cout<<"\n\nPreguntas.pwd\n\n";
	
	archPwd=fopen("preguntas.pwd","ab");
	
	if(archPwd==NULL)
	{
		cout<<"Error I/O"<<endl;
		exit(1);
	}
	
	for(int i=0; i<tam; i++)
	{
		cout<<"Cedula: ";
		cin>>reg.cedula;
		cout<<"Pregunta de seguridad: ";
		fflush(stdin);
		gets(reg.texto_pregunta);
		cout<<"Respuesta: ";
		cin>>reg.respuesta;
		cout<<"Imagen: ";
		cin>>reg.imagen;
		fwrite(&reg,sizeof(preguntaT),1,archPwd);
	}
	
	fclose(archPwd);
}

void reiniciaCliente()
{
	FILE *archPwd;
	
	archPwd=fopen("clientes.pwd","wb");
	
	if(archPwd==NULL)
	{
		cout<<"Error I/O"<<endl;
		exit(1);
	}
	
	fclose(archPwd);
}
void reiniciaPreguntas()
{
	FILE *archPwd;
	
	archPwd=fopen("preguntas.pwd","wb");
	
	if(archPwd==NULL)
	{
		cout<<"Error I/O"<<endl;
		exit(1);
	}
	
	fclose(archPwd);
}