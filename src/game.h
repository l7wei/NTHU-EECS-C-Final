#pragma once
#include "global.h"

void game_init();
void game_destroy();
int game_process(ALLEGRO_EVENT);
void game_draw();

extern int number;