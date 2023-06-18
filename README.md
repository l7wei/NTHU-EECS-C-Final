# I2P1_Final_project
Introduction to programming 1 final project
## Rules
- You can only use C language to do this project, otherwise you will get 0 point.
  Any C++ header file is not allow.
- Plagiarism is strictly not allowed

## Resource

- Allegro download: [https ://github.com/liballeg/allegro5/releases](https://github.com/liballeg/allegro5/releases)

- Allegro install(mac): https://hackmd.io/@kerwintsai/SkRTk6kCS
- Allegro install(Windows):  https://github.com/yuan7122/I2P1_Final_project/blob/master/tutorial/Allegro_install.pdf
- Allegro documentation: https://liballeg.org/a5docs/trunk/
- For more information refer to [tutorial folder](https://github.com/yuan7122/I2P1_Final_project/tree/master/tutorial)

---

## For Future Reference

### Folder Structure
```
.
├── README.md
├── final_project.cbp
├── src
│   ├── main.c // main function, use a while loop to control the game
│   ├── scene.c // scene control, use a switch to control the scene
│   ├── scene.h
│   ├── resource.c // load resource
│   ├── resource.h
│   ├── game.c // game logic
│   ├── game.h
.   . // and so on in other scene
├── lib
│   ├── allegro // allegro library
│   └── algif5 // algif5 library
├── assets // assets folder
│   ├── font
│   ├── image
│   ├── sound
.   .
```

### Scene Control
在 `main.c` 中，透過 `while` 迴圈控制遊戲，並透過 `scene` 變數控制場景，我們使用 `enum` 來定義場景，並在 `scene.c` 中透過 `if - else` 來傳遞訊息和控制場景（`switch` 會更好）。

以下這些 `enum` 可以在 `global.h` 中找到
```c
enum
{
    MSG_TERMINATE,
    MSG_NOPE,
    MSG_GAME_START,
    MSG_GAME_OVER,
    MSG_GAME_RESTART,
    MSG_BACK_TO_MENU,
    MSG_CHANGE_SETTING,
    MSG_ABOUT_START,
    MSG_STORY_START,
    MSG_GAME_PAUSE
};

enum
{
    SCENE_MENU,
    SCENE_SELECT_ROLE,
    SCENE_GAME,
    SCENE_RESULT,
    SCENE_SETTING,
    SCENE_STORY,
    SCENE_ABOUT,
    SCENE_PAUSE
};
```

這樣的好處是，你可以在 `game.c` 中透過回傳 `MSG` 來告訴 `scene` 目前的狀態，例如：

```c
int game()
{
    // ...
    if (game_over)
    {
        return MSG_GAME_OVER;
    }
    // ...
}
```

然後在 `scene.c` 中更新場景狀態，例如：

```c
int scene_process(ALLEGRO_EVENT event)
{ 
    // ...
    if (scene_state == SCENE_MENU)
    {
      // Do something
    }
    // ...
}
```


### final_project.cbp 配置
#### Linker
```xml
<Add directory="lib/allegro/include" />
<Add directory="lib/algif5/include" />
```
配置 lib 路徑，讓你可以這樣引入標頭檔
```c
#include <algif5/algif.h>
```

#### Search Files
```xml
<Unit filename="src/event.c">
	<Option compilerVar="CC" />
</Unit>
<Unit filename="src/event.h" />
```
配置檔案路徑，讓 codeblock 找得到你的檔案

## Team
- 奇葦
- 筠浩
- 沛芠
