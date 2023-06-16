#ifndef EVENT_H
#define EVENT_H

#include "global.h"

// Event struct
typedef struct Event
{
    const char *description;
    int moneyChange;
} Event;

Event getEvent();

// Event array
extern Event events[MAX_EVENT];

#endif