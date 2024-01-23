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

class CPintar{
public:

    void menuPrincipal(int i);
	void menuNuevaPartida(int);
    void menuCargarPartida(int);
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

    al_draw_bitmap(cajaTexto, 200, 240,0);
    al_draw_text(font, al_map_rgb(20, 20, 20), 386, 260, 0, nombre);
    al_draw_text(font, al_map_rgb(255, 255, 255), 384, 259, 0, nombre);

    sprintf_s(cadena, "_");
    if (i % 24 < 12 && charPos < 3)
    {
        al_draw_text(font, al_map_rgb(255, 255, 255), 383 + (charPos * 8), 262, 0, cadena);
    }
    

    al_draw_bitmap(menuSelectorShort, 588, 555, 0);
    sprintf_s(cadena, "Regresar");
    al_draw_text(font, al_map_rgb(20, 20, 20), 645, 571, 0, cadena);
    al_draw_text(font, al_map_rgb(255, 255, 255), 643, 570, 0, cadena);

    //escribir();
    al_flip_display();

}

void CPintar::menuCargarPartida(int i)
{
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

    al_draw_bitmap(menuSelector, 215, 131, 0);
    sprintf_s(cadena, "SELECTOR DE USUARIO");
    al_draw_text(font, al_map_rgb(20, 20, 20), 326, 146, 0, cadena);
    al_draw_text(font, al_map_rgb(255, 255, 255), 328, 147, 0, cadena);
    
    al_draw_bitmap(menuSelectorPartida, 100, 180, 0);


    al_draw_bitmap(menuSelectorShort, 588, 555, 0);
    sprintf_s(cadena, "Regresar");
    al_draw_text(font, al_map_rgb(20, 20, 20), 645, 571, 0, cadena);
    al_draw_text(font, al_map_rgb(255, 255, 255), 643, 570, 0, cadena);

    al_flip_display();
}

/*
char CPintar::escribir() {
    char caracter;
    char palabra[10];
    char cadena[10];
    string miCadena;
    int i = 0;  // Inicializa i a 0

    do {
        cout << "Presiona una tecla (sin Enter): ";

        // Lee un solo car�cter sin esperar a Enter (Windows)
        caracter = _getch();

        if (i < 10 && caracter != 13) {  // Aseg�rate de no exceder el tama�o del array y no incluir Enter
            miCadena = caracter;
            al_draw_textf(font, al_map_rgb(20, 20, 20), 400, 240, 0, "%s", miCadena.c_str());
            i++;
        }
    } while (caracter != 13);
}*/
