#ifndef CFloat_h
#define CFloat_h
#include <iostream>

using namespace std;

class CFloat
{
private:
	float num;
public:
	
	//cosntructores
	CFloat(void);
	CFloat(float);
	CFloat(int);
	CFloat(double);
	CFloat(const CFloat&);
	
	//set & gets
	void setValue(float);
	
	int getValue();
	
	//metodos to_____
	int toInt();
	double toDouble();
	char* toString();
	
	//operaciones aritméticas
	CFloat operator+ (const CFloat&);
	CFloat operator- (const CFloat&);
	CFloat operator* (const CFloat&);
	CFloat operator/ (const CFloat&);
	CFloat operator= (const CFloat&);
	
	friend ostream& operator<< (ostream&, const CFloat&);
	friend istream& operator>> (istream&,CFloat&);
};

#endif