#include "scene.h"
#define GAME_TERMINATE -1
int main()
{
    printf("Hello World!\n");

    game_init();
    game_begin();
    // 建立遊戲
    int msg = 0;
    while ((msg = game_run()) != GAME_TERMINATE)
    {
        ;
    }
    printf("Game Over\n");
    game_destroy();
    return 0;
}
