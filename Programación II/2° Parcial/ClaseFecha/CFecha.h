#ifndef CFecha_h
#define CFecha_h
#include <iostream>

using namespace std;

class CFecha
{
private:
	int dia;
	int mes;
	int ano;
public:
	
	//cosntructores
	CFecha(void);
	CFecha(int,int,int);
	CFecha(const CFecha&);
	
	//set & get
	void setDia(int);
	void setMes(int);
	void setAno(int);
	
	int getDia();
	int getMes();
	int getAno();
	
	//Mostrar fecha
	char* mostrarFecha();
	
	//operadores de flujo (añadido personal)
	friend ostream& operator<< (ostream&,const CFecha&);
	friend istream& operator>> (istream&,CFecha&);
};

#endif