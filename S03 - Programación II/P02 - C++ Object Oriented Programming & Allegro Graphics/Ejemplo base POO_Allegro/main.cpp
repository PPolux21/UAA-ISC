//
//  main.cpp
//  testAllegro
//
//  Created by Jose de Jesus Palos on 26/10/22.
//  Copyright © 2022 Jose de Jesus Palos. All rights reserved.
//

#include <stdlib.h>
/*#include <allegro5/allegro.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>*/
#include "main.hpp"
#include "CJuego.hpp"


int main(int argc,char **args) {
    
    CJuego juego = CJuego();
    juego.run();
    
    return 0;
}


