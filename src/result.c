#include "result.h"
#include "resource.h"

void result_init()
{
}

void result_destroy()
{
}

int result_process(ALLEGRO_EVENT event)
{
    if (event.type == ALLEGRO_EVENT_KEY_DOWN)
    {
        if (event.keyboard.keycode == ALLEGRO_KEY_ENTER)
        {
            return MSG_GAME_RESTART;
        }
        else if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
        {
            return MSG_BACK_TO_MENU;
        }
    }
}

void result_draw()
{
    al_stop_sample_instance(bgm_music_spi);
    al_play_sample_instance(menu_hello_spi);
    al_draw_bitmap(ending_1_1, 0, 0, 0);
}
