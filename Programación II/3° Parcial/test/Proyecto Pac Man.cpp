//
//  main.cpp
//  testAllegro
//
//  Created by Jose de Jesus Palos on 26/10/22.
//  Copyright © 2022 Jose de Jesus Palos. All rights reserved.
//


#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include "main.hpp"

//xVPer, yVPer, xPer, yPer, dt, direction, dir, rot, tiempo, pts
CPac per(200,200, TAM, TAM, 0, DERECHA, 0, 0, 0);
//CMalo malo(200, 200, 25, 25, 0, ABAJO, 1,0);
//CPac malo(200,200,25,25,0, ABAJO);


int main(int argc, char** args) {

    init();

    int i = 0;

    bool done = false;
    bool redraw = true;
    ALLEGRO_EVENT event;

    background = al_load_bitmap("background.png");
    imgPersonaje = al_load_bitmap("Skeleton.png");
    imgPersonaje2 = al_load_bitmap("Skeleton.png");
    //imgPersonajeMalo[0] = al_load_bitmap("pacman_mini.png");
   // imgPersonajeMalo = al_load_bitmap("pacman_mini.png");
    //muro = al_load_bitmap("wall_mini.png");
    muro = al_load_bitmap("nether_bricks.png");
    item = al_load_bitmap("diamond.png");
    portal = al_load_bitmap("portal.png");
    //img = al_load_bitmap("pacman_mini.png");
    //INFO x;
    //x = structClase(x);

    al_start_timer(timer);

    float tActual = 0;
    float tAnterior = 0;

    while (1) {
        per.dt = tActual - tAnterior;
        //malo.dt = tActual - tAnterior;
        per.fisica();
        //malo.rutina_fantasma();
        //malo.fisica();
        al_wait_for_event(queue, &event);
        switch (event.type) {
            case ALLEGRO_EVENT_TIMER:
            // logica del juego
            redraw = true;
            break;
            case ALLEGRO_EVENT_KEY_DOWN:
                if ((event.keyboard.keycode == ALLEGRO_KEY_LEFT) || (event.keyboard.keycode == ALLEGRO_KEY_A)) {
                    per.direction = IZQUIERDA;
                }
                if ((event.keyboard.keycode == ALLEGRO_KEY_RIGHT) || (event.keyboard.keycode == ALLEGRO_KEY_D)) {
                    per.direction = DERECHA;
                }
                if ((event.keyboard.keycode == ALLEGRO_KEY_UP) || (event.keyboard.keycode == ALLEGRO_KEY_W)) {
                    per.direction = ARRIBA;
                }
                if ((event.keyboard.keycode == ALLEGRO_KEY_DOWN) || (event.keyboard.keycode == ALLEGRO_KEY_S)) {
                    per.direction = ABAJO;
                }
                break;
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                done = true;
             break;
        }

        if (done) {
            break;
        }
        if (redraw && al_is_event_queue_empty(queue)) {
            per.pintar();
            //malo.pintar();
            redraw = false;
        }
        tAnterior = tActual;
        tActual = al_get_time();
        per.tiempo = 500 - tActual;
    }


    //Destruimos y liberamos

    deinit();

    return 0;
}

/*
INFO structClase(INFO x){
    x.xVPer = 20;
    x.yPer = 20;
    x.xPer = 200;
    x.yPer = 200;
    x.dt = 0;
    x.direction;
    return x;
}
*/




int init() {
    //inicializamos allegro
    if (!al_init())
    {
        printf("couldn't initialize allegro\n");
        return 1;
    }
    //Inicializamos teclado
    if (!al_install_keyboard())
    {
        printf("couldn't initialize keyboard\n");
        return 1;
    }
    //Inicializamos timer y event_queue para garantizar
    //consistencia en la velocidad
    timer = al_create_timer(1.0 / 30.0);
    if (!timer)
    {
        printf("couldn't initialize timer\n");
        return 1;
    }

    //Create Keybord queue
    queue = al_create_event_queue();
    if (!queue)
    {
        printf("couldn't initialize queue\n");
        return 1;
    }

    //Inicializamos parntalla de 640x480
    display = al_create_display(ANCHO, ALTO);
    if (!display)
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
    if (!font)
    {
        printf("couldn't initialize font\n");
        return 1;
    }

    if (!al_init_image_addon())
    {
        printf("couldn't initialize image addon\n");
        return 1;
    }

    if (!al_init_primitives_addon())
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
    al_destroy_bitmap(imgPersonaje);
    al_destroy_bitmap(imgPersonaje2);
    //al_clear_keybuf();
    /* add other deinitializations here */
    al_destroy_font(font);
    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
    al_destroy_bitmap(background);

}


/*
CPac::CPac(INFO _x){
    x.xVPer = _x.xVPer;
    x.yVPer = _x.yVPer;
    x.xPer = _x.xPer;
    x.yPer = _x.yPer;
    x.dt = _x.dt;
    x.direction = _x.direction;
}*/


/*
 * ALEATORIOS
 xPer += vXPer * dt;
 yPer += vYPer * dt;

 if ((vXPer < 0 && xPer <= 0) || (vXPer > 0 && xPer >= ANCHO)) {
     vXPer = -vXPer;
 }
 if ((vYPer < 0 && yPer <= 0) || (vYPer > 0 && yPer >= ALTO)) {
     vYPer = -vYPer;
 }

 */