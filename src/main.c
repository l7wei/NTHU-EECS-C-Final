#include "global.h"
#include "scene.h"
//#include "algif5/src/algif.h"

int main()
{
    printf("Hello World!\n");

    scene_init();
    scene_begin();
    // 建立遊戲
    while ((scene_run()) != MSG_TERMINATE)
    {
        ;
    }
    printf("Game Over\n");
    scene_destroy();
    return 0;
}
