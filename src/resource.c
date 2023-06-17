#include "resource.h"

float bgm_gain = 1.0f;
float se_gain = 1.0f;

// Hello
ALLEGRO_SAMPLE *sample_hello;

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

// Credit Menu
ALLEGRO_BITMAP *credit_menu_all;

// Pause Menu
ALLEGRO_BITMAP *pause_menu_all;
ALLEGRO_BITMAP *pause_menu_restart;
ALLEGRO_BITMAP *pause_menu_continue;
ALLEGRO_BITMAP *pause_menu_finish;

// Game Background
ALLEGRO_BITMAP *game_background;

// Font
ALLEGRO_FONT *write_font;

//story
ALLEGRO_BITMAP *sm_story_1;
ALLEGRO_BITMAP *sm_story_2;
ALLEGRO_BITMAP *sm_story_3;
ALLEGRO_BITMAP *sm_rotate;

//about
ALLEGRO_BITMAP *sm_about_1;
ALLEGRO_BITMAP *sm_about_2;
ALLEGRO_BITMAP *sm_about_3;

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
    // Credit Menu
    credit_menu_all = al_load_bitmap("./assets/image/credits/credits_all.png");
    // Game Background
    game_background = al_load_bitmap("./assets/image/game/background.png");
    // Font
    write_font = al_load_ttf_font("./assets/font/write.ttf", 36, 0); // 載入字體
    // Pause Menu
    pause_menu_all = al_load_bitmap("./assets/image/pause_menu/all.png");
    pause_menu_restart = al_load_bitmap("./assets/image/pause_menu/restart.png");    pause_menu_continue = al_load_bitmap("./assets/image/pause_menu/continue.png");
    pause_menu_finish = al_load_bitmap("./assets/image/pause_menu/finish.png");
    //story
    sm_story_1 = al_load_bitmap("./assets/image/sm_story&about/sm_story_1.png");
    sm_story_2 = al_load_bitmap("./assets/image/sm_story&about/sm_story_2.png");
    sm_story_3 = al_load_bitmap("./assets/image/sm_story&about/sm_story_3.png");
    sm_rotate = al_load_bitmap("./assets/image/sm_story&about/sm_rotate.png");

    //about
    sm_about_1 = al_load_bitmap("./assets/image/sm_story&about/sm_about_1.png");
    sm_about_2 = al_load_bitmap("./assets/image/sm_story&about/sm_about_2.png");
    sm_about_3 = al_load_bitmap("./assets/image/sm_story&about/sm_about_3.png");
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