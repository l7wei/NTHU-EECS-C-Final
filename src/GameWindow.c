#include <allegro5/allegro.h>

#include <allegro5/allegro_audio.h> //使用 Allegro 的音效功能
#include <allegro5/allegro_font.h>  //使用 Allegro 的字體和文本功能
#include <allegro5/allegro_ttf.h>   //支援TrueType字體

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 20
#define MAX_EVENT 5

#define SYSTEM_MESSAGE "[系統訊息]"
#define PLAYER_MESSAGE "[玩家訊息]"

typedef struct Player
{
    int position;
    int money;
} Player;

typedef struct Event
{
    const char *description;
    int moneyChange;
} Event;

Event events[MAX_EVENT] = {
    {"你找到了一筆錢，獲得$100!", 100}, {"你被罰款$50!", -50}, {"你被罰款$100!", -100},
    {"你找到了一筆錢，獲得$50!", 50},   {"沒有事件發生", 0},
};

void initializePlayer(Player *player)
{
    player->position = 0;
    player->money = 1000;
}

int rollDice()
{
    return rand() % 6 + 1;
}

Event getEvent()
{
    return events[rand() % MAX_EVENT];
}

ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_SAMPLE *song = NULL;
ALLEGRO_SAMPLE_INSTANCE *sample_instance;

ALLEGRO_FONT *font = NULL;

void Game_establish()
{
    game_init();
    game_scene();
    game_destroy();
}

void game_init()
{
    // 初始化 Allegro
    printf("Game Initializing...\n");
    if (!al_init())
    {
        fprintf(stderr, "failed to initialize allegro!\n");
        exit(-1);
    }

    al_set_new_display_flags(ALLEGRO_RESIZABLE); // 讓視窗可以調整大小
    display = al_create_display(1000, 800);      // 創建一個800x600的視窗
    if (!display)
    {
        fprintf(stderr, "failed to create display!\n");
        exit(-1);
    }

    al_init_font_addon(); // 初始化字體插件
    al_init_ttf_addon();  // 初始化 TTF (True Type Font) 插件

    font = al_load_ttf_font("./assets/font/write.ttf", 72, 0); // 載入字體

    if (!font)
    {
        fprintf(stderr, "Could not load 'write.ttf'.\n");
        exit(-1);
    }
    srand(time(0));
}

void game_begin()
{
    // Game Window
    // Load sound
    song = al_load_sample("./assets/sound/hello.mp3");
    al_reserve_samples(20);
    sample_instance = al_create_sample_instance(song);
    // Loop the song until the display closes
    al_set_sample_instance_playmode(sample_instance, ALLEGRO_PLAYMODE_LOOP);
    al_restore_default_mixer();
    al_attach_sample_instance_to_mixer(sample_instance, al_get_default_mixer());
    // set the volume of instance
    al_set_sample_instance_gain(sample_instance, 1);
    al_play_sample_instance(sample_instance);
}

void game_scene()
{
    Player player;
    initializePlayer(&player);
    while (player.position < MAP_SIZE)
    {
        al_clear_to_color(al_map_rgb(0, 0, 0)); // 將視窗設置為黑色
        al_draw_textf(font, al_map_rgb(255, 255, 255), 400, 300, ALLEGRO_ALIGN_CENTRE, "%s你現在在%d位置，有%d的金錢。",
                      SYSTEM_MESSAGE, player.position, player.money);
        al_flip_display(); // 更新視窗內容

        getchar();

        int dice = rollDice();
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_textf(font, al_map_rgb(255, 255, 255), 400, 300, ALLEGRO_ALIGN_CENTRE, "%s你擲出了%d。", SYSTEM_MESSAGE,
                      dice);
        al_flip_display();

        player.position += dice;

        if (player.position >= MAP_SIZE)
        {
            al_clear_to_color(al_map_rgb(0, 0, 0));
            al_draw_text(font, al_map_rgb(255, 255, 255), 400, 300, ALLEGRO_ALIGN_CENTRE,
                         "恭喜，你已經達到終點，遊戲結束!");
            al_flip_display();
            break;
        }

        Event event = getEvent();
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_textf(font, al_map_rgb(255, 255, 255), 400, 300, ALLEGRO_ALIGN_CENTRE, "%s%s", PLAYER_MESSAGE,
                      event.description);
        al_flip_display();

        player.money += event.moneyChange;

        if (player.money <= 0)
        {
            al_clear_to_color(al_map_rgb(0, 0, 0));
            al_draw_text(font, al_map_rgb(255, 255, 255), 400, 300, ALLEGRO_ALIGN_CENTRE, "你的錢已經用完，遊戲結束!");
            al_flip_display();
            break;
        }
    }
}

void game_destroy()
{
    al_rest(5.0);                // 等待10秒
    al_destroy_display(display); // 清理並關閉顯示視窗
    al_destroy_font(font);       // 銷毀字體
}

int main()
{
    Game_establish();
    return 0;
}