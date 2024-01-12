#include "CPersona.h"
#include <iostream>
#include <string.h>

using namespace std;

//costructor por defecto
CPersona::CPersona(void)
{
	curp=new char[20];
	nombre=new char[20];
	apellidoP=new char[20];
	apellidoM=new char[20];
	strcpy(curp,"");
	strcpy(nombre,"");
	strcpy(apellidoP,"");
	strcpy(apellidoM,"");
	edad=0;
	sexo='\0';
	altura=0;
	peso=0;
}
//costructor con parametros
CPersona::CPersona(char* _curp,char* _nombre,char* _apellidoP,char* _apellidoM,int _edad,char _sexo)
{
	curp=new char[20];
	nombre=new char[20];
	apellidoP=new char[20];
	apellidoM=new char[20];
	strcpy(curp,_curp);
	strcpy(nombre,_nombre);
	strcpy(apellidoP,_apellidoP);
	strcpy(apellidoM,_apellidoM);
	edad=_edad;
	sexo=_sexo;
	altura=0;
	peso=0;
}

//	sets

void CPersona::setCurp(char* _curp)
{
	strcpy(curp,_curp);
}

void CPersona::setNombre(char* _nombre)
{
	strcpy(nombre,_nombre);
}

void CPersona::setApellidoP(char* _apellidoP) 
{
	strcpy(apellidoP,_apellidoP);
}

void CPersona::setApellidoM(char* _apellidoM)
{
	strcpy(apellidoM,_apellidoM);
}

void CPersona::setEdad(int _edad)
{
	edad=_edad;
}

void CPersona::setSexo(char _sexo)
{
	sexo=_sexo;
}

//	gets

char* CPersona::getCurp()
{
	return curp;
}

char* CPersona::getNombre()
{
	return nombre;
}

char* CPersona::getApellidoP()
{
	return apellidoP;
}

char* CPersona::getApellidoM()
{
	return apellidoM;
}

int CPersona::getEdad()
{
	return edad;
}

char CPersona::getSexo()
{
	return sexo;
}

char* CPersona::toString()
{
	char * texto = new char [150];
	strcpy(texto,"CURP: ");
	strcat(texto,curp);
	strcat(texto,", Nombre: ");
	strcat(texto,nombre);
	strcat(texto,", Apellido Paterno: ");
	strcat(texto,apellidoP);
	strcat(texto,", Apellido Materno: ");
	strcat(texto,apellidoM);
	strcat(texto,", Edad: ");
	strcat(texto,(char*)edad);
	strcat(texto,", Sexo: ");
	strcat(texto,(char*)sexo);
	return texto;
}

//funciones extra
float calcImc(float peso,float altura)
{
	return peso/(altura*altura);
}

bool mayorEdad(int edad)
{
	if(edad>=18)
		return true;
	else
		return false;
}

//destructor
CPersona::~CPersona()
{
	delete curp;
	delete nombre;
	delete apellidoP;
	delete apellidoM;
}