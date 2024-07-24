/*
	Realice una clase llamada Archivo, esta clase deberá contener 
	los atributos: nombre de archivo, extensión, tamaño (bytes), 
	genere un constructor que inicialice estos atributos. 
	Además de un método get y set para cada atributo. 
	Genere diferentes clases para clasificar estos archivos 
	y darles propiedades únicas, algunas clasificaciones pueden ser:

	a. Archivos multimedia
	i. mp3
	ii. wav
	iii. avi
	iv. mpg

	b. Archivos de texto
	i. txt
	ii. dat

	c. Archivos comprimidos
	i. zip
	ii. rar
*/


#include <iostream>
#include <string.h>

using namespace std;

class CArchivo
{
protected:
	char* nom;
	char* ext;
	long tam;
public:
	
	CArchivo(const char *_nom,const char *_ext,long _tam);
	void setNom(const char *_nom);
	void setExt(const char *_ext);
	void setTam(long _tam);
	
	char *getNom();
	char *getExt();
	long getTam();
	
	char* toString();
};

CArchivo::CArchivo(const char *_nom,const char *_ext,long _tam)
{
	nom= new char[20];
	ext= new char[7];
	strcpy(nom,_nom);
	strcpy(ext,_ext);
	tam = _tam;
}

void CArchivo::setNom(const char *_nom)
{
	strcpy(nom,_nom);
}

void CArchivo::setExt(const char *_ext)
{
	strcpy(ext,_ext);
}

void CArchivo::setTam(long _tam)
{
	tam = _tam;
}

char* CArchivo::getNom()
{
	return nom;
}

char* CArchivo::getExt()
{
	return ext;
}

long CArchivo::getTam()
{
	return tam;
}

char* CArchivo::toString()
{
	char * texto = new char [40];
	sprintf(texto,"%s%s %d bytes",nom,ext,tam);
	
	return texto;
}

class CMultimedia:public CArchivo
{
private:
	char titulo[20];
	char autor[20];
	int duracion;//segundos
public:
	CMultimedia(const char *_nom,const char *_ext,long _tam,const char *_titulo,const char *_autor,int _duracion);
	
	void cambiaTitulo();
	void cambiaAutor();
	char* mostrarMetadatos();
};

CMultimedia::CMultimedia(const char *_nom,const char *_ext,long _tam,const char *_titulo,const char *_autor,int _duracion):CArchivo(_nom,_ext,_tam)
{
	strcpy(titulo,_titulo);
	strcpy(autor,_autor);
	duracion=_duracion;
}

void CMultimedia::cambiaTitulo()
{
	char _titulo[20];
	cout<<"Titulo nuevo: ";
	cin.getline(_titulo,20,'\n');
	strcpy(titulo,_titulo);
}

void CMultimedia::cambiaAutor()
{
	char _autor[20];
	cout<<"Autor nuevo: ";
	cin.getline(_autor,20,'\n');
	strcpy(autor,_autor);
}

char* CMultimedia::mostrarMetadatos()
{
	char *texto = new char[100];
	sprintf(texto,"%s, %s, %d segundos",titulo,autor,duracion);
	
	return (texto);
}

class CTexto:public CArchivo
{
private:
	char cont[100];
public:
	CTexto(const char *_nom,const char *_ext,long _tam,const char *_cont);
	
	void borrarCont();
	void agregaCont();
	char* mostrarCont();
};

CTexto::CTexto(const char *_nom,const char *_ext,long _tam,const char *_cont):CArchivo(_nom,_ext,_tam)
{
	strcpy(cont,_cont);
}

void CTexto::borrarCont()
{
	strcpy(cont,"");
}

void CTexto::agregaCont()
{
	char _cont[100];
	cout<<"Cadena a agragar: ";
	cin.getline(_cont,100,'\n');
	strcat(cont,_cont);
}

char* CTexto::mostrarCont()
{
	return (cont);
}

class CComprimido:public CArchivo
{
private:
	int cantArch;
public:
	CComprimido(const char *_nom,const char *_ext,long _tam,int _cantArch);
	
	void agregarArch();
	void descomprimir();
	char* mostrarCont();
};

CComprimido::CComprimido(const char *_nom,const char *_ext,long _tam,int _cantArch): CArchivo(_nom,_ext,_tam)
{
	cantArch=_cantArch;
}

void CComprimido::agregarArch()
{
	tam+=7000;
	cantArch++;
}

void CComprimido::descomprimir()
{
	tam=0;
	cantArch=0;
}

char* CComprimido::mostrarCont()
{
	char *texto = new char[100];
	sprintf(texto,"%s%s %d bytes\n\t%d archivos comprimidos",nom,ext,tam,cantArch);
	
	return (texto);
}



int main()
{
	CMultimedia multimedia=CMultimedia("song",".mp3",40000,"Hola","Yo",3000);
	cout<<multimedia.toString()<<"\t"<<multimedia.mostrarMetadatos()<<endl<<endl;
	
	CTexto texto=CTexto("notas",".txt",1000,"");
	texto.agregaCont();
	cout<<texto.toString()<<"\t"<<texto.mostrarCont()<<endl<<endl;
	
	CComprimido comprimido=CComprimido("archivos",".zip",50000,6);
	comprimido.agregarArch();
	cout<<comprimido.mostrarCont()<<endl;
	comprimido.descomprimir();
	cout<<comprimido.mostrarCont()<<endl;
	return 0;
}