#include "CFraccion.h"
#include <iostream>

using namespace std;

//constructores
CFraccion::CFraccion()
{
	numer=0;
	denom=1;
}

CFraccion::CFraccion(int n,int d)
{
	numer = n;
	denom = d;
}

CFraccion::CFraccion(const CFraccion& obj)
{
	numer = obj.numer;
	denom = obj.denom;
}

//sets
void CFraccion::setNumer(int n)
{
	numer = n;
}

void CFraccion::setDenom(int d)
{
	denom = d;
}

//gets	
int CFraccion::getNumer()
{
	return numer;
}

int CFraccion::getDenom()
{
	return denom;
}

char* CFraccion::toString()
{
	char* texto = new char [15];
	sprintf(texto,"%d / %d",numer,denom);
	return texto;
}

//operaciones recibiendo dos eneteros
CFraccion CFraccion::suma(int n,int d)
{
	CFraccion res;
	
	res.setNumer(this->numer*d + n*this->denom);
	res.setDenom(this->denom*d);
	
	return res;
}

CFraccion CFraccion::resta(int n,int d)
{
	CFraccion res;
	
	res.setNumer(this->numer*d - n*this->denom);
	res.setDenom(this->denom*d);
	
	return res;
}

CFraccion CFraccion::mult(int n,int d)
{
	CFraccion res;
	
	res.setNumer(this->numer*n);
	res.setDenom(this->denom*d);
	
	return res;
}

CFraccion CFraccion::div(int n,int d)
{
	CFraccion res;
	
	res.setNumer(this->numer*d);
	res.setDenom(this->denom*n);
	
	return res;
}

//operaciones recibiendo objeto
CFraccion CFraccion::suma(CFraccion obj)
{
	CFraccion res;
	
	res.setNumer(this->numer*obj.denom + obj.numer*this->denom);
	res.setDenom(this->denom*obj.denom);
	
	return res;
}

CFraccion CFraccion::resta(CFraccion obj)
{
	CFraccion res;
	
	res.setNumer(this->numer*obj.denom - obj.numer*this->denom);
	res.setDenom(this->denom*obj.denom);
	
	return res;
}

CFraccion CFraccion::mult(CFraccion obj)
{
	CFraccion res;
	
	res.setNumer(this->numer*obj.numer);
	res.setDenom(this->denom*obj.denom);
	
	return res;
}

CFraccion CFraccion::div(CFraccion obj)
{
	CFraccion res;
	
	res.setNumer(this->numer*obj.denom);
	res.setDenom(this->denom*obj.numer);
	
	return res;
}

//sobrecarga de operadores
CFraccion CFraccion::operator+ (const CFraccion &obj)
{
	CFraccion res;
	
	res.numer = (numer * obj.denom) + (obj.numer * denom);
	res.denom = denom * obj.denom;
	
	return res;
}

CFraccion CFraccion::operator- (const CFraccion &obj)
{
	CFraccion res;
	
	res.numer = (numer * obj.denom) - (obj.numer * denom);
	res.denom = denom * obj.denom;
	
	return res;
}

CFraccion CFraccion::operator* (const CFraccion &obj)
{
	CFraccion res;
	
	res.numer = numer * obj.numer;
	res.denom = denom * obj.denom;
	
	return res;
}

CFraccion CFraccion::operator/ (const CFraccion &obj)
{
	CFraccion res;
	
	res.numer = numer * obj.denom;
	res.denom = denom * obj.numer;
	
	return res;
}

CFraccion CFraccion::operator= (const CFraccion& obj)
{
	this->numer = obj.numer;
	this->denom = obj.denom;
	return (*this);
}

CFraccion CFraccion::operator++ ()
{
	(this->numer)++;
	return (*this);
}

//Operadores lógicos y de I/O
bool operator== (CFraccion &a, CFraccion &b)
{
	if(a.numer==b.numer && a.denom==b.denom)
		return true;
	else
		return false;
}

bool operator!= (CFraccion &a, CFraccion &b)
{
	if(a.numer!=b.numer || a.denom!=b.denom)
		return true;
	else
		return false;
}

bool operator< (CFraccion &a, CFraccion &b)
{
	if((a.numer<b.numer || a.denom<b.denom) && (a.numer%b.numer!=0 || a.denom%b.denom!=0))
		return true;
	else
		return false;
}

bool operator> (CFraccion &a, CFraccion &b)
{
	if((a.numer>b.numer || a.denom>b.denom) && (b.numer%a.numer!=0 || b.denom%a.denom!=0))
		return true;
	else
		return false;
}

bool operator<= (CFraccion &a, CFraccion &b)
{
	if((a.numer<=b.numer && a.denom<=b.denom) || (a.numer%b.numer==0 && a.denom%b.denom==0))
		return true;
	else
		return false;
}

bool operator>= (CFraccion &a, CFraccion &b)
{
	if((a.numer>=b.numer && a.denom>=b.denom) || (b.numer%a.numer==0 && b.denom%a.denom==0))
		return true;
	else
		return false;
}

ostream& operator<< (ostream& co, const CFraccion &obj)
{
	co<<obj.numer<<"/"<<obj.denom;
	return co;
} 

istream& operator>> (istream& in, CFraccion &obj)
{
	cout<<"Introduce los valores de la fraccion: "<<endl;
	cout<<"\tNumerador: ";
	cin>>obj.numer;
	cout<<"\tDenumerador: ";
	cin>>obj.denom;
	return in;
} 