/*
Realice una clase llamada MediosDeComunicación que englobe los diferentes medios de comunicación como son:
a. Impresos
   i. Libros
   ii. Revistas
   iii. Historietas
   iv. Volantes
b. Electrónicos
   i. Cinematografía
   ii. Radio
   iii. Televisión
   
Haga que la clase MediosDeComunicacion sea una clase abstracta, recuerde que una clase abstracta 
es aquella que tiene una o más funciones virtuales puras. Cada clase tiene sus atributos, 
constructores y métodos particulares, realice al menos 2 métodos y defina 2 atributos para cada clase.
*/

#include <iostream>
#include <string.h>

using namespace std;

class MediosDeComunicacion
{
protected:
	char *titulo;
	char *autor;
	char *abs;
public:
	
	MediosDeComunicacion(void);
	MediosDeComunicacion(char* _titulo,char* _autor,char* _abs);
	
	char* getTitulo(){return titulo;};
	char* getAutor(){return autor;};
	char* getabs(){return abs;};
	virtual char* getTituloAutor()=0;
	
	void setTitulo(char* _titulo){strcpy(titulo,_titulo);};
	void setAutor(char* _autor){strcpy(autor,_autor);};
	void setabs(char* _abs){strcpy(abs,_abs);};
	virtual void setTituloAutor()=0;
	
	~MediosDeComunicacion();	
};

MediosDeComunicacion::MediosDeComunicacion(void)
{
	titulo=new char[20];
	autor=new char[20];
	abs=new char[150];
}

MediosDeComunicacion::MediosDeComunicacion(char* _titulo,char* _autor,char* _abs)
{
	titulo=new char[20];
	autor=new char[20];
	abs=new char[150];
	
	strcpy(titulo,_titulo);
	strcpy(autor,_autor);
	strcpy(abs,_abs);
}

MediosDeComunicacion::~MediosDeComunicacion()
{
	delete titulo;
	delete autor;
	delete abs;
}




class Impresos:public MediosDeComunicacion//Flatan otros 2 métodos más
{
private:
	int cantPag;
	int isbn;
public:
	Impresos();
	Impresos(int _cantPag,int _isbn,char* _abs,char* _titulo,char* _autor);
	
	virtual char* getTituloAutor();//WIP
	
	virtual void setTituloAutor();//WIP
};

Impresos::Impresos():MediosDeComunicacion()
{
	cantPag=0;
	isbn=0;
}

Impresos::Impresos(int _cantPag,int _isbn,char* _abs,char* _titulo,char* _autor):MediosDeComunicacion(_titulo,_autor,_abs)
{
	cantPag=_cantPag;
	isbn=_isbn;
}




class Electronicos:public MediosDeComunicacion//WIP
{
	
};




int main()
{
	
	
	return 0;
}