#include "event.h"
#include "global.h"

//    const char *description;
//    const char *operator;
//    int moneyChange;
//    const char *image_path;

Game_event events[MAX_EVENT] = {{"土地公有求必應", "+", 10000, "./assets/image/event/15.png"},
                                {"土地公有求必應", "+", 10000, "./assets/image/event/15.png"},
                                {"土地公有求必應", "+", 10000, "./assets/image/event/15.png"}};

Game_event getEvent()
{
    return events[rand() % MAX_EVENT];
}
