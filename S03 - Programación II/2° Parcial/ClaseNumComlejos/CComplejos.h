#ifndef CComplejos_h
#define CComplejos_h
#include <iostream>

using namespace std;

class CComplejos{
private:
	int real;
	int imagin;
public:
	
	//constructores
	CComplejos(void);
	CComplejos(int, int);
	CComplejos(const CComplejos&);
	
	//set & get
	void setReal(int);
	void setImaginario(int);
	
	int getReal();
	int getImaginario();
	
	char* toString();
	
	//funciones extra
	CComplejos operator+ (const CComplejos&);
	CComplejos operator- (const CComplejos&);	
	CComplejos operator* (const CComplejos&);	
	CComplejos operator/ (const CComplejos&);	
	CComplejos operator= (const CComplejos&);
	
	friend bool operator== (CComplejos&,CComplejos&);
	friend bool operator!= (CComplejos&,CComplejos&);
	friend bool operator< (CComplejos&,CComplejos&);
	friend bool operator> (CComplejos&,CComplejos&);
	friend bool operator<= (CComplejos&,CComplejos&);
	friend bool operator>= (CComplejos&,CComplejos&);
	friend ostream& operator<< (ostream&, const CComplejos&);
	friend istream& operator>> (istream&, CComplejos&);
	
};

#endif