//
//  CJuego.hpp
//  testAllegro
//
//  Created by Jose de Jesus Palos on 08/11/22.
//  Copyright © 2022 Jose de Jesus Palos. All rights reserved.
//

#ifndef CJuego_hpp
#define CJuego_hpp

#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

class CJuego{

private:

    ALLEGRO_TIMER* timer;
    ALLEGRO_EVENT_QUEUE* queue;
    ALLEGRO_DISPLAY *display;
    ALLEGRO_FONT* font;
    ALLEGRO_EVENT event;
    bool done;
    bool redraw;
    ALLEGRO_BITMAP* uaa;
    
    int posX;
    int posY;
    
public:
    //constructor
    CJuego(void);

    //Metodos
    int init();
    void deinit();
    void pintar();
    void logicaTeclado();
    void run();
    
    //Destructor
    ~CJuego();
};
#endif /* CJuego_hpp */
