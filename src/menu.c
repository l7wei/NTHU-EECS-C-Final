#include "menu.h"
#include "resource.h"
int menu_button_index = 0;

int menu_process(ALLEGRO_EVENT event)
{
    if (event.type == ALLEGRO_EVENT_KEY_DOWN)
    {
        if (event.keyboard.keycode == ALLEGRO_KEY_DOWN)
        {
            menu_button_index++;
            if (menu_button_index > 3)
            {
                menu_button_index = 0;
            }
        }
        if (event.keyboard.keycode == ALLEGRO_KEY_UP)
        {
            menu_button_index--;
            if (menu_button_index < 0)
            {
                menu_button_index = 3;
            }
        }
        if (event.keyboard.keycode == ALLEGRO_KEY_ENTER && menu_button_index == 0)
        {
            // al_play_sample_instance(click_se_spi);
            return MSG_GAME_START;
        }
        else if (event.keyboard.keycode == ALLEGRO_KEY_ENTER && menu_button_index == 1)
        {
            // al_play_sample_instance(click_se_spi);
            return MSG_STORY_START;
        }
        else if (event.keyboard.keycode == ALLEGRO_KEY_ENTER && menu_button_index == 2)
        {
            // al_play_sample_instance(click_se_spi);
            return MSG_ABOUT_START;
        }
        else if (event.keyboard.keycode == ALLEGRO_KEY_ENTER && menu_button_index == 3)
        {
            // al_play_sample_instance(click_se_spi);
            return MSG_TERMINATE;
        }
        else if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
        {
            printf("Game Resume\n");
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

int pause_menu_button_index = 0;

int pause_menu_process(ALLEGRO_EVENT event)
{
    if (event.type == ALLEGRO_EVENT_KEY_DOWN)
    {
        if (event.keyboard.keycode == ALLEGRO_KEY_DOWN)
        {
            pause_menu_button_index++;
            if (pause_menu_button_index > 2)
            {
                pause_menu_button_index = 0;
            }
        }
        if (event.keyboard.keycode == ALLEGRO_KEY_UP)
        {

            pause_menu_button_index--;
            if (pause_menu_button_index < 0)
            {
                pause_menu_button_index = 2;
            }
        }
        if (event.keyboard.keycode == ALLEGRO_KEY_ENTER && pause_menu_button_index == 0)
        {
            // al_play_sample_instance(click_se_spi);
            return MSG_GAME_START;
        }
        else if (event.keyboard.keycode == ALLEGRO_KEY_ENTER && pause_menu_button_index == 1)
        {
            // al_play_sample_instance(click_se_spi);
            return MSG_GAME_START;
        }
        else if (event.keyboard.keycode == ALLEGRO_KEY_ENTER && pause_menu_button_index == 2)
        {
            // al_play_sample_instance(click_se_spi);
            return MSG_TERMINATE;
        }
        else if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
        {
            printf("Game Continue\n");
            return MSG_GAME_START;
        }
    }
}

void pause_menu_draw()
{
    printf("pause_menu_button_index = %d\n", pause_menu_button_index);
    if (pause_menu_button_index == 0)
    {
        al_draw_bitmap(pause_menu_continue, 0, 0, 0);
    }
    else if (pause_menu_button_index == 1)
    {
        al_draw_bitmap(pause_menu_restart, 0, 0, 0);
    }
    else if (pause_menu_button_index == 2)
    {
        al_draw_bitmap(pause_menu_finish, 0, 0, 0);
    }
}

void pause_menu_init()
{
}

void pause_menu_destroy()
{
}