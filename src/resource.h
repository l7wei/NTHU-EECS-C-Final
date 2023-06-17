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

// Credit Menu
extern ALLEGRO_BITMAP *credit_menu_all;

// Pause Menu
extern ALLEGRO_BITMAP *pause_menu_all;
extern ALLEGRO_BITMAP *pause_menu_restart;
extern ALLEGRO_BITMAP *pause_menu_continue;
extern ALLEGRO_BITMAP *pause_menu_finish;

// Game Background
extern ALLEGRO_BITMAP *game_background;

//story
extern ALLEGRO_BITMAP *sm_story_1;
extern ALLEGRO_BITMAP *sm_story_2;
extern ALLEGRO_BITMAP *sm_story_3;
extern ALLEGRO_BITMAP *sm_rotate;

// Font
extern ALLEGRO_FONT *write_font;

//about
extern ALLEGRO_BITMAP *sm_about_1;
extern ALLEGRO_BITMAP *sm_about_2;
extern ALLEGRO_BITMAP *sm_about_3;

void load_resource();
void destroy_resource();

void set_bgm_gain(float);
void set_se_gain(float);
