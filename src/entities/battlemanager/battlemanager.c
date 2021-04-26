/*
** EPITECH PROJECT, 2021
** battlemanager
** File description:
** Source code
*/

#include "distract/util.h"
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

bool create_battlemanager(game_t *game UNUSED, entity_t *entity)
{
    battlemanager_t *battlemanager = dcalloc(sizeof(battlemanager_t), 1);

    D_ASSERT(battlemanager, NULL, "Could not create battle manager", false)
    battlemanager->entity = entity;
    battlemanager->clock = create_pausable_clock(game);
    D_ASSERT(battlemanager->clock, NULL,
        "Could not create battle manager clock", false)
    if (create_battlemanager_enemies(game, battlemanager) < 0)
        return (false);
    if (create_battlemanager_friends(game, battlemanager) < 0)
        return (false);
    entity->instance = battlemanager;
    return (true);
}

void destroy_battlemanager(game_t *game UNUSED, entity_t *entity)
{
    battlemanager_t *battlemanager = entity->instance;

    for (int i = 0; i < battlemanager->enemies_count; i++)
        sfSprite_destroy(battlemanager->enemies[i].animable.info.sprite);
    for (int i = 0; i < battlemanager->friends_count; i++)
        sfSprite_destroy(battlemanager->friends[i].animable.info.sprite);
    destroy_pausable_clock(battlemanager->clock);
    free(battlemanager);
}

void update_battlemanager(game_t *game UNUSED, entity_t *entity)
{
    battlemanager_t *battlemanager = entity->instance;

    if (battlemanager->clock->time > 0.2f) {
        animate_battlemanager_sprites(battlemanager);
        battlemanager->clock->time = 0;
    }
    tick_pausable_clock(battlemanager->clock);
}

void draw_battlemanager(game_t *game UNUSED, entity_t *entity)
{
    battlemanager_t *battlemanager = entity->instance;

    for (int i = 0; i < battlemanager->enemies_count; i++)
        sfRenderWindow_drawSprite(game->window,
            battlemanager->enemies[i].animable.info.sprite, NULL);
    for (int i = 0; i < battlemanager->friends_count; i++)
        sfRenderWindow_drawSprite(game->window,
            battlemanager->friends[i].animable.info.sprite, NULL);
}

bool handle_battlemanager_events(game_t *game UNUSED,
    entity_t *entity UNUSED, sfEvent *event UNUSED)
{
    return (false);
}