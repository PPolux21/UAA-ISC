#include "CVehiculo.h"
#include <iostream>
#include <string.h>

using namespace std;

//constructor por defecto
CVehiculo::CVehiculo(void){
	edoFisico = 0;
	km = 0;
	
	marca= new char[20];
	submarca= new char[20];
	modelo= new char[20];
	color= new char[20];	
	
//	strcpy(marca,"");
//	strcpy(submarca,"");
//	strcpy(modelo,"");
//	strcpy(color,"");

	encendido = false;
	velocidad = 0;
}

CVehiculo::CVehiculo(char* _marca, char* _submarca, char* _modelo, int _km, int _edoFisico, char* _color){
	edoFisico = _edoFisico;
	km = _km;
	strcpy(marca, _marca);
	strcpy(submarca, _submarca);
	strcpy(modelo, _modelo);
	strcpy(color, _color);
	encendido = false;
	velocidad = 0;
}

//destructor
CVehiculo::~CVehiculo(){
	delete marca;
	delete submarca;
	delete modelo;
	delete color;
}

//sets
void CVehiculo::setMarca(char* _marca){
	strcpy(marca, _marca);
}

void CVehiculo::setSubmarca(char* _submarca){
	strcpy(submarca, _submarca);
}

void CVehiculo::setModelo(char* _modelo){
	strcpy(modelo, _modelo);
}

void CVehiculo::setKm(int _km){
	km = _km;
}

void CVehiculo::setEncendido(){
	encendido=true;
}

void CVehiculo::setApagado(){
	encendido=false;
}

void CVehiculo::setVelocidad(int _vel){
	velocidad=_vel;
}

void CVehiculo::aumentaVel(int plus){
	velocidad+=plus;
}

void CVehiculo::decrementaVel(int minus){
	velocidad-=minus;
}


//gets
int CVehiculo::getKm(){
	return km;
}

char* CVehiculo::getMarca(){
	return marca;
}
char* CVehiculo::getSubmarca(){
	return submarca;
}

char* CVehiculo::getModelo(){
	return modelo;
}

bool CVehiculo::getEncendido(){
	return encendido;
}

int CVehiculo::getVelocidad(){
	return velocidad;
}

char* CVehiculo::toString(){
	char * texto = new char [100];
	strcpy(texto,"Estado fisico: ");
	strcat(texto,"");
	strcat(texto,", color: ");
	strcat(texto,color);
	strcat(texto,", marca: ");
	strcat(texto,marca);
	return texto;
}
