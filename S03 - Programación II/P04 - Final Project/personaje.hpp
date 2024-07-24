#pragma once

#include <allegro5/allegro.h>
#include <allegro5/timer.h>
#include <allegro5/allegro_font.h>
#include <iostream>
#include <stdlib.h>

#ifndef PERSONAJE_HPP
#define PERSONAJE_HPP

#define ARRIBA 1
#define ABAJO 2
#define IZQUIERDA 3
#define DERECHA 4
#define TAM 30


int kMat = 0, iMat = 0, jMat = 0, hMat = 0;


int mat_Nivel1[20][26] = {
    {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4},
    {3,2,3,2,2,2,2,3,3,2,2,2,2,2,2,2,2,3,3,2,2,2,2,3,2,3},
    {3,2,2,2,3,3,2,2,2,2,3,3,3,3,3,3,2,2,2,2,3,3,2,2,2,3},
    {3,2,3,2,3,3,2,3,3,2,3,3,2,2,3,3,2,3,3,2,3,3,2,3,2,3},
    {5,2,3,2,3,3,2,3,5,2,2,2,2,2,2,2,2,3,5,2,3,3,2,3,2,4},
    {5,2,2,2,5,3,2,2,2,2,5,5,2,2,5,5,2,5,5,2,5,5,2,2,2,5},
    {5,5,5,2,2,2,2,2,2,2,2,5,2,2,5,2,2,2,2,2,2,2,2,5,5,5},
    {5,2,5,5,2,2,5,5,5,2,2,5,2,2,5,2,2,5,5,5,2,2,5,5,2,5},
    {5,2,2,2,2,2,2,5,2,2,5,5,2,2,5,5,2,2,5,2,2,2,2,2,2,5},
    {5,2,2,2,2,2,2,2,2,5,5,2,2,2,2,5,5,2,2,2,2,2,2,2,2,5},
    {5,5,5,2,2,2,5,2,2,2,2,2,2,2,2,2,2,2,2,5,2,2,2,5,5,5},
    {5,2,5,5,2,5,5,5,2,5,5,2,2,2,2,5,5,2,5,5,5,2,5,5,2,5},
    {5,2,5,2,2,2,5,2,2,2,5,5,2,2,5,5,2,2,2,5,2,2,2,5,2,5},
    {5,2,5,2,2,5,5,5,2,2,2,5,2,2,5,2,2,2,5,5,5,2,2,5,2,5},
    {5,2,2,2,2,2,5,2,2,2,2,5,2,2,5,2,2,2,2,5,2,2,2,2,2,5},
    {5,2,5,2,2,2,5,2,5,2,2,5,2,2,5,2,2,5,2,5,2,2,2,5,2,5},
    {5,2,5,5,5,2,2,2,5,2,5,5,2,2,5,5,2,5,2,2,2,5,5,5,2,5},
    {5,2,2,5,5,5,2,2,5,2,2,2,2,2,2,2,2,5,2,2,5,5,5,2,2,5},
    {6,2,2,2,2,2,2,2,6,2,2,2,2,2,2,2,2,6,2,2,2,2,2,2,2,6},
    {6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6},
};

int mat_Nivel2[20][26] = {
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


int mat_Nivel3[20][26] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,3,3,3,4,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4,3,3,3,1},
    {1,3,3,4,4,4,3,2,2,2,2,3,2,2,3,2,2,2,2,3,4,4,4,3,4,1},
    {1,3,3,3,4,2,2,3,2,3,3,2,2,2,2,3,3,2,3,2,2,4,3,3,3,1},
    {1,2,2,2,3,2,2,3,3,2,2,2,2,2,2,2,2,3,3,2,2,3,2,2,2,1},
    {1,2,2,2,2,2,2,3,2,2,2,3,2,2,3,2,2,2,3,2,2,2,2,2,2,1},
    {1,3,3,2,2,2,2,3,2,2,3,2,2,2,2,3,2,2,3,2,2,2,2,3,3,1},
    {1,3,3,2,2,2,2,3,2,2,3,2,2,2,2,3,2,2,3,2,2,2,2,3,3,1},
    {1,3,2,2,2,2,2,3,2,2,3,2,4,4,2,3,2,2,3,2,2,2,2,2,3,1},
    {1,3,2,2,2,2,2,2,2,2,2,2,4,4,4,4,2,2,2,2,2,2,2,2,3,1},
    {1,3,4,3,2,2,2,2,2,2,3,2,4,4,2,3,2,2,2,2,2,2,3,4,3,1},
    {1,4,4,4,2,2,2,3,2,2,3,2,2,2,2,3,2,2,3,2,2,2,4,4,4,1},
    {1,3,4,2,2,2,3,3,2,2,3,2,2,2,2,3,2,2,3,3,2,2,2,4,3,1},
    {1,2,2,2,2,2,3,3,2,2,2,3,2,2,3,2,2,2,3,3,2,2,2,2,2,1},
    {1,2,2,2,2,2,2,3,2,2,2,2,2,2,2,2,2,2,3,2,2,2,2,2,2,1},
    {1,3,2,2,3,2,2,3,2,2,2,2,2,2,2,2,2,2,3,2,2,3,2,2,3,1},
    {1,3,3,3,4,3,3,3,2,2,2,3,3,3,3,2,2,2,3,3,3,4,3,3,3,1},
    {1,3,3,4,4,4,3,2,2,2,3,3,4,4,3,3,2,2,2,3,4,4,4,3,3,1},
    {1,3,3,3,4,3,2,2,2,3,3,4,4,4,4,3,3,2,2,2,3,4,3,3,3,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};


class CPersonajes
{
protected:
    int posX;
    int posY;
    float velX;
    float velY;
    int direccion;
public:
    CPersonajes(int _posX, int _posY, float _velX, float _velY, int _direccion)
        :posX(_posX), posY(_posY), velX(_velX), velY(_velY), direccion(_direccion) {};
    virtual void pintar() = 0;
    virtual void fisica(float dt) = 0;

};


class CJugador : private CPersonajes{
private:
    char nombre[3];
    int vidas;
    long puntuacion;
    long tiempoTotal;
public:
    CJugador(int _posX, int _posY, float _velX, float _velY, int _direccion);
    virtual void pintar();
    virtual void fisica(float dt);
    friend void selectorNombre();
    friend void ordenaLista();
    friend void menuPintar(int i, int escenario);
    friend class CPintar;
    CJugador operator= (const CJugador&);
    friend ostream& operator<< (ostream&, const CJugador&);
    //Antiguo


    void fisicaNivel1();
    void fisicaNivel2();
    void fisicaNivel3();

    void pintarNivel1();
    void pintarNivel2();
    void pintarNivel3();

    //Falta por hacer la clase para nivel, 
    bool lvlCompleted();
};

CJugador::CJugador()
{
}

CJugador::CJugador(int _posX, int _posY, float _velX, float _velY, int _direccion) :CPersonajes(_posX, _posY, _velX, _velY, _direccion)
{
    strcpy(nombre, "AAA");
    vidas = 5;
    puntuacion = 0;
    tiempoTotal = 0;
}


//CONSTRUCTOR
CPac::CPac(float _xVPer, float _yVPer, int _xPer, int _yPer, float _dt,
    int _direction, int _tiempo, int _pts) {
    xVPer = _xVPer;
    yVPer = _yVPer;
    xPer = _xPer;
    yPer = _yPer;
    dt = _dt;
    direction = _direction;
    tiempo = _tiempo;
    pts = _pts;
}


//          NIVEL I.
void CPac::pintarNivel1() {

    al_clear_to_color(al_map_rgb(0, 0, 0));

    al_draw_bitmap(nivelIbackground, 0, 0, 0);

    for (int y = 0; y < 20; y++)
    {
        for (int x = 0; x < 26; x++)
        {
            if (mat_Nivel1[y][x] == 4)
            {
                al_draw_bitmap(muroNivel11, x * TAM, (y * TAM), 0);
            }
            if (mat_Nivel1[y][x] == 2)
            {
                al_draw_bitmap(item, (x * TAM) + 5, (y * TAM) + 5, 0);
            }
            if (mat_Nivel1[y][x] == 3) {
                al_draw_bitmap(muroNivel13, x * TAM, (y * TAM), 0);
            }
            if (mat_Nivel1[y][x] == 3) {
                al_draw_bitmap(muroNivel13, x * TAM, (y * TAM), 0);
            }
            if (mat_Nivel1[y][x] == 5) {
                al_draw_bitmap(muroNivel1, x * TAM, (y * TAM), 0); 
            }
            if (mat_Nivel1[y][x] == 6) {
                al_draw_bitmap(muroNivel16, x * TAM, (y * TAM), 0);
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

void CPac::fisicaNivel1() {
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

        if (mat_Nivel1[iMat][jMat + 1] == 4 || mat_Nivel1[iMat][jMat + 1] == 3 || 
            mat_Nivel1[iMat][jMat + 1] == 5 || mat_Nivel1[iMat][jMat + 1] == 6) {
            xPer = jMat * TAM;
        }

        if (mat_Nivel1[iMat][jMat + 1] == 4 || mat_Nivel1[iMat][jMat + 1] == 3 ||
            mat_Nivel1[iMat][jMat + 1] == 5 || mat_Nivel1[iMat][jMat + 1] == 6) {
            xPer = jMat * TAM;
        }

        if (mat_Nivel1[iMat][jMat + 1] == 4 || mat_Nivel1[iMat][jMat + 1] == 3 ||
            mat_Nivel1[iMat][jMat + 1] == 5 || mat_Nivel1[iMat][jMat + 1] == 6) {
            mat_Nivel1[iMat][jMat] = 0;
            pts++;
        }

        if (mat_Nivel1[iMat][jMat + 1] == 4 || mat_Nivel1[iMat][jMat + 1] == 3 ||
            mat_Nivel1[iMat][jMat + 1] == 5 || mat_Nivel1[iMat][jMat + 1] == 6) {
            mat_Nivel1[kMat][jMat] = 0;
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
        if (mat_Nivel1[iMat + 1][jMat] == 1) {
            yPer = iMat * TAM;
        }
        if (mat_Nivel1[iMat + 1][hMat] == 1) {
            yPer = iMat * TAM;
        }
        //		y		x
        if (mat_Nivel1[iMat][jMat] == 2) {
            mat_Nivel1[iMat][jMat] = 0;
            pts++;
        }
        //		y		x aux
        if (mat_Nivel1[iMat][hMat] == 2) {
            mat_Nivel1[iMat][hMat] = 0;
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
        if (mat_Nivel1[iMat][jMat - 1] == 1) {

            xPer = jMat * TAM;
        }
        if (mat_Nivel1[kMat][jMat - 1] == 1) {

            xPer = jMat * TAM;
        }

        if (mat_Nivel1[iMat][jMat] == 2) {
            mat_Nivel1[iMat][jMat] = 0;
            pts++;
        }

        if (mat_Nivel1[kMat][jMat] == 2) {
            mat_Nivel1[kMat][jMat] = 0;
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

        if (mat_Nivel1[iMat - 1][jMat] == 1) {
            yPer = iMat * TAM;
        }
        if (mat_Nivel1[iMat - 1][hMat] == 1) {

            yPer = iMat * TAM;
        }

        if (mat_Nivel1[iMat][jMat] == 2) {
            mat_Nivel1[iMat][jMat] = 0;
            pts++;
        }

        if (mat_Nivel1[iMat][hMat] == 2) {
            mat_Nivel1[iMat][hMat] = 0;
            pts++;
        }
    }
}

//---------------- NIVEL I. FIN ---------------------


//          NIVEL II.

void CPac::fisicaNivel2() {
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

        if (mat_Nivel1[iMat][jMat + 1] == 4 || mat_Nivel1[iMat][jMat + 1] == 3 ||
            mat_Nivel1[iMat][jMat + 1] == 5 || mat_Nivel1[iMat][jMat + 1] == 6) {
            xPer = jMat * TAM;
        }

        if (mat_Nivel1[iMat][jMat + 1] == 4 || mat_Nivel1[iMat][jMat + 1] == 3 ||
            mat_Nivel1[iMat][jMat + 1] == 5 || mat_Nivel1[iMat][jMat + 1] == 6) {
            xPer = jMat * TAM;
        }

        if (mat_Nivel1[iMat][jMat + 1] == 4 || mat_Nivel1[iMat][jMat + 1] == 3 ||
            mat_Nivel1[iMat][jMat + 1] == 5 || mat_Nivel1[iMat][jMat + 1] == 6) {
            mat_Nivel1[iMat][jMat] = 0;
            pts++;
        }

        if (mat_Nivel1[iMat][jMat + 1] == 4 || mat_Nivel1[iMat][jMat + 1] == 3 ||
            mat_Nivel1[iMat][jMat + 1] == 5 || mat_Nivel1[iMat][jMat + 1] == 6) {
            mat_Nivel1[kMat][jMat] = 0;
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
        if (mat_Nivel1[iMat + 1][jMat] == 1) {
            yPer = iMat * TAM;
        }
        if (mat_Nivel1[iMat + 1][hMat] == 1) {
            yPer = iMat * TAM;
        }
        //		y		x
        if (mat_Nivel1[iMat][jMat] == 2) {
            mat_Nivel1[iMat][jMat] = 0;
            pts++;
        }
        //		y		x aux
        if (mat_Nivel1[iMat][hMat] == 2) {
            mat_Nivel1[iMat][hMat] = 0;
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
        if (mat_Nivel1[iMat][jMat - 1] == 1) {

            xPer = jMat * TAM;
        }
        if (mat_Nivel1[kMat][jMat - 1] == 1) {

            xPer = jMat * TAM;
        }

        if (mat_Nivel1[iMat][jMat] == 2) {
            mat_Nivel1[iMat][jMat] = 0;
            pts++;
        }

        if (mat_Nivel1[kMat][jMat] == 2) {
            mat_Nivel1[kMat][jMat] = 0;
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

        if (mat_Nivel1[iMat - 1][jMat] == 1) {
            yPer = iMat * TAM;
        }
        if (mat_Nivel1[iMat - 1][hMat] == 1) {

            yPer = iMat * TAM;
        }

        if (mat_Nivel1[iMat][jMat] == 2) {
            mat_Nivel1[iMat][jMat] = 0;
            pts++;
        }

        if (mat_Nivel1[iMat][hMat] == 2) {
            mat_Nivel1[iMat][hMat] = 0;
            pts++;
        }
    }
}

void CPac::pintarNivel2() {

    al_clear_to_color(al_map_rgb(0, 0, 0));

    al_draw_bitmap(background, 0, 0, 0);

    for (int y = 0; y < 20; y++)
    {
        for (int x = 0; x < 26; x++)
        {
            if (mat_Nivel2[y][x] == 1)
            {
                al_draw_bitmap(muro, x * TAM, (y * TAM), 0);
            }
            if (mat_Nivel2[y][x] == 2)
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

//---------------- NIVEL II. FIN ---------------------

//NIVEL III.
void CPac::pintarNivel3()
{
    al_clear_to_color(al_map_rgb(0, 0, 0));

    al_draw_bitmap(backGroundNivel3, 0, 0, 0);

    for (int y = 0; y < 20; y++)
    {
        for (int x = 0; x < 26; x++)
        {
            if (mat_Nivel3[y][x] == 1)
            {
                al_draw_bitmap(muroNivel32, x * TAM, (y * TAM), 0);
            }
            if (mat_Nivel3[y][x] == 2)
            {
                al_draw_bitmap(item, (x * TAM) + 5, (y * TAM) + 5, 0);
            }
            if (mat_Nivel3[y][x] == 3) {
                al_draw_bitmap(muroNivel3, x * TAM, (y * TAM), 0);
            }
            if (mat_Nivel3[y][x] == 4) {
                al_draw_bitmap(muroNivel33, x * TAM, (y * TAM), 0);
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

void CPac::fisicaNivel3() {

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

        if (mat_Nivel1[iMat][jMat + 1] == 4 || mat_Nivel1[iMat][jMat + 1] == 3 ||
            mat_Nivel1[iMat][jMat + 1] == 5 || mat_Nivel1[iMat][jMat + 1] == 6) {
            xPer = jMat * TAM;
        }

        if (mat_Nivel1[iMat][jMat + 1] == 4 || mat_Nivel1[iMat][jMat + 1] == 3 ||
            mat_Nivel1[iMat][jMat + 1] == 5 || mat_Nivel1[iMat][jMat + 1] == 6) {
            xPer = jMat * TAM;
        }

        if (mat_Nivel1[iMat][jMat + 1] == 4 || mat_Nivel1[iMat][jMat + 1] == 3 ||
            mat_Nivel1[iMat][jMat + 1] == 5 || mat_Nivel1[iMat][jMat + 1] == 6) {
            mat_Nivel1[iMat][jMat] = 0;
            pts++;
        }

        if (mat_Nivel1[iMat][jMat + 1] == 4 || mat_Nivel1[iMat][jMat + 1] == 3 ||
            mat_Nivel1[iMat][jMat + 1] == 5 || mat_Nivel1[iMat][jMat + 1] == 6) {
            mat_Nivel1[kMat][jMat] = 0;
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
        if (mat_Nivel1[iMat + 1][jMat] == 1) {
            yPer = iMat * TAM;
        }
        if (mat_Nivel1[iMat + 1][hMat] == 1) {
            yPer = iMat * TAM;
        }
        //		y		x
        if (mat_Nivel1[iMat][jMat] == 2) {
            mat_Nivel1[iMat][jMat] = 0;
            pts++;
        }
        //		y		x aux
        if (mat_Nivel1[iMat][hMat] == 2) {
            mat_Nivel1[iMat][hMat] = 0;
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
        if (mat_Nivel1[iMat][jMat - 1] == 1) {

            xPer = jMat * TAM;
        }
        if (mat_Nivel1[kMat][jMat - 1] == 1) {

            xPer = jMat * TAM;
        }

        if (mat_Nivel1[iMat][jMat] == 2) {
            mat_Nivel1[iMat][jMat] = 0;
            pts++;
        }

        if (mat_Nivel1[kMat][jMat] == 2) {
            mat_Nivel1[kMat][jMat] = 0;
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

        if (mat_Nivel1[iMat - 1][jMat] == 1) {
            yPer = iMat * TAM;
        }
        if (mat_Nivel1[iMat - 1][hMat] == 1) {

            yPer = iMat * TAM;
        }

        if (mat_Nivel1[iMat][jMat] == 2) {
            mat_Nivel1[iMat][jMat] = 0;
            pts++;
        }

        if (mat_Nivel1[iMat][hMat] == 2) {
            mat_Nivel1[iMat][hMat] = 0;
            pts++;
        }
    }
}

//---------------- NIVEL III. FIN ---------------------

bool CPac::lvlCompleted() {
    bool lvlFin = true;

    for (int y = 0; y < 20; y++)
    {
        for (int x = 0; x < 26; x++)
        {
            if (mat_Nivel1[y][x] == 2)
            {
                lvlFin = false;
            }
        }
    }
    return lvlFin;
}

#endif