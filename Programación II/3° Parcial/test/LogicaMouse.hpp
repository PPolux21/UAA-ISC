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

	int logicaMenu(int);
	int logicaMouseMenu(int);

    int logica_MenuNuevaPartida();
    int logicaMouseNuevaPartida(int );

    int logicaMouseCargaPartida(int);
};




int CMouse::logicaMenu(int escenario) {
    // Nueva partida	1
	// Cargar Partida	2
	// Marcadores		3
	// Salir			4
    switch (escenario) {
    case 0:
        escenario = logicaMouseMenu(escenario);
        break;
    case 1:
        //escenario = logica_MenuNuevaPartida();
        escenario = logicaMouseNuevaPartida(escenario);
        break;
    case 2:
        escenario = logicaMouseCargaPartida(escenario);
        break;
    default:
        break;
    }
    return escenario;
}

int CMouse::logica_MenuNuevaPartida() {
    //Crear usuario     1
    //Salir             2
    switch (escenarioNuevaPartida) {
    case 1:
        //
        //escenarioNuevaPartida = logicaMouseNuevaPartida(escenarioNuevaPartida);
        break;
    case 2:
        //Este es para salir
        return 0;
        break;
    }
    return 1;
}

int CMouse::logicaMouseNuevaPartida(int escenarioNuevaPartida) {
    //Coordenadas para las cajas de texto
    //if(mouseX >=)

    //Regresar
    if (mouseX >= 585 && mouseX <= 755 && mouseY >= 555 && mouseY <= 586) {
        if (event.mouse.button) {
            return 0;
        }
        else {
            return escenarioNuevaPartida;
        }
    }   

    return escenarioNuevaPartida;
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

#endif