#include "game.h"
#include "event.h"
#include "menu.h"
#include "resource.h"

int rollDice()
{
    return rand() % 6 + 1;
}

typedef struct Player
{
    int role;             // 0: Panda, 1: Kiwi, 2: Otter
    int credit;           // 1 ~ 28
    int position;         // 0 ~ 39
    int money;            // Infinite
    char last_event[256]; // Last event description
} Player;

Player player;
Game_event game_event;

int dice;

enum
{
    ROLE_PANDA,
    ROLE_KIWI,
    ROLE_OTTER,
};

int game_process(ALLEGRO_EVENT event)
// 遊戲執行中
{
    printf("Game Running...\n");
    if (!player.role)
    {
        printf("Choose role\n");
        select_role_process(event);
        // 選擇角色
        return MSG_NOPE;
    }
    if (!player.credit)
    {
        printf("Choose credit\n");
        select_credit_process(event);
        // 選擇學分
        return MSG_NOPE;
    }
    if (player.position < MAP_SIZE)
    {
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

void game_draw()
{
    al_clear_to_color(al_map_rgb(0, 0, 0)); // 清除畫布
    if (!player.role)
    {
        printf("Draw role selection\n");
        select_role_draw();
        // 繪製角色選擇介面
        return;
    }
    if (!player.credit)
    {
        printf("Draw credit selection\n");
        select_credit_draw();
        // 繪製學分選擇介面
        return;
    }
    printf("Draw game\n");
    draw_game();
    // 繪製遊戲介面
}

void game_init()
{
    printf("Game Init...\n");
    // 初始化遊戲
    // 初始化地圖
    // 初始化玩家
    player.role = NULL;
    player.credit = NULL;
    player.position = 0;
    player.money = 1000;
    // 初始化事件
    // 初始化資源
    // 初始化遊戲介面
}

void game_destroy()
{
}

void draw_game()
{
    // 繪製遊戲介面
    char status_buffer[256];
    sprintf(status_buffer, "Position:%d Money:%d", player.position, player.money);
    al_draw_text(write_font, al_map_rgb(255, 255, 255), 0, 0, ALLEGRO_ALIGN_LEFT, status_buffer);

    char dice_buffer[256];
    sprintf(dice_buffer, "Dice: %d", dice);
    al_draw_text(write_font, al_map_rgb(255, 255, 255), SCREEN_WIDTH, 0, ALLEGRO_ALIGN_RIGHT, dice_buffer);

    char event_buffer[256];
    sprintf(event_buffer, "Event: %s", game_event.description);
    al_draw_text(write_font, al_map_rgb(255, 255, 255), 640, 360, ALLEGRO_ALIGN_CENTRE, event_buffer);
    // 繪製地圖
    // 繪製玩家
    // 繪製事件
    // 繪製資源
}

int role_button_index = 0;

int select_role_process(ALLEGRO_EVENT event)
{
    if (event.type == ALLEGRO_EVENT_KEY_DOWN)
    {
        if (event.keyboard.keycode == ALLEGRO_KEY_DOWN)
        {
            if (role_button_index <= 2)
            {
                role_button_index++;
            }
        }
        if (event.keyboard.keycode == ALLEGRO_KEY_UP)
        {
            if (role_button_index > 0)
            {
                role_button_index--;
            }
        }
        if (event.keyboard.keycode == ALLEGRO_KEY_ENTER && role_button_index == 0)
        {
            player.role = ROLE_PANDA;
            return MSG_NOPE;
        }
        else if (event.keyboard.keycode == ALLEGRO_KEY_ENTER && role_button_index == 1)
        {
            player.role = ROLE_KIWI;
            return MSG_NOPE;
        }
        else if (event.keyboard.keycode == ALLEGRO_KEY_ENTER && role_button_index == 2)
        {
            player.role = ROLE_OTTER;
            return MSG_NOPE;
        }
        else if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
        {
            printf("Game Resume\n");
        }
    }
}

int select_credit_process(ALLEGRO_EVENT event)
{
    if (event.type == ALLEGRO_EVENT_KEY_DOWN)
    {
        printf("Game Credit\n");
        player.credit = 26;
    }
}

void select_role_draw()
{
    printf("role_button_index = %d\n", role_button_index);
    if (role_button_index == 0)
    {
        al_draw_bitmap(role_menu_all, 0, 0, 0);
    }
    else if (role_button_index == 1)
    {
        al_draw_bitmap(role_menu_panda, 0, 0, 0);
    }
    else if (role_button_index == 2)
    {
        al_draw_bitmap(role_menu_kiwi, 0, 0, 0);
    }
    else if (role_button_index == 3)
    {
        al_draw_bitmap(role_menu_otter, 0, 0, 0);
    }
}

void select_credit_draw()
{
    // 繪製學分選擇介面
    al_draw_bitmap(credit_menu_all, 0, 0, 0);
}