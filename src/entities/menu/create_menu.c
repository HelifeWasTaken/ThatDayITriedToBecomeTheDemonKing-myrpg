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

static void create_background(game_t *game UNUSED,
    menu_t *menu, const sfVideoMode *window)
{
    sfTexture *menu_texture =
        create_texture(game, MAIN_MENU_BG, &MENU_BG_RECT(window));
    sfTexture * buton_texture;
    int pos_y = 3;

    menu->bg_sprite = create_sprite(menu_texture, NULL);
    for (int i = 0; i < 3; i++) {
        buton_texture = create_texture(game, ASSET_MENU_PATH[i],
            &MENU_BUTON_RECT);
        menu->buton_sprite[i] = create_sprite(buton_texture, NULL);
        SET_SPRITE_POS(menu->buton_sprite[i], VEC2F(window->width/2,
            window->height/pos_y));
        pos_y--;
    }
}

void create_menu(game_t *game UNUSED, entity_t *entity)
{
    const sfVideoMode *window = sfVideoMode_getFullscreenModes(NULL);
    menu_t *menu = malloc(sizeof(menu_t));
    
    create_background(game, menu, window);
    entity->instance = menu;
}