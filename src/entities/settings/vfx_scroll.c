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
#include "distract/debug.h"
#include "SFML/Window.h"
#include "SFML/Graphics.h"
#include "myrpg/entities.h"
#include "myrpg/asset.h"
#include "myrpg/define.h"
#include "myrpg/parameters.h"

bool create_vfx_scroll(game_t *game UNUSED, entity_t *entity)
{
    vfx_scroll_t *vfx_scroll = malloc(sizeof(vfx_scroll_t) * 1);

    D_ASSERT(vfx_scroll, NULL, "err malloc", false);
    vfx_scroll->text = init_text(game, entity);
    vfx_scroll->sprite_bar = init_scroll(game, entity);
    vfx_scroll->scrolin =  init_scrolin(game);
    D_ASSERT(vfx_scroll->text, NULL, "error txt", false);
    D_ASSERT(vfx_scroll->sprite_bar, NULL, "error sprite_bar", false);
    D_ASSERT(vfx_scroll->scrolin, NULL, "error scrollin", false);
    vfx_scroll->entity = entity;
    vfx_scroll->clock = create_pausable_clock(game);
    D_ASSERT(vfx_scroll->clock, NULL, "error clock", false);
    vfx_scroll->on_scroll = NULL;
    entity->instance = vfx_scroll;
    return (true);
}

void destroy_vfx_scroll(game_t *game UNUSED, entity_t *entity)
{
    vfx_scroll_t *vfx_scroll = entity->instance;

    sfSprite_destroy(vfx_scroll->sprite_bar);
    sfSprite_destroy(vfx_scroll->scrolin);
    destroy_pausable_clock(vfx_scroll->clock);
    sfText_destroy(vfx_scroll->text);
    free(vfx_scroll);
}

void update_vfx_scroll(game_t *game UNUSED, entity_t *entity)
{
    vfx_scroll_t *vfx_scroll = entity->instance;
    sfFloatRect pos = sfSprite_getGlobalBounds(vfx_scroll->sprite_bar);

    sfText_setPosition(vfx_scroll->text,
        VEC2F(pos.left, pos.top - (pos.height / 2)));
    tick_pausable_clock(vfx_scroll->clock);
}

void draw_vfx_scroll(game_t *game UNUSED, entity_t *entity)
{
    vfx_scroll_t *vfx_scroll = entity->instance;

    sfRenderWindow_drawSprite(game->window, vfx_scroll->sprite_bar, NULL);
    sfRenderWindow_drawSprite(game->window, vfx_scroll->scrolin, NULL);
    sfRenderWindow_drawText(game->window, vfx_scroll->text, NULL);
}

bool handle_vfx_scroll_events(game_t *game UNUSED,
        entity_t *entity UNUSED, sfEvent *event UNUSED)
{
    vfx_scroll_t *vfx_scroll = entity->instance;
    sfFloatRect scrollin = sfSprite_getGlobalBounds(vfx_scroll->sprite_bar);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);

    scrollin.left = scrollin.left + 100;
    scrollin.width = scrollin.width - 160;
    if (sfFloatRect_contains(&scrollin, mouse.x, mouse.y)) {
        return (fonc_scroll_vfx(game, entity));
    }
    return (false);
}
