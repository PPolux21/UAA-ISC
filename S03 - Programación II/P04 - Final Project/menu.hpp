#include <allegro5/timer.h>
#include <allegro5/allegro_font.h>
#include <iostream>
#include <stdlib.h>

#ifndef menu_hpp
#define menu_hpp

#define ALTO 600
#define ANCHO 800

#define ARRIBA 1
#define ABAJO 2
#define IZQUIERDA 3
#define DERECHA 4
#define TAM 30

ALLEGRO_EVENT event;
ALLEGRO_TIMER* timer = NULL;
ALLEGRO_EVENT_QUEUE* queue = NULL;
ALLEGRO_DISPLAY* display = NULL;
ALLEGRO_FONT* font = NULL;

char nombre[] = { "AAA" };// Luego se cambiará al nombre que exista para el parsonaje del usuario
int charPos = 0; // Auxiliar para determinar la posicion a cambiar del nombre de usuario

bool done;
bool redraw;

int mouseX;
int mouseY;
int opcionMenu;
int escenario = 0;
int i;

int userCount = 0;
int userPage = 1;// para indicar la cantidad de paginas 
int pageView;//para indicar la pagina de la lista de usuarios que se está mostrando 
bool cargaArch;



ALLEGRO_BITMAP* menuBackground;
ALLEGRO_BITMAP* menuSelector;
ALLEGRO_BITMAP* menuSelectorShort;
ALLEGRO_BITMAP* menuTitle;
ALLEGRO_BITMAP* menuNewPartida;
ALLEGRO_BITMAP* menuSelectorPartida;
ALLEGRO_BITMAP* cajaTexto;
ALLEGRO_BITMAP* menuNivelesBackground;
ALLEGRO_BITMAP* imgNivel1;
ALLEGRO_BITMAP* imgNivel2;
ALLEGRO_BITMAP* imgNivel3;
ALLEGRO_BITMAP* cajaSi;
ALLEGRO_BITMAP* cajaNo;
ALLEGRO_BITMAP* cajaSeleccion;
ALLEGRO_BITMAP* imgPersonaje;
ALLEGRO_BITMAP* imgPersonaje2;
//ALLEGRO_BITMAP* imgPersonajeMalo[3];
ALLEGRO_BITMAP* muro;
ALLEGRO_BITMAP* item;
ALLEGRO_BITMAP* portal;
ALLEGRO_BITMAP* background;
ALLEGRO_BITMAP* instrucciones;
ALLEGRO_BITMAP* cajaVacia;
ALLEGRO_BITMAP* nivelIbackground;
ALLEGRO_BITMAP* muroNivel1;
ALLEGRO_BITMAP* muroNivel11;
ALLEGRO_BITMAP* muroNivel12;
ALLEGRO_BITMAP* muroNivel13; 
ALLEGRO_BITMAP* muroNivel16;
ALLEGRO_BITMAP* muroNivel3;
ALLEGRO_BITMAP* muroNivel32;
ALLEGRO_BITMAP* muroNivel33;
ALLEGRO_BITMAP* backGroundNivel3;
ALLEGRO_BITMAP* cajaOpciones;

void menuPintar(int, int);
int init();
void deinit();
void selectorNombre();
void cuentaUsuarios();
void lecturaArchivo();
void ordenaLista();
void cargar_imagenes();

#endif