#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include "MoverPacman.hpp"


int main(int argc,char **args) {
    
    init();
    
    int i=0;
    
    bool done = false;
    bool redraw = true;
    ALLEGRO_EVENT event;
    
    uaa = al_load_bitmap("uaa.png");
    imgPersonaje = al_load_bitmap("pacman_mini.png");
    imgPersonaje2 = al_load_bitmap("pacman_mini_2.png");
    xPer = 20;
    yPer = 20;
    vXPer = 200;
    vYPer = 200;
    direccion=DERECHA;
    // ...
    al_start_timer(timer);
    
    double tActual=0;
    double tAnterior=0;
    dt=0;
    
    while(1)
    {
        dt=tActual-tAnterior;
        fisica(dt);
		
		al_wait_for_event(queue, &event);
        switch(event.type)
        {
            case ALLEGRO_EVENT_TIMER:
                // logica del juego.
                redraw = true;
                break;
            case ALLEGRO_EVENT_KEY_DOWN:
            	if((event.keyboard.keycode== ALLEGRO_KEY_LEFT)||(event.keyboard.keycode==ALLEGRO_KEY_A)){
            		direccion=IZQUIERDA;
            		dir=ALLEGRO_FLIP_HORIZONTAL;
				}
				if((event.keyboard.keycode== ALLEGRO_KEY_RIGHT)||(event.keyboard.keycode==ALLEGRO_KEY_D)){
            		direccion=DERECHA;
            		dir=0;
				}
				if((event.keyboard.keycode== ALLEGRO_KEY_UP)||(event.keyboard.keycode==ALLEGRO_KEY_W)){
            		direccion=ARRIBA;
            		rot=270 *3.1416/180;
				}
				if((event.keyboard.keycode== ALLEGRO_KEY_DOWN)||(event.keyboard.keycode==ALLEGRO_KEY_S)){
            		direccion=ABAJO;
            		rot=90 *3.1416/180;
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
    
    return 0;
}

void pintar(int i){
    //Limpiamos lienzo para pintar
    al_clear_to_color(al_map_rgb(0, 0, 0));
    //Pintamos texto
    al_draw_text(font, al_map_rgb(255, 255, 255), 0, 50, 0, "Hello world!");
    char cadena[20];
    sprintf(cadena, "%d-%d, dt=%f", yPer,xPer,dt);
    al_draw_text(font, al_map_rgb(255, 255, 255), 0, 0, 0, cadena);
    //Pintamos imagen
    al_draw_bitmap(uaa, 10+i, 10, 0);
    
    nImage++;
    
    if(direccion==DERECHA || direccion==IZQUIERDA)
    {
    	if(nImage<7)
    	{
    		al_draw_bitmap(imgPersonaje, xPer, yPer, dir);
		}else if(nImage<14){
			al_draw_bitmap(imgPersonaje2, xPer, yPer, dir);
		}else{
    		nImage=0;
		}
	}
	
	if(direccion==ABAJO || direccion==ARRIBA)
    {
    	if(nImage<7)
    	{
    		al_draw_rotated_bitmap(imgPersonaje,12.5,12.5, xPer+12.5, yPer+12.5, rot,0);
		}else if(nImage<14){
			al_draw_rotated_bitmap(imgPersonaje2,12.5,12.5, xPer+12.5, yPer+12.5, rot,0);
		}else{
    		nImage=0;
		}
	}
    //al_draw_bitmap(imgPersonaje, xPer, yPer, 0);
    
     //al_draw_filled_triangle(35, 350, 85, 375, 35, 400, al_map_rgb_f(0, 1, 0));
     //al_draw_filled_rectangle(240, 260, 340, 340, al_map_rgba_f(0, 0, 0.5, 0.5));
     //al_draw_circle(450, 370, 30, al_map_rgb_f(1, 0, 1), 2);
     //al_draw_line(440, 110, 460, 210, al_map_rgb_f(1, 0, 0), 1);
     //al_draw_line(500, 220, 570, 200, al_map_rgb_f(1, 1, 0), 1);
    
    
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
    
    //Inicializamos parntalla de 640x480
    //display = al_create_display(1600, 1200);
    display = al_create_display(ANCHO,ALTO);
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
    al_destroy_font(font);
    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
}

void fisica(float dt){
	/*Para que rebote
	xPer += vXPer * dt;
	yPer += vYPer * dt;
	
	if((vXPer < 0 && xPer <= 0) || (vXPer > 0 && xPer >= ANCHO)){
		vXPer = -vXPer;
		
	}
	if((vYPer < 0 && yPer < 0) || (vYPer > 0 && yPer >= ALTO)){
		vYPer = -vYPer;
	}*/
	//Para moverlo
	if(direccion==DERECHA){
		xPer += vXPer * dt;
		if(xPer>ANCHO-20){
			xPer=ANCHO-20;
		}
	}
	if(direccion==IZQUIERDA){
		xPer -= vXPer * dt;
		if(xPer<0){
			xPer=0;
		}
	}
	if(direccion==ARRIBA){
		yPer -= vYPer * dt;
		if(yPer<0){
			yPer=0;
		}
	}
	if(direccion==ABAJO){
		yPer += vYPer * dt;
		if(yPer>ALTO-20){
			yPer=ALTO-20;
		}
	}
}
