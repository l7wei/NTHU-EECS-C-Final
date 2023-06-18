#include "event.h"
#include "global.h"

//    const char *description;      敘述
//    const char *moneyOperator;    Money 運算符號
//    int moneyChange;              Money 變化
//    const char *loadingOperator;  Loading 運算符號
//    int loadingChange;            Loading 變化
//    const char *image_path;       圖片路徑 用 ./開頭)

Game_event events[MAX_EVENT] = {{"土地公", "+", 10000000, "+", 0, "./assets/image/event/1.png"},
                                {"阿嬤", "+", 30000, "+", 0, "./assets/image/event/2.png"},
                                {"圖書館", "+", 500, "+", 0, "./assets/image/event/3.png"},
                                {"刮刮樂", "+", 1000000, "+", 0, "./assets/image/event/4.png"},
                                {"足球", "+", 200000, "+", 0, "./assets/image/event/5.png"},
                                {"棄交保清", "+", 100000, "+", 0, "./assets/image/event/6.png"},
                                {"書卷", "+", 10000, "+", 0, "./assets/image/event/7.png"},
                                {"體育競賽", "+", 50000, "+", 0, "./assets/image/event/8.png"},
                                {"駐警隊", "-", 30000, "-", 0, "./assets/image/event/9.png"},
                                {"線上遊戲", "-", 3000, "-", 0, "./assets/image/event/10.png"},
                                {"偷拍", "-", 70000, "-", 0, "./assets/image/event/11.png"},
                                {"啦啦隊", "-", 100000, "-", 0, "./assets/image/event/12.png"},
                                {"P2P", "-", 50000, "-", 0, "./assets/image/event/13.png"},
                                {"學霸被當", "-", 0, "-", 48, "./assets/image/event/14.png"},
                                {"麥當勞", "-", 10000, "-", 32, "./assets/image/event/15.png"},
                                {"告白", "-", 10000, "-", 0, "./assets/image/event/16.png"},
                                {"天使輪", "+", 50000000000, "+", 0, "./assets/image/event/17.png"},
                                {"梅校長", "-", 5000000000, "-", 0, "./assets/image/event/18.png"},
                                {"變電箱", "-", 100000000, "-", 0, "./assets/image/event/19.png"},
                                {"外系搶課", "+", 0, "-", 0, "./assets/image/event/20.png"},
                                {"新成功湖", "+", 0, "+", 0, "./assets/image/event/21.png"},
                                {"鴉片粉圓", "+", 0, "+", 0, "./assets/image/event/22.png"},
                                {"放煙火", "+", 0, "+", 0, "./assets/image/event/23.png"}};

Game_event getEvent()
{
    return events[rand() % MAX_EVENT];
}
