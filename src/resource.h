#pragma once
#include "global.h"

extern float bgm_gain;
extern float se_gain;

// Start Menu
extern ALLEGRO_BITMAP *start_menu_all;
extern ALLEGRO_BITMAP *start_menu_start;
extern ALLEGRO_BITMAP *start_menu_story;
extern ALLEGRO_BITMAP *start_menu_about;
extern ALLEGRO_BITMAP *start_menu_exit;

// Font
extern ALLEGRO_FONT *write_font;

void load_resource();
void destroy_resource();

void set_bgm_gain(float);
void set_se_gain(float);
