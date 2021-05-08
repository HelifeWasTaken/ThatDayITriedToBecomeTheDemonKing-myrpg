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
    #define ENABLE_DEBUG_MENU 0

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

#endif
