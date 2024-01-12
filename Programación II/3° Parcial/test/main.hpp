//.hpp
//  testAllegro
//
//  Created by Jose de Jesus Palos on 26/10/22.
//  Copyright © 2022 Jose de Jesus Palos. All rights reserved.
//



#include <allegro5/timer.h>
#include <allegro5/allegro_font.h>
#include <iostream>
#include <stdlib.h>

#ifndef MAIN_HPP
#define MAIN_HPP
#define ALTO 600
#define ANCHO 800

#define TAM 30

ALLEGRO_TIMER* timer = NULL;
ALLEGRO_EVENT_QUEUE* queue = NULL;
ALLEGRO_DISPLAY* display = NULL;
ALLEGRO_FONT* font = NULL;

ALLEGRO_EVENT* event = NULL;

ALLEGRO_BITMAP* imgPersonaje;
ALLEGRO_BITMAP* imgPersonaje2;
//ALLEGRO_BITMAP* imgPersonajeMalo[3];
ALLEGRO_BITMAP* muro;
ALLEGRO_BITMAP* item;
ALLEGRO_BITMAP* portal;
ALLEGRO_BITMAP* background;

int kMat=0, iMat=0, jMat=0, hMat=0;


#define ARRIBA 1
#define ABAJO 2
#define IZQUIERDA 3
#define DERECHA 4

#define TAM 30

int init();
void deinit();

class CPac {

    public:
	    CPac();

	    CPac(float, float, int, int, float, int, int, int, int);

	    float xVPer, yVPer;
	    int xPer, yPer;
	    float dt;
	    int direction;
        int tiempo;
        int pts;
        int nImage;


	    virtual void fisica();
	    void pintar();
        //Falta por hacer la clase para nivel, 
        bool lvlCompleted();
};

CPac::CPac(float _xVPer, float _yVPer, int _xPer, int _yPer, float _dt, 
    int _direction, int _tiempo, int _pts, int _nImage) {
    xVPer = _xVPer;
    yVPer = _yVPer;
    xPer = _xPer;
    yPer = _yPer;
    dt = _dt;
    direction = _direction;
    tiempo = _tiempo;
    pts = _pts;
    nImage = _nImage;
}

/*
class CMalo : public CPac {
public:
    CMalo();
    CMalo(float _XVPer, float _yVPer, int _xPer, int _yPer, double _dt, int _direction, int _id, int _cont) : CPac(_XVPer,
        _yVPer, _xPer, _yPer, _dt, _direction), id(_id), cont(_cont) {}
    float xVPer, yVPer;
    int xPer, yPer;
    double dt;
    int direction, id, cont;

    void rutina_fantasma();
    int rutina1();
    virtual void fisica();
    void pintar();

};

*/


int mat[20][26] = {
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

/*
int mat[20][26] = {
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

*/


CPac::CPac()
{
}
//CPAC NO MALO
void CPac::fisica() {
    //if(mat[iMat][jMat]==1
//
    if (direction == DERECHA) {
        jMat = xPer / TAM;
        iMat = (yPer + 3) / TAM;
        kMat = (yPer + 22) / TAM;

        if (kMat == 20)
            kMat--;

        xPer = xPer + (xVPer * dt);
        if (xPer > ANCHO - 25) {
            xPer = ANCHO - 25;
        }

        if (mat[iMat][jMat + 1] == 1) {
            xPer = jMat * TAM;
        }

        if (mat[kMat][jMat + 1] == 1) {
            xPer = jMat * TAM;
        }

        if (mat[iMat][jMat] == 2) {
            mat[iMat][jMat] = 0;
            pts++;
        }

        if (mat[kMat][jMat] == 2) {
            mat[kMat][jMat] = 0;
            pts++;
        }
    }
///

    if (direction == ABAJO) {
        jMat = (xPer + 2) / TAM;// x
        iMat = yPer / TAM;// y
        hMat = (xPer + 23) / TAM;	// x a la derecha

        if (hMat == 26)
            hMat--;

        yPer = yPer + (yVPer * dt);
        if (yPer > ALTO - 25) {
            yPer = ALTO - 25;
        }
        if (mat[iMat + 1][jMat] == 1) {
            yPer = iMat * TAM;
        }
        if (mat[iMat + 1][hMat] == 1) {
            yPer = iMat * TAM;
        }
        //		y		x
        if (mat[iMat][jMat] == 2) {
            mat[iMat][jMat] = 0;
            pts++;
        }
        //		y		x aux
        if (mat[iMat][hMat] == 2) {
            mat[iMat][hMat] = 0;
            pts++;
        }
    }
    //

    /*
    //Para hacer los calculos más exactos para los movimientos de IZQUIERDA y ARRIBA
    jMat=(xPer+25)/TAM;
    iMat=(yPer+25)/TAM;

    if(jMat==26)
        jMat--;

    if(iMat==20)
        iMat--;*/


    if (direction == IZQUIERDA) {
        jMat = (xPer + 25) / TAM;
        iMat = (yPer + 22) / TAM;
        kMat = (yPer + 3) / TAM;

        if (jMat == 26)
            jMat--;

        if (iMat == 20)
            iMat--;

        xPer = xPer - (xVPer * dt);
        if (xPer < 0) {
            xPer = 0;
        }
        if (mat[iMat][jMat - 1] == 1) {

            xPer = jMat * TAM;
        }
        if (mat[kMat][jMat - 1] == 1) {

            xPer = jMat * TAM;
        }

        if (mat[iMat][jMat] == 2) {
            mat[iMat][jMat] = 0;
            pts++;
        }

        if (mat[kMat][jMat] == 2) {
            mat[kMat][jMat] = 0;
            pts++;
        }
    }

    if (direction == ARRIBA) {
        jMat = (xPer + 23) / TAM;
        iMat = (yPer + 25) / TAM;
        hMat = (xPer + 2) / TAM;

        if (jMat == 26)
            jMat--;

        if (iMat == 20)
            iMat--;

        yPer -= yVPer * dt;
        if (yPer < 0) {
            yPer = 0;
        }

        if (mat[iMat - 1][jMat] == 1) {
            yPer = iMat * TAM;
        }
        if (mat[iMat - 1][hMat] == 1) {

            yPer = iMat * TAM;
        }

        if (mat[iMat][jMat] == 2) {
            mat[iMat][jMat] = 0;
            pts++;
        }

        if (mat[iMat][hMat] == 2) {
            mat[iMat][hMat] = 0;
            pts++;
        }
    }

}
	
 
//CPAC 1ER OBJETO 
void CPac::pintar() {

    al_clear_to_color(al_map_rgb(0, 0, 0));

    al_draw_bitmap(background, 0, 0, 0);

    for (int y = 0; y < 20; y++)
    {
        for (int x = 0; x < 26; x++)
        {
            if (mat[y][x] == 1)
            {
                al_draw_bitmap(muro, x * TAM, (y * TAM), 0);
            }
            if (mat[y][x] == 2)
            {
                al_draw_bitmap(item, (x * TAM) + 5, (y * TAM) + 5, 0);
            }
        }
    }

    if (lvlCompleted())
    {
        al_draw_bitmap(portal, (TAM), (TAM), 0);
    }
    al_draw_bitmap(imgPersonaje, xPer, yPer, 0);
    //Pintamos texto
    char cadena[20];
    sprintf_s(cadena, "%d", tiempo);
    al_draw_text(font, al_map_rgb(255, 255, 255), 775, 0, 0, cadena);

   sprintf_s(cadena, "Score: %d", pts * 100);
    al_draw_text(font, al_map_rgb(255, 255, 255), 650, 0, 0, cadena);



    //mandamos a pantalla
    al_flip_display();
}


bool CPac::lvlCompleted() {
    bool lvlFin = true;

    for (int y = 0; y < 20; y++)
    {
        for (int x = 0; x < 26; x++)
        {
            if (mat[y][x] == 2)
            {
                lvlFin = false;
            }
        }
    }
    return lvlFin;
}
//MALO INFO FUNCIONES
/*
//MALOS
CMalo::CMalo()
{
}


void CMalo::rutina_fantasma()
{
    switch (id)
    {
    case 1:
        direction = rutina1();
        break;
    }
}

int CMalo::rutina1()
{
    while (cont > 10) {
        cont++;
        switch (cont)
        {
        case 1:
            return ABAJO;
            break;
        case 2:
            return ABAJO;
            break;
        case 3:
            return ABAJO;
            break;
        case 4:
            return IZQUIERDA;
            break;
        default:
            return ARRIBA;
            break;
        }
        cont++;
    }
    if (cont == 10) {
        cont = 0;
    }
}



void CMalo::fisica()
{
    CPac::fisica();
}

void CMalo::pintar()
{

    //Limpiamos lienzo para pintar
    al_clear_to_color(al_map_rgb(0, 0, 0));
    //Pintamos texto

    for (int x = 0; x < 26; x++) {
        for (int y = 0; y < 20; y++) {
            if (mat[y][x] == 1) {
                al_draw_bitmap(muro1, x * TAM, y * TAM, 0);
            }
        }
    }

    //Pintamos imagen

    nImage1++;

    if (direction == DERECHA || direction == IZQUIERDA) {
        if (nImage1 < 7) {
            al_draw_bitmap(imgPersonajeMalo[0], xPer, yPer, dir1);
        }
        else if (nImage1 < 14) {
            al_draw_bitmap(imgPersonajeMalo[0], xPer, yPer, dir1);
        }
        else {
            al_draw_bitmap(imgPersonajeMalo[0], xPer, yPer, dir1);
            nImage1 = 0;
        }
    }

    if (direction == ABAJO || direction == ARRIBA)
    {
        if (nImage1 < 7)
        {
            al_draw_rotated_bitmap(imgPersonajeMalo[0], 12.5, 12.5, xPer + 12.5, yPer + 12.5, rot1, 0);
        }
        else if (nImage1 < 14) {
            al_draw_rotated_bitmap(imgPersonajeMalo[0], 12.5, 12.5, xPer + 12.5, yPer + 12.5, rot1, 0);
        }
        else {
            al_draw_bitmap(imgPersonajeMalo[0], xPer, yPer, dir1);
            nImage1 = 0;
        }
    }
    //al_draw_circle(jMat * TAM, iMat * TAM, 2, al_map_rgb_f(255, 0, 0), 0);


    //mandamos a pantalla
    al_flip_display();
}
*/

#endif /* main_hpp */


