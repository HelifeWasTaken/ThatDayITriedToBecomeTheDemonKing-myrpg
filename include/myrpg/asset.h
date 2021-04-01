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

    #define MENU_BUTTON_SPT_W 192
    #define MENU_BUTTON_SPT_H 64
    #define MENU_BUTTON_RECT IRECT(0, 0, MENU_BUTTON_SPT_W, MENU_BUTTON_SPT_H)
<<<<<<< HEAD
    #define BUTTON_MENU_POS (int[]) {WINDOW_H / 3,\
        WINDOW_H / 2,  WINDOW_H / 1.5}

    #define QUIT_BUTTON_SPT "asset/menu/quit.png"
    #define PLAY_BUTTON_SPT "asset/menu/play.png"
    #define SETTING_BUTTON_SPT "asset/menu/setting.png"
=======

    #define BUTTON_MENU_POS (int[]) {WINDOW_H / 4,\
        WINDOW_H / 3,  WINDOW_H / 2}

    #define QUIT_BUTTON_SPT "asset/menu/quit_button.png"
    #define PLAY_BUTTON_SPT "asset/menu/play_button.png"
    #define SETTING_BUTTON_SPT "asset/menu/setting_button.png"
>>>>>>> 77e26e7fab2e5d9181faf54f23f8d939293d79ca

    #define ASSET_MENU_PATH (char *[]) {PLAY_BUTTON_SPT,\
        SETTING_BUTTON_SPT, QUIT_BUTTON_SPT}

    ///
    /// SETTINGS_MENU_DEFINE
    ///

    #define FONT "asset/title.ttf"
    #define ASSET_BAR "asset/setting/golden_rod.png"
    #define ASSET_SC "asset/setting/cursor.png"

    #define BACK_BUTTON "asset/setting/back_button.png"
    #define MUTE_BUTTON "asset/setting/select.png"

    #define SET_BACK "asset/setting/setting_background.png"

    #define ASSET_SETTING_PATH (char *[]) {BACK_BUTTON, \
        MUTE_BUTTON, MUTE_BUTTON, MUTE_BUTTON}

    /// ATH DEFINE
    ///
    #define CHAR_ICON "asset/ath/character.png"
    #define EQUIP_ICON "asset/ath/equipment.png"
    #define INVENTORY_ICON "asset/ath/inventory.png"
    #define QUEST_ICON "asset/ath/Quests-Icon.png"
    #define SKILL_ICON "asset/ath/skills.png"
    #define OPTION_ICON "asset/ath/option.png"

    #define ICON_RECT 100
    #define ATH_ICON (char *[]) {CHAR_ICON, EQUIP_ICON, INVENTORY_ICON,\
        QUEST_ICON, SKILL_ICON, OPTION_ICON}

<<<<<<< HEAD
    #define PLAYER_ATH "asset/ath/player_ath.png"
    #define PLAYER_ATH_W 410
    #define PLAYER_ATH_H 150
    #define PLAYER_ATH_POS_Y 860
=======
    #define PLAYER_ATH "asset/ath/player_ath_test.png"
    #define PLAYER_ATH_W 400
    #define PLAYER_ATH_H 250
    #define PLAYER_ATH_POS_Y 775
>>>>>>> 77e26e7fab2e5d9181faf54f23f8d939293d79ca

#endif