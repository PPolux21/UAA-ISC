#include "CFecha.h"
#include <iostream>

using namespace std;

//cosntructores
CFecha::CFecha(void)
{
	dia = 1;
	mes = 1;
	ano = 0;
}

CFecha::CFecha(int _dia,int _mes,int _ano)
{
	dia = _dia;
	mes = _mes;
	ano = _ano;		
}

CFecha::CFecha(const CFecha& obj)
{
	dia = obj.dia;
	mes = obj.mes;
	ano = obj.ano;
}
	
//set & get
void CFecha::setDia(int _dia)
{
	dia = _dia;
}

void CFecha::setMes(int _mes)
{
	mes = _mes;
}

void CFecha::setAno(int _ano)
{
	ano = _ano;
}
	
	
int CFecha::getDia()
{
	return dia;
}

int CFecha::getMes()
{
	return mes;
}

int CFecha::getAno()
{
	return ano;
}
	
//Mostrar fecha
char* CFecha::mostrarFecha()//simil a toString
{
	char* texto = new char[10];
	sprintf(texto,"%d/%d/%d",dia,mes,ano);
	return texto;
}

//operadores de flujo (facilidad de llenado y muestra de fecha)
ostream& operator<< (ostream& co,const CFecha& obj)
{
	co.width(2);
	co.fill('0');
	co<<obj.dia<<"/";
	co.width(2);
	co.fill('0');
	co<<obj.mes<<"/";
	co.width(4);
	co.fill('0');
	co<<obj.ano;
	return co;
}

istream& operator>> (istream& in,CFecha& obj)
{
	cout<<"Introduce dato de la fecha:"<<endl;
	cout<<"\tDia: ";
	cin>>obj.dia;
	cout<<"\tMes: ";
	cin>>obj.mes;
	cout<<"\tAno: ";
	cin>>obj.ano;
	return in;
}