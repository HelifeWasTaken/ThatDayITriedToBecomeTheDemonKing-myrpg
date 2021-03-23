/*
** EPITECH PROJECT, 2020
** menu
** File description:
** menu.c
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

void create_menu(game_t *game UNUSED, entity_t *entity)
{
    const sfVideoMode *window = sfVideoMode_getFullscreenModes(NULL);
    menu_t *menu = malloc(sizeof(menu_t));
    sfIntRect play_rect = IRECT(0, 0, PLAY_BUTON_SPT_W, PLAY_BUTON_SPT_H);
    sfTexture *menu_texture =
        create_texture(game, MAIN_MENU_BG,
        &IRECT(0, 0, window->width, window->height));
    sfTexture *play_texture =
        create_texture(game, PLAY_BUTON_SPT, &play_rect);

    menu->sprite = create_sprite(menu_texture, NULL);
    menu->play_sprite = create_sprite(play_texture, NULL);
    sfSprite_setPosition(menu->play_sprite,
        VEC2F(window->width/2, window->height/4));
    entity->instance = menu;
}

bool handle_menu_events(game_t *game UNUSED,
    entity_t *entity UNUSED, sfEvent *event UNUSED)
{
    menu_t *menu = entity->instance;
    sfVector2i mouse_pos = sfMouse_getPosition(NULL);
    sfFloatRect sprite_pos = sfSprite_getGlobalBounds(menu->play_sprite);

    if (sfFloatRect_contains(&sprite_pos, mouse_pos.x ,
        mouse_pos.y) == sfTrue) {
        sfSprite_setScale(menu->play_sprite, VEC2F(1.5, 1.5));
        return (true);
    } else
        sfSprite_setScale(menu->play_sprite, VEC2F(1, 1));
    return (false);
}

void draw_menu(game_t *game UNUSED, entity_t *entity)
{
    menu_t *menu = entity->instance;

    sfRenderWindow_drawSprite(game->window, menu->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, menu->play_sprite, NULL);
}

void destroy_menu(game_t *game UNUSED, entity_t *entity)
{
    menu_t *menu = entity->instance;

    sfSprite_destroy(menu->sprite);
    sfTexture_destroy(menu->texture);
    sfSprite_destroy(menu->play_sprite);
    sfTexture_destroy(menu->play_texture);
    free(menu);
}