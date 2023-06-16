#include "event.h"
#include "global.h"

Event events[MAX_EVENT] = {
    {"你找到了一筆錢，獲得$100!", 100}, {"你被罰款$50!", -50}, {"你被罰款$100!", -100},
    {"你找到了一筆錢，獲得$50!", 50},   {"沒有事件發生", 0},
};

Event getEvent()
{
    return events[rand() % MAX_EVENT];
}