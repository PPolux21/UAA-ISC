#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	char archivo[]="prueba.dat";
	/*
	//ejemplo 1 
	
	char cad[17]="TEXTO A ESCRIBIR";
	
	ofstream fichout(archivo, ios::out | ios::binary);
	if(!fichout)
	{
		cout<<"\n Incapaz de Crear o Abrir el archivo";
	}else{
		for(int i=0;i<16;i++)
			fichout.put(cad[i]);
		fichout.close();
	}	*/
	
	// .get para leer información del archivo
	// .put para escribir información del archivo
	
	/*
	//ejemplo 2 
	
	float R=1234.86;
	int i,N;
	//apertura como salida
	fstream fichbin(archivo,ios::binary | ios::out);
	fichbin.write(reinterpret_cast<char*>(&R),sizeof(float));
	for(int i=0;i<=20;i++)
		fichbin.write(reinterpret_cast<char*>(&i),sizeof(int));
	fichbin.close();
	
	//apertura como entrada
	fichbin.open(archivo,ios::binary | ios::in);
	fichbin.read(reinterpret_cast<char*>(&R),sizeof(float));
	cout<<endl<<"R= "<<R<<endl;
	for(int i=0;i<=20;i++)
	{
		fichbin.read(reinterpret_cast<char*>(&N),sizeof(int));
		cout<<endl<<i<<"= "<<N<<endl;
	}*/
	
	//ejemplo 3
	
	int i,N;
	fstream fichbin(archivo, ios::binary | ios::in | ios::out);
	//almacena los 10 primeros enteros
	for(i=1;i<=10;i++)
		fichbin.write(reinterpret_cast<char*>(&i),sizeof(int));
	//seposiciona al principio del quinto entero
	fichbin.seekp(4*sizeof(int));
	//lee dicho entero
	fichbin.read(reinterpret_cast<char*>(&N),sizeof(int));
	//visualiza el valor 5 
	cout<<endl<<"Quinto= "<<N<<endl;
	//se posiciona de nuevo en el quinto entero
	fichbin.seekp(4*sizeof(int));
	
	i=100;
	//modifica eñ valor de 5 por el valor 100
	fichbin.write(reinterpret_cast<char*>(&i),sizeof(int));
	// se posiciona en el principio del archivo
	fichbin.seekp(0*sizeof(int));
	// se visualiza el contenido
	for(i=1;i<=10;i++)
	{
		fichbin.read(reinterpret_cast<char*>(&N),sizeof(int));
		cout<<endl<<i<<"= "<<N<<endl;
	}
	fichbin.close();
}