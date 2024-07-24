#pragma once

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/timer.h>
#include <allegro5/allegro_font.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>

using namespace std;

#ifndef PERSONAJES_HPP
#define PERSONAJES_HPP

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
    {5,2,3,2,3,3,2,3,5,2,2,2,2,2,2,2,2,3,5,2,3,3,2,3,2,3},
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
    /*
    virtual void pintarNivel1();
    virtual void fisicaNivel1(float dt);

    virtual void pintarNivel2();
    virtual void fisicaNivel2(int dt);

    virtual void pintarNivel3();
    virtual void fisicaNivel3(int dt);
    friend int main();
    friend class CPintar;
    */
};

class CJugador : private CPersonajes
{
private:
    char nombre[5];
    int vidas;
    long puntuacion;
    long tiempoTotal;
public:
    CJugador(int _posX, int _posY, float _velX, float _velY, int _direccion);

    void pintarNivel1();
    void fisicaNivel1(float dt);

    void pintarNivel2();
    void fisicaNivel2(int dt);

    void pintarNivel3();
    void fisicaNivel3(int dt);

    friend void selectorNombre();
    friend void ordenaLista();

    friend void menuPintar(int i, int escenario);

    bool lvlCompleted();

    CJugador operator= (const CJugador&);
    friend ostream& operator<< (ostream&, const CJugador&);
    friend int main();
    friend class CPintar;
};

//          NIVEL I.

void CJugador::pintarNivel1() {
    char cadena[30];
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

    al_draw_bitmap(imgPersonaje, posX, posY, 0);
    //Pintamos texto
    sprintf_s(cadena, "%d", tiempoTotal);
    al_draw_text(font, al_map_rgb(255, 255, 255), 775, 0, 0, cadena);

    sprintf_s(cadena, "Score: %d", puntuacion * 100);
    al_draw_text(font, al_map_rgb(255, 255, 255), 650, 0, 0, cadena);

    sprintf_s(cadena, "x:%d y:%d", mouseX, mouseY);
    al_draw_text(font, al_map_rgb(20, 20, 20), 2, 1, 0, cadena);
    al_draw_text(font, al_map_rgb(255, 255, 255), 0, 0, 0, cadena);

    al_draw_bitmap(cajaOpciones, 206, 178, 0);

    sprintf_s(cadena, "NIVEL COMPLETADO!");
    al_draw_text(font, al_map_rgb(20, 20, 20), 324, 242, 0, cadena);
    al_draw_text(font, al_map_rgb(255, 255, 255), 321, 242, 0, cadena);

    sprintf_s(cadena, "CONTINUAR");
    al_draw_text(font, al_map_rgb(20, 20, 20), 460, 352, 0, cadena);
    al_draw_text(font, al_map_rgb(255, 255, 255), 458, 352, 0, cadena);

    sprintf_s(cadena, "SALIR");
    al_draw_text(font, al_map_rgb(20, 20, 20), 266, 356, 0, cadena);
    al_draw_text(font, al_map_rgb(255, 255, 255), 264, 356, 0, cadena);
    //mandamos a pantalla
    al_flip_display();
}

void CJugador::fisicaNivel1(float dt){
//if(mat[iMat][jMat]==1
//
    if (direccion == DERECHA) {
        jMat = posX / TAM;
        iMat = (posY + 3) / TAM;
        kMat = (posY + 22) / TAM;

        if (kMat == 20)
            kMat--;

        posX = posX + (velX * dt);
        if (posX > ANCHO - 25) {
            posX = ANCHO - 25;
        }

        if (mat_Nivel1[iMat][jMat + 1] == 4 || mat_Nivel1[iMat][jMat + 1] == 3 ||
            mat_Nivel1[iMat][jMat + 1] == 5 || mat_Nivel1[iMat][jMat + 1] == 6) {
            posX = jMat * TAM;
        }

        if (mat_Nivel1[iMat][jMat + 1] == 4 || mat_Nivel1[iMat][jMat + 1] == 3 ||
            mat_Nivel1[iMat][jMat + 1] == 5 || mat_Nivel1[iMat][jMat + 1] == 6) {
            posX = jMat * TAM;
        }

        if (mat_Nivel1[iMat][jMat + 1] == 4 || mat_Nivel1[iMat][jMat + 1] == 3 ||
            mat_Nivel1[iMat][jMat + 1] == 5 || mat_Nivel1[iMat][jMat + 1] == 6) {
            mat_Nivel1[iMat][jMat] = 0;
            puntuacion++;
        }

        if (mat_Nivel1[iMat][jMat + 1] == 4 || mat_Nivel1[iMat][jMat + 1] == 3 ||
            mat_Nivel1[iMat][jMat + 1] == 5 || mat_Nivel1[iMat][jMat + 1] == 6) {
            mat_Nivel1[kMat][jMat] = 0;
            puntuacion++;
        }
    }
    ///

    if (direccion == ABAJO) {
        jMat = (posX + 2) / TAM;// x
        iMat = posY / TAM;// y
        hMat = (posX + 23) / TAM;	// x a la derecha

        if (hMat == 26)
            hMat--;

        posY = posY + (velY * dt);
        if (posY > ALTO - 25) {
            posY = ALTO - 25;
        }
        if (mat_Nivel1[iMat + 1][jMat] == 1) {
            posY = iMat * TAM;
        }
        if (mat_Nivel1[iMat + 1][hMat] == 1) {
            posY = iMat * TAM;
        }
        //		y		x
        if (mat_Nivel1[iMat][jMat] == 2) {
            mat_Nivel1[iMat][jMat] = 0;
            puntuacion++;
        }
        //		y		x aux
        if (mat_Nivel1[iMat][hMat] == 2) {
            mat_Nivel1[iMat][hMat] = 0;
            puntuacion++;
        }
    }
    //

    /*
    //Para hacer los calculos m�s exactos para los movimientos de IZQUIERDA y ARRIBA
    jMat=(xPer+25)/TAM;
    iMat=(yPer+25)/TAM;

    if(jMat==26)
        jMat--;

    if(iMat==20)
        iMat--;*/


    if (direccion == IZQUIERDA) {
        jMat = (posX + 25) / TAM;
        iMat = (posY + 22) / TAM;
        kMat = (posY + 3) / TAM;

        if (jMat == 26)
            jMat--;

        if (iMat == 20)
            iMat--;

        posX = posX - (velX * dt);
        if (posX < 0) {
            posX = 0;
        }
        if (mat_Nivel1[iMat][jMat - 1] == 1) {

            posX = jMat * TAM;
        }
        if (mat_Nivel1[kMat][jMat - 1] == 1) {

            posX = jMat * TAM;
        }

        if (mat_Nivel1[iMat][jMat] == 2) {
            mat_Nivel1[iMat][jMat] = 0;
            puntuacion++;
        }

        if (mat_Nivel1[kMat][jMat] == 2) {
            mat_Nivel1[kMat][jMat] = 0;
            puntuacion++;
        }
    }

    if (direccion == ARRIBA) {
        jMat = (posX + 23) / TAM;
        iMat = (posY + 25) / TAM;
        hMat = (posX + 2) / TAM;

        if (jMat == 26)
            jMat--;

        if (iMat == 20)
            iMat--;

        posY -= velY * dt;
        if (posY < 0) {
            posY = 0;
        }

        if (mat_Nivel1[iMat - 1][jMat] == 1) {
            posY = iMat * TAM;
        }
        if (mat_Nivel1[iMat - 1][hMat] == 1) {

            posY = iMat * TAM;
        }

        if (mat_Nivel1[iMat][jMat] == 2) {
            mat_Nivel1[iMat][jMat] = 0;
            puntuacion++;
        }

        if (mat_Nivel1[iMat][hMat] == 2) {
            mat_Nivel1[iMat][hMat] = 0;
            puntuacion++;
        }
    }
}

//---------------- NIVEL I. FIN ---------------------


void CJugador::fisicaNivel2(int dt) {
    if (direccion == DERECHA) {
        jMat = posX / TAM;
        iMat = (posY + 3) / TAM;
        kMat = (posY + 22) / TAM;

        if (kMat == 20)
            kMat--;

        posX = posX + (velX * dt);
        if (posX > ANCHO - 25) {
            posX = ANCHO - 25;
        }

        if (mat_Nivel1[iMat][jMat + 1] == 4 || mat_Nivel1[iMat][jMat + 1] == 3 ||
            mat_Nivel1[iMat][jMat + 1] == 5 || mat_Nivel1[iMat][jMat + 1] == 6) {
            posX = jMat * TAM;
        }

        if (mat_Nivel1[iMat][jMat + 1] == 4 || mat_Nivel1[iMat][jMat + 1] == 3 ||
            mat_Nivel1[iMat][jMat + 1] == 5 || mat_Nivel1[iMat][jMat + 1] == 6) {
            posX = jMat * TAM;
        }

        if (mat_Nivel1[iMat][jMat + 1] == 4 || mat_Nivel1[iMat][jMat + 1] == 3 ||
            mat_Nivel1[iMat][jMat + 1] == 5 || mat_Nivel1[iMat][jMat + 1] == 6) {
            mat_Nivel1[iMat][jMat] = 0;
            puntuacion++;
        }

        if (mat_Nivel1[iMat][jMat + 1] == 4 || mat_Nivel1[iMat][jMat + 1] == 3 ||
            mat_Nivel1[iMat][jMat + 1] == 5 || mat_Nivel1[iMat][jMat + 1] == 6) {
            mat_Nivel1[kMat][jMat] = 0;
            puntuacion++;
        }
    }
    ///

    if (direccion == ABAJO) {
        jMat = (posX + 2) / TAM;// x
        iMat = posY / TAM;// y
        hMat = (posX + 23) / TAM;	// x a la derecha

        if (hMat == 26)
            hMat--;

        posY = posY + (velY * dt);
        if (posY > ALTO - 25) {
            posY = ALTO - 25;
        }
        if (mat_Nivel1[iMat + 1][jMat] == 1) {
            posY = iMat * TAM;
        }
        if (mat_Nivel1[iMat + 1][hMat] == 1) {
            posY = iMat * TAM;
        }
        //		y		x
        if (mat_Nivel1[iMat][jMat] == 2) {
            mat_Nivel1[iMat][jMat] = 0;
            puntuacion++;
        }
        //		y		x aux
        if (mat_Nivel1[iMat][hMat] == 2) {
            mat_Nivel1[iMat][hMat] = 0;
            puntuacion++;
        }
    }
    //

    /*
    //Para hacer los calculos m�s exactos para los movimientos de IZQUIERDA y ARRIBA
    jMat=(posX+25)/TAM;
    iMat=(posY+25)/TAM;

    if(jMat==26)
        jMat--;

    if(iMat==20)
        iMat--;*/


    if (direccion == IZQUIERDA) {
        jMat = (posX + 25) / TAM;
        iMat = (posY + 22) / TAM;
        kMat = (posY + 3) / TAM;

        if (jMat == 26)
            jMat--;

        if (iMat == 20)
            iMat--;

        posX = posX - (velX * dt);
        if (posX < 0) {
            posX = 0;
        }
        if (mat_Nivel1[iMat][jMat - 1] == 1) {

            posX = jMat * TAM;
        }
        if (mat_Nivel1[kMat][jMat - 1] == 1) {

            posX = jMat * TAM;
        }

        if (mat_Nivel1[iMat][jMat] == 2) {
            mat_Nivel1[iMat][jMat] = 0;
            puntuacion++;
        }

        if (mat_Nivel1[kMat][jMat] == 2) {
            mat_Nivel1[kMat][jMat] = 0;
            puntuacion++;
        }
    }

    if (direccion == ARRIBA) {
        jMat = (posX + 23) / TAM;
        iMat = (posY + 25) / TAM;
        hMat = (posX + 2) / TAM;

        if (jMat == 26)
            jMat--;

        if (iMat == 20)
            iMat--;

        posY -= velY * dt;
        if (posY < 0) {
            posY = 0;
        }

        if (mat_Nivel1[iMat - 1][jMat] == 1) {
            posY = iMat * TAM;
        }
        if (mat_Nivel1[iMat - 1][hMat] == 1) {

            posY = iMat * TAM;
        }

        if (mat_Nivel1[iMat][jMat] == 2) {
            mat_Nivel1[iMat][jMat] = 0;
            puntuacion++;
        }

        if (mat_Nivel1[iMat][hMat] == 2) {
            mat_Nivel1[iMat][hMat] = 0;
            puntuacion++;
        }
    }
}

void CJugador::pintarNivel2() {

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
    al_draw_bitmap(imgPersonaje, posX, posY, 0);
    //Pintamos texto
    char cadena[20];
    sprintf_s(cadena, "%d", tiempoTotal);
    al_draw_text(font, al_map_rgb(255, 255, 255), 775, 0, 0, cadena);

    sprintf_s(cadena, "Score: %d", puntuacion * 100);
    al_draw_text(font, al_map_rgb(255, 255, 255), 650, 0, 0, cadena);
    //mandamos a pantalla
    al_flip_display();
}

//---------------- NIVEL II. FIN ---------------------

//NIVEL III.     

void CJugador::pintarNivel3()
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
        //cuando el muchachon llegue al punto
        al_draw_bitmap(cajaOpciones, 206, 178, 0);

    }

    al_draw_bitmap(imgPersonaje, posX, posY, 0);
    //Pintamos texto
    char cadena[20];
    sprintf_s(cadena, "%d", tiempoTotal);
    al_draw_text(font, al_map_rgb(255, 255, 255), 775, 0, 0, cadena);

    sprintf_s(cadena, "Score: %d", puntuacion * 100);
    al_draw_text(font, al_map_rgb(255, 255, 255), 650, 0, 0, cadena);
    //mandamos a pantalla
    al_flip_display();



}

void CJugador::fisicaNivel3(int dt) {

    if (direccion == DERECHA) {
        jMat = posX / TAM;
        iMat = (posY + 3) / TAM;
        kMat = (posY + 22) / TAM;

        if (kMat == 20)
            kMat--;

        posX = posX + (velX * dt);
        if (posX > ANCHO - 25) {
            posX = ANCHO - 25;
        }

        if (mat_Nivel1[iMat][jMat + 1] == 4 || mat_Nivel1[iMat][jMat + 1] == 3 ||
            mat_Nivel1[iMat][jMat + 1] == 5 || mat_Nivel1[iMat][jMat + 1] == 6) {
            posX = jMat * TAM;
        }

        if (mat_Nivel1[iMat][jMat + 1] == 4 || mat_Nivel1[iMat][jMat + 1] == 3 ||
            mat_Nivel1[iMat][jMat + 1] == 5 || mat_Nivel1[iMat][jMat + 1] == 6) {
            posX = jMat * TAM;
        }

        if (mat_Nivel1[iMat][jMat + 1] == 4 || mat_Nivel1[iMat][jMat + 1] == 3 ||
            mat_Nivel1[iMat][jMat + 1] == 5 || mat_Nivel1[iMat][jMat + 1] == 6) {
            mat_Nivel1[iMat][jMat] = 0;
            puntuacion++;
        }

        if (mat_Nivel1[iMat][jMat + 1] == 4 || mat_Nivel1[iMat][jMat + 1] == 3 ||
            mat_Nivel1[iMat][jMat + 1] == 5 || mat_Nivel1[iMat][jMat + 1] == 6) {
            mat_Nivel1[kMat][jMat] = 0;
            puntuacion++;
        }
    }
    ///

    if (direccion == ABAJO) {
        jMat = (posX + 2) / TAM;// x
        iMat = posY / TAM;// y
        hMat = (posX + 23) / TAM;	// x a la derecha

        if (hMat == 26)
            hMat--;

        posY = posY + (velY * dt);
        if (posY > ALTO - 25) {
            posY = ALTO - 25;
        }
        if (mat_Nivel1[iMat + 1][jMat] == 1) {
            posY = iMat * TAM;
        }
        if (mat_Nivel1[iMat + 1][hMat] == 1) {
            posY = iMat * TAM;
        }
        //		y		x
        if (mat_Nivel1[iMat][jMat] == 2) {
            mat_Nivel1[iMat][jMat] = 0;
            puntuacion++;
        }
        //		y		x aux
        if (mat_Nivel1[iMat][hMat] == 2) {
            mat_Nivel1[iMat][hMat] = 0;
            puntuacion++;
        }
    }
    //

    /*
    //Para hacer los calculos m�s exactos para los movimientos de IZQUIERDA y ARRIBA
    jMat=(posX+25)/TAM;
    iMat=(posY+25)/TAM;

    if(jMat==26)
        jMat--;

    if(iMat==20)
        iMat--;*/


    if (direccion == IZQUIERDA) {
        jMat = (posX + 25) / TAM;
        iMat = (posY + 22) / TAM;
        kMat = (posY + 3) / TAM;

        if (jMat == 26)
            jMat--;

        if (iMat == 20)
            iMat--;

        posX = posX - (velX * dt);
        if (posX < 0) {
            posX = 0;
        }
        if (mat_Nivel1[iMat][jMat - 1] == 1) {

            posX = jMat * TAM;
        }
        if (mat_Nivel1[kMat][jMat - 1] == 1) {

            posX = jMat * TAM;
        }

        if (mat_Nivel1[iMat][jMat] == 2) {
            mat_Nivel1[iMat][jMat] = 0;
            puntuacion++;
        }

        if (mat_Nivel1[kMat][jMat] == 2) {
            mat_Nivel1[kMat][jMat] = 0;
            puntuacion++;
        }
    }

    if (direccion == ARRIBA) {
        jMat = (posX + 23) / TAM;
        iMat = (posY + 25) / TAM;
        hMat = (posX + 2) / TAM;

        if (jMat == 26)
            jMat--;

        if (iMat == 20)
            iMat--;

        posY -= velY * dt;
        if (posY < 0) {
            posY = 0;
        }

        if (mat_Nivel1[iMat - 1][jMat] == 1) {
            posY = iMat * TAM;
        }
        if (mat_Nivel1[iMat - 1][hMat] == 1) {

            posY = iMat * TAM;
        }

        if (mat_Nivel1[iMat][jMat] == 2) {
            mat_Nivel1[iMat][jMat] = 0;
            puntuacion++;
        }

        if (mat_Nivel1[iMat][hMat] == 2) {
            mat_Nivel1[iMat][hMat] = 0;
            puntuacion++;
        }
    }
}


//---------------- NIVEL III. FIN ---------------------



bool CJugador::lvlCompleted() {
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


CJugador::CJugador(int _posX, int _posY, float _velX, float _velY, int _direccion) :CPersonajes(_posX, _posY, _velX, _velY, _direccion)
{
    strcpy_s(nombre, "AAA");
    vidas = 5;
    puntuacion = 0;
    tiempoTotal = 0;
}

CJugador CJugador::operator= (const CJugador& obj)
{
    this->posX = obj.posX;
    this->posY = obj.posY;
    this->velX = obj.velX;
    this->velY = obj.velY;
    this->direccion = obj.direccion;
    strcpy_s(this->nombre, obj.nombre);
    this->vidas = obj.vidas;
    this->puntuacion = obj.puntuacion;
    this->tiempoTotal = obj.tiempoTotal;
    return (*this);
}

ostream& operator<< (ostream& co, const CJugador& obj)
{
    co << obj.posX << " " << obj.posY << " " << obj.velX << " " << obj.velY << " " << obj.direccion << " "
        << obj.nombre << " " << obj.vidas << " " << obj.puntuacion << " " << obj.tiempoTotal;
    return co;
}


class CEnemigo : public CPersonajes
{
public:
    bool sentido;// true = horario      false = antihorario
    CEnemigo(float, float, int, int, int,bool);
    void fisicaNivel1(float);
    void fisicaNivel2(float);
    void fisicaNivel3(float);
};

CEnemigo::CEnemigo(float _velX, float _velY, int _posX, int _posY, int _direccion,bool _sentido)
:CPersonajes(_velX, _velY,  _posX,  _posY, _direccion)
{
    sentido = _sentido;
}

void CEnemigo::fisicaNivel1(float dt)//cambia de direccion cada que hay un bloque enfrente del enemigo
{
// chocar con 3,4,5,6
    int iMat = (posX+3)/TAM;
    int jMat = (posY+3)/TAM;
    int kMat = (posX+22)/TAM;
    int hMat = (posY+22)/TAM;
    if (sentido)
    {//sentido horario
        switch (direccion)
        {
        case ARRIBA:
            if(mat_Nivel1[hMat-1][iMat] == 3 || mat_Nivel1[hMat-1][kMat] == 3
            || mat_Nivel1[hMat-1][iMat] == 4 || mat_Nivel1[hMat-1][kMat] == 4
            || mat_Nivel1[hMat-1][iMat] == 5 || mat_Nivel1[hMat-1][kMat] == 5
            || mat_Nivel1[hMat-1][iMat] == 6 || mat_Nivel1[hMat-1][kMat] == 6)
            {
                posY = hMat *TAM;
                if((mat_Nivel1[hMat][iMat+1] == 2 || mat_Nivel1[hMat][iMat+1] == 0) 
                && (mat_Nivel1[hMat][kMat+1] == 2 || mat_Nivel1[hMat][kMat+1] == 0))
                {
                    posX += velX * dt;
                    direccion = DERECHA;
                }else if((mat_Nivel1[hMat-1][iMat] == 2 || mat_Nivel1[hMat-1][iMat] == 0) 
                && (mat_Nivel1[hMat-1][kMat] == 2 || mat_Nivel1[hMat-1][kMat] == 0))
                {
                    posY -= velY * dt;
                    direccion = ARRIBA;
                }else if((mat_Nivel1[hMat][iMat-1] == 2 || mat_Nivel1[hMat][iMat-1] == 0) 
                && (mat_Nivel1[hMat][kMat-1] == 2 || mat_Nivel1[hMat][kMat-1] == 0))
                {
                    posX -= velX * dt;
                    direccion = IZQUIERDA;
                }else if((mat_Nivel1[hMat+1][iMat] == 2 || mat_Nivel1[hMat+1][iMat] == 0) 
                && (mat_Nivel1[hMat+1][kMat] == 2 || mat_Nivel1[hMat+1][kMat] == 0))
                {
                    posY += velY * dt;
                    direccion = ABAJO;
                }
            }else{
                posY -= velY * dt;
            }
            break;
        case ABAJO:
            if(mat_Nivel1[jMat+1][iMat] == 3 || mat_Nivel1[jMat+1][kMat] == 3
            || mat_Nivel1[jMat+1][iMat] == 4 || mat_Nivel1[jMat+1][kMat] == 4
            || mat_Nivel1[jMat+1][iMat] == 5 || mat_Nivel1[jMat+1][kMat] == 5
            || mat_Nivel1[jMat+1][iMat] == 6 || mat_Nivel1[jMat+1][kMat] == 6)
            {
                posY = jMat *TAM;
                if((mat_Nivel1[jMat][iMat-1] == 2 || mat_Nivel1[jMat][iMat-1] == 0) 
                && (mat_Nivel1[jMat][kMat-1] == 2 || mat_Nivel1[jMat][kMat-1] == 0))
                {
                    posX -= velX * dt;
                    direccion = IZQUIERDA;
                }else if((mat_Nivel1[jMat+1][iMat] == 2 || mat_Nivel1[jMat+1][iMat] == 0) 
                && (mat_Nivel1[jMat+1][kMat] == 2 || mat_Nivel1[jMat+1][kMat] == 0))
                {
                    posY += velY * dt;
                    direccion = ABAJO;
                }else if((mat_Nivel1[jMat][iMat+1] == 2 || mat_Nivel1[jMat][iMat+1] == 0) 
                && (mat_Nivel1[jMat][kMat+1] == 2 || mat_Nivel1[jMat][kMat+1] == 0))
                {
                    posX += velX * dt;
                    direccion = DERECHA;
                }else if((mat_Nivel1[jMat-1][iMat] == 2 || mat_Nivel1[jMat-1][iMat] == 0) 
                && (mat_Nivel1[jMat-1][kMat] == 2 || mat_Nivel1[jMat-1][kMat] == 0))
                {
                    posY -= velY * dt;
                    direccion = ARRIBA;
                }
            }else{
                posY += velY * dt;
            }
            break;
        case IZQUIERDA:
            if(mat_Nivel1[jMat][iMat-1] == 3 || mat_Nivel1[hMat][iMat-1] == 3
            || mat_Nivel1[jMat][iMat-1] == 4 || mat_Nivel1[hMat][iMat-1] == 4
            || mat_Nivel1[jMat][iMat-1] == 5 || mat_Nivel1[hMat][iMat-1] == 5
            || mat_Nivel1[jMat][iMat-1] == 6 || mat_Nivel1[hMat][iMat-1] == 6)
            {
                posX = iMat *TAM;
                if((mat_Nivel1[jMat-1][iMat] == 2 || mat_Nivel1[jMat-1][iMat] == 0) 
                && (mat_Nivel1[hMat-1][iMat] == 2 || mat_Nivel1[hMat-1][iMat] == 0))
                {
                    posY -= velY * dt;
                    direccion = ARRIBA;
                }else if((mat_Nivel1[jMat][iMat-1] == 2 || mat_Nivel1[jMat][iMat-1] == 0) 
                && (mat_Nivel1[hMat][iMat-1] == 2 || mat_Nivel1[hMat][iMat-1] == 0))
                {
                    posX -= velX * dt;
                    direccion = IZQUIERDA;
                }else if((mat_Nivel1[jMat+1][iMat] == 2 || mat_Nivel1[jMat+1][iMat] == 0) 
                && (mat_Nivel1[hMat+1][iMat] == 2 || mat_Nivel1[hMat+1][iMat] == 0))
                {
                    posY += velY * dt;
                    direccion = ABAJO;
                }else if((mat_Nivel1[jMat][iMat+1] == 2 || mat_Nivel1[jMat][iMat+1] == 0) 
                && (mat_Nivel1[hMat][iMat+1] == 2 || mat_Nivel1[hMat][iMat+1] == 0))
                {
                    posX += velX * dt;
                    direccion = DERECHA;
                }
            }else{
                posX -= velX * dt;
            }
            break;
        case DERECHA:
            if(mat_Nivel1[jMat][kMat+1] == 3 || mat_Nivel1[hMat][kMat+1] == 3
            || mat_Nivel1[jMat][kMat+1] == 4 || mat_Nivel1[hMat][kMat+1] == 4
            || mat_Nivel1[jMat][kMat+1] == 5 || mat_Nivel1[hMat][kMat+1] == 5
            || mat_Nivel1[jMat][kMat+1] == 6 || mat_Nivel1[hMat][kMat+1] == 6)
            {
                posX = kMat *TAM;
                if((mat_Nivel1[jMat+1][kMat] == 2 || mat_Nivel1[jMat+1][kMat] == 0) 
                && (mat_Nivel1[hMat+1][kMat] == 2 || mat_Nivel1[hMat+1][kMat] == 0))
                {
                    posY += velY * dt;
                    direccion = ABAJO;
                }else if((mat_Nivel1[jMat][kMat+1] == 2 || mat_Nivel1[jMat][kMat+1] == 0) 
                && (mat_Nivel1[hMat][kMat+1] == 2 || mat_Nivel1[hMat][kMat+1] == 0))
                {
                    posX += velX * dt;
                    direccion = DERECHA;
                }else if((mat_Nivel1[jMat-1][kMat] == 2 || mat_Nivel1[jMat-1][kMat] == 0) 
                && (mat_Nivel1[hMat-1][kMat] == 2 || mat_Nivel1[hMat-1][kMat] == 0))
                {
                    posY -= velY * dt;
                    direccion = ARRIBA;
                }else if((mat_Nivel1[jMat][kMat-1] == 2 || mat_Nivel1[jMat][kMat-1] == 0) 
                && (mat_Nivel1[hMat][kMat-1] == 2 || mat_Nivel1[hMat][kMat-1] == 0))
                {
                    posX -= velX * dt;
                    direccion = IZQUIERDA;
                }
            }else{
                posX += velX * dt;
            }
            break;
        }
    }else{
        switch (direccion)
        {
        case ARRIBA:
            if(mat_Nivel1[hMat-1][iMat] == 3 || mat_Nivel1[hMat-1][kMat] == 3
            || mat_Nivel1[hMat-1][iMat] == 4 || mat_Nivel1[hMat-1][kMat] == 4
            || mat_Nivel1[hMat-1][iMat] == 5 || mat_Nivel1[hMat-1][kMat] == 5
            || mat_Nivel1[hMat-1][iMat] == 6 || mat_Nivel1[hMat-1][kMat] == 6)
            {
                posY = hMat *TAM;
                if((mat_Nivel1[hMat][iMat-1] == 2 || mat_Nivel1[hMat][iMat-1] == 0) 
                && (mat_Nivel1[hMat][kMat-1] == 2 || mat_Nivel1[hMat][kMat-1] == 0))
                {
                    posX -= velX * dt;
                    direccion = IZQUIERDA;
                }else if((mat_Nivel1[hMat-1][iMat] == 2 || mat_Nivel1[hMat-1][iMat] == 0) 
                && (mat_Nivel1[hMat-1][kMat] == 2 || mat_Nivel1[hMat-1][kMat] == 0))
                {
                    posY -= velY * dt;
                    direccion = ARRIBA;
                }else if((mat_Nivel1[hMat][iMat+1] == 2 || mat_Nivel1[hMat][iMat+1] == 0) 
                && (mat_Nivel1[hMat][kMat+1] == 2 || mat_Nivel1[hMat][kMat+1] == 0))
                {
                    posX += velX * dt;
                    direccion = DERECHA;
                }else if((mat_Nivel1[hMat+1][iMat] == 2 || mat_Nivel1[hMat+1][iMat] == 0) 
                && (mat_Nivel1[hMat+1][kMat] == 2 || mat_Nivel1[hMat+1][kMat] == 0))
                {
                    posY += velY * dt;
                    direccion = ABAJO;
                }
            }else{
                posY -= velY * dt;
            }
            break;
        case ABAJO:
            if(mat_Nivel1[jMat+1][iMat] == 3 || mat_Nivel1[jMat+1][kMat] == 3
            || mat_Nivel1[jMat+1][iMat] == 4 || mat_Nivel1[jMat+1][kMat] == 4
            || mat_Nivel1[jMat+1][iMat] == 5 || mat_Nivel1[jMat+1][kMat] == 5
            || mat_Nivel1[jMat+1][iMat] == 6 || mat_Nivel1[jMat+1][kMat] == 6)
            {
                posY = jMat *TAM;
                if((mat_Nivel1[jMat][iMat+1] == 2 || mat_Nivel1[jMat][iMat+1] == 0) 
                && (mat_Nivel1[jMat][kMat+1] == 2 || mat_Nivel1[jMat][kMat+1] == 0))
                {
                    posX += velX * dt;
                    direccion = DERECHA;
                }else if((mat_Nivel1[jMat+1][iMat] == 2 || mat_Nivel1[jMat+1][iMat] == 0) 
                && (mat_Nivel1[jMat+1][kMat] == 2 || mat_Nivel1[jMat+1][kMat] == 0))
                {
                    posY += velY * dt;
                    direccion = ABAJO;
                }else if((mat_Nivel1[jMat][iMat-1] == 2 || mat_Nivel1[jMat][iMat-1] == 0) 
                && (mat_Nivel1[jMat][kMat-1] == 2 || mat_Nivel1[jMat][kMat-1] == 0))
                {
                    posX -= velX * dt;
                    direccion = IZQUIERDA;
                }else if((mat_Nivel1[jMat-1][iMat] == 2 || mat_Nivel1[jMat-1][iMat] == 0) 
                && (mat_Nivel1[jMat-1][kMat] == 2 || mat_Nivel1[jMat-1][kMat] == 0))
                {
                    posY -= velY * dt;
                    direccion = ARRIBA;
                }
            }else{
                posY += velY * dt;
            }
            break;
        case IZQUIERDA:
            if(mat_Nivel1[jMat][iMat-1] == 3 || mat_Nivel1[hMat][iMat-1] == 3
            || mat_Nivel1[jMat][iMat-1] == 4 || mat_Nivel1[hMat][iMat-1] == 4
            || mat_Nivel1[jMat][iMat-1] == 5 || mat_Nivel1[hMat][iMat-1] == 5
            || mat_Nivel1[jMat][iMat-1] == 6 || mat_Nivel1[hMat][iMat-1] == 6)
            {
                posX = iMat *TAM;
                if((mat_Nivel1[jMat+1][iMat] == 2 || mat_Nivel1[jMat+1][iMat] == 0) 
                && (mat_Nivel1[hMat+1][iMat] == 2 || mat_Nivel1[hMat+1][iMat] == 0))
                {
                    posY += velY * dt;
                    direccion = ABAJO;
                }else if((mat_Nivel1[jMat][iMat-1] == 2 || mat_Nivel1[jMat][iMat-1] == 0) 
                && (mat_Nivel1[hMat][iMat-1] == 2 || mat_Nivel1[hMat][iMat-1] == 0))
                {
                    posX -= velX * dt;
                    direccion = IZQUIERDA;
                }else if((mat_Nivel1[jMat-1][iMat] == 2 || mat_Nivel1[jMat-1][iMat] == 0) 
                && (mat_Nivel1[hMat-1][iMat] == 2 || mat_Nivel1[hMat-1][iMat] == 0))
                {
                    posY -= velY * dt;
                    direccion = ARRIBA;
                }else if((mat_Nivel1[jMat][iMat+1] == 2 || mat_Nivel1[jMat][iMat+1] == 0) 
                && (mat_Nivel1[hMat][iMat+1] == 2 || mat_Nivel1[hMat][iMat+1] == 0))
                {
                    posX += velX * dt;
                    direccion = DERECHA;
                }
            }else{
                posX -= velX * dt;
            }
            break;
        case DERECHA:
            if(mat_Nivel1[jMat][kMat+1] == 3 || mat_Nivel1[hMat][kMat+1] == 3
            || mat_Nivel1[jMat][kMat+1] == 4 || mat_Nivel1[hMat][kMat+1] == 4
            || mat_Nivel1[jMat][kMat+1] == 5 || mat_Nivel1[hMat][kMat+1] == 5
            || mat_Nivel1[jMat][kMat+1] == 6 || mat_Nivel1[hMat][kMat+1] == 6)
            {
                posX = kMat *TAM;
                if((mat_Nivel1[jMat-1][kMat] == 2 || mat_Nivel1[jMat-1][kMat] == 0) 
                && (mat_Nivel1[hMat-1][kMat] == 2 || mat_Nivel1[hMat-1][kMat] == 0))
                {
                    posY -= velY * dt;
                    direccion = ARRIBA;
                }else if((mat_Nivel1[jMat][kMat+1] == 2 || mat_Nivel1[jMat][kMat+1] == 0) 
                && (mat_Nivel1[hMat][kMat+1] == 2 || mat_Nivel1[hMat][kMat+1] == 0))
                {
                    posX += velX * dt;
                    direccion = DERECHA;
                }else if((mat_Nivel1[jMat+1][kMat] == 2 || mat_Nivel1[jMat+1][kMat] == 0) 
                && (mat_Nivel1[hMat+1][kMat] == 2 || mat_Nivel1[hMat+1][kMat] == 0))
                {
                    posY += velY * dt;
                    direccion = ABAJO;
                }else if((mat_Nivel1[jMat][kMat-1] == 2 || mat_Nivel1[jMat][kMat-1] == 0) 
                && (mat_Nivel1[hMat][kMat-1] == 2 || mat_Nivel1[hMat][kMat-1] == 0))
                {
                    posX -= velX * dt;
                    direccion = IZQUIERDA;
                }
            }else{
                posX += velX * dt;
            }
            break;
        }
    }
}

void CEnemigo::fisicaNivel2(float dt)
{
    //choca con 1
    int iMat = (posX+3)/TAM;
    int jMat = (posY+3)/TAM;
    int kMat = (posX+22)/TAM;
    int hMat = (posY+22)/TAM;
    if (sentido)
    {//sentido horario
        switch (direccion)
        {
        case ARRIBA:
            if(mat_Nivel2[hMat-1][iMat] == 1 || mat_Nivel2[hMat-1][kMat] == 1)
            {
                posY = hMat *TAM;
                if((mat_Nivel2[hMat][iMat+1] == 2 || mat_Nivel2[hMat][iMat+1] == 0) 
                && (mat_Nivel2[hMat][kMat+1] == 2 || mat_Nivel2[hMat][kMat+1] == 0))
                {
                    posX += velX * dt;
                    direccion = DERECHA;
                }else if((mat_Nivel2[hMat-1][iMat] == 2 || mat_Nivel2[hMat-1][iMat] == 0) 
                && (mat_Nivel2[hMat-1][kMat] == 2 || mat_Nivel2[hMat-1][kMat] == 0))
                {
                    posY -= velY * dt;
                    direccion = ARRIBA;
                }else if((mat_Nivel2[hMat][iMat-1] == 2 || mat_Nivel2[hMat][iMat-1] == 0) 
                && (mat_Nivel2[hMat][kMat-1] == 2 || mat_Nivel2[hMat][kMat-1] == 0))
                {
                    posX -= velX * dt;
                    direccion = IZQUIERDA;
                }else if((mat_Nivel2[hMat+1][iMat] == 2 || mat_Nivel2[hMat+1][iMat] == 0) 
                && (mat_Nivel2[hMat+1][kMat] == 2 || mat_Nivel2[hMat+1][kMat] == 0))
                {
                    posY += velY * dt;
                    direccion = ABAJO;
                }
            }else{
                posY -= velY * dt;
            }
            break;
        case ABAJO:
            if(mat_Nivel2[jMat+1][iMat] == 1 || mat_Nivel2[jMat+1][kMat] == 1)
            {
                posY = jMat *TAM;
                if((mat_Nivel2[jMat][iMat-1] == 2 || mat_Nivel2[jMat][iMat-1] == 0) 
                && (mat_Nivel2[jMat][kMat-1] == 2 || mat_Nivel2[jMat][kMat-1] == 0))
                {
                    posX -= velX * dt;
                    direccion = IZQUIERDA;
                }else if((mat_Nivel2[jMat+1][iMat] == 2 || mat_Nivel2[jMat+1][iMat] == 0) 
                && (mat_Nivel2[jMat+1][kMat] == 2 || mat_Nivel2[jMat+1][kMat] == 0))
                {
                    posY += velY * dt;
                    direccion = ABAJO;
                }else if((mat_Nivel2[jMat][iMat+1] == 2 || mat_Nivel2[jMat][iMat+1] == 0) 
                && (mat_Nivel2[jMat][kMat+1] == 2 || mat_Nivel2[jMat][kMat+1] == 0))
                {
                    posX += velX * dt;
                    direccion = DERECHA;
                }else if((mat_Nivel2[jMat-1][iMat] == 2 || mat_Nivel2[jMat-1][iMat] == 0) 
                && (mat_Nivel2[jMat-1][kMat] == 2 || mat_Nivel2[jMat-1][kMat] == 0))
                {
                    posY -= velY * dt;
                    direccion = ARRIBA;
                }
            }else{
                posY += velY * dt;
            }
            break;
        case IZQUIERDA:
            if(mat_Nivel2[jMat][iMat-1] == 1 || mat_Nivel2[hMat][iMat-1] == 1)
            {
                posX = iMat *TAM;
                if((mat_Nivel2[jMat-1][iMat] == 2 || mat_Nivel2[jMat-1][iMat] == 0) 
                && (mat_Nivel2[hMat-1][iMat] == 2 || mat_Nivel2[hMat-1][iMat] == 0))
                {
                    posY -= velY * dt;
                    direccion = ARRIBA;
                }else if((mat_Nivel2[jMat][iMat-1] == 2 || mat_Nivel2[jMat][iMat-1] == 0) 
                && (mat_Nivel2[hMat][iMat-1] == 2 || mat_Nivel2[hMat][iMat-1] == 0))
                {
                    posX -= velX * dt;
                    direccion = IZQUIERDA;
                }else if((mat_Nivel2[jMat+1][iMat] == 2 || mat_Nivel2[jMat+1][iMat] == 0) 
                && (mat_Nivel2[hMat+1][iMat] == 2 || mat_Nivel2[hMat+1][iMat] == 0))
                {
                    posY += velY * dt;
                    direccion = ABAJO;
                }else if((mat_Nivel2[jMat][iMat+1] == 2 || mat_Nivel2[jMat][iMat+1] == 0) 
                && (mat_Nivel2[hMat][iMat+1] == 2 || mat_Nivel2[hMat][iMat+1] == 0))
                {
                    posX += velX * dt;
                    direccion = DERECHA;
                }
            }else{
                posX -= velX * dt;
            }
            break;
        case DERECHA:
            if(mat_Nivel2[jMat][kMat+1] == 1 || mat_Nivel2[hMat][kMat+1] == 1)
            {
                posX = kMat *TAM;
                if((mat_Nivel2[jMat+1][kMat] == 2 || mat_Nivel2[jMat+1][kMat] == 0) 
                && (mat_Nivel2[hMat+1][kMat] == 2 || mat_Nivel2[hMat+1][kMat] == 0))
                {
                    posY += velY * dt;
                    direccion = ABAJO;
                }else if((mat_Nivel2[jMat][kMat+1] == 2 || mat_Nivel2[jMat][kMat+1] == 0) 
                && (mat_Nivel2[hMat][kMat+1] == 2 || mat_Nivel2[hMat][kMat+1] == 0))
                {
                    posX += velX * dt;
                    direccion = DERECHA;
                }else if((mat_Nivel2[jMat-1][kMat] == 2 || mat_Nivel2[jMat-1][kMat] == 0) 
                && (mat_Nivel2[hMat-1][kMat] == 2 || mat_Nivel2[hMat-1][kMat] == 0))
                {
                    posY -= velY * dt;
                    direccion = ARRIBA;
                }else if((mat_Nivel2[jMat][kMat-1] == 2 || mat_Nivel2[jMat][kMat-1] == 0) 
                && (mat_Nivel2[hMat][kMat-1] == 2 || mat_Nivel2[hMat][kMat-1] == 0))
                {
                    posX -= velX * dt;
                    direccion = IZQUIERDA;
                }
            }else{
                posX += velX * dt;
            }
            break;
        }
    }else{
        switch (direccion)
        {
        case ARRIBA:
            if(mat_Nivel2[hMat-1][iMat] == 1 || mat_Nivel2[hMat-1][kMat] == 1)
            {
                posY = hMat *TAM;
                if((mat_Nivel2[hMat][iMat-1] == 2 || mat_Nivel2[hMat][iMat-1] == 0) 
                && (mat_Nivel2[hMat][kMat-1] == 2 || mat_Nivel2[hMat][kMat-1] == 0))
                {
                    posX -= velX * dt;
                    direccion = IZQUIERDA;
                }else if((mat_Nivel2[hMat-1][iMat] == 2 || mat_Nivel2[hMat-1][iMat] == 0) 
                && (mat_Nivel2[hMat-1][kMat] == 2 || mat_Nivel2[hMat-1][kMat] == 0))
                {
                    posY -= velY * dt;
                    direccion = ARRIBA;
                }else if((mat_Nivel2[hMat][iMat+1] == 2 || mat_Nivel2[hMat][iMat+1] == 0) 
                && (mat_Nivel2[hMat][kMat+1] == 2 || mat_Nivel2[hMat][kMat+1] == 0))
                {
                    posX += velX * dt;
                    direccion = DERECHA;
                }else if((mat_Nivel2[hMat+1][iMat] == 2 || mat_Nivel2[hMat+1][iMat] == 0) 
                && (mat_Nivel2[hMat+1][kMat] == 2 || mat_Nivel2[hMat+1][kMat] == 0))
                {
                    posY += velY * dt;
                    direccion = ABAJO;
                }
            }else{
                posY -= velY * dt;
            }
            break;
        case ABAJO:
            if(mat_Nivel2[jMat+1][iMat] == 1 || mat_Nivel2[jMat+1][kMat] == 1)
            {
                posY = jMat *TAM;
                if((mat_Nivel2[jMat][iMat+1] == 2 || mat_Nivel2[jMat][iMat+1] == 0) 
                && (mat_Nivel2[jMat][kMat+1] == 2 || mat_Nivel2[jMat][kMat+1] == 0))
                {
                    posX += velX * dt;
                    direccion = DERECHA;
                }else if((mat_Nivel2[jMat+1][iMat] == 2 || mat_Nivel2[jMat+1][iMat] == 0) 
                && (mat_Nivel2[jMat+1][kMat] == 2 || mat_Nivel2[jMat+1][kMat] == 0))
                {
                    posY += velY * dt;
                    direccion = ABAJO;
                }else if((mat_Nivel2[jMat][iMat-1] == 2 || mat_Nivel2[jMat][iMat-1] == 0) 
                && (mat_Nivel2[jMat][kMat-1] == 2 || mat_Nivel2[jMat][kMat-1] == 0))
                {
                    posX -= velX * dt;
                    direccion = IZQUIERDA;
                }else if((mat_Nivel2[jMat-1][iMat] == 2 || mat_Nivel2[jMat-1][iMat] == 0) 
                && (mat_Nivel2[jMat-1][kMat] == 2 || mat_Nivel2[jMat-1][kMat] == 0))
                {
                    posY -= velY * dt;
                    direccion = ARRIBA;
                }
            }else{
                posY += velY * dt;
            }
            break;
        case IZQUIERDA:
            if(mat_Nivel2[jMat][iMat-1] == 1 || mat_Nivel2[hMat][iMat-1] == 1)
            {
                posX = iMat *TAM;
                if((mat_Nivel2[jMat+1][iMat] == 2 || mat_Nivel2[jMat+1][iMat] == 0) 
                && (mat_Nivel2[hMat+1][iMat] == 2 || mat_Nivel2[hMat+1][iMat] == 0))
                {
                    posY += velY * dt;
                    direccion = ABAJO;
                }else if((mat_Nivel2[jMat][iMat-1] == 2 || mat_Nivel2[jMat][iMat-1] == 0) 
                && (mat_Nivel2[hMat][iMat-1] == 2 || mat_Nivel2[hMat][iMat-1] == 0))
                {
                    posX -= velX * dt;
                    direccion = IZQUIERDA;
                }else if((mat_Nivel2[jMat-1][iMat] == 2 || mat_Nivel2[jMat-1][iMat] == 0) 
                && (mat_Nivel2[hMat-1][iMat] == 2 || mat_Nivel2[hMat-1][iMat] == 0))
                {
                    posY -= velY * dt;
                    direccion = ARRIBA;
                }else if((mat_Nivel2[jMat][iMat+1] == 2 || mat_Nivel2[jMat][iMat+1] == 0) 
                && (mat_Nivel2[hMat][iMat+1] == 2 || mat_Nivel2[hMat][iMat+1] == 0))
                {
                    posX += velX * dt;
                    direccion = DERECHA;
                }
            }else{
                posX -= velX * dt;
            }
            break;
        case DERECHA:
            if(mat_Nivel2[jMat][kMat+1] == 4 || mat_Nivel2[hMat][kMat+1] == 4)
            {
                posX = kMat *TAM;
                if((mat_Nivel2[jMat-1][kMat] == 2 || mat_Nivel2[jMat-1][kMat] == 0) 
                && (mat_Nivel2[hMat-1][kMat] == 2 || mat_Nivel2[hMat-1][kMat] == 0))
                {
                    posY -= velY * dt;
                    direccion = ARRIBA;
                }else if((mat_Nivel2[jMat][kMat+1] == 2 || mat_Nivel2[jMat][kMat+1] == 0) 
                && (mat_Nivel2[hMat][kMat+1] == 2 || mat_Nivel2[hMat][kMat+1] == 0))
                {
                    posX += velX * dt;
                    direccion = DERECHA;
                }else if((mat_Nivel2[jMat+1][kMat] == 2 || mat_Nivel2[jMat+1][kMat] == 0) 
                && (mat_Nivel2[hMat+1][kMat] == 2 || mat_Nivel2[hMat+1][kMat] == 0))
                {
                    posY += velY * dt;
                    direccion = ABAJO;
                }else if((mat_Nivel2[jMat][kMat-1] == 2 || mat_Nivel2[jMat][kMat-1] == 0) 
                && (mat_Nivel2[hMat][kMat-1] == 2 || mat_Nivel2[hMat][kMat-1] == 0))
                {
                    posX -= velX * dt;
                    direccion = IZQUIERDA;
                }
            }else{
                posX += velX * dt;
            }
            break;
        }
    }
}

void CEnemigo::fisicaNivel3(float dt)
{
    //choca con 1,3,4
    int iMat = (posX+3)/TAM;
    int jMat = (posY+3)/TAM;
    int kMat = (posX+22)/TAM;
    int hMat = (posY+22)/TAM;
    if (sentido)
    {//sentido horario
        switch (direccion)
        {
        case ARRIBA:
            if(mat_Nivel3[hMat-1][iMat] == 3 || mat_Nivel3[hMat-1][kMat] == 3
            || mat_Nivel3[hMat-1][iMat] == 4 || mat_Nivel3[hMat-1][kMat] == 4
            || mat_Nivel3[hMat-1][iMat] == 1 || mat_Nivel3[hMat-1][kMat] == 1)
            {
                posY = hMat *TAM;
                if((mat_Nivel3[hMat][iMat+1] == 2 || mat_Nivel3[hMat][iMat+1] == 0) 
                && (mat_Nivel3[hMat][kMat+1] == 2 || mat_Nivel3[hMat][kMat+1] == 0))
                {
                    posX += velX * dt;
                    direccion = DERECHA;
                }else if((mat_Nivel3[hMat-1][iMat] == 2 || mat_Nivel3[hMat-1][iMat] == 0) 
                && (mat_Nivel3[hMat-1][kMat] == 2 || mat_Nivel3[hMat-1][kMat] == 0))
                {
                    posY -= velY * dt;
                    direccion = ARRIBA;
                }else if((mat_Nivel3[hMat][iMat-1] == 2 || mat_Nivel3[hMat][iMat-1] == 0) 
                && (mat_Nivel3[hMat][kMat-1] == 2 || mat_Nivel3[hMat][kMat-1] == 0))
                {
                    posX -= velX * dt;
                    direccion = IZQUIERDA;
                }else if((mat_Nivel3[hMat+1][iMat] == 2 || mat_Nivel3[hMat+1][iMat] == 0) 
                && (mat_Nivel3[hMat+1][kMat] == 2 || mat_Nivel3[hMat+1][kMat] == 0))
                {
                    posY += velY * dt;
                    direccion = ABAJO;
                }
            }else{
                posY -= velY * dt;
            }
            break;
        case ABAJO:
            if(mat_Nivel3[jMat+1][iMat] == 3 || mat_Nivel3[jMat+1][kMat] == 3
            || mat_Nivel3[jMat+1][iMat] == 4 || mat_Nivel3[jMat+1][kMat] == 4
            || mat_Nivel3[jMat+1][iMat] == 1 || mat_Nivel3[jMat+1][kMat] == 1)
            {
                posY = jMat *TAM;
                if((mat_Nivel3[jMat][iMat-1] == 2 || mat_Nivel3[jMat][iMat-1] == 0) 
                && (mat_Nivel3[jMat][kMat-1] == 2 || mat_Nivel3[jMat][kMat-1] == 0))
                {
                    posX -= velX * dt;
                    direccion = IZQUIERDA;
                }else if((mat_Nivel3[jMat+1][iMat] == 2 || mat_Nivel3[jMat+1][iMat] == 0) 
                && (mat_Nivel3[jMat+1][kMat] == 2 || mat_Nivel3[jMat+1][kMat] == 0))
                {
                    posY += velY * dt;
                    direccion = ABAJO;
                }else if((mat_Nivel3[jMat][iMat+1] == 2 || mat_Nivel3[jMat][iMat+1] == 0) 
                && (mat_Nivel3[jMat][kMat+1] == 2 || mat_Nivel3[jMat][kMat+1] == 0))
                {
                    posX += velX * dt;
                    direccion = DERECHA;
                }else if((mat_Nivel3[jMat-1][iMat] == 2 || mat_Nivel3[jMat-1][iMat] == 0) 
                && (mat_Nivel3[jMat-1][kMat] == 2 || mat_Nivel3[jMat-1][kMat] == 0))
                {
                    posY -= velY * dt;
                    direccion = ARRIBA;
                }
            }else{
                posY += velY * dt;
            }
            break;
        case IZQUIERDA:
            if(mat_Nivel3[jMat][iMat-1] == 3 || mat_Nivel3[hMat][iMat-1] == 3
            || mat_Nivel3[jMat][iMat-1] == 4 || mat_Nivel3[hMat][iMat-1] == 4
            || mat_Nivel3[jMat][iMat-1] == 1 || mat_Nivel3[hMat][iMat-1] == 1)
            {
                posX = iMat *TAM;
                if((mat_Nivel3[jMat-1][iMat] == 2 || mat_Nivel3[jMat-1][iMat] == 0) 
                && (mat_Nivel3[hMat-1][iMat] == 2 || mat_Nivel3[hMat-1][iMat] == 0))
                {
                    posY -= velY * dt;
                    direccion = ARRIBA;
                }else if((mat_Nivel3[jMat][iMat-1] == 2 || mat_Nivel3[jMat][iMat-1] == 0) 
                && (mat_Nivel3[hMat][iMat-1] == 2 || mat_Nivel3[hMat][iMat-1] == 0))
                {
                    posX -= velX * dt;
                    direccion = IZQUIERDA;
                }else if((mat_Nivel3[jMat+1][iMat] == 2 || mat_Nivel3[jMat+1][iMat] == 0) 
                && (mat_Nivel3[hMat+1][iMat] == 2 || mat_Nivel3[hMat+1][iMat] == 0))
                {
                    posY += velY * dt;
                    direccion = ABAJO;
                }else if((mat_Nivel3[jMat][iMat+1] == 2 || mat_Nivel3[jMat][iMat+1] == 0) 
                && (mat_Nivel3[hMat][iMat+1] == 2 || mat_Nivel3[hMat][iMat+1] == 0))
                {
                    posX += velX * dt;
                    direccion = DERECHA;
                }
            }else{
                posX -= velX * dt;
            }
            break;
        case DERECHA:
            if(mat_Nivel3[jMat][kMat+1] == 3 || mat_Nivel3[hMat][kMat+1] == 3
            || mat_Nivel3[jMat][kMat+1] == 4 || mat_Nivel3[hMat][kMat+1] == 4
            || mat_Nivel3[jMat][kMat+1] == 1 || mat_Nivel3[hMat][kMat+1] == 1)
            {
                posX = kMat *TAM;
                if((mat_Nivel3[jMat+1][kMat] == 2 || mat_Nivel3[jMat+1][kMat] == 0) 
                && (mat_Nivel3[hMat+1][kMat] == 2 || mat_Nivel3[hMat+1][kMat] == 0))
                {
                    posY += velY * dt;
                    direccion = ABAJO;
                }else if((mat_Nivel3[jMat][kMat+1] == 2 || mat_Nivel3[jMat][kMat+1] == 0) 
                && (mat_Nivel3[hMat][kMat+1] == 2 || mat_Nivel3[hMat][kMat+1] == 0))
                {
                    posX += velX * dt;
                    direccion = DERECHA;
                }else if((mat_Nivel3[jMat-1][kMat] == 2 || mat_Nivel3[jMat-1][kMat] == 0) 
                && (mat_Nivel3[hMat-1][kMat] == 2 || mat_Nivel3[hMat-1][kMat] == 0))
                {
                    posY -= velY * dt;
                    direccion = ARRIBA;
                }else if((mat_Nivel3[jMat][kMat-1] == 2 || mat_Nivel3[jMat][kMat-1] == 0) 
                && (mat_Nivel3[hMat][kMat-1] == 2 || mat_Nivel3[hMat][kMat-1] == 0))
                {
                    posX -= velX * dt;
                    direccion = IZQUIERDA;
                }
            }else{
                posX += velX * dt;
            }
            break;
        }
    }else{
        switch (direccion)
        {
        case ARRIBA:
            if(mat_Nivel3[hMat-1][iMat] == 3 || mat_Nivel3[hMat-1][kMat] == 3
            || mat_Nivel3[hMat-1][iMat] == 4 || mat_Nivel3[hMat-1][kMat] == 4
            || mat_Nivel3[hMat-1][iMat] == 1 || mat_Nivel3[hMat-1][kMat] == 1)
            {
                posY = hMat *TAM;
                if((mat_Nivel3[hMat][iMat-1] == 2 || mat_Nivel3[hMat][iMat-1] == 0) 
                && (mat_Nivel3[hMat][kMat-1] == 2 || mat_Nivel3[hMat][kMat-1] == 0))
                {
                    posX -= velX * dt;
                    direccion = IZQUIERDA;
                }else if((mat_Nivel3[hMat-1][iMat] == 2 || mat_Nivel3[hMat-1][iMat] == 0) 
                && (mat_Nivel3[hMat-1][kMat] == 2 || mat_Nivel3[hMat-1][kMat] == 0))
                {
                    posY -= velY * dt;
                    direccion = ARRIBA;
                }else if((mat_Nivel3[hMat][iMat+1] == 2 || mat_Nivel3[hMat][iMat+1] == 0) 
                && (mat_Nivel3[hMat][kMat+1] == 2 || mat_Nivel3[hMat][kMat+1] == 0))
                {
                    posX += velX * dt;
                    direccion = DERECHA;
                }else if((mat_Nivel3[hMat+1][iMat] == 2 || mat_Nivel3[hMat+1][iMat] == 0) 
                && (mat_Nivel3[hMat+1][kMat] == 2 || mat_Nivel3[hMat+1][kMat] == 0))
                {
                    posY += velY * dt;
                    direccion = ABAJO;
                }
            }else{
                posY -= velY * dt;
            }
            break;
        case ABAJO:
            if(mat_Nivel3[jMat+1][iMat] == 3 || mat_Nivel3[jMat+1][kMat] == 3
            || mat_Nivel3[jMat+1][iMat] == 4 || mat_Nivel3[jMat+1][kMat] == 4
            || mat_Nivel3[jMat+1][iMat] == 1 || mat_Nivel3[jMat+1][kMat] == 1)
            {
                posY = jMat *TAM;
                if((mat_Nivel3[jMat][iMat+1] == 2 || mat_Nivel3[jMat][iMat+1] == 0) 
                && (mat_Nivel3[jMat][kMat+1] == 2 || mat_Nivel3[jMat][kMat+1] == 0))
                {
                    posX += velX * dt;
                    direccion = DERECHA;
                }else if((mat_Nivel3[jMat+1][iMat] == 2 || mat_Nivel3[jMat+1][iMat] == 0) 
                && (mat_Nivel3[jMat+1][kMat] == 2 || mat_Nivel3[jMat+1][kMat] == 0))
                {
                    posY += velY * dt;
                    direccion = ABAJO;
                }else if((mat_Nivel3[jMat][iMat-1] == 2 || mat_Nivel3[jMat][iMat-1] == 0) 
                && (mat_Nivel3[jMat][kMat-1] == 2 || mat_Nivel3[jMat][kMat-1] == 0))
                {
                    posX -= velX * dt;
                    direccion = IZQUIERDA;
                }else if((mat_Nivel3[jMat-1][iMat] == 2 || mat_Nivel3[jMat-1][iMat] == 0) 
                && (mat_Nivel3[jMat-1][kMat] == 2 || mat_Nivel3[jMat-1][kMat] == 0))
                {
                    posY -= velY * dt;
                    direccion = ARRIBA;
                }
            }else{
                posY += velY * dt;
            }
            break;
        case IZQUIERDA:
            if(mat_Nivel3[jMat][iMat-1] == 3 || mat_Nivel3[hMat][iMat-1] == 3
            || mat_Nivel3[jMat][iMat-1] == 4 || mat_Nivel3[hMat][iMat-1] == 4
            || mat_Nivel3[jMat][iMat-1] == 1 || mat_Nivel3[hMat][iMat-1] == 1)
            {
                posX = iMat *TAM;
                if((mat_Nivel3[jMat+1][iMat] == 2 || mat_Nivel3[jMat+1][iMat] == 0) 
                && (mat_Nivel3[hMat+1][iMat] == 2 || mat_Nivel3[hMat+1][iMat] == 0))
                {
                    posY += velY * dt;
                    direccion = ABAJO;
                }else if((mat_Nivel3[jMat][iMat-1] == 2 || mat_Nivel3[jMat][iMat-1] == 0) 
                && (mat_Nivel3[hMat][iMat-1] == 2 || mat_Nivel3[hMat][iMat-1] == 0))
                {
                    posX -= velX * dt;
                    direccion = IZQUIERDA;
                }else if((mat_Nivel3[jMat-1][iMat] == 2 || mat_Nivel3[jMat-1][iMat] == 0) 
                && (mat_Nivel3[hMat-1][iMat] == 2 || mat_Nivel3[hMat-1][iMat] == 0))
                {
                    posY -= velY * dt;
                    direccion = ARRIBA;
                }else if((mat_Nivel3[jMat][iMat+1] == 2 || mat_Nivel3[jMat][iMat+1] == 0) 
                && (mat_Nivel3[hMat][iMat+1] == 2 || mat_Nivel3[hMat][iMat+1] == 0))
                {
                    posX += velX * dt;
                    direccion = DERECHA;
                }
            }else{
                posX -= velX * dt;
            }
            break;
        case DERECHA:
            if(mat_Nivel3[jMat][kMat+1] == 1 || mat_Nivel3[hMat][kMat+1] == 1
            || mat_Nivel3[jMat][kMat+1] == 3 || mat_Nivel3[hMat][kMat+1] == 3
            || mat_Nivel3[jMat][kMat+1] == 4 || mat_Nivel3[hMat][kMat+1] == 4)
            {
                posX = kMat *TAM;
                if((mat_Nivel3[jMat-1][kMat] == 2 || mat_Nivel3[jMat-1][kMat] == 0) 
                && (mat_Nivel3[hMat-1][kMat] == 2 || mat_Nivel3[hMat-1][kMat] == 0))
                {
                    posY -= velY * dt;
                    direccion = ARRIBA;
                }else if((mat_Nivel3[jMat][kMat+1] == 2 || mat_Nivel3[jMat][kMat+1] == 0) 
                && (mat_Nivel3[hMat][kMat+1] == 2 || mat_Nivel3[hMat][kMat+1] == 0))
                {
                    posX += velX * dt;
                    direccion = DERECHA;
                }else if((mat_Nivel3[jMat+1][kMat] == 2 || mat_Nivel3[jMat+1][kMat] == 0) 
                && (mat_Nivel3[hMat+1][kMat] == 2 || mat_Nivel3[hMat+1][kMat] == 0))
                {
                    posY += velY * dt;
                    direccion = ABAJO;
                }else if((mat_Nivel3[jMat][kMat-1] == 2 || mat_Nivel3[jMat][kMat-1] == 0) 
                && (mat_Nivel3[hMat][kMat-1] == 2 || mat_Nivel3[hMat][kMat-1] == 0))
                {
                    posX -= velX * dt;
                    direccion = IZQUIERDA;
                }
            }else{
                posX += velX * dt;
            }
            break;
        }
    }
}

#endif