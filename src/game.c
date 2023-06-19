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
    int x;
    int y;                // x, y 為角色在地圖上的位置
    int role;             // 0: Panda, 1: Kiwi, 2: Otter
    int loading;          // 1 ~ 28 (x 18)
    long long money;      // use unsigned long long to prevent overflow (2^64) , llu
    char last_event[256]; // Last event description
} Player;

Player player;
Game_event game_event;

int dice = 1;

enum // 角色
{
    ROLE_NULL,
    ROLE_PANDA,
    ROLE_KIWI,
    ROLE_OTTER,
};

enum // 遊戲狀態
{
    MENU_GAME_NULL,
    MENU_GAME_ROLE_SELECT,
    MENU_GAME_CREDIT_SELECT,
    MENU_GAME_PLAYING,
    MENU_GAME_PAUSE,
    MENU_GAME_TERMINATE
};

enum // 遊戲訊息
{
    MSG_GAME_NULL,
    MSG_GAME_NEW_EVENT
};

int GAME_STATUS = MENU_GAME_ROLE_SELECT;
int GAME_MSG = MSG_GAME_NULL;

int game_process(ALLEGRO_EVENT event)
// 遊戲執行中
{
    printf("Game Running...\n");
    if (player.loading < 0)
    {
        GAME_STATUS = MENU_GAME_ROLE_SELECT;
        return MSG_GAME_OVER;
    }
    if (player.money < -1000000)
    {
        GAME_STATUS = MENU_GAME_ROLE_SELECT;
        return MSG_GAME_OVER;
    }
    if (GAME_STATUS == MENU_GAME_ROLE_SELECT)
    {
        printf("Choose role\n");
        role_select_process(event);
        // 選擇角色
    }
    else if (GAME_STATUS == MENU_GAME_CREDIT_SELECT)
    {
        printf("Choose credit\n");
        credit_select_process(event);
        // 選擇學分
    }
    else if (GAME_STATUS == MENU_GAME_PLAYING)
    {
        if (event.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            if (event.keyboard.keycode == ALLEGRO_KEY_ENTER)
            {
                if (GAME_MSG == MSG_GAME_NEW_EVENT)
                {
                    GAME_MSG = MSG_GAME_NULL;
                }
                else if (player.x >= 535 && player.x <= 555)
                {
                    event_process();
                }
            }
            else if (event.keyboard.keycode == ALLEGRO_KEY_LEFT)
            {
                player.x -= 50;
            }
            else if (event.keyboard.keycode == ALLEGRO_KEY_RIGHT)
            {
                player.x += 50;
            }
            else if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
            {
                printf("Game Pause\n");
                // 按下 ESC 時暫停遊戲
                GAME_STATUS = MENU_GAME_PAUSE;
            }
        }
        if (event.type == ALLEGRO_EVENT_KEY_CHAR)
        {
            switch (event.keyboard.unichar)
            {
            case 'a':
            case 'A':
                player.x -= 50;
                break;
            case 'd':
            case 'D':
                player.x += 50;
                break;
            }
        }
    }
    else if (GAME_STATUS == MENU_GAME_PAUSE)
    {
        printf("Game Pause\n");
        // 暫停遊戲
        if (event.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
            {
                printf("Game Resume\n");
                // 按下 ESC 時繼續遊戲
                GAME_STATUS = MENU_GAME_PLAYING;
            }
            else
            {
                pause_menu_process(event);
            }
        }
    }
    else if (GAME_STATUS == MENU_GAME_TERMINATE)
    {
        printf("Game Terminate\n");
        // 結束遊戲
        return MSG_GAME_OVER;
    }
    return MSG_NOPE;
}

void game_draw()
{
    // 清除畫布
    al_clear_to_color(al_map_rgb(0, 0, 0));
    if (GAME_STATUS == MENU_GAME_ROLE_SELECT)
    {
        // 繪製角色選擇介面
        printf("Draw role selection\n");
        role_select_draw();
    }
    else if (GAME_STATUS == MENU_GAME_CREDIT_SELECT)
    {
        // 繪製學分選擇介面
        printf("Draw credit selection\n");
        credit_select_draw();
    }
    else if (GAME_STATUS == MENU_GAME_PLAYING)
    {
        // 繪製遊戲介面
        printf("Draw game\n");
        draw_game();
    }
    else if (GAME_STATUS == MENU_GAME_PAUSE)
    {
        // 繪製暫停介面
        printf("Draw pause\n");
        pause_menu_draw();
    }
    else
    {
    }
}

ALLEGRO_BITMAP *new_event;
ALLEGRO_BITMAP *new_dice;

void game_init()
{
    printf("Game Init...\n");
    // 初始化遊戲
    // 初始化地圖
    // 初始化玩家
    player.role = NULL;
    player.loading = NULL;
    player.money = 0;
    player.x = 555; // 放大要調整
    player.y = 495; // 放大要調整
    // 初始化事件
    // 初始化資源
    // 初始化遊戲介面
    new_dice = al_load_bitmap("./assets/image/dice/1.png");
}

void game_destroy()
{
}

void draw_game()
{
    if (GAME_MSG == MSG_GAME_NEW_EVENT)
    {
        printf("Draw event\n");
        // 繪製事件
        al_draw_bitmap(new_event, 0, 0, 0);
    }
    else
    {
        draw_background(); // 繪製背景
        draw_interface();  // 繪製遊戲介面
        draw_role();       // 繪製玩家
    }
}

void event_process()
{
    // 進行下一個事件
    printf("Next event\n");
    game_event = getEvent();
    new_event = al_load_bitmap(game_event.image_path);
    GAME_MSG = MSG_GAME_NEW_EVENT;

    // 擲骰子減少 loading
    dice = rollDice();
    char filenametmp[100];
    sprintf(filenametmp, "./assets/image/dice/%d.png", dice);
    new_dice = al_load_bitmap(filenametmp);
    player.loading -= dice;

    // 錢要變化了
    if (strcmp(game_event.moneyOperator, "+") == 0)
    {
        player.money += game_event.moneyChange;
    }
    else if (strcmp(game_event.moneyOperator, "-") == 0)
    {
        player.money -= game_event.moneyChange;
    }
    else if (strcmp(game_event.moneyOperator, "*") == 0)
    {
        player.money *= game_event.moneyChange;
    }
    else if (strcmp(game_event.moneyOperator, "/") == 0)
    {
        player.money /= game_event.moneyChange;
    }

    // Loading 要變化了
    if (strcmp(game_event.loadingOperator, "+") == 0)
    {
        player.loading += game_event.loadingChange;
    }
    else if (strcmp(game_event.loadingOperator, "-") == 0)
    {
        player.loading -= game_event.loadingChange;
    }
    else if (strcmp(game_event.loadingOperator, "*") == 0)
    {
        player.loading *= game_event.loadingChange;
    }
    else if (strcmp(game_event.loadingOperator, "/") == 0)
    {
        player.loading /= game_event.loadingChange;
    }
}

int current_background_index = 0;

void draw_background()
{
    // 繪製背景
    if (player.x < 0)
    {
        current_background_index = (current_background_index == 0) ? 1 : 0;
    }
    else if (player.x > SCREEN_WIDTH)
    {
        current_background_index = (current_background_index == 0) ? 1 : 0;
    }
    // 繪製背景
    switch (current_background_index)
    {
    case 0:
        al_draw_bitmap(game_background_1, 0, 0, 0);
        break;
    case 1:
        al_draw_bitmap(game_background_2, 0, 0, 0);
        break;
    }
}

void draw_role()
{
    // 繪製玩家
    char role_path[256];
    if (player.x >= 535 && player.x <= 555)
    {
        static int direction = 1; // 跳躍方向，1 表示向下，-1 表示向上
        player.y += direction;    // 因為左上角 是 (0,0)，所以 y 越大越往下
        if (player.y >= 485)      // 到達底部
        {
            direction = -1; // 改為向上跳
        }
        else if (player.y <= 460) // 到達頂點
        {
            direction = 1; // 改為向下跳
        }
    }
    else
    {
        player.y = 485;
    }
    // 超出邊界回到另一邊
    if (player.x < 0)
    {
        player.x = SCREEN_WIDTH;
    }
    else if (player.x > SCREEN_WIDTH)
    {
        player.x = 0;
    }
    if (player.role == ROLE_PANDA)
    {
        al_draw_bitmap(role_panda, player.x, player.y, 0);
    }
    else if (player.role == ROLE_KIWI)
    {
        al_draw_bitmap(role_kiwi, player.x, player.y, 0);
    }
    else if (player.role == ROLE_OTTER)
    {
        al_draw_bitmap(role_otter, player.x, player.y, 0);
    }
}

void draw_interface()
{
    // 繪製遊戲介面
    char money_buffer[256];
    sprintf(money_buffer, "Money:%lld", player.money);
    al_draw_text(bit_font, al_map_rgb(255, 255, 255), 0, 0, ALLEGRO_ALIGN_LEFT, money_buffer);

    char loading_buffer[256];
    sprintf(loading_buffer, "Loading:%d", player.loading);
    al_draw_text(bit_font, al_map_rgb(255, 255, 255), SCREEN_WIDTH / 2, 0, ALLEGRO_ALIGN_LEFT, loading_buffer);

    // 繪製骰子
    al_draw_bitmap(algif_get_bitmap(credits_roll, al_get_time()), SCREEN_WIDTH - 200, 10, 0);
    // al_draw_bitmap(new_dice, SCREEN_WIDTH - 200, 10, 0);

    char event_buffer[256];
    sprintf(event_buffer, "Last Event: %s", game_event.description);
    al_draw_text(bit_font, al_map_rgb(255, 255, 255), SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, ALLEGRO_ALIGN_CENTRE,
                 event_buffer);
}

int role_select = 0;

int role_select_process(ALLEGRO_EVENT event)
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
            GAME_STATUS = MENU_GAME_CREDIT_SELECT;
            return MSG_NOPE;
        }
        else if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
        {
            printf("Back\n");
        }
    }
}

void role_select_draw()
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

int credit_select_process(ALLEGRO_EVENT event)
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

                al_play_sample_instance(effect_good_spi);
                printf("Game Start\n");
                GAME_STATUS = MENU_GAME_PLAYING;
            }
        }
    }
}

void credit_select_draw()
{
    // 繪製學分選擇介面
    if (!player.loading)
    {
        // Credit Menu
        al_draw_bitmap(credits_all, 0, 0, 0);
        // al_clear_to_color(al_map_rgb(255, 255, 255));
        // al_draw_bitmap(algif_get_bitmap(credits_roll, al_get_time()), 0, 0, 0);
    }
    else
    {
        int credit = player.loading / 18;
        char filename[100];
        sprintf(filename, "./assets/image/credits/numbers/%d.jpg", credit);
        ALLEGRO_BITMAP *loading_selected = al_load_bitmap(filename);
        al_draw_bitmap(loading_selected, 0, 0, 0);
    }
    return;
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
            GAME_STATUS = MENU_GAME_PLAYING;
        }
        else if (event.keyboard.keycode == ALLEGRO_KEY_ENTER && pause_menu_button_index == 1)
        {
            // al_play_sample_instance(click_se_spi);
            GAME_STATUS = MENU_GAME_ROLE_SELECT;
        }
        else if (event.keyboard.keycode == ALLEGRO_KEY_ENTER && pause_menu_button_index == 2)
        {
            // al_play_sample_instance(click_se_spi);
            GAME_STATUS = MENU_GAME_TERMINATE;
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