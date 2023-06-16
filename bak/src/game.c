#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 遊戲設定
#define MAP_SIZE 20
#define MAX_EVENT 5

// 訊息
#define SYSTEM_MESSAGE "[系統訊息]"
#define PLAYER_MESSAGE "[玩家訊息]"

// 事件
typedef struct Event
{
    const char *description;
    int moneyChange;
} Event;

// 事件列表
Event events[MAX_EVENT] = {
    {"你找到了一筆錢，獲得$100!", 100}, {"你被罰款$50!", -50}, {"你被罰款$100!", -100},
    {"你找到了一筆錢，獲得$50!", 50},   {"沒有事件發生", 0},
};

// 初始化玩家
void initializePlayer(Player *player)
{
    player->position = 0;
    player->money = 1000;
}

// 擲骰子
int rollDice()
{
    return rand() % 6 + 1;
}

// 隨機取得事件
Event getEvent()
{
    return events[rand() % MAX_EVENT];
}

// 主程式
int main()
{
    printf("這場遊戲有%d個區塊\n", MAP_SIZE);

    srand(time(0));

    Player player;
    initializePlayer(&player);

    while (player.position < MAP_SIZE)
    {
        printf("%s你現在在%d位置，有%d的金錢。\n", SYSTEM_MESSAGE, player.position, player.money);
        printf("%s按Enter擲骰子...\n", SYSTEM_MESSAGE);
        getchar();
        printf("\n");
        int dice = rollDice();
        printf("%s你擲出了%d。\n", SYSTEM_MESSAGE, dice);
        printf("%s距離終點還有%d格。\n", SYSTEM_MESSAGE, MAP_SIZE - player.position);
        player.position += dice;

        if (player.position >= MAP_SIZE)
        {
            printf("\n恭喜，你已經達到終點，遊戲結束!\n");
            break;
        }

        Event event = getEvent();
        printf("%s%s\n", PLAYER_MESSAGE, event.description);
        player.money += event.moneyChange;

        if (player.money <= 0)
        {
            printf("你的錢已經用完，遊戲結束!\n");
            break;
        }
    }

    return 0;
}
