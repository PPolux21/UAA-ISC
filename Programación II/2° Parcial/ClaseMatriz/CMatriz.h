#ifndef CMatriz_h
#define CMatriz_h
#include <iostream>

using namespace std;

class CMatriz
{
private:
	int mat[3][3];
public:
	
	//constuctores
	CMatriz(void);
	CMatriz(int,int,int,int,int,int,int,int,int);
	CMatriz(const CMatriz&);
	
	//sets & gets
	void setNum(int,int,int);
	
	int getNum(int,int);
	
	//operadores 
	CMatriz operator+ (const CMatriz&);
	CMatriz operator- (const CMatriz&);
	CMatriz operator= (const CMatriz&);
	
	friend bool operator== (CMatriz&,CMatriz&);
	friend bool operator!= (CMatriz&,CMatriz&);
	friend ostream& operator<< (ostream&,const CMatriz&);
	friend istream& operator>> (istream&,CMatriz&);
};

#endif