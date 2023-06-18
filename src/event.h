#pragma once

#include "global.h"

// Game Settings
#define MAX_EVENT 1

// Event struct
typedef struct Game_event
{
    const char *description;
    const char *moneyOperator;
    int moneyChange;
    const char *loadingOperator;
    int loadingChange;
    const char *image_path;
} Game_event;

Game_event getEvent();

// Event array
extern Game_event events[MAX_EVENT];