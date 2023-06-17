#include "global.h"

// variables for global usage
const float FPS = 60.0;
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_TIMER *fps = NULL;
bool key_state[ALLEGRO_KEY_MAX] = {false};
bool judge_next_window = false;

ALLEGRO_FONT *font = NULL;
