//
//  main.hpp
//  testAllegro
//
//  Created by Jose de Jesus Palos on 26/10/22.
//  Copyright © 2022 Jose de Jesus Palos. All rights reserved.
//

#ifndef main_hpp
#define main_hpp

#define PERSON 2

#define ARRIBA 1
#define ABAJO 2
#define IZQUIERDA 3
#define DERECHA 4

#define ALTO 600
#define ANCHO 800

#include "CPersonaje.h"
#include "CPersonajeKey.h"
#include "CPersonajeBounce.h"

ALLEGRO_TIMER* timer=NULL;
ALLEGRO_EVENT_QUEUE* queue=NULL;
ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_FONT* font = NULL;

ALLEGRO_EVENT event;

ALLEGRO_BITMAP* uaa;

ALLEGRO_BITMAP* imgPersonaje;

CPersonajeKey personaje=CPersonajeKey("pacman_mini.png",20,20,100,100,DERECHA,0);
CPersonajeBounce* vector=new CPersonajeBounce("pacman_mini.png",50,50,100,100);


double dt;

int init();
void deinit();
void pintar(int i);

#endif /* main_hpp */
