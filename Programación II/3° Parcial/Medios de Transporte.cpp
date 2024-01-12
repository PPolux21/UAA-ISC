#include <iostream>
#include <string>

using namespace std;

class CTransporte {
protected:
    int matricula;
    string marca;

public:
    CTransporte(int _matricula, string _marca) : matricula(_matricula), marca(_marca) {}
    virtual void transportarse() = 0;
};

class CTerrestre : public CTransporte {
protected:
    int no_llantas;

public:
    CTerrestre(int _matricula, string _marca, int _no_llantas) : CTransporte(_matricula, _marca),
    no_llantas(_no_llantas) {}
    virtual void transportarse() = 0;
};

class CCarro : public CTerrestre {
private:
    string modelo;
    float km;

public:
    CCarro(int _matricula, string _marca, int _no_llantas, string _modelo, float _km)
        : CTerrestre(_matricula, _marca, _no_llantas), modelo(_modelo), km(_km) {}

    void transportarse() ;
};

void CCarro::transportarse() {
    cout << "El auto tiene la matricula: " << matricula << " Modelo: " << modelo << endl;
    cout << "La marca del auto es: " << marca << endl;
    cout << "El numero de llantas es: " << no_llantas << endl;
    cout << "Kilometros a avanzar: " << km << endl;
}

class CAereo : public CTransporte {
protected:
    string tipo;
    int capacidad;

public:
    CAereo(int _matricula, string _marca, string _tipo, int _capacidad)
        : CTransporte(_matricula, _marca), tipo(_tipo), capacidad(_capacidad) {}
    virtual void transportarse() = 0;
};

class CAvion : public CAereo {
private:
    string aerolinea;

public:
    CAvion(int _matricula, string _marca, string _tipo, int _capacidad, string _aerolinea)
        : CAereo(_matricula, _marca, _tipo, _capacidad), aerolinea(_aerolinea) {}

    void transportarse() ;
};

void CAvion::transportarse() {
    cout << "El avion tiene la matricula: " << matricula << "   Marca: " << marca << endl;
    cout << "El tipo de avion es: " << tipo << endl;
    cout << "La aerolinea del avion es: " << aerolinea << endl;
    cout << "La capacidad es: " << capacidad << endl;
}

int main() {
    int numTrans = 2;
    CTransporte *metodo[2];

    metodo[0] = new CAvion(111, "boeing", "publico", 150, "Volaris");
    metodo[1] = new CCarro(327, "KIA", 4, "RIO", 25000);

    for (int i = 0; i < 2; i++) {
        metodo[i]->transportarse();
    }

    // Liberar memoria
    for (int i = 0; i < 2; i++) {
        delete metodo[i];
    }

    return 0;
}



