#include "menu.h"

#define MENU_ITEM_COUNT 3
#define FONT_SIZE 32

enum MenuItem
{
    ITEM_DIFFICULTY,
    ITEM_MAIN_MENU,
    ITEM_EXIT
};

const char *menu_items[MENU_ITEM_COUNT] = {"難度", "主選單", "退出遊戲"};

int menu_init()
{
    ALLEGRO_EVENT event;

    bool done = false, redraw = true;
    int selected_item = 0;

    while (!done)
    {
        al_wait_for_event(event_queue, &event);

        switch (event.type)
        {
        case ALLEGRO_EVENT_KEY_CHAR:
            switch (event.keyboard.keycode)
            {
            case ALLEGRO_KEY_ESCAPE:
                done = true;
                break;
            case ALLEGRO_KEY_UP:
                if (selected_item > 0)
                    selected_item--;
                redraw = true;
                break;
            case ALLEGRO_KEY_DOWN:
                if (selected_item < MENU_ITEM_COUNT - 1)
                    selected_item++;
                redraw = true;
                break;
            case ALLEGRO_KEY_ENTER:
                printf("你選擇了選單項目: %s\n", menu_items[selected_item]);
                switch (selected_item)
                {
                case ITEM_DIFFICULTY:
                    printf("改變難度\n");
                    // 在這裡調整遊戲的難度
                    break;
                case ITEM_MAIN_MENU:
                    printf("返回主選單\n");
                    // 在這裡返回遊戲的主選單
                    break;
                case ITEM_EXIT:
                    printf("退出遊戲\n");
                    done = true;
                    break;
                }
                break;
            }
            break;
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            done = true;
            break;
        }

        if (redraw && al_is_event_queue_empty(event_queue))
        {
            int y;
            al_clear_to_color(al_map_rgb(0, 0, 0));
            for (y = 0; y < MENU_ITEM_COUNT; y++)
            {
                if (y == selected_item)
                {
                    al_draw_text(font, al_map_rgb(255, 0, 0), SCREEN_WIDTH / 2,
                                 (SCREEN_HEIGHT / 2 - MENU_ITEM_COUNT / 2 * FONT_SIZE) + y * FONT_SIZE,
                                 ALLEGRO_ALIGN_CENTRE, menu_items[y]);
                }
                else
                {
                    al_draw_text(font, al_map_rgb(255, 255, 255), SCREEN_WIDTH / 2,
                                 (SCREEN_HEIGHT / 2 - MENU_ITEM_COUNT / 2 * FONT_SIZE) + y * FONT_SIZE,
                                 ALLEGRO_ALIGN_CENTRE, menu_items[y]);
                }
            }
            al_flip_display();
            redraw = false;
        }
    }

    al_destroy_event_queue(event_queue);

    return 0;
}
