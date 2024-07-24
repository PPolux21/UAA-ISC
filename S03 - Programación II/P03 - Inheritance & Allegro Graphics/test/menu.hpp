#include <allegro5/timer.h>
#include <allegro5/allegro_font.h>
#include <iostream>
#include <stdlib.h>

#ifndef menu_hpp
#define menu_hpp

#define ALTO 600
#define ANCHO 800

ALLEGRO_EVENT event;
ALLEGRO_TIMER* timer = NULL;
ALLEGRO_EVENT_QUEUE* queue = NULL;
ALLEGRO_DISPLAY* display = NULL;
ALLEGRO_FONT* font = NULL;

char nombre[] = {"AAA"};// Luego se cambiará al nombre que exista para el parsonaje del usuario
int charPos = 0; // Auxiliar para determinar la posicion a cambiar del nombre de usuario

bool done;
bool redraw;

int mouseX;
int mouseY;
int opcionMenu;
int escenario = 0;
int i;

ALLEGRO_BITMAP* menuBackground;
ALLEGRO_BITMAP* menuSelector;
ALLEGRO_BITMAP* menuSelectorShort;
ALLEGRO_BITMAP* menuTitle;
ALLEGRO_BITMAP* menuNewPartida;
ALLEGRO_BITMAP* menuSelectorPartida;
ALLEGRO_BITMAP* cajaTexto;


void menuPintar(int , int );
int init();
void deinit();
void selectorNombre();

#endif