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
#include "stdlib.h"

void create_player(game_t *game UNUSED, entity_t *entity)
{
    player_t *player = malloc(sizeof(player_t));
    sfIntRect rect = IRECT(0, 0, 9133, 379);
    sfTexture *texture = create_texture(game, "assets/sprite.png", &rect);

    player->entity = entity;
    player->clock = create_pausable_clock(game);
    player->sprite = create_sprite(texture, NULL);
    entity->instance = player;
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