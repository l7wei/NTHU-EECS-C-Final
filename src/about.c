#include "about.h"

int about_process(ALLEGRO_EVENT event)
{
}

void about_draw()
{
    printf("menu_about_index = %d\n", menu_about_index);
    if (menu_about_index == 0)
    {
        if (!sm_story&about_about)
        {
            printf("Failed to load sm_story&about_about bitmap!\n");
        }
        al_draw_bitmap(start_menu_start, 0, 0, 0);
    }
    else if (sm_story&about_about == 1)
    {
        al_draw_bitmap(sm_about_1, 0, 0, 0);
    }
    else if (menu_about_index == 2)
    {
        al_draw_bitmap(sm_about_2, 0, 0, 0);
    }
    else if (menu_about_index == 3)
    {
        al_draw_bitmap(sm_about_3, 0, 0, 0);
    }
}

void about_init()
{
}

void about_destroy()
{
}
