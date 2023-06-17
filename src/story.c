#include "story.h"
#include "event.h"
#include "menu.h"
#include "resource.h"

int rollDice2()
{
    return rand() % 6 + 1;
}

typedef struct Player2
{
    int position;
    int money;
    char last_event[256];
} Player2;

Player2 player2;
Game_event story_event;

int dice2;

int story_process(ALLEGRO_EVENT event)
// 遊戲執行中
{
    printf("Story Running...\n");
    if (player2.position < MAP_SIZE)
    {
        al_clear_to_color(al_map_rgb(0, 0, 0)); // 清除畫布

        if (event.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            if (event.keyboard.keycode == ALLEGRO_KEY_ENTER)
            {
                dice2 = rollDice2();
                player2.position += dice2;

                if (player2.position >= MAP_SIZE)
                {
                    return MSG_GAME_OVER;
                }

                story_event = getEvent();

                player2.money += story_event.moneyChange;

                if (player2.money <= 0)
                {
                    return MSG_GAME_OVER;
                }
            }
            else if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
            {
                printf("Story Pause\n");
                // 按下 ESC 時暫停遊戲
            }
        }
    }
    return MSG_NOPE;
}

void story_draw()
{
    char status_buffer[256];
    sprintf(status_buffer, "Position:%d Money:%d", player2.position, player2.money);
    al_draw_text(write_font, al_map_rgb(255, 255, 255), 0, 0, ALLEGRO_ALIGN_LEFT, status_buffer);

    char dice_buffer[256];
    sprintf(dice_buffer, "Dice: %d", dice2);
    al_draw_text(write_font, al_map_rgb(255, 255, 255), SCREEN_WIDTH, 0, ALLEGRO_ALIGN_RIGHT, dice_buffer);

    char event_buffer[256];
    sprintf(event_buffer, "Event: %s", story_event.description);
    al_draw_text(write_font, al_map_rgb(255, 255, 255), 640, 360, ALLEGRO_ALIGN_CENTRE, event_buffer);
}

void story_init()
{
    printf("Story Init...\n");
    // 初始化遊戲
    // 初始化地圖
    // 初始化玩家
    player2.position = 0;
    player2.money = 1000;
    // 初始化事件
    // 初始化資源
    // 初始化遊戲介面
}

void story_destroy()
{
}