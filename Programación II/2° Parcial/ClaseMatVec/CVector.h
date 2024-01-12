#ifndef CVector_h
#define CVector_h
#include "CMatriz.h"
#include <iostream>

using namespace std;

class CVector
{
private:
	int vec[3];
public:
	
	//constuctores
	CVector(void);
	CVector(int,int,int);
	CVector(const CVector&);
	
	//sets & gets
	void setNum(int,int);
	
	int getNum(int);
	
	CVector multiplicar(CVector&);
	
	//operadores 
	CVector operator+ (const CVector&);
	CVector operator- (const CVector&);
	CVector operator= (const CVector&);
	
	friend bool operator== (CVector&,CVector&);
	friend bool operator!= (CVector&,CVector&);
	friend ostream& operator<< (ostream&,const CVector&);
	friend istream& operator>> (istream&,CVector&);
};

#endif