//
//  CJuego.cpp
//  testAllegro
//
//  Created by Jose de Jesus Palos on 08/11/22.
//  Copyright © 2022 Jose de Jesus Palos. All rights reserved.
//

#include "CJuego.hpp"
#include "CButton.h"
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

CJuego::CJuego (void){
    timer=NULL;
    queue=NULL;
    display = NULL;
    font = NULL;
    
    int posX=0;
    int posY=0;
    
    init();
    
    done = false;
    redraw = true;
    boton= CButton("button_green.png",20,20);
    boton2= CButton("button_green.png","button_red.png",520,520);

    al_start_timer(timer);
}

CJuego::~CJuego(){
    deinit();
}

void CJuego::run(){
    
    while(1)
    {
        al_wait_for_event(queue, &event);
        switch(event.type)
        {
            case ALLEGRO_EVENT_TIMER:
                // logica del juego.
                redraw = true;
                break;
                
            case ALLEGRO_EVENT_MOUSE_AXES:
            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
            case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
            	logicaMouse();
            	break;
            	
            case ALLEGRO_EVENT_KEY_CHAR:
            case ALLEGRO_EVENT_KEY_DOWN:
            case ALLEGRO_EVENT_KEY_UP:
                logicaTeclado();
                break;
                
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                done = true;
                break;
        }
        
        if(done)
            break;
        
        if(redraw && al_is_event_queue_empty(queue))
        {
            pintar();
            redraw = false;
        }
    }
}

void CJuego::pintar(){
    //Limpiamos lienzo para pintar
    al_clear_to_color(al_map_rgb(25, 0, 60));
    //Pintamos texto
    al_draw_text(font, al_map_rgb(255, 255, 255), 0, 0, 0, "Hello world!");
    							//  r    g    b    x   y  
    al_draw_textf(font, al_map_rgb(255, 255, 255), 0, 20, 0, "PosX:%i",posX);
    al_draw_textf(font, al_map_rgb(255, 255, 255), 0, 50, 0, "PosY:%i",posY);
    
    boton.paint();
    boton2.paint();
    
    al_draw_textf(font,al_map_rgb(255,255,255),0,20,0,"Mouse (%i, %i)",msestate.x,msestate.y);
    
    for(int i=0;i<= NUM_BUTTONS;i++){
    	draw_mouse_button(i,al_mosue_button(&msestate,i));
	}
    
    al_draw_circle(450+posX, 370+posY, 30, al_map_rgb_f(1,0,1),2);
    //mandamos a pantalla
    al_flip_display();
}


void CJuego::logicaTeclado(){
    if (event.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
        posX++;
    }
    if (event.keyboard.keycode == ALLEGRO_KEY_LEFT) {
        posX--;
    }
    if (event.keyboard.keycode == ALLEGRO_KEY_UP) {
    	posY--;
    }
    if (event.keyboard.keycode == ALLEGRO_KEY_DOWN) {
    	posY++;
    }
}

void CJuego::logicaMouse(){
	al_get_mouse_state(&msestate);
	
	boton.estaSobre(msestate.x,msestate.y);
	boton2.estaSobre(msestate.x,msestate.y);
	
	if(al_mouse_button_down(&msestate,1) && boton.esSobre){
		boton.setPos(msestate.x-100,msestate.y-100);
	}
}

int CJuego::init() {
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
    
    //Inicializamos parntalla de 640x480
    //display = al_create_display(1600, 1200);
    display = al_create_display(640, 480);
    if(!display)
    {
        printf("couldn't initialize display\n");
        return 1;
    }
    
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_register_event_source(queue, al_get_mouse_event_source());
    
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
    al_register_event_source(queue, al_get_mouse_event_source());
    
    return 0;
}

void CJuego::deinit() {
    
    al_destroy_bitmap(uaa);
    //al_clear_keybuf();
    /* add other deinitializations here */
    al_destroy_font(font);
    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
}

