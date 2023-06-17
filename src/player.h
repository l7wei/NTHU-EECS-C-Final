#ifndef PLAYER_H
#define PLAYER_H

#include "global.h"

// Player struct
typedef struct Player
{
    int position;
    int money;
} Player;

void charater_process();

#endif