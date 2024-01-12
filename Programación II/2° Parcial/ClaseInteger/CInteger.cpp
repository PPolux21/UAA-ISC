#include "CInteger.h"
#include <iostream>


//cosntructores
CInteger::CInteger(void)
{
	num = 0;
}

CInteger::CInteger(int _num)
{
	num = _num;
}

CInteger::CInteger(float _num)
{
	num = (int)_num;
}

CInteger::CInteger(double _num)
{
	num = (int)_num;
}

CInteger::CInteger(const CInteger& obj)
{
	num = obj.num;
}

//set & gets
void CInteger::setValue(int _num)
{
	num = _num;
}

int CInteger::getValue()
{
	return num;
}

//metodos to_____
float CInteger::toFloat()
{
	float aux=num;
	return aux;
}

double CInteger::toDouble()
{
	double aux=num;
	return aux;
}

char* CInteger::toString()
{
	char* texto = new char[16];
	sprintf(texto,"%d",num);
	return texto;
}

//operaciones aritméticas
CInteger CInteger::operator+ (const CInteger& obj)
{
	CInteger res;
	
	res = this->num + obj.num;
	
	return res;
}

CInteger CInteger::operator- (const CInteger& obj)
{
	CInteger res;
	
	res = this->num - obj.num;
	
	return res;
}

CInteger CInteger::operator* (const CInteger& obj)
{
	CInteger res;
	
	res = this->num * obj.num;
	
	return res;
}

CInteger CInteger::operator/ (const CInteger& obj)
{
	CInteger res;
	
	res = this->num / obj.num;
	
	return res;
}

CInteger CInteger::operator= (const CInteger& obj)
{
	this->num = obj.num;
	
	return (*this);
}

ostream& operator<< (ostream& co, const CInteger& obj)
{
	co<<obj.num;
	return co;
}

istream& operator>> (istream& in,CInteger& obj)
{
	cout<<"Numero entero: ";
	cin>>obj.num;
	return in;
}