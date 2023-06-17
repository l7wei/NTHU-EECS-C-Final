#include "game.h"
#include "global.h"

const char *title = "Final Project CatOtter";

bool draw = false;
int window = 1;

// ALLEGRO Variables
ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_SAMPLE *song = NULL;
ALLEGRO_SAMPLE_INSTANCE *sample_instance;

int Game_establish()
// 建立遊戲
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
// 初始化遊戲
{
    // 初始化 Allegro
    printf("Game Initializing...\n");
    al_init();

    // 初始化 audio
    al_install_audio();
    al_init_acodec_addon();

    // Create display
    display = al_create_display(WIDTH, HEIGHT);

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

    font = al_load_ttf_font("./assets/font/write.ttf", 36, 0); // 載入字體

    if (!font)
    {
        fprintf(stderr, "Could not load 'write.ttf'.\n");
        exit(-1);
    }
    srand(time(0));
}

void game_begin()
// 遊戲（視窗）開始時
{
    printf("Game Starting...\n");
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

void game_destroy()
// 遊戲結束時
{
    printf("Game Closing...\n");
    al_rest(1.0);                // 等待10秒
    al_destroy_display(display); // 清理並關閉顯示視窗
    al_destroy_font(font);       // 銷毀字體
}

int main()
{
    printf("Hello World!\n");
    Game_establish();
}
