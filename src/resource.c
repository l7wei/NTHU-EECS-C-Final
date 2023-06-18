#include "resource.h"

float bgm_gain = 1.0f;
float se_gain = 1.0f;

// Hello
ALLEGRO_SAMPLE *sample_hello;
ALLEGRO_BITMAP *hello_cover;
ALGIF_ANIMATION *hello_start;

// Start Menu
ALLEGRO_BITMAP *start_menu_all;
ALLEGRO_BITMAP *start_menu_start;
ALLEGRO_BITMAP *start_menu_story;
ALLEGRO_BITMAP *start_menu_about;
ALLEGRO_BITMAP *start_menu_exit;

// Role Select Menu
ALLEGRO_BITMAP *role_menu_all;
ALLEGRO_BITMAP *role_menu_panda;
ALLEGRO_BITMAP *role_menu_kiwi;
ALLEGRO_BITMAP *role_menu_otter;

// Pause Menu
ALLEGRO_BITMAP *pause_menu_all;
ALLEGRO_BITMAP *pause_menu_restart;
ALLEGRO_BITMAP *pause_menu_continue;
ALLEGRO_BITMAP *pause_menu_finish;

// Game Background
ALLEGRO_BITMAP *game_background;

// Font
ALLEGRO_FONT *write_font;

// story
ALLEGRO_BITMAP *story_1;
ALLEGRO_BITMAP *story_2;
ALLEGRO_BITMAP *story_3;

// about
ALLEGRO_BITMAP *about_1;
ALLEGRO_BITMAP *about_2;
ALLEGRO_BITMAP *about_3;
ALLEGRO_BITMAP *teams;

// Credits
ALLEGRO_BITMAP *credits_all;

// role
ALLEGRO_BITMAP *role_panda;
ALLEGRO_BITMAP *role_kiwi;
ALLEGRO_BITMAP *role_otter;

void load_sound(const char *filename, ALLEGRO_SAMPLE **sp, ALLEGRO_SAMPLE_INSTANCE **spi, ALLEGRO_PLAYMODE playmode)
{
    *sp = al_load_sample(filename);
    *spi = al_create_sample_instance(*sp);
    al_set_sample_instance_playmode(*spi, playmode);
    al_attach_sample_instance_to_mixer(*spi, al_get_default_mixer());
}

void destroy_sound(ALLEGRO_SAMPLE *sp, ALLEGRO_SAMPLE_INSTANCE *spi)
{
    al_destroy_sample_instance(spi);
    al_destroy_sample(sp);
}

void load_resource()
{
    // Hello
    sample_hello = al_load_sample("./assets/sound/hello.mp3");
    hello_cover = al_load_bitmap("./assets/image/hello/cover.png");
    hello_start = algif_load_animation("../assets/image/hello/start.gif"); // algif 只支援相對路徑
    // Start Menu
    start_menu_all = al_load_bitmap("./assets/image/start_menu/all.png");
    start_menu_start = al_load_bitmap("./assets/image/start_menu/start.png");
    start_menu_story = al_load_bitmap("./assets/image/start_menu/story.png"); // Game basic Interface
    start_menu_about = al_load_bitmap("./assets/image/start_menu/about.png");
    start_menu_exit = al_load_bitmap("./assets/image/start_menu/exit.png");
    // Role Select Menu
    role_menu_all = al_load_bitmap("./assets/image/role_select/all_detailed.png");
    role_menu_panda = al_load_bitmap("./assets/image/role_select/1_panda.png");
    role_menu_kiwi = al_load_bitmap("./assets/image/role_select/2_kiwi.png");
    role_menu_otter = al_load_bitmap("./assets/image/role_select/3_otter.png");
    // Game Background
    game_background = al_load_bitmap("./assets/image/game/background.png");
    // Font
    write_font = al_load_ttf_font("./assets/font/write.ttf", 36, 0); // 載入字體
    // Pause Menu
    pause_menu_all = al_load_bitmap("./assets/image/pause_menu/all.png");
    pause_menu_restart = al_load_bitmap("./assets/image/pause_menu/restart.png");
    pause_menu_continue = al_load_bitmap("./assets/image/pause_menu/continue.png");
    pause_menu_finish = al_load_bitmap("./assets/image/pause_menu/finish.png");
    // story
    story_1 = al_load_bitmap("./assets/image/start_menu/story/1.png");
    story_2 = al_load_bitmap("./assets/image/start_menu/story/2.png");
    story_3 = al_load_bitmap("./assets/image/start_menu/story/3.png");
    // about
    about_1 = al_load_bitmap("./assets/image/start_menu/about/1.png");
    about_2 = al_load_bitmap("./assets/image/start_menu/about/2.png");
    about_3 = al_load_bitmap("./assets/image/start_menu/about/3.png");
    teams = al_load_bitmap("./assets/image/start_menu/teams.png");
    // Games
    credits_all = al_load_bitmap("./assets/image/credits/credits_all.png");
    // Role
    role_panda = al_load_bitmap("./assets/image/game/panda.png");
    role_kiwi = al_load_bitmap("./assets/image/game/kiwi.png");
    role_otter = al_load_bitmap("./assets/image/game/otter.png");
}

void destroy_resource()
{
    al_destroy_font(write_font); // 清理字體
}

void set_bgm_gain(float gain)
{
    bgm_gain = gain;
    // al_set_sample_instance_gain(, gain);
    // al_set_sample_instance_gain(, gain);
}

void set_se_gain(float gain)
{
    se_gain = gain;
    // al_set_sample_instance_gain(, gain);
    // al_set_sample_instance_gain(, gain);
}