#ifndef EVENT_H
#define EVENT_H

#include "global.h"

// Event struct
typedef struct Game_event
{
    const char *description;
    int moneyChange;
} Game_event;

Game_event getEvent();

// Event array
extern Game_event events[MAX_EVENT];

#endif