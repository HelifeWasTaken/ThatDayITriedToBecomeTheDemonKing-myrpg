/*
** EPITECH PROJECT, 2020
** player
** File description:
** Entity
*/

#include "distract/game.h"
#include "distract/entity.h"
#include "distract/resources.h"
#include "distract/graphics.h"
#include "SFML/Window.h"
#include "SFML/Graphics.h"
#include "myrpg/entities.h"
#include "myrpg/asset.h"
#include "stdlib.h"
#include "distract/debug.h"

bool create_player(game_t *game UNUSED, entity_t *entity)
{
    player_t *player = malloc(sizeof(player_t));
    sfIntRect rect = IRECT(0, 0, 9133, 379);
    sfTexture *texture = create_texture(game, "assets/sprite.png", &rect);

    if (player == NULL || texture == NULL) {
        print_error("Player could not be initted");
        return (false);
    }
    player->entity = entity;
    if ((player->clock = create_pausable_clock(game)) == NULL)
        return (false);
    if ((player->sprite = create_sprite(texture, NULL)) == NULL)
        return (false);
    entity->instance = player;
    return (true);
}

void destroy_player(game_t *game UNUSED, entity_t *entity)
{
    player_t *player = entity->instance;

    sfSprite_destroy(player->sprite);
    destroy_pausable_clock(player->clock);
    free(player);
}

void update_player(game_t *game UNUSED, entity_t *entity)
{
    player_t *player = entity->instance;

    sfSprite_setPosition(player->sprite, entity->pos);
    tick_pausable_clock(player->clock);
}

void draw_player(game_t *game UNUSED, entity_t *entity)
{
    player_t *player = entity->instance;

    sfRenderWindow_drawSprite(game->window, player->sprite, NULL);
}

bool handle_player_events(game_t *game UNUSED,
    entity_t *entity UNUSED, sfEvent *event UNUSED)
{
    return (false);
}