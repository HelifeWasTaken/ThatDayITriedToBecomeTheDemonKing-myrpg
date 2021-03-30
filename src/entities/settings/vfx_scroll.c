/*
** EPITECH PROJECT, 2020
** vfx_scroll
** File description:
** Entity
*/

#include "stdlib.h"
#include "distract/game.h"
#include "distract/entity.h"
#include "distract/resources.h"
#include "distract/graphics.h"
#include "SFML/Window.h"
#include "SFML/Graphics.h"
#include "myrpg/entities.h"
#include "myrpg/asset.h"
#include "myrpg/define.h"
#include "myrpg/parameters.h"


void create_vfx_scroll(game_t *game UNUSED, entity_t *entity)
{
    vfx_scroll_t *vfx_scroll = malloc(sizeof(vfx_scroll_t) * 1);
    sfTexture *texture = create_texture(game, ASSET_BAR, NULL);
    //parameters_t *param = game->state;
    //sfFloatRect pos;
    //sfFloatRect pos_sc;

    vfx_scroll->sprite_bar = create_sprite(texture, NULL);
    texture = create_texture(game, ASSET_SC, NULL);
    vfx_scroll->scrolin = create_sprite(texture, NULL);
    vfx_scroll->entity = entity;
    vfx_scroll->clock = create_pausable_clock(game);
    sfSprite_setScale(vfx_scroll->sprite_bar, VEC2F(4, 3));
    sfSprite_setPosition(vfx_scroll->sprite_bar, VEC2F(500,500));
    //pos = sfSprite_getGlobalBounds(vfx_scroll->sprite_bar);
    //pos_sc = sfSprite_getGlobalBounds(vfx_scroll->scrolin);
    sfSprite_setScale(vfx_scroll->scrolin, VEC2F(2, 2));
    //sfSprite_setPosition(vfx_scroll->scrolin, VEC2F(pos.left + param->vfx_vol * pos.width / 2, pos.top - (pos_sc.height) + pos.height / 2));
    entity->instance = vfx_scroll;
}

void destroy_vfx_scroll(game_t *game UNUSED, entity_t *entity)
{
    vfx_scroll_t *vfx_scroll = entity->instance;

    sfSprite_destroy(vfx_scroll->sprite_bar);
    sfSprite_destroy(vfx_scroll->scrolin);
    destroy_pausable_clock(vfx_scroll->clock);
    free(vfx_scroll);
}

void update_vfx_scroll(game_t *game UNUSED, entity_t *entity)
{
    vfx_scroll_t *vfx_scroll = entity->instance;
    parameters_t *param = game->state;
    //sfFloatRect bar = sfSprite_getGlobalBounds(vfx_scroll->sprite_bar);
    //sfFloatRect sc = sfSprite_getGlobalBounds(vfx_scroll->scrolin);

    //sfSprite_setPosition(vfx_scroll->scrolin, VEC2F(bar.left + param->vfx_vol * (bar.width / 2), bar.top - (sc.height / 2) + bar.height / 2));
    printf("%f\n", param->vfx_vol);
    //param->vfx_vol = ((((sc.left - bar.left)) / 2) / 100);
    tick_pausable_clock(vfx_scroll->clock);
}

void draw_vfx_scroll(game_t *game UNUSED, entity_t *entity)
{
    vfx_scroll_t *vfx_scroll = entity->instance;

    sfRenderWindow_drawSprite(game->window, vfx_scroll->sprite_bar, NULL);
    sfRenderWindow_drawSprite(game->window, vfx_scroll->scrolin, NULL);
}

bool handle_vfx_scroll_events(game_t *game UNUSED,
    entity_t *entity UNUSED, sfEvent *event UNUSED)
{
    vfx_scroll_t *vfx_scroll = entity->instance;
    sfFloatRect scrollin = sfSprite_getGlobalBounds(vfx_scroll->sprite_bar);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);

    if (sfFloatRect_contains(&scrollin, mouse.x, mouse.y)) {
        return (fonc_scroll_vfx(game, entity));
    }
    return (false);
}