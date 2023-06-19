#include "menu.h"
#include "resource.h"
int menu_button_index = 0;

int menu_process(ALLEGRO_EVENT event)
{
    int MAX_BUTTON = 3;
    if (event.type == ALLEGRO_EVENT_KEY_DOWN)
    {
        if (event.keyboard.keycode == ALLEGRO_KEY_DOWN)
        {
            al_play_sample_instance(menu_change_select_spi);
            menu_button_index++;
            if (menu_button_index > MAX_BUTTON)
            {
                menu_button_index = 0;
            }
        }
        if (event.keyboard.keycode == ALLEGRO_KEY_UP)
        {
            al_play_sample_instance(menu_change_select_spi);
            menu_button_index--;
            if (menu_button_index < 0)
            {
                menu_button_index = MAX_BUTTON;
            }
        }
        if (event.keyboard.keycode == ALLEGRO_KEY_ENTER && menu_button_index == 0)
        {
            al_play_sample_instance(menu_change_role_spi);
            return MSG_GAME_START;
        }
        else if (event.keyboard.keycode == ALLEGRO_KEY_ENTER && menu_button_index == 1)
        {
            al_play_sample_instance(menu_change_role_spi);
            return MSG_STORY_START;
        }
        else if (event.keyboard.keycode == ALLEGRO_KEY_ENTER && menu_button_index == 2)
        {
            al_play_sample_instance(menu_change_role_spi);
            return MSG_ABOUT_START;
        }
        else if (event.keyboard.keycode == ALLEGRO_KEY_ENTER && menu_button_index == 3)
        {
            al_play_sample_instance(menu_change_role_spi);
            return MSG_TERMINATE;
        }
    }
}

void menu_draw()
{
    printf("menu_button_index = %d\n", menu_button_index);
    if (menu_button_index == 0)
    {
        al_draw_bitmap(start_menu_start, 0, 0, 0);
    }
    else if (menu_button_index == 1)
    {
        al_draw_bitmap(start_menu_story, 0, 0, 0);
    }
    else if (menu_button_index == 2)
    {
        al_draw_bitmap(start_menu_about, 0, 0, 0);
    }
    else if (menu_button_index == 3)
    {
        al_draw_bitmap(start_menu_exit, 0, 0, 0);
    }
}

void menu_init()
{
    menu_button_index = 0;
}

void menu_destroy()
{
}
