#include "menu.hpp"
#include "LogicaMouse.hpp"
#include "pintar.hpp"
#include <allegro5/allegro.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;
extern ALLEGRO_EVENT event;

int main()
{
    init();
    int i = 0, escenario = 0;
    CMouse mouse;
    menuBackground = al_load_bitmap("menu_background.png");
    menuSelector = al_load_bitmap("menu_selector.png");
    menuSelectorShort = al_load_bitmap("menu_selector_short.png");
    menuTitle = al_load_bitmap("menu_title.png");
    menuNewPartida = al_load_bitmap("MenuNuevaPartida.png");
    cajaTexto = al_load_bitmap("cajaEscribir.png");
    menuSelectorPartida = al_load_bitmap("selectorPartida.png");
    al_start_timer(timer);

    while (1) 
    {
        al_wait_for_event(queue, &event);
        switch (event.type)
        {
        case ALLEGRO_EVENT_TIMER:
            // logica del juego.
            redraw = true;
            break;
        case ALLEGRO_EVENT_MOUSE_AXES:
        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
            //Logica en Menu
            mouse.mouseX = mouseX = event.mouse.x;
            mouse.mouseY = mouseY = event.mouse.y;
            escenario = mouse.logicaMenu(escenario);
            cout << "Escenario: " << escenario << endl;
            break;
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            done = true;
            break;
        case ALLEGRO_EVENT_KEY_DOWN:
            if (escenario == 1)
            {
                selectorNombre();
            }
            if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE && escenario == 0)
                done = true;
            break;
        }

        if(escenario == 4)
            done = true;

        if (done)
            break;

        if (redraw && al_is_event_queue_empty(queue))
        {
            menuPintar(i++, escenario);
            redraw = false;
        }

    }

    deinit();
}


void menuPintar(int i, int escenario) {
    CPintar pintar;
    switch (escenario) {
    case 0:
        charPos = 0;
        pintar.menuPrincipal(i);
        break;
    case 1:
        pintar.menuNuevaPartida(i);
        break;
    case 2:
        pintar.menuCargarPartida(i);
        break;
    }
}

void selectorNombre()
{
    if(charPos<3)
    {
        if(event.keyboard.keycode == ALLEGRO_KEY_DOWN)
        {
            if(nombre[charPos] == 'Z')
            {
                nombre[charPos] = 'A';
            }else{
                nombre[charPos]++;
            }
        }
        if(event.keyboard.keycode == ALLEGRO_KEY_UP)
        {
            if(nombre[charPos] == 'A')
            {
                nombre[charPos] = 'Z';
            }else{
                nombre[charPos]--;
            }
        }
        if(event.keyboard.keycode == ALLEGRO_KEY_ENTER)
        {
            charPos++;
        }
    }
}

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
    al_register_event_source(queue, al_get_mouse_event_source());


    return 0;
}

void deinit() {
    al_destroy_bitmap(menuBackground);
    al_destroy_bitmap(menuSelector);
    al_destroy_bitmap(menuTitle);
    al_destroy_font(font);
    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

}