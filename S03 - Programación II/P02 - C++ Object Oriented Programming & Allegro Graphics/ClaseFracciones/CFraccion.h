

#ifndef CFraccion_h
#define CFraccion_h
#include <iostream>

using namespace std;

class CFraccion
{
private:
	int numer; //numerador
	int denom; //denominador
	
public:
	
	//costructores
	CFraccion(void);
	CFraccion(int,int);
	CFraccion(const CFraccion&);
	
	//set & gets
	void setNumer(int);
	void setDenom(int);
	
	int getNumer();
	int getDenom();
	
	char* toString();
	
	//operaciones aritméticas
	CFraccion suma(int,int);
	CFraccion resta(int,int);
	CFraccion mult(int,int);
	CFraccion div(int,int);
	
	CFraccion suma(CFraccion);
	CFraccion resta(CFraccion);
	CFraccion mult(CFraccion);
	CFraccion div(CFraccion);
	
	CFraccion operator+ (const CFraccion&);
	CFraccion operator- (const CFraccion&);	
	CFraccion operator* (const CFraccion&);	
	CFraccion operator/ (const CFraccion&);	
	CFraccion operator= (const CFraccion&);
	CFraccion operator++ ();
	
	//operadores logicos
	friend bool operator== (CFraccion&,CFraccion&);
	friend bool operator!= (CFraccion&,CFraccion&);
	friend bool operator< (CFraccion&,CFraccion&);
	friend bool operator> (CFraccion&,CFraccion&);
	friend bool operator<= (CFraccion&,CFraccion&);
	friend bool operator>= (CFraccion&,CFraccion&);
	friend ostream& operator<< (ostream&, const CFraccion&);
	friend istream& operator>> (istream&, CFraccion&);
};

#endif