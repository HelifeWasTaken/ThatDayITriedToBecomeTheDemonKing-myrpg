/*
** EPITECH PROJECT, 2020
** MY_RPG_PUBLIC
** File description:
** asset.h
*/

#ifndef  ASSET_H
#define  ASSET_H
    #include "distract/def.h"

    #define WINDOW_W 1920
    #define WINDOW_H 1080
    ///
    /// MAIN_MENU_DEFINE
    ///
    #define MAIN_MENU_BG "asset/menu/menu_background_test.png"
    #define MAIN_MENU_BG_W 1920
    #define MAIN_MENU_BG_H 1080
    #define MENU_BG_RECT(window) IRECT(0, 0, WINDOW_W, WINDOW_H)

    #define MENU_BUTTON_SPT_W 300
    #define MENU_BUTTON_SPT_H 129
    #define MENU_BUTTON_RECT IRECT(0, 0, MENU_BUTTON_SPT_W, MENU_BUTTON_SPT_H)
    #define BUTTON_MENU_POS (int[]) {WINDOW_H / 3,\
        WINDOW_H / 2,  WINDOW_H / 1.5}

    #define QUIT_BUTTON_SPT "asset/menu/quit.png"
    #define PLAY_BUTTON_SPT "asset/menu/play.png"
    #define SETTING_BUTTON_SPT "asset/menu/setting.png"

    #define ASSET_MENU_PATH (char *[]) {PLAY_BUTTON_SPT,\
        SETTING_BUTTON_SPT, QUIT_BUTTON_SPT}

    ///
    /// SETTINGS_MENU_DEFINE
    ///

    #define BACK_BUTTON "asset/menu/quit.png"
    #define MUTE_BUTTON "asset/menu/play.png"

    #define ASSET_SETTINGPATH (char *[]) {BACK_BUTTON, \
        MUTE_BUTTON}

#endif