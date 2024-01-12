/*
3.ControlBiometrico

Archivos necesarios:
	clientes.pwd para struct clienteT
	preguntas.pwd para struct preguntaT
*/

#include <iostream>
#include <ctype.h>
#include <string.h>
using namespace std;

//declaración enum para switch
enum { INCORRECTAS=0, CORRECTAS, RESPESTA, IMAGEN };

//declaración de union para validación de la contraseña
union Password{
	char passWCar[4];
	int passWNum;
};

//declaración de las estructuras
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

//decclaración de las funciones
void cargarPreguntas(preguntaT [], FILE *, int *);
void cargarClientes(clienteT [], FILE *, int *);
int validaUsuario(char *, int, clienteT [], int);
int validacionSeguridad(preguntaT [],int , char *);
void ingreso();
int cuentaClientes();	//cuentan la cantidad de renglones que hay en el arch
char *cedulaCte(char *, int, clienteT [], int);
bool validaContasena(char *);

//main
int main()
{
	// se llama otra función para dejar libre main
	ingreso();
	
	return 0;
}

void ingreso()
{
	//declaración de varables
	char usuario[20], *cedula;	//variables que pertenecen al usuario
	Password contrasena;
	int tam=cuentaClientes(), tamBackup;
	FILE *archClientes, *archPreguntas;
	preguntaT *datosPreguntas;
	clienteT *datosClientes;
	
	//se crean los arreglosdinámicos teniendo en cuenta el tamaño del archivo
	datosClientes = new clienteT [tam];
	datosPreguntas = new preguntaT [tam];
	
	//se llenan los arreglos con el contenido de los archivos y se actualiza el tamaño
	cargarClientes(datosClientes,archClientes,&tam);
	cargarPreguntas(datosPreguntas,archPreguntas,&tam);
	
	//se crea variable de respaldo por fallo y eliminación con un cin siguiente
	tamBackup=tam;
	
	//se solicitan datos de log in al ususario
	cout<<"Dame tu nombre de usuario: ";
	cin>>usuario;
	cout<<"Dame tu contrasena: ";
	cin>>contrasena.passWCar;
	
	//tras el ultimo cin se recupera el valor de tam, que ateriormente fue guardado
	tam=tamBackup;
	
	//condicional que verifica que la contraseña se componga de digitos
	if(validaContasena(contrasena.passWCar))
	{
		//tras haber detectado unicamente digitos se para a entero el numero de la contraseña
		contrasena.passWNum = atoi(contrasena.passWCar);
		
		//condicional que valida el usuario y contraseña se encuentren y sean identicos a los del arreglo
		if(validaUsuario(usuario,contrasena.passWNum,datosClientes,tam)==1)
		{
			cout<<"\nUsuario y contrasena correctos\n\n";
			
			//con la información recabada se obtiene la cédula para usarla como método de busqueda siguiente
			cedula=cedulaCte(usuario,contrasena.passWNum,datosClientes,tam);
			
			//switch que determina el resltado de la respuesta a la pregunta e imagen solicitadas
			switch(validacionSeguridad(datosPreguntas,tam,cedula))
			{
				case INCORRECTAS:
					cout<<"\nRespuesta e imagen incorrectas"<<endl;
					break;
				case CORRECTAS:
					cout<<"\nRespuesta e imagen correctas"<<endl;
					break;
				case RESPESTA:
					cout<<"\nRespuesta correcta\nImagen incorrecta"<<endl;
					break;
				case IMAGEN:
					cout<<"\nImagen correcta\nRespuesta incorrecta"<<endl;
					break;
			}//switch
		}
		else
		{
			cout<<"Usuario y/o contrasena incorrectos"<<endl;
		}//if validaUsuario
	}
	else
	{
		cout<<"Contrasena no valida!"<<endl;
	}//if validaContrasena
}

//función que llena el arreglos con el contenido del archivo clientes.pwd y se actualiza el tamaño
void cargarClientes(clienteT A[], FILE *clientes, int *tam)
{
	int cant=0;//se declara un contador
	
	//proceso de apertura de archivo
	clientes=fopen("clientes.pwd","rb");
	
	if(clientes==NULL)
	{
		cout<<"Error I/O"<<endl;
		exit(1);
	}
	
	//lectura del archivo y paso de contenido al areglo
	fread(&A[0],sizeof(clienteT),1,clientes);
	
	for(int i=1; !feof(clientes); i++)
	{
		fread(&A[i],sizeof(clienteT),1,clientes);
		cant++;
	}
	
	fclose(clientes);	//cierre de archivo
	
	//se asigna el valor del contador al puntero del tamaño
	*tam=cant;
}

//función que llena el arreglos con el contenido del archivo preguntas.pwd y se actualiza el tamaño
void cargarPreguntas(preguntaT A[], FILE *preguntas, int *tam)
{
	int cant=0;	//se declara un contador
	
	//proceso de apertura de archivo
	preguntas=fopen("preguntas.pwd","rb");
	
	if(preguntas==NULL)
	{
		cout<<"Error I/O"<<endl;
		exit(1);
	}
	
	//lectura del archivo y paso de contenido al areglo
	fread(&A[0],sizeof(preguntaT),1,preguntas);
	
	for(int i=1; !feof(preguntas); i++)
	{
		fread(&A[i],sizeof(preguntaT),1,preguntas);
		cant++;
	}
	
	fclose(preguntas);	//cierre de archivo
	
	//se asigna el valor del contador al puntero del tamaño
	*tam=cant;
}

//funcion recursiva para validar usuario y contraseña
int validaUsuario(char *usuario, int contrasena, clienteT A[], int tam)
{	
	//en caso de recorrer el vector y no encontrar coincidencias regresa 0
	if(tam==0)
	{
		return 0;
	}
	
	//en caso de haber coincidencias regresa un 1
	if(strcmp(usuario, A[tam-1].usuario) == 0 && contrasena == A[tam-1].contrasena)
	{
		return 1;
	}
	
	//en caso de no cumplirse lo anterior vuelve a llamar a la función para seguir recorriendo el arreglo
	return validaUsuario(usuario, contrasena, A, tam-1);
}

//función que comprueba si la respuesta y la imagen coinciden con las del areglo
int validacionSeguridad(preguntaT A[],int tam, char *cedula)
{
	//declaración de variables
	char respuesta[20],imagen[20];
	int flag=0;	//bandera que de retorna al final de la función
	
	//recorre el arreglo 
	for(int i=0; i<tam; i++)
	{
		//cuando se encuentra la cédula se preguntan la pregunta e imagen
		if(strcmp(A[i].cedula,cedula)==0)
		{
			cout<<A[i].texto_pregunta<<" ";
			cin>>respuesta;
			cout<<"Imagen: ";
			cin>>imagen;
			
			//si ambas respuestas son iguales a las del arreglo se regrea un 1
			if(strcmp(A[i].respuesta,respuesta)==0 && strcmp(A[i].imagen,imagen)==0)
			{
				flag=1;
				break;
			}
			
			//si sólo la respuesta es corercta se regresa 2
			if(strcmp(A[i].respuesta,respuesta)==0)
			{
				flag=2;
				break;
			}
			
			//si la imgen es correcta se regresa 3
			if(strcmp(A[i].imagen,imagen)==0)
			{
				flag=3;
			}
			break;
		}//if
	}//for
	
	return flag;
}

//función que cuenta la cantidad de renglones en el archivo clientes.pwd
int cuentaClientes()
{
	//declaración de variables
	int tam=0;
	clienteT reg;
	FILE *archPwd;
	
	//procedimiento de apertura
	archPwd=fopen("clientes.pwd","rb");
	
	if(archPwd==NULL)
	{
		cout<<"Error I/O"<<endl;
		exit(1);
	}
	
	//Lectura y conteo de los renglones de archivo
	fread(&reg,sizeof(clienteT),1,archPwd);
	
	while(!feof(archPwd))
	{
		fread(&reg,sizeof(clienteT),1,archPwd);
		tam++;
	}
	
	fclose(archPwd);	//cierre de archivo
	
	//retorno del tamaño
	return tam;
}

//función que obtiene la cedula del usuario 
char *cedulaCte(char *usuario, int contrasena, clienteT A[], int tam)
{
	//declaración de la variable
	char *cedula;
	
	cedula = new char [11];	//asignación de memoria
	
	//ciclo que recorre el arreglo
	for(int i=0; i<tam; i++)
	{
		//cuando coinciden el usuario y contraseña se copia la cédula del archivo a la variable
		if(strcmp(usuario, A[i].usuario) == 0 && contrasena == A[i].contrasena)
		{
			strcpy(cedula,A[i].cedula);
			break;
		}
	}
	
	//se regresa la cedula
	return cedula;
}

//función que valida que la contraseña sea completamente en digitos
bool validaContasena(char *passCar)
{
	bool flag=true;
	
	//recorre las posiciones de la contraseña
	for(int i=0; i<4; i++)
	{
		//si se encuantra un caracter que no es digito regresa falso
		if(!isdigit(passCar[i]))
		{
			flag=false;
			break;
		}
	}
	return flag;
}