#include "event.h"
#include "global.h"

//    const char *description;      敘述
//    const char *moneyOperator;    Money 運算符號
//    int moneyChange;              Money 變化
//    const char *loadingOperator;  Loading 運算符號
//    int loadingChange;            Loading 變化
//    const char *image_path;       圖片路徑 用 ./開頭)

Game_event events[MAX_EVENT] = {
    {"土地公有求必應，中發票特獎", "+", 10000000, "+", 0, "./assets/image/event/1.png"},
    {"周末回家當米蟲，阿嬤斗內零用錢", "+", 30000, "+", 0, "./assets/image/event/2.png"},
    {"圖書館路邊撿到錢", "+", 500, "+", 0, "./assets/image/event/3.png"},
    {"爸爸刮刮樂中獎", "+", 1000000, "+", 0, "./assets/image/event/4.png"},
    {"世足期間幸運押高賠率運彩獎金", "+", 200000, "+", 0, "./assets/image/event/5.png"},
    {"棄交保清，考上清大研究所獎學金", "+", 100000, "+", 0, "./assets/image/event/6.png"},
    {"認真讀書，系排第一書卷獎獎學金", "+", 10000, "+", 0, "./assets/image/event/7.png"},
    {"參加體育競賽為校爭光獲得", "+", 50000, "+", 0, "./assets/image/event/8.png"},
    {"被駐警隊鎖車50次", "-", 30000, "-", 0, "./assets/image/event/9.png"},
    {"線上遊戲交易被詐騙", "-", 3000, "-", 0, "./assets/image/event/10.png"},
    {"偷拍女同學上傳網路", "-", 70000, "-", 0, "./assets/image/event/11.png"},
    {"梅竹賽釣到交大啦啦隊小姐姐", "-", 100000, "-", 0, "./assets/image/event/12.png"},
    {"P2P", "-", 50000, "-", 0, "./assets/image/event/13.png"},
    {"學霸朋友期中期末睡過頭被當 ", "-", 0, "-", 48, "./assets/image/event/14.png"},
    {"麥當勞排太長遲到沒點名二退", "-", 10000, "-", 32, "./assets/image/event/15.png"},
    {"告白被發好人卡，爆吃變肥宅", "-", 10000, "-", 0, "./assets/image/event/16.png"},
    {"創業獲得天使輪融資", "+", 50000000000, "+", 0, "./assets/image/event/17.png"},
    {"夜遊梅園梅校長顯靈中樂透頭獎", "+", 5000000000, "+", 0, "./assets/image/event/18.png"},
    {"目睹變電箱爆炸", "-", 100000000, "-", 0, "./assets/image/event/19.png"},
    {"必修課被外系搶占", "-", 0, "-", 32, "./assets/image/event/20.png"},
    {"去新蓋好的成功湖散步", "+", 0, "+", 0, "./assets/image/event/21.png"},
    {"嘗鮮搬家的鴉片粉圓  好吃", "+", 0, "+", 0, "./assets/image/event/22.png"},
    {"半夜偷偷跑去台積館放煙火", "+", 0, "+", 0, "./assets/image/event/23.png"}};

Game_event getEvent()
{
    return events[rand() % MAX_EVENT];
}
