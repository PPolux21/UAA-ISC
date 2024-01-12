// Punteros

#include <iostream>

using namespace std;

int main()
{
	int edad=18;	//variables estáticas
	int *ptrEdad=NULL; 	// puntero inicializado en NULL
	cout<<"Dir. donde se ubica edad: "<< &edad <<endl;
	cout<<"Dir. donde se ubica ptrEdad: "<< &ptrEdad <<endl;
	
	cout<<"\nContenido de edad: "<< edad <<endl;
	cout<<"Contenido de ptrEdad: "<< ptrEdad <<endl;
	
	/*Tras no tener contenido en ptrEdad el programa falla 
	
	cout<<"\nValor almacenado donde apunta ptrEdad: "<< *ptrEdad <<endl;
	*/
	
	ptrEdad=&edad; 	//se guarda la dirección de memoria de la variable estática
	
	cout<<"Contenido de ptrEdad: "<< ptrEdad <<endl;
	
	cout<<"\nValor almacenado donde apunta ptrEdad: "<< *ptrEdad <<endl;
	
	int nuevaEdad=25;
	*ptrEdad=nuevaEdad;
	
	cout<<"Nuevo valor almacenado donde apunta ptrEdad: "<< *ptrEdad <<endl;
	
	return 0;
}