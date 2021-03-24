/*
** EPITECH PROJECT, 2020
** MY_RPG_PUBLIC
** File description:
** asset.h
*/

#ifndef  ASSET_H
#define  ASSET_H
    #include "distract/def.h"

    ///
    /// MAIN_MENU_DEFINE
    ///
    #define MAIN_MENU_BG "asset/menu/menu_background_test.png"
    #define MAIN_MENU_BG_W 1280
    #define MAIN_MENU_BG_H 720
    #define MENU_BG_RECT(window) IRECT(0, 0, window->width, window->height)

    #define MENU_BUTTON_SPT_W 300
    #define MENU_BUTTON_SPT_H 129
    #define MENU_BUTTON_RECT IRECT(0, 0, MENU_BUTTON_SPT_W, MENU_BUTTON_SPT_H)
    #define BUTTON_MENU_POS (int[]) {window->height / 3, window->height / 2,  window->height / 1.5}
    
    #define QUIT_BUTTON_SPT "asset/menu/quit.png"
    #define PLAY_BUTTON_SPT "asset/menu/play.png"
    #define SETTING_BUTTON_SPT "asset/menu/setting.png"

    #define ASSET_MENU_PATH (char *[]) {PLAY_BUTTON_SPT, SETTING_BUTTON_SPT, QUIT_BUTTON_SPT}

#endif