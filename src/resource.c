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

// Pause Menu
ALLEGRO_BITMAP *pause_menu_all;
ALLEGRO_BITMAP *pause_menu_restart;
ALLEGRO_BITMAP *pause_menu_continue;
ALLEGRO_BITMAP *pause_menu_finish;

// Game Background
ALLEGRO_BITMAP *game_background_1;
ALLEGRO_BITMAP *game_background_2;

// 計分橫條
ALLEGRO_BITMAP *calculate;

// Font
ALLEGRO_FONT *bit_font;

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
ALGIF_ANIMATION *easter_egg;

// role
ALLEGRO_BITMAP *role_panda;
ALLEGRO_BITMAP *role_kiwi;
ALLEGRO_BITMAP *role_otter;

// dice
ALLEGRO_BITMAP *dice1;
ALLEGRO_BITMAP *dice2;
ALLEGRO_BITMAP *dice3;
ALLEGRO_BITMAP *dice4;
ALLEGRO_BITMAP *dice5;
ALLEGRO_BITMAP *dice6;
ALGIF_ANIMATION *dice_rolling;

// test
ALGIF_ANIMATION *test_gif;

// ending
ALLEGRO_BITMAP *ending_1_1;
ALLEGRO_BITMAP *ending_1_2;
ALLEGRO_BITMAP *ending_2_1;
ALLEGRO_BITMAP *ending_2_2;
ALLEGRO_BITMAP *ending_3_1;
ALLEGRO_BITMAP *ending_3_2;
ALLEGRO_BITMAP *ending_4_1;
ALLEGRO_BITMAP *ending_4_2;
ALLEGRO_BITMAP *ending_5_1;
ALLEGRO_BITMAP *ending_5_2;
ALLEGRO_BITMAP *ending_6_1;
ALLEGRO_BITMAP *ending_6_2;
ALLEGRO_BITMAP *ending_7_1;
ALLEGRO_BITMAP *ending_7_2;

// sound
ALLEGRO_SAMPLE *badthings;
ALLEGRO_SAMPLE *bus_road;
ALLEGRO_SAMPLE *credit_changing;
ALLEGRO_SAMPLE *decision1;
ALLEGRO_SAMPLE *failure;
ALLEGRO_SAMPLE *gamestart;
ALLEGRO_SAMPLE *role_selectchange;
ALLEGRO_SAMPLE *story_open;
ALLEGRO_SAMPLE *treasureget;
ALLEGRO_SAMPLE *working;
ALLEGRO_SAMPLE *backgroung_music;

ALLEGRO_SAMPLE *bgm_bus_road_sp;
ALLEGRO_SAMPLE_INSTANCE *bgm_bus_road_spi;
ALLEGRO_SAMPLE *bgm_music_sp;
ALLEGRO_SAMPLE_INSTANCE *bgm_music_spi;
ALLEGRO_SAMPLE *credit_changing_sp;
ALLEGRO_SAMPLE_INSTANCE *credit_changing_spi;
ALLEGRO_SAMPLE *effect_bad_sp;
ALLEGRO_SAMPLE_INSTANCE *effect_bad_spi;
ALLEGRO_SAMPLE *effect_fail_sp;
ALLEGRO_SAMPLE_INSTANCE *effect_fail_spi;
ALLEGRO_SAMPLE *effect_good_sp;
ALLEGRO_SAMPLE_INSTANCE *effect_good_spi;
ALLEGRO_SAMPLE *effect_gooddecision_sp;
ALLEGRO_SAMPLE_INSTANCE *effect_gooddecision_spi;
ALLEGRO_SAMPLE *game_start_sp;
ALLEGRO_SAMPLE_INSTANCE *game_start_spi;
ALLEGRO_SAMPLE *game_walking_sp;
ALLEGRO_SAMPLE_INSTANCE *game_walking_spi;
ALLEGRO_SAMPLE *menu_change_role_sp;
ALLEGRO_SAMPLE_INSTANCE *menu_change_role_spi;
ALLEGRO_SAMPLE *menu_change_select_sp;
ALLEGRO_SAMPLE_INSTANCE *menu_change_select_spi;
ALLEGRO_SAMPLE *menu_hello_sp;
ALLEGRO_SAMPLE_INSTANCE *menu_hello_spi;
ALLEGRO_SAMPLE *menu_story_open_sp;
ALLEGRO_SAMPLE_INSTANCE *menu_story_open_spi;

void load_sound(const char *filename, ALLEGRO_SAMPLE **sp, ALLEGRO_SAMPLE_INSTANCE **spi, ALLEGRO_PLAYMODE playmode)
{
    *sp = al_load_sample(filename);
    *spi = al_create_sample_instance(*sp);
    al_set_sample_instance_playmode(*spi, playmode);                  // 設定播放模式
    al_set_sample_instance_gain(*spi, 1);                             // 設定音量
    al_attach_sample_instance_to_mixer(*spi, al_get_default_mixer()); // 將音效附加到混音器
}

void destroy_sound(ALLEGRO_SAMPLE *sp, ALLEGRO_SAMPLE_INSTANCE *spi)
{
    al_destroy_sample_instance(spi);
    al_destroy_sample(sp);
}

void load_resource()
{
    // Hello
    sample_hello = al_load_sample("./assets/sound/menu_hello.mp3");
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
    game_background_1 = al_load_bitmap("./assets/image/game/background_1.png");
    game_background_2 = al_load_bitmap("./assets/image/game/background_2.png");
    // 橫條
    calculate = al_load_bitmap("./assets/image/game/calculate.png");
    // Font
    bit_font = al_load_ttf_font("./assets/font/bit.ttf", 36, 0); // 載入字體
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
    easter_egg = algif_load_animation("./assets/image/egg.gif");
    // Test
    test_gif = algif_load_animation("./assets/image/test.gif");
    // Role
    role_panda = al_load_bitmap("./assets/image/role/simple/panda.png");
    role_kiwi = al_load_bitmap("./assets/image/role/simple/kiwi.png");
    role_otter = al_load_bitmap("./assets/image/role/simple/otter.png");
    // dice
    dice1 = al_load_bitmap("./assets/image/dice/1.png");
    dice2 = al_load_bitmap("./assets/image/dice/2.png");
    dice3 = al_load_bitmap("./assets/image/dice/3.png");
    dice4 = al_load_bitmap("./assets/image/dice/4.png");
    dice5 = al_load_bitmap("./assets/image/dice/5.png");
    dice6 = al_load_bitmap("./assets/image/dice/6.png");
    dice_rolling = algif_load_animation("./assets/image/dice/rolling.gif");
    // ending
    ending_1_1 = al_load_bitmap("./assets/image/ending/level1_1.png");
    ending_1_2 = al_load_bitmap("./assets/image/ending/level1_2.png");
    ending_2_1 = al_load_bitmap("./assets/image/ending/level2_1.png");
    ending_2_2 = al_load_bitmap("./assets/image/ending/level2_2.png");
    ending_3_1 = al_load_bitmap("./assets/image/ending/level3_1.png");
    ending_3_2 = al_load_bitmap("./assets/image/ending/level3_2.png");
    ending_4_1 = al_load_bitmap("./assets/image/ending/level4_1.png");
    ending_4_2 = al_load_bitmap("./assets/image/ending/level4_2.png");
    ending_5_1 = al_load_bitmap("./assets/image/ending/level5_1.png");
    ending_5_2 = al_load_bitmap("./assets/image/ending/level5_2.png");
    ending_6_1 = al_load_bitmap("./assets/image/ending/level6_1.png");
    ending_6_2 = al_load_bitmap("./assets/image/ending/level6_2.png");
    ending_7_1 = al_load_bitmap("./assets/image/ending/level7_1.png");
    ending_7_2 = al_load_bitmap("./assets/image/ending/level7_2.png");
    // sound
    load_sound("./assets/sound/bgm_bus_road.mp3", &bgm_bus_road_sp, &bgm_bus_road_spi, ALLEGRO_PLAYMODE_ONCE);
    printf("Loading sound...\n");
    load_sound("./assets/sound/bgm_music.mp3", &bgm_music_sp, &bgm_music_spi, ALLEGRO_PLAYMODE_ONCE);
    load_sound("./assets/sound/credit_changing.mp3", &credit_changing_sp, &credit_changing_spi, ALLEGRO_PLAYMODE_ONCE);
    load_sound("./assets/sound/effect_bad.mp3", &effect_bad_sp, &effect_bad_spi, ALLEGRO_PLAYMODE_ONCE);
    load_sound("./assets/sound/effect_fail.mp3", &effect_fail_sp, &effect_fail_spi, ALLEGRO_PLAYMODE_ONCE);
    load_sound("./assets/sound/effect_good.mp3", &effect_good_sp, &effect_good_spi, ALLEGRO_PLAYMODE_ONCE);
    load_sound("./assets/sound/effect_gooddecision.mp3", &effect_gooddecision_sp, &effect_gooddecision_spi,
               ALLEGRO_PLAYMODE_ONCE);
    load_sound("./assets/sound/game_start.mp3", &game_start_sp, &game_start_spi, ALLEGRO_PLAYMODE_ONCE);
    load_sound("./assets/sound/game_walking.mp3", &game_walking_sp, &game_walking_spi, ALLEGRO_PLAYMODE_ONCE);
    load_sound("./assets/sound/menu_change_role.mp3", &menu_change_role_sp, &menu_change_role_spi,
               ALLEGRO_PLAYMODE_ONCE);
    load_sound("./assets/sound/menu_change_select.mp3", &menu_change_select_sp, &menu_change_select_spi,
               ALLEGRO_PLAYMODE_ONCE);
    load_sound("./assets/sound/menu_hello.mp3", &menu_hello_sp, &menu_hello_spi, ALLEGRO_PLAYMODE_ONCE);
    load_sound("./assets/sound/menu_story_open.mp3", &menu_story_open_sp, &menu_story_open_spi, ALLEGRO_PLAYMODE_ONCE);
    // ...其他 load_sound()
}

void destroy_resource()
{
    al_destroy_font(bit_font); // 清理字體
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