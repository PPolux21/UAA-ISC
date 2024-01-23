#ifndef CPersonajeKey_h
#define CPersonajeKey_h

#include "CPersonaje.h"

class CPersonajeKey:public CPersonaje
{
public:	
	int dir;
	int rot;
	CPersonajeKey(const char* _img,int _posX,int _posY,float _velX,float _velY,int _dir,int _rot);
	
	void fisica(float dt);
};

CPersonajeKey::CPersonajeKey(const char* _img,int _posX,int _posY,float _velX,float _velY,int _dir,int _rot):CPersonaje(_img,_posX,_posY,_velX,_velY)
{
	dir = _dir;
	rot = _rot;
}

void CPersonajeKey::fisica(float dt)
{
	if(dir==DERECHA)
	{
		posX += velX * dt;
		if(posX>ANCHO-20)
			posX=ANCHO-20;
	}
	
	if(dir==IZQUIERDA)
	{
		posX -= velX * dt;
		if(posX<0)
			posX=0;
	}
	
	if(dir==ABAJO)
	{
		posY += velY * dt;
		if(posY>ALTO-20)
			posY=ALTO-20;
	}
	
	if(dir==ARRIBA)
	{
		posY -= velX * dt;
		if(posY<0)
			posY=0;
	}
}


#endif