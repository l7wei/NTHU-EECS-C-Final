#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "GameWindow.h"

const char *title = "Final Project CatOtter";

#define MAP_SIZE 20
#define MAX_EVENT 5

bool draw = false;
int window = 1;

// ALLEGRO Variables
ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_SAMPLE *song = NULL;
ALLEGRO_SAMPLE_INSTANCE *sample_instance;

ALLEGRO_FONT *font = NULL;

int Game_establish()
{
    int msg = 0;

    game_init();
    game_begin();
    while (msg != GAME_TERMINATE)
    {
        msg = game_run();
        if (msg == GAME_TERMINATE)
            printf("Game Over\n");
    }
    game_destroy();
    return 0;
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
    // 初始化 audio
    al_install_audio();
    al_init_acodec_addon();
    // 初始化 display
    display = al_create_display(WIDTH, HEIGHT);
    if (!display)
    {
        fprintf(stderr, "failed to create display!\n");
        exit(-1);
    }

    // create event queue
    event_queue = al_create_event_queue();

    // Initialize Allegro settings
    al_set_window_position(display, 0, 0);
    al_set_window_title(display, title);
    al_init_primitives_addon();
    al_init_font_addon();   // initialize the font addon
    al_init_ttf_addon();    // initialize the ttf (True Type Font) addon
    al_init_image_addon();  // initialize the image addon
    al_init_acodec_addon(); // initialize acodec addon
    al_install_keyboard();  // install keyboard event
    al_install_mouse();     // install mouse event
    al_install_audio();     // install audio event

    // Register event
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());
    fps = al_create_timer(1.0 / FPS);
    al_register_event_source(event_queue, al_get_timer_event_source(fps));

    // initialize the icon on the display
    ALLEGRO_BITMAP *icon = al_load_bitmap("./assets/image/icon.jpg");
    al_set_display_icon(display, icon);

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
    al_start_timer(fps);
}

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

int game_run()
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
    return -1;
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