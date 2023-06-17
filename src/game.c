#include "game.h"
#include "event.h"
#include "interface.h"
#include "menu.h"
#include "player.h"

#define SYSTEM_MESSAGE "[系統訊息]"
#define PLAYER_MESSAGE "[玩家訊息]"

void initializePlayer(Player *player)
{
    player->position = 0;
    player->money = 1000;
}

int rollDice()
{
    return rand() % 6 + 1;
}

Player player;

int game_run()
// 遊戲執行中
{
    printf("Game Running...\n");
    initializePlayer(&player);
    while (player.position < MAP_SIZE)
    {
        al_clear_to_color(al_map_rgb(0, 0, 0)); // 清除畫布
        al_wait_for_event(event_queue, &event);
        button_process(event);
        // use the idea of finite state machine to deal with different state
        if (key_state[ALLEGRO_KEY_ENTER])
        {
            // 地板
            ALLEGRO_BITMAP *floor = al_load_bitmap("./assets/image/road.png");
            al_draw_bitmap(floor, 0, SCREEN_HEIGHT - 66, 0);
            if (!floor)
            {
                fprintf(stderr, "Could not load 'road.png'.\n");
            }

            char status_buffer[256];
            sprintf(status_buffer, "Position:%d Money:%d", player.position, player.money);
            al_draw_text(font, al_map_rgb(255, 255, 255), 0, 0, ALLEGRO_ALIGN_LEFT, status_buffer);

            char dice_buffer[256];
            int dice = rollDice();
            sprintf(dice_buffer, "Dice: %d", dice);
            al_draw_text(font, al_map_rgb(255, 255, 255), SCREEN_WIDTH, 0, ALLEGRO_ALIGN_RIGHT, dice_buffer);
            player.position += dice;

            if (player.position >= MAP_SIZE)
            {
                al_clear_to_color(al_map_rgb(0, 0, 0));
                al_draw_text(font, al_map_rgb(255, 255, 255), 400, 300, ALLEGRO_ALIGN_CENTRE,
                             "恭喜，你已經達到終點，遊戲結束!");
                al_flip_display();
                getchar();
                break;
            }

            char event_buffer[256];
            Game_event game_event = getEvent();
            sprintf(event_buffer, "Event: %s", game_event.description);
            al_draw_text(font, al_map_rgb(255, 255, 255), 640, 360, ALLEGRO_ALIGN_CENTRE, event_buffer);
            player.money += game_event.moneyChange;

            if (player.money <= 0)
            {
                al_clear_to_color(al_map_rgb(0, 0, 0));
                al_draw_text(font, al_map_rgb(255, 255, 255), 400, 300, ALLEGRO_ALIGN_CENTRE,
                             "你的錢已經用完，遊戲結束!");
                al_flip_display();
                getchar();
                break;
            }

            al_flip_display();
        }
        else if (key_state[ALLEGRO_KEY_A])
        {
        }
        else if (key_state[ALLEGRO_KEY_S])
        {
        }
        else if (key_state[ALLEGRO_KEY_D])
        {
        }
        else if (key_state[ALLEGRO_KEY_SPACE])
        {
        }
        else if (key_state[ALLEGRO_KEY_ESCAPE])
        {
            printf("Game Pause\n");
            menu_init();
            // 按下 ESC 時暫停遊戲
        }
    }
    return -1;
}