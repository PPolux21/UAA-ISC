#ifndef pacman_hpp
#define pacman_hpp

#define ALTO 600
#define ANCHO 800

#define ARRIBA 1
#define ABAJO 2
#define IZQUIERDA 3
#define DERECHA 4

#define TAM 30

ALLEGRO_TIMER* timer=NULL;
ALLEGRO_EVENT_QUEUE* queue=NULL;
ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_FONT* font = NULL;

ALLEGRO_EVENT event;

ALLEGRO_BITMAP* background;

ALLEGRO_BITMAP* imgPersonaje;
int xPer, yPer;
float vXPer, vYPer;
int direccion;
double dt;

ALLEGRO_BITMAP* imgPersonaje2;
int dir;
float rot;
int nImage=0;

ALLEGRO_BITMAP* muro;
ALLEGRO_BITMAP* item;
ALLEGRO_BITMAP* portal;

int mat[20][26]={
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,1,2,2,2,2,1,1,2,2,2,2,2,2,2,2,1,1,2,2,2,2,1,2,1},
	{1,2,1,2,1,1,2,2,2,2,2,1,2,2,1,2,2,2,2,2,1,1,2,1,2,1},
	{1,2,2,2,1,1,2,2,1,1,1,2,2,2,2,1,1,1,2,2,1,1,2,2,2,1},
	{1,1,1,2,1,1,2,2,1,2,1,2,2,2,2,1,2,1,2,2,1,1,2,1,1,1},
	{1,2,1,2,1,1,2,2,1,2,1,1,1,1,1,1,2,1,2,2,1,1,2,1,2,1},
	{1,2,2,2,2,1,2,2,2,2,1,1,2,2,1,1,2,2,2,2,1,2,2,2,2,1},
	{1,2,1,1,2,1,2,1,1,2,2,1,2,2,1,2,2,1,1,2,1,2,1,1,2,1},
	{1,2,2,1,2,2,2,1,2,2,2,2,2,2,2,2,2,2,1,2,2,2,1,2,2,1},
	{1,2,2,1,2,1,1,1,1,2,1,1,2,2,1,1,2,1,1,1,1,2,1,2,2,1},
	{1,2,1,1,2,2,1,1,2,2,1,1,2,2,1,1,2,2,1,1,2,2,1,1,2,1},
	{1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1},
	{1,2,1,1,2,2,1,2,2,1,1,1,2,2,1,1,1,2,2,1,2,2,1,1,2,1},
	{1,2,1,2,2,1,1,1,2,2,1,1,2,2,1,1,2,2,1,1,1,2,2,1,2,1},
	{1,2,1,2,2,2,2,1,1,2,2,1,2,2,1,2,2,1,1,2,2,2,2,1,2,1},
	{1,2,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,2,1},
	{1,2,2,2,2,1,2,2,1,2,1,2,2,2,2,1,2,1,2,2,1,2,2,2,2,1},
	{1,1,2,1,2,1,1,1,1,2,1,1,2,2,1,1,2,1,1,1,1,2,1,2,1,1},
	{1,2,2,1,2,2,2,2,2,2,1,2,2,2,2,1,2,2,2,2,2,2,1,2,2,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int iMat=0,jMat=0,hMat=0,kMat=0;
int pts=0;
int tiempo=0;

int init();
void deinit();
void pintar(int i);
void fisica(float dt);
bool lvlCompleted();

#endif /* main_hpp */


