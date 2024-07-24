#pragma once

#include <iostream>
#include <string.h>

using namespace std;

#ifndef personajes_hpp
#define personajes_hpp

class CPersonajes
{
protected:
    int posX;
    int posY;
    float velX;
    float velY;
    int direccion;
public:
    CPersonajes(int _posX,int _posY,float _velX,float _velY, int _direccion)
    :posX(_posX),posY(_posY),velX(_velX),velY(_velY),direccion(_direccion){};
    virtual void pintar() = 0;
    virtual void fisica(float dt) = 0;
};




class CJugador: private CPersonajes
{
private:
    char nombre[3];
    int vidas;
    long puntuacion;
    long tiempoTotal;
public:
    CJugador(int _posX,int _posY,float _velX,float _velY, int _direccion);
    virtual void pintar();
    virtual void fisica(float dt);
    friend void selectorNombre();
    friend void ordenaLista();
    friend void menuPintar(int i,int escenario);
    friend class CPintar;
    CJugador operator= (const CJugador&);
    friend ostream& operator<< (ostream&, const CJugador&);
};

CJugador::CJugador(int _posX,int _posY,float _velX,float _velY, int _direccion):CPersonajes(_posX,_posY,_velX,_velY, _direccion)
{
    strcpy(nombre,"AAA");
    vidas = 5;
    puntuacion = 0;
    tiempoTotal = 0;
}

void CJugador::pintar()
{

}
void CJugador::fisica(float dt)
{

}

CJugador CJugador::operator= (const CJugador& obj)
{
    this->posX = obj.posX;
    this->posY = obj.posY;
    this->velX = obj.velX;
    this->velY = obj.velY;
    this->direccion = obj.direccion;
    strcpy(this->nombre,obj.nombre);
    this->vidas = obj.vidas;
    this->puntuacion = obj.puntuacion;
    this->tiempoTotal = obj.tiempoTotal;
    return (*this);
}

ostream& operator<< (ostream& co, const CJugador& obj)
{
    co<<obj.posX<<" "<<obj.posY<<" "<<obj.velX<<" "<<obj.velY<<" "<<obj.direccion<<" "
    <<obj.nombre<<" "<<obj.vidas<<" "<<obj.puntuacion<<" "<<obj.tiempoTotal;
    return co;
}

#endif