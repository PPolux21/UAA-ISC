/*
Ejercicio 3
 Escribir una función que reciba un arreglo char y aparte una letra,
 la función debe buscar la letra dentro del arreglo y devolver un true 
 si localiza dicha letra dentro del arreglo. Hacer uso de la búsqueda secuencial
*/
#include <iostream>
#define TAM 10

using namespace std;

bool busqueda(char [],char);

int main()
{
	char palabra[TAM],letra;
	
	cout<<"Dame el arreglo de caracteres: ";
	cin>>palabra;
	
	cout<<"Dame el caracter a buscar: ";
	cin>>letra;
	
	//condicion que da uso al return de la funcion
	if(busqueda(palabra,letra))
	{
		cout<<"Caracter encontrado! :D"<<endl;
	}
	else
	{
		cout<<"Caracter no encontrado :c"<<endl;
	}
}

//función del ejercicio
bool busqueda(char vec[],char letra)
{
	for(int i=0;i<TAM;i++)
        if(vec[i]==letra) 
		{
            return true;
        }
    return false;
}