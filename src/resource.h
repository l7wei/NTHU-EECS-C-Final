#pragma once
#include "global.h"

extern float bgm_gain;
extern float se_gain;

// Hello
extern ALLEGRO_SAMPLE *sample_hello;

// Start Menu
extern ALLEGRO_BITMAP *start_menu_all;
extern ALLEGRO_BITMAP *start_menu_start;
extern ALLEGRO_BITMAP *start_menu_story;
extern ALLEGRO_BITMAP *start_menu_about;
extern ALLEGRO_BITMAP *start_menu_exit;

// Role Select Menu
extern ALLEGRO_BITMAP *role_menu_all;
extern ALLEGRO_BITMAP *role_menu_panda;
extern ALLEGRO_BITMAP *role_menu_kiwi;
extern ALLEGRO_BITMAP *role_menu_otter;

// Pause Menu
extern ALLEGRO_BITMAP *pause_menu_all;
extern ALLEGRO_BITMAP *pause_menu_restart;
extern ALLEGRO_BITMAP *pause_menu_continue;
extern ALLEGRO_BITMAP *pause_menu_finish;

// Game Background
extern ALLEGRO_BITMAP *game_background_1;
extern ALLEGRO_BITMAP *game_background_2;

// 計分橫條
extern ALLEGRO_BITMAP *calculate;

// Font
extern ALLEGRO_FONT *bit_font;

// story
extern ALLEGRO_BITMAP *story_1;
extern ALLEGRO_BITMAP *story_2;
extern ALLEGRO_BITMAP *story_3;

// about
extern ALLEGRO_BITMAP *about_1;
extern ALLEGRO_BITMAP *about_2;
extern ALLEGRO_BITMAP *about_3;
extern ALLEGRO_BITMAP *teams;

// credits
extern ALLEGRO_BITMAP *credits_all;

// role
extern ALLEGRO_BITMAP *role_panda;
extern ALLEGRO_BITMAP *role_kiwi;
extern ALLEGRO_BITMAP *role_otter;

// dice
extern ALLEGRO_BITMAP *dice1;
extern ALLEGRO_BITMAP *dice2;
extern ALLEGRO_BITMAP *dice3;
extern ALLEGRO_BITMAP *dice4;
extern ALLEGRO_BITMAP *dice5;
extern ALLEGRO_BITMAP *dice6;
extern ALGIF_ANIMATION *dice_rolling;

// ending
extern ALLEGRO_BITMAP *ending_1_1;
extern ALLEGRO_BITMAP *ending_1_2;
extern ALLEGRO_BITMAP *ending_2_1;
extern ALLEGRO_BITMAP *ending_2_2;
extern ALLEGRO_BITMAP *ending_3_1;
extern ALLEGRO_BITMAP *ending_3_2;
extern ALLEGRO_BITMAP *ending_4_1;
extern ALLEGRO_BITMAP *ending_4_2;
extern ALLEGRO_BITMAP *ending_5_1;
extern ALLEGRO_BITMAP *ending_5_2;
extern ALLEGRO_BITMAP *ending_6_1;
extern ALLEGRO_BITMAP *ending_6_2;
extern ALLEGRO_BITMAP *ending_7_1;
extern ALLEGRO_BITMAP *ending_7_2;

// sound
extern ALLEGRO_SAMPLE *badthings;
extern ALLEGRO_SAMPLE *bus_road;
extern ALLEGRO_SAMPLE *changeselect;
// extern ALLEGRO_SAMPLE *credit_changing;
extern ALLEGRO_SAMPLE *decision1;
extern ALLEGRO_SAMPLE *failure;
extern ALLEGRO_SAMPLE *gamestart;
extern ALLEGRO_SAMPLE *role_selectchange;
extern ALLEGRO_SAMPLE *story_open;
extern ALLEGRO_SAMPLE *treasureget;
extern ALLEGRO_SAMPLE *working;
extern ALLEGRO_SAMPLE *backgroung_music;

extern ALLEGRO_SAMPLE_INSTANCE *credit_changing_spi;


void load_resource();
void destroy_resource();

void set_bgm_gain(float);
void set_se_gain(float);
