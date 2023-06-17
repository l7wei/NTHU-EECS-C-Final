#include "game.h"
#include "event.h"
#include "menu.h"
#include "resource.h"

#define SYSTEM_MESSAGE "[系統訊息]"
#define PLAYER_MESSAGE "[玩家訊息]"

int rollDice()
{
    return rand() % 6 + 1;
}

typedef struct Player
{
    int position;
    int money;
    char last_event[256];
} Player;

Player player;
Game_event game_event;

int dice;

int game_process(ALLEGRO_EVENT event)
// 遊戲執行中
{
    printf("Game Running...\n");
    if (player.position < MAP_SIZE)
    {
        al_clear_to_color(al_map_rgb(0, 0, 0)); // 清除畫布

        if (event.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            if (event.keyboard.keycode == ALLEGRO_KEY_ENTER)
            {
                dice = rollDice();
                player.position += dice;

                if (player.position >= MAP_SIZE)
                {
                    return MSG_GAME_OVER;
                }

                game_event = getEvent();

                player.money += game_event.moneyChange;

                if (player.money <= 0)
                {
                    return MSG_GAME_OVER;
                }
            }
            else if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
            {
                printf("Game Pause\n");
                // 按下 ESC 時暫停遊戲
            }
        }
    }
    return MSG_NOPE;
}

void game_init()
{
    printf("Game Init...\n");
    // 初始化遊戲
    // 初始化地圖
    // 初始化玩家
    player.position = 0;
    player.money = 1000;
    // 初始化事件
    // 初始化資源
    // 初始化遊戲介面
}

void game_destroy()
{
}

void game_draw()
{
    char status_buffer[256];
    sprintf(status_buffer, "Position:%d Money:%d", player.position, player.money);
    al_draw_text(write_font, al_map_rgb(255, 255, 255), 0, 0, ALLEGRO_ALIGN_LEFT, status_buffer);

    char dice_buffer[256];
    sprintf(dice_buffer, "Dice: %d", dice);
    al_draw_text(write_font, al_map_rgb(255, 255, 255), SCREEN_WIDTH, 0, ALLEGRO_ALIGN_RIGHT, dice_buffer);

    char event_buffer[256];
    sprintf(event_buffer, "Event: %s", game_event.description);
    al_draw_text(write_font, al_map_rgb(255, 255, 255), 640, 360, ALLEGRO_ALIGN_CENTRE, event_buffer);
}