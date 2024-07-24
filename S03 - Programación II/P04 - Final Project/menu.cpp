#include "menu.hpp"
#include "jugador.hpp"
CJugador* listaUsuarios;
CJugador per(TAM, TAM, 200, 200, DERECHA);
#include "LogicaMouse.hpp"
#include "pintar.hpp"
#include <allegro5/allegro.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <stdlib.h>
#include <stdio.h>
//#include <windows.h>
#include <fstream>
#include <iostream>


using namespace std;
extern ALLEGRO_EVENT event;

int main()
{
    float tActual = 0;
    float tAnterior = 0;
    float dt = 0;
    init();
    int i = 0, escenario = 0;
    CMouse mouse;
    cargar_imagenes();


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
            //Nivel 1
            dt = tActual - tAnterior;

            if (escenario == 7) {
                per.fisicaNivel1(dt);
                if ((event.keyboard.keycode == ALLEGRO_KEY_LEFT) || (event.keyboard.keycode == ALLEGRO_KEY_A)) {
                    per.direccion = IZQUIERDA;
                }
                if ((event.keyboard.keycode == ALLEGRO_KEY_RIGHT) || (event.keyboard.keycode == ALLEGRO_KEY_D)) {
                    per.direccion = DERECHA;
                }
                if ((event.keyboard.keycode == ALLEGRO_KEY_UP) || (event.keyboard.keycode == ALLEGRO_KEY_W)) {
                    per.direccion = ARRIBA;
                }
                if ((event.keyboard.keycode == ALLEGRO_KEY_DOWN) || (event.keyboard.keycode == ALLEGRO_KEY_S)) {
                    per.direccion = ABAJO;
                }
                break;
            }
            if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE && escenario == 0)
                done = true;
            break;
        }

        if (escenario == 4)
            done = true;

        if (done)
            break;

        if (redraw && al_is_event_queue_empty(queue))
        {
            menuPintar(i++, escenario);
            redraw = false;
        }
        if (escenario == 7) {
            tAnterior = tActual;
            tActual = al_get_time();
            per.tiempoTotal = 500 - tActual;
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
        if (cargaArch)
        {
            strcpy_s(nombre,"AAA");
            pageView = 1;
            cuentaUsuarios();
            cargaArch = false;
        }
        pintar.menuCargarPartida(i);
        break;
    case 3:
        if(cargaArch)
        {
            pageView = 1;
            cuentaUsuarios();
            ordenaLista();
            cargaArch = false;
        }
        pintar.menuPuntuaciones(i);
        break;
    case 5:
        pintar.menuNiveles(i);
        break;
    case 6:
        pintar.menuNuevaPartida2(i);
        break;
    case 7:
        per.pintarNivel1();
        break;
    case 8:
        pintar.instruccioness();
        break;
    case 9:
        per.pintarNivel2();
        break;
    case 10:
        per.pintarNivel3();
        break;
    }
}

void selectorNombre()
{
    if (charPos < 3)
    {
        if (event.keyboard.keycode == ALLEGRO_KEY_DOWN)
        {
            if (nombre[charPos] == 'Z')
            {
                nombre[charPos] = 'A';
            }
            else {
                nombre[charPos]++;
            }
        }
        if (event.keyboard.keycode == ALLEGRO_KEY_UP)
        {
            if (nombre[charPos] == 'A')
            {
                nombre[charPos] = 'Z';
            }
            else {
                nombre[charPos]--;
            }
        }
        if (event.keyboard.keycode == ALLEGRO_KEY_ENTER)
        {
            charPos++;
        }
    }else{
        strcpy(per.nombre,nombre);
    }
}

void cuentaUsuarios()
{
    CJugador recorre( 0, 0, 0, 0, 0);
    char archivo[] = { "user.txt" };
    userCount = 0;
    fstream archUser(archivo, ios::in | ios::out);

    while (!archUser.eof())
    {
        archUser.read(reinterpret_cast<char*>(&recorre), sizeof(CJugador));
        userCount++;
    }
    userCount--;

    archUser.close();

    if (userCount != 0)
    {
        lecturaArchivo();
        if (userCount % 12 == 0)
        {
            userPage = userCount / 12;
        }
        else {
            userPage = (userCount / 12) + 1;
        }
    }
}

void lecturaArchivo()
{
    CJugador lector( 0, 0, 0, 0, 0);
    char archivo[] = { "user.txt" };

    listaUsuarios = new CJugador(0, 0, 0, 0, 0);// [userCount];

    fstream archUser(archivo, ios::in | ios::out);

    for (int i = 0; i < userCount; i++)
    {
        archUser.read(reinterpret_cast<char*>(&lector), sizeof(CJugador));
        listaUsuarios[i] = lector;
    }

    archUser.close();
}

void ordenaLista()
{
    CJugador aux( 0, 0, 0, 0, 0);

    for (int i = 0; i < userCount - 1; i++)
    {
        for (int j = 0; j < userCount - i - 1; j++)
        {
            if (listaUsuarios[j].puntuacion < listaUsuarios[j + 1].puntuacion)
            {
                aux = listaUsuarios[j];
                listaUsuarios[j] = listaUsuarios[j + 1];
                listaUsuarios[j + 1] = aux;
            }

        }
    }
}

void cargar_imagenes() {

    menuBackground = al_load_bitmap("menu_background.png");
    menuSelector = al_load_bitmap("menu_selector.png");
    menuSelectorShort = al_load_bitmap("menu_selector_short.png");
    menuTitle = al_load_bitmap("menu_title.png");
    menuNewPartida = al_load_bitmap("nivel1_background.png");
    cajaTexto = al_load_bitmap("cajaEscribir.png");
    menuSelectorPartida = al_load_bitmap("selectorPartida.png");
    menuNivelesBackground = al_load_bitmap("backgroundEnd.png");
    imgNivel1 = al_load_bitmap("nivel_1.png");
    imgNivel2 = al_load_bitmap("nivel_2_2.png");
    imgNivel3 = al_load_bitmap("nivel_3.png");
    cajaSi = al_load_bitmap("CajaSi.png");
    cajaSeleccion = al_load_bitmap("Caja Seleccion.png");
    cajaNo = al_load_bitmap("CajaNo.png");
    instrucciones = al_load_bitmap("instrucciones.png");
    cajaVacia = al_load_bitmap("CajaVacia.png");
    cajaOpciones = al_load_bitmap("opcionesNivel.png");

    //JUEGO

    imgPersonaje = al_load_bitmap("Skeleton.png");
    imgPersonaje2 = al_load_bitmap("Skeleton.png");


    item = al_load_bitmap("diamond.png");
    portal = al_load_bitmap("portal.png");

    //NIVEL 1
    nivelIbackground = al_load_bitmap("background_nivel1.png");
    muroNivel1 = al_load_bitmap("muroNivel1.png");
    muroNivel11 = al_load_bitmap("tierra.png");
    muroNivel12 = al_load_bitmap("bedrockk.png");
    muroNivel13 = al_load_bitmap("tierra_sinPasto.png");
    muroNivel16 = al_load_bitmap("bedrockk.png");

    //Nivel 2
    muro = al_load_bitmap("nether_bricks.png");
    background = al_load_bitmap("background.png");

    //Nivel 3
    muroNivel3 = al_load_bitmap("muroNivel3.png");
    muroNivel32 = al_load_bitmap("muroNivel32.png");
    muroNivel33 = al_load_bitmap("obsidiana.png");
    backGroundNivel3 = al_load_bitmap("backgroundEnd.png");
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