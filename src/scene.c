#include "scene.h"
#include "game.h"
#include "menu.h"
#include "resource.h"
#include "result.h"
#include "setting.h"
#include "story.h"

int scene_state;

const char *title = "Final Project CatOtter";

bool draw = false;
int window = 1;

int scene_run()
{
    ALLEGRO_EVENT event;
    al_wait_for_event(event_queue, &event);
    // 當按下右上角的 X 時，關閉視窗
    if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE && event.display.source == display)
    {
        return MSG_TERMINATE;
    }

    if (scene_process(event) == MSG_TERMINATE)
    {
        return MSG_TERMINATE;
    }

    if (event.type == ALLEGRO_EVENT_TIMER && event.timer.source == timer)
    {
        scene_draw();
    }
    return MSG_NOPE;
}

int scene_process(ALLEGRO_EVENT event)
{
    int msg;
    if (scene_state == SCENE_MENU)
    {
        msg = menu_process(event);
        // printf("final\n");
        if (msg == MSG_GAME_START)
        {
            menu_destroy();
            scene_state = SCENE_GAME;
            game_init();
        }
        else if (msg == MSG_STORY_START)
        {
            menu_destroy();
            scene_state = SCENE_STORY;
            story_init();
        }
        else if (msg == MSG_ABOUT_START)
        {
            menu_destroy();
            scene_state = SCENE_ABOUT;
        }
        else if (msg == MSG_TERMINATE)
        {
            return MSG_TERMINATE;
        }
    }
    else if (scene_state == SCENE_GAME)
    {
        msg = game_process(event);
        if (msg == MSG_GAME_OVER)
        {
            game_destroy();
            scene_state = SCENE_RESULT;
            result_init();
        }
    }
    else if (scene_state == SCENE_STORY)
    {
        msg = story_process(event);
        if (msg == MSG_GAME_OVER)
        {
            story_destroy();
        }
    }
    else if (scene_state == SCENE_RESULT)
    {
        msg = result_process(event);
        if (msg == MSG_GAME_RESTART)
        {
            result_destroy();
            scene_state = SCENE_GAME;
            game_init();
        }
        else if (msg == MSG_BACK_TO_MENU)
        {
            result_destroy();
            scene_state = SCENE_MENU;
            menu_init();
        }
        else if (msg == MSG_TERMINATE)
        {
            return MSG_TERMINATE;
        }
    }
    else if (scene_state == SCENE_SETTING)
    {
        msg = setting_process(event);
        if (msg == MSG_BACK_TO_MENU)
        {
            setting_destroy();
            scene_state = SCENE_MENU;
            menu_init();
        }
    }
    return MSG_NOPE;
}

void scene_draw()
{
    if (scene_state == SCENE_MENU)
    {
        menu_draw();
    }
    else if (scene_state == SCENE_GAME)
    {
        game_draw();
    }
    else if (scene_state == SCENE_STORY)
    {
        story_draw();
    }
    else if (scene_state == SCENE_RESULT)
    {
        result_draw();
    }
    else if (scene_state == SCENE_SETTING)
    {
        setting_draw();
    }
    al_flip_display();
}

void scene_init()
// 初始化遊戲
{
    // 初始化 Allegro
    printf("Initializing Allegro...\n");
    al_init();
    al_init_primitives_addon();

    // 初始化 audio
    al_install_audio();
    al_init_acodec_addon();

    // create event queue
    event_queue = al_create_event_queue();

    printf("Initializing Addons...\n");
    // 字型、圖片、音效
    al_init_font_addon();   // initialize the font addon
    al_init_ttf_addon();    // initialize the ttf (True Type Font) addon
    al_init_image_addon();  // initialize the image addon
    al_init_acodec_addon(); // initialize acodec addon

    printf("Initializing Inputs...\n");
    // 鍵盤、滑鼠、音效
    al_install_keyboard(); // install keyboard event
    al_install_mouse();    // install mouse event
    al_install_audio();    // install audio event

    // Create display
    display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
    al_set_window_position(display, 0, 0);
    al_set_window_title(display, title);
    // initialize the icon on the display
    // Icon
    ALLEGRO_BITMAP *icon = al_load_bitmap("./assets/image/icon.jpg");
    al_set_display_icon(display, icon);

    timer = al_create_timer(1.0 / FPS);

    // Register event
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(timer));

    al_init_font_addon(); // 初始化字體插件
    al_init_ttf_addon();  // 初始化 TTF (True Type Font) 插件

    srand(time(0));

    // 初始化文件
    printf("Loading resources...\n");
    load_resource();
}

void scene_begin()
// 遊戲（視窗）開始時
{
    printf("Game Starting...\n");
    // Game Window
    // Load sound
    al_reserve_samples(20);
    sample_instance = al_create_sample_instance(sample_hello);
    // Loop the song until the display closes
    // 快點來跟我去旅遊~
    // al_set_sample_instance_playmode(sample_instance, ALLEGRO_PLAYMODE_LOOP);
    al_restore_default_mixer();
    al_attach_sample_instance_to_mixer(sample_instance, al_get_default_mixer());
    // set the volume of instance
    al_set_sample_instance_gain(sample_instance, 1);
    al_play_sample_instance(sample_instance);
    al_start_timer(timer);
}

void scene_destroy()
// 遊戲結束時
{
    printf("Game Closing...\n");
    // Destroy
    al_destroy_event_queue(event_queue); // 清理並關閉事件佇列
    al_destroy_timer(timer);             // 清理並關閉計時器
    al_destroy_display(display);         // 清理並關閉顯示視窗

    destroy_resource();
}