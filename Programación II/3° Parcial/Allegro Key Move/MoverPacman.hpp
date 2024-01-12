#ifndef pacman_hpp
#define pacman_hpp

#define ALTO 600
#define ANCHO 800
#define ARRIBA 1
#define ABAJO 2
#define IZQUIERDA 3
#define DERECHA 4

ALLEGRO_TIMER* timer=NULL;
ALLEGRO_EVENT_QUEUE* queue=NULL;
ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_FONT* font = NULL;

ALLEGRO_EVENT event;

ALLEGRO_BITMAP* uaa;

ALLEGRO_BITMAP* imgPersonaje;
int xPer, yPer;
float vXPer, vYPer;
int direccion;
double dt;

ALLEGRO_BITMAP* imgPersonaje2;
int dir;
float rot;
int nImage=0;


int init();
void deinit();
void pintar(int i);
void fisica(float dt);

#endif /* main_hpp */
