/*
** EPITECH PROJECT, 2020
** MY_RPG_PUBLIC
** File description:
** define.h
*/

#ifndef DEFINE_H
    #define DEFINE_H

    #include <SFML/Graphics.h>

    ///
    /// If true, enable debug menu when F2 is pressed
    ///
    #ifdef DEBUG
        #define ENABLE_DEBUG_MENU 1
    #else
        #define ENABLE_DEBUG_MENU 0
    #endif

    #define DRAW_SPRITE sfRenderWindow_drawSprite
    #define SET_SPRITE_POS sfSprite_setPosition

    #ifdef ENABLE_DEBUG_MENU
        #define IN_DEBUG_MENU(...) \
            (get_entity(game, DEBUGMENU) != NULL \
            && ((debugmenu_t *)get_entity(game, DEBUGMENU)->instance)->enabled \
            ? (__VA_ARGS__) : 0)
    # else
        #define IN_DEBUG_MENU(...) ((void)0)
    #endif // ENABLE_DEBUG_MENU

    ///
    /// in case of an AppImage, we need to patch the path using an environment
    /// variable to keep the behaviour consistent with the unpacked version
    ///
    #ifdef APPIMAGE
        #define SAVE_PATH getenv("SAVE_FILE")
    #else
        #define SAVE_PATH "save"
    #endif

    #define USAGE \
        " __       __            _______                      \n" \
        "/  \\     /  |          /       \\                      \n" \
        "$$  \\   /$$ | __    __ $$$$$$$  |  ______    ______   \n" \
        "$$$  \\ /$$$ |/  |  /  |$$ |__$$ | /      \\  /      \\ \n" \
        "$$$$  /$$$$ |$$ |  $$ |$$    $$< /$$$$$$  |/$$$$$$  |\n" \
        "$$ $$ $$/$$ |$$ |  $$ |$$$$$$$  |$$ |  $$ |$$ |  $$ |\n" \
        "$$ |$$$/ $$ |$$ \\__$$ |$$ |  $$ |$$ |__$$ |$$ \\__$$ |\n" \
        "$$ | $/  $$ |$$    $$ |$$ |  $$ |$$    $$/ $$    $$ |\n" \
        "$$/      $$/  $$$$$$$ |$$/   $$/ $$$$$$$/   $$$$$$$ |\n" \
        "             /  \\__$$ |          $$ |      /  \\__$$ |\n" \
        "              $$    $$/           $$ |      $$    $$/\n" \
        "               $$$$$$/            $$/        $$$$$$/\n" \
        "* Main Menu\n" \
        "    * Use your mouse to select an option\n" \
        "    * Left click to select it\n" \
        "* Movement in game\n" \
        "    * Use the Arrow keys to move\n" \
        "    * Use Space or Enter to interact with objects or PNJ\n" \
        "    * ESCAPE to open the pause menu and use" \
        " your mouse to move in the menu\n" \
        "* Fights\n" \
        "    * Use the mouse to chose an action\n" \
        "    * ENTER to select it\n"

#endif
