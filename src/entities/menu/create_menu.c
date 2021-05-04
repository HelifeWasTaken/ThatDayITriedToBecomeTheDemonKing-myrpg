/*
** EPITECH PROJECT, 2020
** MY_RPG_PUBLIC
** File description:
** create_menu.c
*/

#include "distract/game.h"
#include "distract/entity.h"
#include "distract/resources.h"
#include "distract/graphics.h"
#include "distract/window.h"
#include "SFML/Window.h"
#include "myrpg/asset.h"
#include "SFML/Graphics.h"
#include "myrpg/entities.h"
#include "stdlib.h"
#include "distract/util.h"

static bool create_background(game_t *game UNUSED,
    menu_t *menu)
{
    sfTexture *menu_texture =
        create_texture(game, MAIN_MENU_BG, &MENU_BG_RECT(window));
    sfTexture *button_texture = NULL;
    int pos_y = 3;

    menu->bg_sprite = create_sprite(menu_texture, NULL);
    if (menu_texture == NULL || menu->bg_sprite == NULL)
        return (false);
    for (int i = 0; i < 3; i++) {
        button_texture = create_texture(game, ASSET_MENU_PATH[i],
            &MENU_BUTTON_RECT);
        if (button_texture == NULL)
            return (false);
        menu->button_sprite[i] = create_sprite(button_texture, NULL);
        if (menu->button_sprite[i] == NULL)
            return (false);
        sfSprite_setScale(menu->button_sprite[i], VEC2F(2, 2));
        SET_SPRITE_POS(menu->button_sprite[i], VEC2F(BUTTON_MENU_POS[i],
            WINDOW_H / 1.5));
        pos_y--;
    }
    return (true);
}

bool create_menu(game_t *game UNUSED, entity_t *entity)
{
    menu_t *menu = dcalloc(sizeof(menu_t), 1);

    if (menu == false)
        return (false);
    if (create_background(game, menu) == false)
        return (false);
    entity->instance = menu;
    return (true);
}
