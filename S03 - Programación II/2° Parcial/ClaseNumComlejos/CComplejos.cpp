#include "CComplejos.h"
#include <iostream>
#include <math.h>

using namespace std;

//constructores
CComplejos::CComplejos(void)
{
	real = 0;
	imagin = 0;
}

CComplejos::CComplejos(int _real, int _imagin)
{
	real = _real;
	imagin = _imagin;
}

CComplejos::CComplejos(const CComplejos& obj)
{
	real = obj.real;
	imagin = obj.imagin;
}
	
//set & get
void CComplejos::setReal(int _real)
{
	real = _real;
}

void CComplejos::setImaginario(int _imagin)
{
	imagin = _imagin;
}

int CComplejos::getReal()
{
	return real;
}

int CComplejos::getImaginario()
{
	return imagin;
}

char* CComplejos::toString()
{
	char* texto = new char [20];
	sprintf(texto,"%d + (%d)i",real,imagin);
	return texto;
}
	
//funciones extra
	//operadores aritméticos
CComplejos CComplejos::operator+ (const CComplejos& obj)
{
	CComplejos res;
	
	res.real = this->real + obj.real;
	res.imagin = this->imagin + obj.imagin;
	
	return res;
}

CComplejos CComplejos::operator- (const CComplejos& obj)
{
	CComplejos res;
	
	res.real = this->real - obj.real;
	res.imagin = this->imagin - obj.imagin;
	
	return res;
}

CComplejos CComplejos::operator* (const CComplejos& obj)
{
	CComplejos res;
	
	res.real = (this->real * obj.real) - (this->imagin * obj.imagin);
	res.imagin = (this->real * obj.imagin) + (this->imagin * obj.real);
	
	return res;
}

CComplejos CComplejos::operator/ (const CComplejos& obj)
{
	CComplejos res, aux;
	
	aux.real = (this->real * obj.real) - (this->imagin * (- obj.imagin));
	aux.imagin = (this->real * (- obj.imagin)) + (this->imagin * obj.real);
	
	res.real = aux.real / (pow(obj.real,2) + pow(obj.imagin,2));
	res.imagin = aux.imagin / (pow(obj.real,2) + pow(obj.imagin,2));
	
	return res;
}

CComplejos CComplejos::operator= (const CComplejos& obj)
{
	this->real = obj.real;
	this->imagin = obj.imagin;
	return (*this);
}

	//operadores lógiccos	
bool operator== (CComplejos& a,CComplejos& b)
{
	if(a.real==b.real && a.imagin==b.imagin)
		return true;
	else
		return false;
}

bool operator!= (CComplejos& a,CComplejos& b)
{
	if(a.real!=b.real || a.imagin!=b.imagin)
		return true;
	else
		return false;
}

bool operator< (CComplejos& a,CComplejos& b)
{
	float magA,magB;
	
	magA = sqrt(pow(a.real,2)+pow(a.imagin,2));
	magB = sqrt(pow(b.real,2)+pow(b.imagin,2));
	
	if(magA<magB)
		return true;
	else
		return false;
}

bool operator> (CComplejos& a,CComplejos& b)
{
	float magA,magB;
	
	magA = sqrt(pow(a.real,2)+pow(a.imagin,2));
	magB = sqrt(pow(b.real,2)+pow(b.imagin,2));
	
	if(magA>magB)
		return true;
	else
		return false;
}

bool operator<= (CComplejos& a,CComplejos& b)
{
	float magA,magB;
	
	magA = sqrt(pow(a.real,2)+pow(a.imagin,2));
	magB = sqrt(pow(b.real,2)+pow(b.imagin,2));
	
	if(magA<=magB)
		return true;
	else
		return false;
}

bool operator>= (CComplejos& a,CComplejos& b)
{
	float magA,magB;
	
	magA = sqrt(pow(a.real,2)+pow(a.imagin,2));
	magB = sqrt(pow(b.real,2)+pow(b.imagin,2));
	
	if(magA>=magB)
		return true;
	else
		return false;
}

ostream& operator<< (ostream& co, const CComplejos& obj)
{
	co<<obj.real<<" + ("<<obj.imagin<<")i";
	return co;
}

istream& operator>> (istream& in, CComplejos& obj)
{
	cout<<"Introduce los valores del numero complejo: "<<endl;
	cout<<"\tComponente Real: ";
	cin>>obj.real;
	cout<<"\tComponente Imaginaria: ";
	cin>>obj.imagin;
	return in;
}