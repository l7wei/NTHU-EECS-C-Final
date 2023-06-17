#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

// Game Settings
#define MAP_SIZE 100
#define MAX_EVENT 5

#include <allegro5/allegro.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// note that you can't assign initial value here!
extern const float FPS;
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern bool judge_next_window;

extern ALLEGRO_EVENT *event;
extern ALLEGRO_EVENT_QUEUE *event_queue;

extern ALLEGRO_DISPLAY *display;
extern ALLEGRO_TIMER *fps;

#endif
