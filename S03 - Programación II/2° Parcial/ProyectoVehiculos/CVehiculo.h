//Se define la existencia de una clase CVehiculo_h
#ifndef CVehiculo_h
#define CVehiculo_h
#include <iostream>

using namespace std;

//Nombre de la clase :O
class CVehiculo{
	
	//Atributos privados (se modifica dentro de la clase)
private:
	char *marca;
	char *submarca;
	char *modelo;
	int km;
	bool encendido;
	int velocidad;
	
	//Atributos publicos (se modifica dentro y fuera de la clase)
public:
	int edoFisico;
	char *color;
	
	//constructores
	CVehiculo (void);
	CVehiculo (char*,char*,char*,int,int,char*);
	
	//sets & gets
	void setMarca(char*);
	void setSubmarca(char*);
	void setModelo(char*);
	void setKm(int);
	void setEncendido();
	void setApagado();
	void setVelocidad(int);
	void aumentaVel(int);
	void decrementaVel(int);
	
	int getKm();
	char* getMarca();
	char* getSubmarca();
	char* getModelo();s
	bool getEncendido();
	int getVelocidad();
	
	//metodo toString
	char* toString();//regresa toda la información de la clase
	
	//Destructor
	~CVehiculo();
};

#endif