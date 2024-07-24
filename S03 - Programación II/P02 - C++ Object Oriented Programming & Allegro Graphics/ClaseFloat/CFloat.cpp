#include "CFloat.h"
#include <iostream>

using namespace std;

//cosntructores
CFloat::CFloat(void)
{
	num = 0;
}

CFloat::CFloat(float _num)
{
	num = _num;
}

CFloat::CFloat(int _num)
{
	num = (float)_num;
}

CFloat::CFloat(double _num)
{
	num = (float)_num;
}

CFloat::CFloat(const CFloat& obj)
{
	num = obj.num;
}

//set & gets
void CFloat::setValue(float _num)
{
	num = _num;
}

int CFloat::getValue()
{
	return num;
}

//metodos to_____
int CFloat::toInt()
{
	int aux = num;
	return aux;
}

double CFloat::toDouble()
{
	double aux = num;
	return aux;
}

char* CFloat::toString()
{
	char* texto = new char[32];
	sprintf(texto,"%f",num);
	return texto;
}

//operaciones aritméticas
CFloat CFloat::operator+ (const CFloat& obj)
{
	CFloat res;
	
	res = this->num + obj.num;
	
	return res;
}

CFloat CFloat::operator- (const CFloat& obj)
{
	CFloat res;
	
	res = this->num - obj.num;
	
	return res;
}

CFloat CFloat::operator* (const CFloat& obj)
{
	CFloat res;
	
	res = this->num * obj.num;
	
	return res;
}

CFloat CFloat::operator/ (const CFloat& obj)
{
	CFloat res;
	
	res = this->num / obj.num;
	
	return res;
}

CFloat CFloat::operator= (const CFloat& obj)
{
	this->num = obj.num;
	
	return (*this);
}

//operadores de flujo
ostream& operator<< (ostream& co, const CFloat& obj)
{
	co<<obj.num;
	return co;
}

istream& operator>> (istream& in,CFloat& obj)
{
	cout<<"Numero con punto flotante: ";
	cin>>obj.num;
	return in;
}