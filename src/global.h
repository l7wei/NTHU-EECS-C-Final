#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>

#include "../lib/algif5/src/algif.h"

// note that you can't assign initial value here!
extern const float FPS;
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern bool judge_next_window;

enum
{
    MSG_TERMINATE,
    MSG_NOPE,
    MSG_GAME_START,
    MSG_GAME_OVER,
    MSG_GAME_RESTART,
    MSG_BACK_TO_MENU,
    MSG_CHANGE_SETTING,
    MSG_ABOUT_START,
    MSG_STORY_START,
    MSG_GAME_PAUSE
};

enum
{
    SCENE_MENU,
    SCENE_SELECT_ROLE,
    SCENE_GAME,
    SCENE_RESULT,
    SCENE_SETTING,
    SCENE_STORY,
    SCENE_ABOUT,
    SCENE_PAUSE
};

extern ALLEGRO_EVENT *event;
extern ALLEGRO_EVENT_QUEUE *event_queue;

extern ALLEGRO_DISPLAY *display;
extern ALLEGRO_TIMER *timer;

extern ALLEGRO_SAMPLE *song;
extern ALLEGRO_SAMPLE_INSTANCE *sample_instance;
