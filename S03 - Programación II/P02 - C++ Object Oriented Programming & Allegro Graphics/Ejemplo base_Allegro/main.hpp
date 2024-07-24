//
//  main.hpp
//  testAllegro
//
//  Created by Jose de Jesus Palos on 26/10/22.
//  Copyright © 2022 Jose de Jesus Palos. All rights reserved.
//

#ifndef main_hpp
#define main_hpp


ALLEGRO_TIMER* timer=NULL;
ALLEGRO_EVENT_QUEUE* queue=NULL;
ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_FONT* font = NULL;

ALLEGRO_EVENT event;

ALLEGRO_BITMAP* uaa;


int init();
void deinit();
void pintar(int i);

#endif /* main_hpp */
