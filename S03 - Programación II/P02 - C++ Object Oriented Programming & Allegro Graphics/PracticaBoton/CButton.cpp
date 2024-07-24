#include "CButton.h"
#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

CButton::CButton(void)
{	
}

CButton::CButton(const char* archivo,int x,int y)
{
	press=false;
	this->x = x;
	this->y = y;
	btn = al_load_bitmap(archivo);
	btn_sobre = NULL;
}

CButton::CButton(const char* archivo,const char* archivoSobre,int x,int y)
{
	press=false;
	this->x = x;
	this->y = y;
	btn = al_load_bitmap(archivo);
	btn_sobre = al_load_bitmap(archivoSobre);
}

CButton::~CButton()
{	
}

void CButton::setPos(int mouse_x,int mouse_y)
{
	x=mouse_x;
	y=mouse_y;
}

void CButton::estaSobre(int mouse_x,int mouse_y)
{
	int tamx=360;
	int tamy=360;
	if(x < mouse_x && y < mouse_y && mouse_x < (x+tamx) && mouse_y <(y+tamy)){
		esSobre=true ;
	}else{
		esSobre=false;
	}
}

void CButton::paint()
{
	if(esSobre && btn_sobre){
		al_draw_bitmap(btn_sobre, x, y, 0);
		al_draw_bitmap(btn, x, y, 0);
	}
}