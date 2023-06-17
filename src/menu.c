#include "menu.h"
#include "resource.h"
int button_index = 0;

void menu_init()
{
}

void menu_destroy()
{
}

int menu_process(ALLEGRO_EVENT event)
{
    menu_draw();
    if (event.type == ALLEGRO_EVENT_KEY_DOWN)
    {
        if (event.keyboard.keycode == ALLEGRO_KEY_DOWN)
        {
            if (button_index <= 2)
            {
                button_index++;
            }
        }
        if (event.keyboard.keycode == ALLEGRO_KEY_UP)
        {
            if (button_index > 0)
            {
                button_index--;
            }
        }
        if (event.keyboard.keycode == ALLEGRO_KEY_ENTER && button_index == 0)
        {
            // al_play_sample_instance(click_se_spi);
            return 10;
        }
        else if (event.keyboard.keycode == ALLEGRO_KEY_ENTER && button_index == 1)
        {
            // al_play_sample_instance(click_se_spi);
            return 11;
        }
        else if (event.keyboard.keycode == ALLEGRO_KEY_ENTER && button_index == 2)
        {
            // al_play_sample_instance(click_se_spi);
            return 12;
        }
        else if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
        {
            printf("Game Resume\n");
        }
    }
}

void menu_draw()
{
    printf("button_index = %d\n", button_index);
    if (button_index == 0)
    {
        if (!start_menu_start)
        {
            printf("Failed to load start_menu_all bitmap!\n");
        }
        al_draw_bitmap(start_menu_start, 0, 0, 0);
    }
    else if (button_index == 1)
    {
        al_draw_bitmap(start_menu_story, 0, 0, 0);
    }
    else if (button_index == 2)
    {
        al_draw_bitmap(start_menu_about, 0, 0, 0);
    }
    else if (button_index == 3)
    {
        al_draw_bitmap(start_menu_exit, 0, 0, 0);
    }
    al_flip_display();
}