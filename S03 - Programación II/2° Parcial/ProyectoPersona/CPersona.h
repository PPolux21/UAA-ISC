#ifndef CPersona_h
#define CPersona_h
#include <iostream>

using namespace std;

class CPersona
{	
private:
	char *curp;
	char *nombre;
	char *apellidoP;
	char *apellidoM;
	int edad;
	char sexo;
public:	
	float peso;
	float altura;
	
	//costructores
	CPersona(void);
	CPersona(char*,char*,char*,char*,int,char);
	CPersona(const CPersona& c);
	
	//sets
	void setCurp(char*);
	void setNombre(char*);
	void setApellidoP(char*);
	void setApellidoM(char*);
	void setEdad(int);
	void setSexo(char);
	
	//gets
	char* getCurp();
	char* getNombre();
	char* getApellidoP();
	char* getApellidoM();
	int getEdad();
	char getSexo();
	
	char* toString();
	
	//métodos extra
	float calcImc(float,float);
	bool mayorEdad(int);
	
	//descructores
	~CPersona();	
};

#endif