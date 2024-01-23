#ifndef CButton_hpp
#define CButton_hpp

#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

class CButton
{
private:
	int x,y;
	bool press;
	ALLEGRO_BITMAP *btn;
	ALLEGRO_BITMAP *btn_sobre;
public:	
	bool esSobre;
	
	CButton(void);
	CButton(const char* archivo,int x,int y);
	CButton(const char* archivo,const char* archivoSobre,int x,int y);
	//metodos
	void estaSobre(int mouse_x,int mouse_y);
	void setPos(int mouse_x,int mouse_y);
	void paint();
	//destructor
	~CButton(void);
};

#endif