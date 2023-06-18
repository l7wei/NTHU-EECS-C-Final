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
        al_draw_bitmap(story_1, 0, 0, 0);
        al_play_sample_instance(effect_gooddecision_spi);
    }
    else if (story_button_index == 1)
    {
        al_draw_bitmap(story_2, 0, 0, 0);
        al_play_sample_instance(effect_gooddecision_spi);
    }
    else if (story_button_index == 2)
    {
        al_draw_bitmap(story_3, 0, 0, 0);
        al_play_sample_instance(effect_gooddecision_spi);
    }
}

int story_process(ALLEGRO_EVENT event)
{
    int MAX_PAGE = 2;
    // 0, 1, 2
    if (event.type == ALLEGRO_EVENT_KEY_DOWN)
    {
        if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
        {
            return MSG_GAME_OVER;
        }
        else if (event.keyboard.keycode == ALLEGRO_KEY_ENTER)
        {
            story_button_index++;
            if (story_button_index > MAX_PAGE)
            {
                return MSG_GAME_OVER;
            }
        }
        else if (event.keyboard.keycode == ALLEGRO_KEY_DOWN)
        {
            story_button_index++;
            if (story_button_index > MAX_PAGE)
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
