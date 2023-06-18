#include "game.h"
#include "event.h"
#include "menu.h"
#include "resource.h"

int rollDice()
{
    return rand() % 6 + 1; // 生成 1~6 的隨機整數
}

int rollCredit()
{
    return rand() % 28 + 1; // 生成 1~28 的隨機整數
}

typedef struct Player
{
    int role;             // 0: Panda, 1: Kiwi, 2: Otter
    int loading;          // 1 ~ 28 (x 18)
    long long money;      // use unsigned long long to prevent overflow (2^64) , llu
    char last_event[256]; // Last event description
} Player;

Player player;
Game_event game_event;

int dice;
int printed_loading_selected = NULL;

enum
{
    ROLE_NULL,
    ROLE_PANDA,
    ROLE_KIWI,
    ROLE_OTTER,
};

enum
{
    GAME_NULL,
    GAME_ROLE_SELECT_MENU,
    GAME_CREDIT_SELECT_MENU,
    GAME_PLAYING,
};

int GAME_STATUS = GAME_ROLE_SELECT_MENU;

int game_process(ALLEGRO_EVENT event)
// 遊戲執行中
{
    printf("Game Running...\n");
    if (GAME_STATUS == GAME_ROLE_SELECT_MENU)
    {
        printf("Choose role\n");
        select_role_process(event);
        // 選擇角色
    }
    else if (GAME_STATUS == GAME_CREDIT_SELECT_MENU)
    {
        printf("Choose credit\n");
        select_credit_process(event);
        // 選擇學分
    }
    else if (GAME_STATUS == GAME_PLAYING)
    {
        if (event.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            if (event.keyboard.keycode == ALLEGRO_KEY_ENTER)
            {
                dice = rollDice();
                player.loading -= dice;

                if (player.loading < 0)
                {
                    return MSG_GAME_OVER;
                }

                game_event = getEvent();

                player.money += game_event.moneyChange;

                if (player.money < -1000000)
                {
                    return MSG_GAME_OVER;
                }
            }
            else if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
            {
                printf("Game Pause\n");
                // 按下 ESC 時暫停遊戲
                return MSG_GAME_PAUSE;
            }
        }
    }
    return MSG_NOPE;
}

void game_draw()
{
    al_clear_to_color(al_map_rgb(0, 0, 0)); // 清除畫布
    if (GAME_STATUS == GAME_ROLE_SELECT_MENU)
    {
        printf("Draw role selection\n");
        select_role_draw();
        // 繪製角色選擇介面
        return;
    }
    if (GAME_STATUS == GAME_CREDIT_SELECT_MENU)
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
    player.loading = NULL;
    player.money = 0;
    // 初始化事件
    // 初始化資源
    // 初始化遊戲介面
}

void game_destroy()
{
}

void draw_game()
{
    // 繪製背景
    al_draw_bitmap(game_background, 0, 0, 0);
    // 繪製遊戲介面
    char money_buffer[256];
    sprintf(money_buffer, "Money:%lld", player.money);
    al_draw_text(write_font, al_map_rgb(255, 255, 255), 0, 0, ALLEGRO_ALIGN_LEFT, money_buffer);

    char loading_buffer[256];
    sprintf(loading_buffer, "Loading:%d", player.loading);
    al_draw_text(write_font, al_map_rgb(255, 255, 255), SCREEN_WIDTH / 2, 0, ALLEGRO_ALIGN_LEFT, loading_buffer);

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

int role_select = 0;

int select_role_process(ALLEGRO_EVENT event)
{
    int ROLE_MAX = 3;
    int ROLE_MIN = 1;
    if (event.type == ALLEGRO_EVENT_KEY_DOWN)
    {
        if (event.keyboard.keycode == ALLEGRO_KEY_DOWN)
        {
            role_select++;
            if (role_select > ROLE_MAX)
            {
                role_select = ROLE_MIN;
            }
        }
        else if (event.keyboard.keycode == ALLEGRO_KEY_UP)
        {
            role_select--;
            if (role_select < ROLE_MIN)
            {
                role_select = ROLE_MAX;
            }
        }
        if (event.keyboard.keycode == ALLEGRO_KEY_ENTER)
        {
            if (role_select == ROLE_NULL)
            {
                return MSG_NOPE;
            }
            else if (role_select == ROLE_PANDA)
            {
                player.role = ROLE_PANDA;
                player.money = -501022;
            }
            else if (role_select == ROLE_KIWI)
            {
                player.role = ROLE_KIWI;
                player.money = 72400;
            }
            else if (role_select == ROLE_OTTER)
            {
                player.role = ROLE_OTTER;
                player.money = 100001128;
            }
            GAME_STATUS = GAME_CREDIT_SELECT_MENU;
            return MSG_NOPE;
        }
        else if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
        {
            printf("Back\n");
        }
    }
}

int select_credit_process(ALLEGRO_EVENT event)
{
    if (event.type == ALLEGRO_EVENT_KEY_DOWN)
    {
        if (!player.loading)
        {
            if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
            {
                printf("Back\n");
                player.loading = NULL;
                player.role = NULL;
            }
            else if (event.keyboard.keycode == ALLEGRO_KEY_ENTER)
            {
                printf("Game Credit\n");
                player.loading = rollCredit() * 18;
                printf("Loading: %d\n", player.loading);
            }
        }    // 未選擇學分
        else // 已選擇學分
        {
            if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
            {
                printf("Back\n");
                player.loading = NULL;
            }
            else if (event.keyboard.keycode == ALLEGRO_KEY_ENTER)
            {
                printf("Game Start\n");
                GAME_STATUS = GAME_PLAYING;
            }
        }
    }
}

void select_role_draw()
{
    printf("role_select = %d\n", role_select);
    if (role_select == 0)
    {
        al_draw_bitmap(role_menu_all, 0, 0, 0);
    }
    else if (role_select == ROLE_PANDA)
    {
        al_draw_bitmap(role_menu_panda, 0, 0, 0);
    }
    else if (role_select == ROLE_KIWI)
    {
        al_draw_bitmap(role_menu_kiwi, 0, 0, 0);
    }
    else if (role_select == ROLE_OTTER)
    {
        al_draw_bitmap(role_menu_otter, 0, 0, 0);
    }
}

void select_credit_draw()
{
    // 繪製學分選擇介面
    if (!player.loading)
    {
        al_draw_bitmap(credit_menu_all, 0, 0, 0);
    }
    else
    {
        int credit = player.loading / 18;
        char filename[100];
        sprintf(filename, "./assets/image/credits/numbers/%d.jpg", credit);
        printf("Print %d loading selection, %s\n", credit, filename);
        ALLEGRO_BITMAP *loading_selected = al_load_bitmap(filename);
        al_draw_bitmap(loading_selected, 0, 0, 0);
    }
}