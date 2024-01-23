#ifndef CPersonajeBounce_h
#define CPersonajeBounce_h

#include "CPersonaje.h"

class CPersonajeBounce:public CPersonaje
{
public:
	CPersonajeBounce(const char* _img,int _posX,int _posY,float _velX,float _velY);
	
	void fisica(float dt);
};

CPersonajeBounce::CPersonajeBounce(const char* _img,int _posX,int _posY,float _velX,float _velY):CPersonaje(_img,_posX,_posY,_velX,_velY)
{
}

void CPersonajeBounce::fisica(float dt)
{
	posX += velX * dt;
	posY += velY * dt;
	
	if((velX<0 && posX<=0)||(velX>0 && posX>=ANCHO))
	{
		velX = -velX;
	}
	
	if((velY<0 && posY<0)||(velY>0 && posY>=ALTO))
	{
		velY = -velY;	
	}
		
}

#endif