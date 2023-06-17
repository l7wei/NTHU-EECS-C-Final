#include "global.h"
#include "scene.h"
int main()
{
    printf("Hello World!\n");

    scene_init();
    scene_begin();
    // 建立遊戲
    // 不斷的跑 scene_run 直到回傳 MSG_TERMINATE 代碼
    // global.h 裡面有定義代碼
    int msg = 0;
    while ((msg = scene_run()) != MSG_TERMINATE)
    {
        ;
    }
    printf("Game Over\n");
    scene_destroy();
    return 0;
}
