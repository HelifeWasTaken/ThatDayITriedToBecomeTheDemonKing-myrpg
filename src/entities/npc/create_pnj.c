/*
** EPITECH PROJECT, 2020
** pnj
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
#include "myrpg/pnj.h"

bool create_pnj(game_t *game UNUSED, entity_t *entity)
{
    pnj_t *pnj = dcalloc(sizeof(pnj_t), 1);
    sfIntRect rect = IRECT(0, 0, 9133, 379);
    sfTexture *texture = create_texture(game, "assets/sprite.png", &rect);

    D_ASSERT(pnj, NULL, "unable to create pnj struct", false)
    pnj->entity = entity;
    pnj->clock = create_pausable_clock(game);
    pnj->sprite = create_sprite(texture, NULL);
    entity->instance = pnj;
}

void destroy_pnj(game_t *game UNUSED, entity_t *entity)
{
    pnj_t *pnj = entity->instance;

    sfSprite_destroy(pnj->sprite);
    destroy_pausable_clock(pnj->clock);
    free(pnj);
}

void update_pnj(game_t *game UNUSED, entity_t *entity)
{
    pnj_t *pnj = entity->instance;

    sfSprite_setPosition(pnj->sprite, entity->pos);
    tick_pausable_clock(pnj->clock);
}

void draw_pnj(game_t *game UNUSED, entity_t *entity)
{
    pnj_t *pnj = entity->instance;

    sfRenderWindow_drawSprite(game->window, pnj->sprite, NULL);
}

bool handle_pnj_events(game_t *game UNUSED,
    entity_t *entity UNUSED, sfEvent *event UNUSED)
{
    return (false);
}