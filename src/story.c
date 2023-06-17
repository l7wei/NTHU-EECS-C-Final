#include "story.h"
#include "event.h"
#include "menu.h"
#include "resource.h"

int story_button_index = 0;

void story_draw()
{
    printf("story_button_index = %d\n", story_button_index);
    if (story_button_index == 0)
    {
        al_draw_bitmap(sm_story_1, 0, 0, 0);
    }
    else if (story_button_index == 1)
    {
        al_draw_bitmap(sm_story_2, 0, 0, 0);
    }
    else if (story_button_index == 2)
    {
        al_draw_bitmap(sm_story_3, 0, 0, 0);
    }
}

int story_process(ALLEGRO_EVENT event)
{
    if (event.type == ALLEGRO_EVENT_KEY_DOWN)
    {
        if (event.keyboard.keycode == ALLEGRO_KEY_DOWN)
        {
            story_button_index++;
            if (story_button_index >= 3)
            {
                return MSG_GAME_OVER;
            }
        }
        else if (event.keyboard.keycode == ALLEGRO_KEY_UP)
        {
            story_button_index--;
            if (story_button_index < 0)
            {
                story_button_index = 0;
            }
        }
    }
    return 0;
}

void story_init()
{
    story_button_index = 0;
}

void story_destroy()
{
}
