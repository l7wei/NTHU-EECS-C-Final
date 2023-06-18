#include "about.h"
#include "event.h"
#include "menu.h"
#include "resource.h"
#include "story.h"

int about_button_index = 0;

void about_draw()
{
    printf("about_button_index = %d\n", about_button_index);
    if (about_button_index == 0)
    {
        al_draw_bitmap(about_1, 0, 0, 0);
    }
    else if (about_button_index == 1)
    {
        al_draw_bitmap(about_2, 0, 0, 0);
    }
    else if (about_button_index == 2)
    {
        al_draw_bitmap(about_3, 0, 0, 0);
    }    
    else if (about_button_index == 3)
    {
        al_draw_bitmap(teams, 0, 0, 0);
    }
}

int about_process(ALLEGRO_EVENT event)
{
    int MAX_PAGE = 3;
    // 0, 1, 2
    if (event.type == ALLEGRO_EVENT_KEY_DOWN)
    {
        if (event.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
            {
                return MSG_GAME_OVER;
            }
            else if (event.keyboard.keycode == ALLEGRO_KEY_ENTER)
            {
                about_button_index++;
                if (about_button_index > MAX_PAGE)
                {
                    return MSG_GAME_OVER;
                }
            }
            else if (event.keyboard.keycode == ALLEGRO_KEY_DOWN)
            {
                about_button_index++;
                if (about_button_index > MAX_PAGE)
                {
                    return MSG_GAME_OVER;
                }
            }
            else if (event.keyboard.keycode == ALLEGRO_KEY_UP)
            {
                about_button_index--;
                if (about_button_index < 0)
                {
                    about_button_index = 0;
                }
            }
        }
        return 0;
    }
}

void about_init()
{
    about_button_index = 0;
}

void about_destroy()
{
}
