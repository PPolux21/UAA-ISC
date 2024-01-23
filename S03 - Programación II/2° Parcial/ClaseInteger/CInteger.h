#ifndef CInteger_h
#define CInteger_h
#include <iostream>

using namespace std;

class CInteger
{
private:
	int num;
public:
	
	//cosntructores
	CInteger(void);
	CInteger(int);
	CInteger(float);
	CInteger(double);
	CInteger(const CInteger&);
	
	//set & gets
	void setValue(int);
	
	int getValue();
	
	//metodos to______
	float toFloat();
	double toDouble();
	char* toString();
	
	//operaciones aritméticas
	CInteger operator+ (const CInteger&);
	CInteger operator- (const CInteger&);
	CInteger operator* (const CInteger&);
	CInteger operator/ (const CInteger&);
	CInteger operator= (const CInteger&);
	
	friend ostream& operator<< (ostream&, const CInteger&);
	friend istream& operator>> (istream&,CInteger&);
};

#endif