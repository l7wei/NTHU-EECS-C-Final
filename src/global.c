#include "global.h"

// variables for global usage
const float FPS = 60.0;
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

ALLEGRO_TIMER *timer = NULL;
bool key_state[ALLEGRO_KEY_MAX] = {false};
bool judge_next_window = false;

ALLEGRO_EVENT *event;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;

ALLEGRO_DISPLAY *display = NULL;

// ALLEGRO Variables
ALLEGRO_SAMPLE *song = NULL;
ALLEGRO_SAMPLE_INSTANCE *sample_instance;