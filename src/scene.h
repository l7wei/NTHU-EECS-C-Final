#include "global.h"

void scene_init();
void scene_begin();
void scene_destroy();

enum
{
    SCENE_MENU,
    SCENE_GAME,
    SCENE_RESULT,
    SCENE_SETTING
};

int scene_run();