//
//  main.cpp
//  testAllegro
//
//  Created by Jose de Jesus Palos on 26/10/22.
//  Copyright © 2022 Jose de Jesus Palos. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

#include "main.hpp"

using namespace std;

int main(int argc,char **args) {
    srand(time(NULL));
    init();
    int i=0;
    
    bool done = false;
    bool redraw = true;
    ALLEGRO_EVENT event;
    
    uaa = al_load_bitmap("uaa.png");
    imgPersonaje = al_load_bitmap("pacman_mini.png");
    
    for(int i=0;i<PERSON;i++)
	{
		vector[i]=CPersonajeBounce("pacman_mini.png",rand()%ANCHO,rand()%ALTO,rand()%1500,rand()%1500);
	}
    
    // ...
    al_start_timer(timer);
    
    double tActual=0;
	double tAnterior=0;
    dt=0;
    
    while(1)
    {
    	dt=tActual-tAnterior;
    	personaje.fisica(dt);
    	
    	for(int i=0;i<PERSON;i++)
    	{
    		vector[i].fisica(dt);
		}
    	
        al_wait_for_event(queue, &event);
        switch(event.type)
        {
            case ALLEGRO_EVENT_TIMER:
                // logica del juego.
                redraw = true;
                break;
            case ALLEGRO_EVENT_KEY_DOWN:
            	if(event.keyboard.keycode==ALLEGRO_KEY_DOWN)
            	{
            		personaje.dir=ABAJO;
				}
				if(event.keyboard.keycode==ALLEGRO_KEY_UP)
            	{
            		personaje.dir=ARRIBA;
				}
				if(event.keyboard.keycode==ALLEGRO_KEY_LEFT)
            	{
            		personaje.dir=IZQUIERDA;
				}
				if(event.keyboard.keycode==ALLEGRO_KEY_RIGHT)
            	{
            		personaje.dir=DERECHA;
				}
				break;
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                done = true;
                break;
        }
        
        if(done)
            break;
        
        if(redraw && al_is_event_queue_empty(queue))
        {
            pintar(i++);
            redraw = false;
        }
        tAnterior=tActual;
        tActual=al_get_time();
    }
    //Destruimos y liberamos
    
    deinit();
    
	delete vector;
	
    return 0;
}

void pintar(int i){
    //Limpiamos lienzo para pintar
    al_clear_to_color(al_map_rgb(0, 0, 0));
    //Pintamos texto
    al_draw_text(font, al_map_rgb(255, 255, 255), 0, 100, 0, "Hello world!");
    char cadena[20],cadena2[20];
//    sprintf(cadena,"%d-%d, dt=%f",per1.yPer,i,dt);
//    sprintf(cadena2,"%d-%d, dt=%f",per2.yPer,i,dt);
//    al_draw_text(font, al_map_rgb(255, 200, 20), 0, 0, 0, cadena);
//    al_draw_text(font, al_map_rgb(200, 200, 50), 0, 20, 0, cadena2);
    //Pintamos imagen
    al_draw_bitmap(uaa, 10+i, 10, 0);
	
    /*for(int i=0;i<PERSON;i++)
    {
    	vector[i].pintar();
    	printf("wenas");
	}// son el vector 
	*/
    personaje.pintar();
    
    
	al_draw_bitmap(imgPersonaje, personaje.posX, personaje.posY, 0);
//    al_draw_bitmap(per2.imgPersonaje, per2.xPer, per2.yPer, 0);
    
    /*al_draw_filled_triangle(35, 350, 85, 375, 35, 400, al_map_rgb_f(0, 1, 0));
     al_draw_filled_rectangle(240, 260, 340, 340, al_map_rgba_f(0, 0, 0.5, 0.5));
     al_draw_circle(450, 370, 30, al_map_rgb_f(1, 0, 1), 2);
     al_draw_line(440, 110, 460, 210, al_map_rgb_f(1, 0, 0), 1);
     al_draw_line(500, 220, 570, 200, al_map_rgb_f(1, 1, 0), 1);*/
    
    
    //mandamos a pantalla
    al_flip_display();
}

int init() {
    //inicializamos allegro
    if(!al_init())
    {
        printf("couldn't initialize allegro\n");
        return 1;
    }
    //Inicializamos teclado
    if(!al_install_keyboard())
    {
        printf("couldn't initialize keyboard\n");
        return 1;
    }
    //Inicializamos timer y event_queue para garantizar
    //consistencia en la velocidad
    timer = al_create_timer(1.0 / 30.0);
    if(!timer)
    {
        printf("couldn't initialize timer\n");
        return 1;
    }
    
    //Create Keybord queue
    queue = al_create_event_queue();
    if(!queue)
    {
        printf("couldn't initialize queue\n");
        return 1;
    }
    
    //Inicializamos parntalla de ancho x alto
    display = al_create_display(ANCHO, ALTO);
    //display = al_create_display(640, 480);
    if(!display)
    {
        printf("couldn't initialize display\n");
        return 1;
    }
    
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer));
    
    //Inicializamos mouse
    al_install_mouse();
    /* add other initializations here */
    
    font = al_create_builtin_font();
    if(!font)
    {
        printf("couldn't initialize font\n");
        return 1;
    }
    
    if(!al_init_image_addon())
    {
        printf("couldn't initialize image addon\n");
        return 1;
    }
    
    if(!al_init_primitives_addon())
    {
        printf("couldn't initialize primitives\n");
        return 1;
    }
    
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer));
    
    return 0;
}

void deinit() {

    al_destroy_bitmap(uaa);
    //al_clear_keybuf();
    /* add other deinitializations here */
    for(int i=0;i<PERSON;i++)
    {
    	vector[i].~CPersonaje();
	}
    personaje.~CPersonaje();
    al_destroy_font(font);
    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
}