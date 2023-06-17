#include "global.h"
#include "scene.h"
int main()
{
    printf("Hello World!\n");

    scene_init();
    scene_begin();
    // 建立遊戲
    int msg = 0;
    while ((msg = scene_run()) != MSG_TERMINATE)
    {
        ;
    }
    printf("Game Over\n");
    scene_destroy();
    return 0;
}
