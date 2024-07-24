#pragma once

#include <allegro5/allegro.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <stdlib.h>
#include <conio.h>

#ifndef PINTAR_HPP
#define PINTAR_HPP

class CPintar {
public:

    void menuPrincipal(int i);
    void menuNuevaPartida(int);
    void menuCargarPartida(int);
    void menuPuntuaciones(int);
    void menuNiveles(int);
    void menuNuevaPartida2(int);
    void instruccioness();
    //char escribir();
};

#endif

void CPintar::menuPrincipal(int i) {
    char cadena[20];
    char mouse[20];

    al_clear_to_color(al_map_rgb(0, 0, 0));
    if (i % 300 < 150)
    {
        al_draw_bitmap(menuBackground, 0, (i % 300) / 3 - 50, 0);
    }
    else {
        al_draw_bitmap(menuBackground, 0, 50 - (i % 300) / 3, 0);
    }

    al_draw_bitmap(menuTitle, 170, 45, 0);

    al_draw_bitmap(menuSelector, 215, 200, 0);
    sprintf_s(cadena, "Juego Nuevo");
    al_draw_text(font, al_map_rgb(20, 20, 20), 360, 217, 0, cadena);
    al_draw_text(font, al_map_rgb(255, 255, 255), 358, 216, 0, cadena);

    al_draw_bitmap(menuSelector, 215, 280, 0);
    sprintf_s(cadena, "Cargar Juego");
    al_draw_text(font, al_map_rgb(20, 20, 20), 353, 297, 0, cadena);
    al_draw_text(font, al_map_rgb(255, 255, 255), 351, 296, 0, cadena);

    al_draw_bitmap(menuSelector, 215, 360, 0);
    sprintf_s(cadena, "Marcadores");
    al_draw_text(font, al_map_rgb(20, 20, 20), 362, 377, 0, cadena);
    al_draw_text(font, al_map_rgb(255, 255, 255), 360, 376, 0, cadena);

    al_draw_bitmap(menuSelectorShort, 588, 555, 0);
    sprintf_s(cadena, "Salir");
    al_draw_text(font, al_map_rgb(20, 20, 20), 652, 571, 0, cadena);
    al_draw_text(font, al_map_rgb(255, 255, 255), 650, 570, 0, cadena);

    sprintf_s(cadena, "x:%d y:%d", mouseX, mouseY);
    al_draw_text(font, al_map_rgb(20, 20, 20), 2, 1, 0, cadena);
    al_draw_text(font, al_map_rgb(255, 255, 255), 0, 0, 0, cadena);

    al_flip_display();
}

void CPintar::menuNuevaPartida(int i) {
    char cadena[20];
    al_clear_to_color(al_map_rgb(0, 0, 0));

    if (i % 300 < 150)
    {
        al_draw_bitmap(menuNewPartida, 0, (i % 300) / 3 - 30, 0);
    }
    else {
        al_draw_bitmap(menuNewPartida, 0, 70 - (i % 300) / 3, 0);
    }
    al_draw_bitmap(menuTitle, 170, 45, 0);
    al_draw_bitmap(menuSelector, 215, 200, 0);
    sprintf_s(cadena, "U S U A R I O");
    al_draw_text(font, al_map_rgb(20, 20, 20), 346, 216, 0, cadena);
    al_draw_text(font, al_map_rgb(255, 255, 255), 348, 218, 0, cadena);

    sprintf_s(cadena, "x:%d y:%d", mouseX, mouseY);
    al_draw_text(font, al_map_rgb(20, 20, 20), 2, 1, 0, cadena);
    al_draw_text(font, al_map_rgb(255, 255, 255), 0, 0, 0, cadena);

    al_draw_bitmap(cajaTexto, 332, 240, 0);
    al_draw_text(font, al_map_rgb(20, 20, 20), 386, 260, 0, nombre);
    al_draw_text(font, al_map_rgb(255, 255, 255), 384, 259, 0, nombre);

    sprintf_s(cadena, "_");
    if (i % 24 < 12 && charPos < 3)
    {
        al_draw_text(font, al_map_rgb(255, 255, 255), 383 + (charPos * 8), 262, 0, cadena);
        al_draw_text(font, al_map_rgb(255, 255, 255), 383 + (charPos * 8), 262, 0, " ");
    }

    al_draw_bitmap(menuSelectorShort, 315, 405, 0);
    sprintf_s(cadena, "C R E A R ");
    al_draw_text(font, al_map_rgb(20, 20, 20), 365, 422, 0, cadena);
    al_draw_text(font, al_map_rgb(255, 255, 255), 363, 420, 0, cadena);

    al_draw_bitmap(menuSelectorShort, 588, 555, 0);
    sprintf_s(cadena, "Regresar");
    al_draw_text(font, al_map_rgb(20, 20, 20), 645, 571, 0, cadena);
    al_draw_text(font, al_map_rgb(255, 255, 255), 643, 570, 0, cadena);
    
    al_flip_display();

}

void CPintar::menuCargarPartida(int i)
{
    char cadena[30];
    al_clear_to_color(al_map_rgb(0, 0, 0));

    if (i % 300 < 150)
    {
        al_draw_bitmap(menuNewPartida, 0, (i % 300) / 3 - 30, 0);
    }
    else {
        al_draw_bitmap(menuNewPartida, 0, 70 - (i % 300) / 3, 0);
    }
    al_draw_bitmap(menuTitle, 170, 45, 0);

    al_draw_bitmap(menuSelector, 215, 131, 0);
    sprintf_s(cadena, "SELECTOR DE USUARIO");
    al_draw_text(font, al_map_rgb(20, 20, 20), 326, 146, 0, cadena);
    al_draw_text(font, al_map_rgb(255, 255, 255), 328, 147, 0, cadena);

    al_draw_bitmap(menuSelectorPartida, 100, 180, 0);

    sprintf_s(cadena, "No.");
    al_draw_text(font, al_map_rgb(255, 255, 255), 118, 196, 0, cadena);

    sprintf_s(cadena, "Usuario");
    al_draw_text(font, al_map_rgb(255, 255, 255), 173, 196, 0, cadena);

    sprintf_s(cadena, "Vidas");
    al_draw_text(font, al_map_rgb(255, 255, 255), 281, 196, 0, cadena);

    sprintf_s(cadena, "Puntuacion");
    al_draw_text(font, al_map_rgb(255, 255, 255), 396, 196, 0, cadena);

    sprintf_s(cadena, "Tiempo Jugado");
    al_draw_text(font, al_map_rgb(255, 255, 255), 546, 196, 0, cadena);
    al_draw_bitmap(cajaOpciones, 206, 178, 0);
    if (userCount != 0)
    {
        if (pageView != userPage)
        {
            for (int i = 1; i <= 12; i++)
            {
                sprintf_s(cadena, "%d", i + (12 * (pageView - 1)));
                al_draw_text(font, al_map_rgb(255, 255, 255), 118, 221 + ((i - 1) * 26), 0, cadena);

                sprintf_s(cadena, "%s", listaUsuarios[i + (12 * (pageView - 1)) - 1].nombre);
                al_draw_text(font, al_map_rgb(255, 255, 255), 173, 221 + ((i - 1) * 26), 0, cadena);

                sprintf_s(cadena, "%d", listaUsuarios[i + (12 * (pageView - 1)) - 1].vidas);
                al_draw_text(font, al_map_rgb(255, 255, 255), 281, 221 + ((i - 1) * 26), 0, cadena);

                sprintf_s(cadena, "%d", listaUsuarios[i + (12 * (pageView - 1)) - 1].puntuacion);
                al_draw_text(font, al_map_rgb(255, 255, 255), 396, 221 + ((i - 1) * 26), 0, cadena);

                sprintf_s(cadena, "%d", listaUsuarios[i + (12 * (pageView - 1)) - 1].tiempoTotal);
                al_draw_text(font, al_map_rgb(255, 255, 255), 546, 221 + ((i - 1) * 26), 0, cadena);
            }
        }
        else {
            if (userCount % 12 == 0)
            {
                for (int i = 1; i <= 12; i++)
                {
                    sprintf_s(cadena, "%d", i + (12 * (pageView - 1)));
                    al_draw_text(font, al_map_rgb(255, 255, 255), 118, 221 + ((i - 1) * 26), 0, cadena);

                    sprintf_s(cadena, "%s", listaUsuarios[i + (12 * (pageView - 1)) - 1].nombre);
                    al_draw_text(font, al_map_rgb(255, 255, 255), 173, 221 + ((i - 1) * 26), 0, cadena);

                    sprintf_s(cadena, "%d", listaUsuarios[i + (12 * (pageView - 1)) - 1].vidas);
                    al_draw_text(font, al_map_rgb(255, 255, 255), 281, 221 + ((i - 1) * 26), 0, cadena);

                    sprintf_s(cadena, "%d", listaUsuarios[i + (12 * (pageView - 1)) - 1].puntuacion);
                    al_draw_text(font, al_map_rgb(255, 255, 255), 396, 221 + ((i - 1) * 26), 0, cadena);

                    sprintf_s(cadena, "%d", listaUsuarios[i + (12 * (pageView - 1)) - 1].tiempoTotal);
                    al_draw_text(font, al_map_rgb(255, 255, 255), 546, 221 + ((i - 1) * 26), 0, cadena);
                }
            }
            else {

                for (int i = 1; i <= userCount % 12; i++)
                {
                    sprintf_s(cadena, "%d", i + (12 * (pageView - 1)));
                    al_draw_text(font, al_map_rgb(255, 255, 255), 118, 221 + ((i - 1) * 26), 0, cadena);

                    sprintf_s(cadena, "%s", listaUsuarios[i + (12 * (pageView - 1)) - 1].nombre);
                    al_draw_text(font, al_map_rgb(255, 255, 255), 173, 221 + ((i - 1) * 26), 0, cadena);

                    sprintf_s(cadena, "%d", listaUsuarios[i + (12 * (pageView - 1)) - 1].vidas);
                    al_draw_text(font, al_map_rgb(255, 255, 255), 281, 221 + ((i - 1) * 26), 0, cadena);

                    sprintf_s(cadena, "%d", listaUsuarios[i + (12 * (pageView - 1)) - 1].puntuacion);
                    al_draw_text(font, al_map_rgb(255, 255, 255), 396, 221 + ((i - 1) * 26), 0, cadena);

                    sprintf_s(cadena, "%d", listaUsuarios[i + (12 * (pageView - 1)) - 1].tiempoTotal);
                    al_draw_text(font, al_map_rgb(255, 255, 255), 546, 221 + ((i - 1) * 26), 0, cadena);
                }
            }
        }
    }
    else {
        sprintf_s(cadena, "No hay partidas guardadas");
        al_draw_text(font, al_map_rgb(255, 255, 255), 301, 351, 0, cadena);
    }

    if (userPage > 1)
    {
        if (pageView == 1)
        {
            al_draw_bitmap(menuSelectorShort, 388, 555, 0);
            sprintf_s(cadena, "----->");
            al_draw_text(font, al_map_rgb(20, 20, 20), 445, 571, 0, cadena);
            al_draw_text(font, al_map_rgb(255, 255, 255), 443, 570, 0, cadena);
        }
        else if (pageView == userPage)
        {
            al_draw_bitmap(menuSelectorShort, 208, 555, 0);
            sprintf_s(cadena, "<-----");
            al_draw_text(font, al_map_rgb(20, 20, 20), 265, 571, 0, cadena);
            al_draw_text(font, al_map_rgb(255, 255, 255), 263, 570, 0, cadena);
        }
        else
        {
            al_draw_bitmap(menuSelectorShort, 208, 555, 0);
            sprintf_s(cadena, "<-----");
            al_draw_text(font, al_map_rgb(20, 20, 20), 265, 571, 0, cadena);
            al_draw_text(font, al_map_rgb(255, 255, 255), 263, 570, 0, cadena);

            al_draw_bitmap(menuSelectorShort, 388, 555, 0);
            sprintf_s(cadena, "----->");
            al_draw_text(font, al_map_rgb(20, 20, 20), 445, 571, 0, cadena);
            al_draw_text(font, al_map_rgb(255, 255, 255), 443, 570, 0, cadena);
        }

    }

    al_draw_bitmap(menuSelectorShort, 588, 555, 0);
    sprintf_s(cadena, "Regresar");
    al_draw_text(font, al_map_rgb(20, 20, 20), 645, 571, 0, cadena);
    al_draw_text(font, al_map_rgb(255, 255, 255), 643, 570, 0, cadena);


    al_flip_display();
}

void CPintar::menuNiveles(int i) 
{
    char cadena[20];
    al_draw_bitmap(menuNivelesBackground, 0,0, 0);
   /*
    if (i % 300 < 150)
    {
        
    }
    else {
        al_draw_bitmap(menuNivelesBackground, 0, 70 - (i % 300) / 3, 0);
    }*/

    sprintf_s(cadena, "x:%d y:%d", mouseX, mouseY);
    al_draw_text(font, al_map_rgb(20, 20, 20), 2, 1, 0, cadena);
    al_draw_text(font, al_map_rgb(255, 255, 255), 0, 0, 0, cadena);

    al_draw_bitmap(imgNivel1, 50, 55, 0 );
    al_draw_bitmap(menuSelectorShort, 65,127, 0);
    sprintf_s(cadena, "N I V E L  I.");
    al_draw_text(font, al_map_rgb(20, 20, 20), 102, 142, 0, cadena);
    al_draw_text(font, al_map_rgb(255, 255, 255), 100, 140, 0, cadena);

    al_draw_bitmap(imgNivel2, 300, 220, 0);
    al_draw_bitmap(menuSelectorShort, 315, 292, 0);
    sprintf_s(cadena, "N I V E L  I I.");
    al_draw_text(font, al_map_rgb(20, 20, 20), 347, 307, 0, cadena);
    al_draw_text(font, al_map_rgb(255, 255, 255), 345, 305, 0, cadena);


    al_draw_bitmap(imgNivel3, 550, 370, 0);
    al_draw_bitmap(menuSelectorShort, 565, 442, 0);
    sprintf_s(cadena, "N I V E L  I I I.");
    al_draw_text(font, al_map_rgb(20, 20, 20), 592, 456, 0, cadena);
    al_draw_text(font, al_map_rgb(255, 255, 255), 590, 454, 0, cadena);

    al_flip_display();
}

void CPintar::menuNuevaPartida2(int i) {
    char cadena[20];
    al_clear_to_color(al_map_rgb(0, 0, 0));

    if (i % 300 < 150)
    {
        al_draw_bitmap(menuNewPartida, 0, (i % 300) / 3 - 30, 0);
    }
    else {
        al_draw_bitmap(menuNewPartida, 0, 70 - (i % 300) / 3, 0);
    }
    al_draw_bitmap(menuTitle, 170, 45, 0);

    al_draw_bitmap(menuSelector, 215, 200, 0);
    sprintf_s(cadena, "U S U A R I O");
    al_draw_text(font, al_map_rgb(20, 20, 20), 346, 216, 0, cadena);
    al_draw_text(font, al_map_rgb(255, 255, 255), 348, 218, 0, cadena);

    sprintf_s(cadena, "x:%d y:%d", mouseX, mouseY);
    al_draw_text(font, al_map_rgb(20, 20, 20), 2, 1, 0, cadena);
    al_draw_text(font, al_map_rgb(255, 255, 255), 0, 0, 0, cadena);

    al_draw_bitmap(cajaTexto, 332, 240, 0);
    al_draw_text(font, al_map_rgb(20, 20, 20), 386, 260, 0, nombre);
    al_draw_text(font, al_map_rgb(255, 255, 255), 384, 259, 0, nombre);

    sprintf_s(cadena, "_");
    if (i % 24 < 12 && charPos < 3)
    {
        al_draw_text(font, al_map_rgb(255, 255, 255), 383 + (charPos * 8), 262, 0, cadena);
        al_draw_text(font, al_map_rgb(255, 255, 255), 383 + (charPos * 8), 262, 0, " ");
    }

    al_draw_bitmap(cajaSeleccion, 273, 320, 0);
    sprintf_s(cadena, "CONFIRMAR   USUARIO");
    al_draw_text(font, al_map_rgb(20, 20, 20), 325, 336, 0, cadena);
    al_draw_text(font, al_map_rgb(255, 255, 255), 323, 334, 0, cadena);
   

    al_draw_bitmap(cajaSi, 250, 420, 0);
    al_draw_bitmap(cajaNo, 462, 420, 0);

    al_draw_bitmap(menuSelectorShort, 588, 555, 0);
    sprintf_s(cadena, "Regresar");
    al_draw_text(font, al_map_rgb(20, 20, 20), 645, 571, 0, cadena);
    al_draw_text(font, al_map_rgb(255, 255, 255), 643, 570, 0, cadena);

    al_flip_display();
}

void CPintar::menuPuntuaciones(int)
{
    char cadena[30];

    al_clear_to_color(al_map_rgb(0, 0, 0));

    if (i % 300 < 150)
    {
        al_draw_bitmap(menuNewPartida, 0, (i % 300) / 3 - 30, 0);
    }
    else {
        al_draw_bitmap(menuNewPartida, 0, 70 - (i % 300) / 3, 0);
    }
    al_draw_bitmap(menuTitle, 170, 45, 0);

    al_draw_bitmap(menuSelector, 215, 131, 0);
    sprintf_s(cadena, "PUNTUACIONES MÁS ALTAS");
    al_draw_text(font, al_map_rgb(20, 20, 20), 306, 146, 0, cadena);
    al_draw_text(font, al_map_rgb(255, 255, 255), 308, 147, 0, cadena);
    
    al_draw_bitmap(menuSelectorPartida, 100, 180, 0);

    sprintf_s(cadena, "No.");
    al_draw_text(font, al_map_rgb(255, 255, 255), 118, 196, 0, cadena);

    sprintf_s(cadena, "Usuario");
    al_draw_text(font, al_map_rgb(255, 255, 255), 173, 196, 0, cadena);

    sprintf_s(cadena, "Vidas");
    al_draw_text(font, al_map_rgb(255, 255, 255), 281, 196, 0, cadena);

    sprintf_s(cadena, "Puntuacion");
    al_draw_text(font, al_map_rgb(255, 255, 255), 396, 196, 0, cadena);

    sprintf_s(cadena, "Tiempo Jugado");
    al_draw_text(font, al_map_rgb(255, 255, 255), 546, 196, 0, cadena);

    if(userCount != 0)
    {
        if(pageView != userPage)
        {
            for (int i = 1; i <= 12; i++)
            {
                sprintf_s(cadena, "%d",i+(12*(pageView-1)));
                al_draw_text(font, al_map_rgb(255, 255, 255), 118, 221 + ((i-1)*26), 0, cadena);

                sprintf_s(cadena, "%s", listaUsuarios[i+(12*(pageView-1))-1].nombre);
                al_draw_text(font, al_map_rgb(255, 255, 255), 173, 221 + ((i-1)*26), 0, cadena);

                sprintf_s(cadena, "%d", listaUsuarios[i+(12*(pageView-1))-1].vidas);
                al_draw_text(font, al_map_rgb(255, 255, 255), 281, 221 + ((i-1)*26), 0, cadena);

                sprintf_s(cadena, "%d", listaUsuarios[i+(12*(pageView-1))-1].puntuacion);
                al_draw_text(font, al_map_rgb(255, 255, 255), 396, 221 + ((i-1)*26), 0, cadena);

                sprintf_s(cadena, "%d", listaUsuarios[i+(12*(pageView-1))-1].tiempoTotal);
                al_draw_text(font, al_map_rgb(255, 255, 255), 546, 221 + ((i-1)*26), 0, cadena);
            }
        }else{
            if(userCount%12 == 0)
            {
                for (int i = 1; i <= 12; i++)
                {
                    sprintf_s(cadena, "%d",i+(12*(pageView-1)));
                    al_draw_text(font, al_map_rgb(255, 255, 255), 118, 221 + ((i-1)*26), 0, cadena);

                    sprintf_s(cadena, "%s", listaUsuarios[i+(12*(pageView-1))-1].nombre);
                    al_draw_text(font, al_map_rgb(255, 255, 255), 173, 221 + ((i-1)*26), 0, cadena);

                    sprintf_s(cadena, "%d", listaUsuarios[i+(12*(pageView-1))-1].vidas);
                    al_draw_text(font, al_map_rgb(255, 255, 255), 281, 221 + ((i-1)*26), 0, cadena);

                    sprintf_s(cadena, "%d", listaUsuarios[i+(12*(pageView-1))-1].puntuacion);
                    al_draw_text(font, al_map_rgb(255, 255, 255), 396, 221 + ((i-1)*26), 0, cadena);

                    sprintf_s(cadena, "%d", listaUsuarios[i+(12*(pageView-1))-1].tiempoTotal);
                    al_draw_text(font, al_map_rgb(255, 255, 255), 546, 221 + ((i-1)*26), 0, cadena);
                }
            }else{

                for (int i = 1; i <= userCount%12 ; i++)
                {
                    sprintf_s(cadena, "%d",i+(12*(pageView-1)));
                    al_draw_text(font, al_map_rgb(255, 255, 255), 118, 221 + ((i-1)*26), 0, cadena);

                    sprintf_s(cadena, "%s", listaUsuarios[i+(12*(pageView-1))-1].nombre);
                    al_draw_text(font, al_map_rgb(255, 255, 255), 173, 221 + ((i-1)*26), 0, cadena);

                    sprintf_s(cadena, "%d", listaUsuarios[i+(12*(pageView-1))-1].vidas);
                    al_draw_text(font, al_map_rgb(255, 255, 255), 281, 221 + ((i-1)*26), 0, cadena);

                    sprintf_s(cadena, "%d", listaUsuarios[i+(12*(pageView-1))-1].puntuacion);
                    al_draw_text(font, al_map_rgb(255, 255, 255), 396, 221 + ((i-1)*26), 0, cadena);

                    sprintf_s(cadena, "%d", listaUsuarios[i+(12*(pageView-1))-1].tiempoTotal);
                    al_draw_text(font, al_map_rgb(255, 255, 255), 546, 221 + ((i-1)*26), 0, cadena);
                }
            }
        }
    }else{
        sprintf_s(cadena, "No hay partidas guardadas");
        al_draw_text(font, al_map_rgb(255, 255, 255), 301, 351, 0, cadena);
    }

    if(userPage > 1)
    {
        if(pageView == 1)
        {
            al_draw_bitmap(menuSelectorShort, 388, 555, 0);
            sprintf_s(cadena, "----->");
            al_draw_text(font, al_map_rgb(20, 20, 20), 445, 571, 0, cadena);
            al_draw_text(font, al_map_rgb(255, 255, 255), 443, 570, 0, cadena);
        }else if(pageView == userPage)
        {
            al_draw_bitmap(menuSelectorShort, 208, 555, 0);
            sprintf_s(cadena, "<-----");
            al_draw_text(font, al_map_rgb(20, 20, 20), 265, 571, 0, cadena);
            al_draw_text(font, al_map_rgb(255, 255, 255), 263, 570, 0, cadena);
        }else
        {
            al_draw_bitmap(menuSelectorShort, 208, 555, 0);
            sprintf_s(cadena, "<-----");
            al_draw_text(font, al_map_rgb(20, 20, 20), 265, 571, 0, cadena);
            al_draw_text(font, al_map_rgb(255, 255, 255), 263, 570, 0, cadena);

            al_draw_bitmap(menuSelectorShort, 388, 555, 0);
            sprintf_s(cadena, "----->");
            al_draw_text(font, al_map_rgb(20, 20, 20), 445, 571, 0, cadena);
            al_draw_text(font, al_map_rgb(255, 255, 255), 443, 570, 0, cadena);
        }

    }

    al_draw_bitmap(menuSelectorShort, 588, 555, 0);
    sprintf_s(cadena, "Regresar");
    al_draw_text(font, al_map_rgb(20, 20, 20), 645, 571, 0, cadena);
    al_draw_text(font, al_map_rgb(255, 255, 255), 643, 570, 0, cadena);

    al_flip_display();
}

void CPintar::instruccioness() {
    char cadena[20];
    al_draw_bitmap(menuNivelesBackground, 0, 0, 0);
    sprintf_s(cadena, "x:%d y:%d", mouseX, mouseY);
    al_draw_text(font, al_map_rgb(20, 20, 20), 2, 1, 0, cadena);
    al_draw_text(font, al_map_rgb(255, 255, 255), 0, 0, 0, cadena);

    al_draw_bitmap(instrucciones, 85,20,0);
    al_draw_bitmap(cajaVacia, 292, 500, 0);
    sprintf_s(cadena, "CONTINUAR");
    al_draw_text(font, al_map_rgb(20, 20, 20), 300, 510, 0, cadena);
    al_draw_text(font, al_map_rgb(255, 255, 255), 298, 510, 0, cadena);

    al_draw_bitmap(cajaVacia, 460, 500, 0);
    sprintf_s(cadena, "SALIR");
    al_draw_text(font, al_map_rgb(20, 20, 20), 485, 510, 0, cadena);
    al_draw_text(font, al_map_rgb(255, 255, 255), 483, 510, 0, cadena);
    al_flip_display();
}