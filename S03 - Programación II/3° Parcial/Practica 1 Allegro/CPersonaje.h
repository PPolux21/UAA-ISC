#ifndef CPersonaje_h
#define CPersonaje_h

#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

class CPersonaje
{
private:
	ALLEGRO_BITMAP* imgPersonaje;
	int xPer,yPer;
	float vXPer,vYPer;
public:
	CPersonaje(const char* _imgPersonaje);
	CPersonaje(int _xPer,int _yPer,float _vXPer,float _vYPer);
	CPersonaje(const char* _imgPersonaje,int _xPer,int _yPer,float _vXPer,float _vYPer);
	
	void pintar();
	void fisica(float dt);
};

CPersonaje::CPersonaje(const char* _imgPersonaje)
{
	imgPersonaje = al_load_bitmap(_imgPersonaje);
	xPer=ANCHO/2;
	yPer=ALTO/2;
	vXPer=200;
	vYPer=200;
}

CPersonaje::CPersonaje(int _xPer,int _yPer,float _vXPer,float _vYPer)
{
	imgPersonaje = al_load_bitmap("pacman_mini_2.png");
	xPer=_xPer;
	yPer=_yPer;
	vXPer=_vXPer;
	vYPer=_vYPer;
}

CPersonaje::CPersonaje(const char* _imgPersonaje,int _xPer,int _yPer,float _vXPer,float _vYPer)
{
	imgPersonaje = al_load_bitmap(_imgPersonaje);
	xPer=_xPer;
	yPer=_yPer;
	vXPer=_vXPer;
	vYPer=_vYPer;
}

void CPersonaje::fisica(float dt)
{
	xPer += vXPer * dt;
	yPer += vYPer * dt;
	
	if((vXPer<0 && xPer<=0)||(vXPer>0 && xPer>=ANCHO))
	{
		vXPer = -vXPer;
	}
	
	if((vYPer<0 && yPer<0)||(vYPer>0 && yPer>=ALTO))
	{
		vYPer = -vYPer;	
	}
		
}

void CPersonaje::pintar()
{
	al_draw_bitmap(imgPersonaje, xPer, yPer, 0);
}

#endif