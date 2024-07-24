#pragma once
#include <iostream>
#include <locale>

using namespace std;

#ifndef LOGICAMOUSE_HPP
#define LOGICAMOUSE_HPP


class CMouse {
public:
    int mouseX;
    int mouseY;
    int escenarioNuevaPartida;
    int escenariomenuNivel;

    int logicaMenu(int);
    int logicaMouseMenu(int);

    int logica_MenuNuevaPartida();
    int logicaMouseNuevaPartida(int);

    int logicaMouseCargaPartida(int);
    int logicaMousePuntuaciones(int);

    int logicaMenuNieveles(int);
    int logicaMouseNieveles(int);

    int logicaMouseMenuNuevaPartida2(int);

    int logicaMouseInstruccion(int);

    int logicaMouseNivel1(int);

    int logicaMouseNivel2(int);

    int logicaMouseNivel3(int);

};




int CMouse::logicaMenu(int escenario) {
    // Nueva partida	1
    // Cargar Partida	2
    // Marcadores		3
    // Salir			4
    // Niveles          5
    //Menu Nueva P2     6
    //Nivel 1           7
    //Instrucciones     8
    //Nivel 2           9
    //Nivel 3           10

    switch (escenario) {
    case 0:
        //MENU PRINCIPAL
        escenario = logicaMouseMenu(escenario);
        break;
    case 1:
        escenario = logicaMouseNuevaPartida(escenario);
        break;
    case 2:
        escenario = logicaMouseCargaPartida(escenario);
        break;
    case 3:
        escenario = logicaMousePuntuaciones(escenario);
        break;
    case 5:
        escenario = logicaMouseNieveles(escenario);
        break;
    case 6:
        escenario = logicaMouseMenuNuevaPartida2(escenario);
        break;
    case 7:
        escenario = logicaMouseNivel1(escenario);
        break;
    case 8:
        escenario = logicaMouseInstruccion(escenario);
        break;
    case 9:
        escenario = logicaMouseNivel2(escenario);
        break;
    case 10:
        escenario = logicaMouseNivel3(escenario);
        break;
    default:
        break;
    }
    return escenario;
}

//################## NUEVA PARTIDA ############################


int CMouse::logicaMouseNuevaPartida(int escenarioNuevaPartida) {

    //Regresar
    if (mouseX >= 585 && mouseX <= 755 && mouseY >= 555 && mouseY <= 586) {
        if (event.mouse.button) {
            return 0;
        }
    }
    //MENU 2, confirmar nombre
    if (mouseX >= 315 && mouseX <= 480 && mouseY >= 407 && mouseY <= 439) {
        if (event.mouse.button) {
            //Para el menu de confirmacion    
            return 6;
        }
    }
    return 1;
}

//A PARTIR DE LA LOGICA MOUSE MENU TENEMOS 
int CMouse::logicaMouseMenu(int escenario) {
    //Nueva Partida
    if (mouseX >= 215 && mouseX <= 585 && mouseY >= 200 && mouseY <= 255) {
        if (event.mouse.button) {
            return 1;
        }
        else {
            return escenario;
        }
    }
    //Cargar Partida
    else if (mouseX >= 215 && mouseX <= 585 && mouseY >= 280 && mouseY <= 315) {
        if (event.mouse.button) {
            return 2;
        }
        else {
            return escenario;
        }
    }
    //Marcadores
    else if (mouseX >= 215 && mouseX <= 585 && mouseY >= 359 && mouseY <= 400) {
        if (event.mouse.button) {
            return 3;
        }
        else {
            return escenario;
        }
    }
    //Salir
    else if (mouseX >= 585 && mouseX <= 755 && mouseY >= 555 && mouseY <= 586) {
        if (event.mouse.button) {
            return 4;
        }
        else {
            return escenario;
        }
    }
    return escenario;
}

int CMouse::logicaMouseCargaPartida(int escenarioCargarPartida)
{
     //selccion del usuario
    if(userCount != 0)
    {
        if(pageView != userPage)
        {
            for (int i = 1; i <= 12; i++)
            {
                if (mouseX >= 100 && mouseX <= 700 && mouseY >= (211 +((i-1)*26)) && mouseY <= (237 + ((i-1)*26))) {
                    if (event.mouse.button) {
                        per = listaUsuarios[i+(12*(pageView-1))-1];
                        //agregar return al selector de niveles
                    }
                }
            }
        }else{
            if(userCount%12 == 0)
            {
                for (int i = 1; i <= 12; i++)
                {
                    if (mouseX >= 100 && mouseX <= 700 && mouseY >= (211 +((i-1)*26)) && mouseY <= (237 + ((i-1)*26))) {
                        if (event.mouse.button) {
                            per = listaUsuarios[i+(12*(pageView-1))-1];
                            //agregar return al selector de niveles
                        }
                    }
                }
            }else{
                for (int i = 1; i <= userCount%12; i++)
                {
                    if (mouseX >= 100 && mouseX <= 700 && mouseY >= (211 +((i-1)*26)) && mouseY <= (237 + ((i-1)*26))) {
                        if (event.mouse.button) {
                            per = listaUsuarios[i+(12*(pageView-1))-1];
                            //agregar return al selector de niveles
                        }
                    }
                }
            }
        }
    }

    //avanzar o retroceder paginas
    if(userPage > 1)
    {
        if(pageView == 1)
        {
            //Avanzar pagina
            if (mouseX >= 385 && mouseX <= 555 && mouseY >= 555 && mouseY <= 586) {
                if (event.mouse.button) {
                    pageView++;
                }
            }
        }else if(pageView == userPage)
        {
            if (mouseX >= 205 && mouseX <= 375 && mouseY >= 555 && mouseY <= 586) {
                if (event.mouse.button) {
                    pageView--;
                }
            }
        }else
        {
            //Regresar pagina
            if (mouseX >= 205 && mouseX <= 375 && mouseY >= 555 && mouseY <= 586) {
                if (event.mouse.button) {
                    pageView--;
                }
            }
            //Avanzar pagina
            if (mouseX >= 385 && mouseX <= 555 && mouseY >= 555 && mouseY <= 586) {
                if (event.mouse.button) {
                    pageView++;
                }
            }
        }
    }

    //Regresar
    if (mouseX >= 585 && mouseX <= 755 && mouseY >= 555 && mouseY <= 586) {
        if (event.mouse.button) {
            return 0;
        }
        else {
            return escenarioCargarPartida;
        }
    }

    return escenarioCargarPartida;
}

int CMouse::logicaMousePuntuaciones(int escenarioPuntuaciones)
{
//avanzar o retroceder paginas
    if(userPage > 1)
    {
        if(pageView == 1)
        {
            //Avanzar pagina
            if (mouseX >= 385 && mouseX <= 555 && mouseY >= 555 && mouseY <= 586) {
                if (event.mouse.button) {
                    pageView++;
                }
            }
        }else if(pageView == userPage)
        {
            if (mouseX >= 205 && mouseX <= 375 && mouseY >= 555 && mouseY <= 586) {
                if (event.mouse.button) {
                    pageView--;
                }
            }
        }else
        {
            //Regresar pagina
            if (mouseX >= 205 && mouseX <= 375 && mouseY >= 555 && mouseY <= 586) {
                if (event.mouse.button) {
                    pageView--;
                }
            }
            //Avanzar pagina
            if (mouseX >= 385 && mouseX <= 555 && mouseY >= 555 && mouseY <= 586) {
                if (event.mouse.button) {
                    pageView++;
                }
            }
        }
    }

    //Regresar
    if (mouseX >= 585 && mouseX <= 755 && mouseY >= 555 && mouseY <= 586) {
        if (event.mouse.button) {
//            cout<<"boton regreso";
            return 0;
        }
        else {
            return escenarioPuntuaciones;
        }
    }   

    return escenarioPuntuaciones;
}

//NIVELES
int CMouse::logicaMenuNieveles(int escenario)
{
    /*
    NIVEL 1...........1
    NIVEL 2...........2
    NIVEL 3...........3
    REGRESAR AL MENU..4
    */

    switch (escenariomenuNivel) {
    case 1:
        //JUEGO
        escenario = logicaMouseNivel1(escenario);
        break;
    case 2:
        escenario = logicaMouseNivel2(escenario);
        break;
    case 3:
        escenario = logicaMouseNivel3(escenario);
        break;
    }
    return escenario;
}

int CMouse::logicaMouseNieveles(int escenario)
{
    //Nivel 1
    if (mouseX >= 50 && mouseX <= 250 && mouseY >= 55 && mouseY <= 250) {
        if (event.mouse.button) {
            escenariomenuNivel = 1;
            //Escenario 7, debido a que este es el 7
            escenario = 7;
            escenario = logicaMenuNieveles(escenario);
            return 7;
        }
    }
    else if (mouseX >= 300 && mouseX <= 500 && mouseY >= 220 && mouseY <= 413) {
        if (event.mouse.button) {
            //Escenario 9, nivel 2
            escenariomenuNivel = 2;
            escenario = 9;
            escenario = logicaMenuNieveles(escenario);
            return 9;
        }
    }
    else if (mouseX >= 550 && mouseX <= 750 && mouseY >= 370 && mouseY <= 562) {
        if (event.mouse.button) {
            escenariomenuNivel = 3;
            escenario = 10;
            escenario = logicaMenuNieveles(escenario);
            return 10;
        }
    }
    return 5;
}


int CMouse::logicaMouseMenuNuevaPartida2(int escenario) {

    if (mouseX >= 250 && mouseX <= 336 && mouseY >= 422 && mouseY <= 457) {
        if (event.mouse.button) {
            //Instrucciones
            return 8;
        }
    }
    else if (mouseX >= 463 && mouseX <= 545 && mouseY >= 421 && mouseY <= 458) {
        if (event.mouse.button) {
            //Regresar Menu Nueva partida
            return 1;
        }
    }
    return 6;
}

//############### NIVEL 1 ###################

int CMouse::logicaMouseNivel1(int escenario) {
    //Regresar 
    if (mouseX >= 255 && mouseX <= 333 && mouseY >= 348 && mouseY <= 376) {
        if (event.mouse.button) {
            //Regresar Menu Nueva partida
            return 0;
        }
    }
    else if (mouseX >= 453 && mouseX <= 534 && mouseY >= 345 && mouseY <= 374) {
        if (event.mouse.button) {
            //Regresar Menu Nueva partida
            return 9;
        }
    }
    return 7;
}

//------------- NIVEL 1 FIN ----------------


// ############ NIVEL 2 ###################

int CMouse::logicaMouseNivel2(int escenario) {
    if (mouseX >= 255 && mouseX <= 333 && mouseY >= 348 && mouseY <= 376) {
        if (event.mouse.button) {
            //Regresar Menu Nueva partida
            return 0;
        }
    }
    else if (mouseX >= 453 && mouseX <= 534 && mouseY >= 345 && mouseY <= 374) {
        if (event.mouse.button) {
            //Regresar Menu Nueva partida
            return 10;
        }
    }
    return 9;
}

int CMouse::logicaMouseNivel3(int escenario)
{
    if (mouseX >= 255 && mouseX <= 333 && mouseY >= 348 && mouseY <= 376) {
        if (event.mouse.button) {
            //Regresar Menu Nueva partida
            return 0;
        }
    }
    else if (mouseX >= 453 && mouseX <= 534 && mouseY >= 345 && mouseY <= 374) {
        if (event.mouse.button) {
            //Regresar Menu Nueva partida
            return 9;
        }
    }
    return 10;
}


// ------------ NIVEL 2 FIN ----------------



//############## Instrucciones #########

int CMouse::logicaMouseInstruccion(int escenario) {
    if (mouseX >= 461 && mouseX <= 550 && mouseY >= 500 && mouseY <= 530) {
        if (event.mouse.button) {
            return 0;
        }
    }
    else if (mouseX >= 290 && mouseX <= 384 && mouseY >= 500 && mouseY <= 530) {
        if (event.mouse.button) {
            return 5;
        }
    }
    return 8;
}

#endif