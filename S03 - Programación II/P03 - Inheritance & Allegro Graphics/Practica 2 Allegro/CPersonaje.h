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
protected:
	ALLEGRO_BITMAP* img;
	int posX,posY;
	float velX,velY;	
public:
	CPersonaje(const char* _img,int _posX,int _posY,float _velX,float _velY);
	
	void pintar();
	
	friend void pintar(int i);
	
	~CPersonaje();
};

CPersonaje::CPersonaje(const char* _img,int _posX,int _posY,float _velX,float _velY)
{
	img = al_load_bitmap(_img);
	posX=_posX;
	posY=_posY;
	velX=_velX;
	velY=_velY;
}

void CPersonaje::pintar()
{
	if(img!=NULL)
		al_draw_bitmap(img, posX, posY, 0);
}

CPersonaje::~CPersonaje()
{
	al_destroy_bitmap(img);
}
#endif