#pragma once

#include "global.h"

// Game Settings
#define MAX_EVENT 5

// Event struct
typedef struct Game_event
{
    const char *description;
    int moneyChange;
} Game_event;

Game_event getEvent();

// Event array
extern Game_event events[MAX_EVENT];