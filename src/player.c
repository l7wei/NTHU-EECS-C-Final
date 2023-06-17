#include "player.h"
void charater_process(ALLEGRO_EVENT event)
{
    // process the animation
    if (event.type == ALLEGRO_EVENT_TIMER)
    {
        if (event.timer.source == fps)
        {
        }
        // process the keyboard event
    }
    else if (event.type == ALLEGRO_EVENT_KEY_DOWN)
    {
        key_state[event.keyboard.keycode] = true;
    }
    else if (event.type == ALLEGRO_EVENT_KEY_UP)
    {
        key_state[event.keyboard.keycode] = false;
    }
}