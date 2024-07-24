#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <fstream>

using namespace std;

#include "personajes.hpp"

CJugador user2(25,25,200,200,3);

void selectorNombre();

int main()
{
    CJugador user(25,25,200,200,1);
    CJugador user1(25,25,200,200,2);
    
    CJugador wenas(0,0,0,0,0);
    int elementos=0;
    char archivo[]={"user.txt"};

    //fstream archUser(archivo, ios::binary | ios::in | ios::out);
    fstream archUser(archivo, ios::in | ios::out );
    if(!archUser.good())
    {
        archUser.close();
        cout<< "Error al cargar archivo"<<endl;
        fstream archUser(archivo, ios::in | ios::out | fstream::trunc);
    }
    
    selectorNombre();
    for (int i = 0; i < 5; i++)
    {
        archUser.write(reinterpret_cast<char*>(&user),sizeof(CJugador));
        archUser.write(reinterpret_cast<char*>(&user1),sizeof(CJugador));
        archUser.write(reinterpret_cast<char*>(&user2),sizeof(CJugador));
    }

    archUser.seekp(0);

    do
    {
        archUser.read(reinterpret_cast<char*>(&wenas),sizeof(CJugador));
        elementos++;
        cout << wenas << endl;
    }while (!archUser.eof());
    elementos--;
    cout<<elementos<<endl;
    if(elementos%12 ==0)
    {
        cout<< elementos/12<<endl;
    }else{
        cout<< elementos/12 +1<<endl;
    }

    archUser.close();
    return 0;
}

void selectorNombre()
{
    user2.vidas=2;
    user2.puntuacion= 53289;
}