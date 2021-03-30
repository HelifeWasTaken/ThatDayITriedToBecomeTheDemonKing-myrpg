/*
** EPITECH PROJECT, 2020
** MY_RPG_PUBLIC
** File description:
** hero.c
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
#include "myrpg/define.h"
#include "stdlib.h"
#include "distract/debug.h"

bool create_hero(game_t *game UNUSED, entity_t *entity)
{
    hero_t *hero = malloc(sizeof(hero_t));
    sfIntRect rect = IRECT(0, 0, 1200, 400);
    sfTexture *texture = create_texture(game, "asset/hero/bard.png", &rect);
    sfVector2u window = sfRenderWindow_getSize(game->window);
    //entity_t *map_entity = GET_ENTITY(game, LAYER);
    //layer_t *layers = NULL;

    D_ASSERT(hero, NULL, "Hero could not be created", false);
    D_ASSERT(texture, NULL, "Tetxure could not be created", false);
    //D_ASSERT(map_entity, NULL, "Layer could not be found", false);
    //layers = map_entity->instance;
    //hero->collison = layers->map.v_collision.layer;
    hero->collison = NULL;
    hero->entity = entity;
    hero->animation_clock = create_pausable_clock(game);
    hero->movement_clock = create_pausable_clock(game);
    hero->sprite = create_sprite(texture, &IRECT(0, 0 , 100, 100));
    hero->entity->pos = VEC2F((window.x/2 - 50), (window.y/2 - 50));
    entity->instance = hero;
    return (true);
}

void destroy_hero(game_t *game UNUSED, entity_t *entity)
{
    hero_t *hero = entity->instance;

    sfSprite_destroy(hero->sprite);
    destroy_pausable_clock(hero->animation_clock);
    destroy_pausable_clock(hero->movement_clock);
    free(hero);
}

void update_hero(game_t *game UNUSED, entity_t *entity UNUSED)
{
    hero_t *hero = entity->instance;

    sfSprite_setPosition(hero->sprite, entity->pos);
    tick_pausable_clock(hero->animation_clock);
    tick_pausable_clock(hero->movement_clock);
}

void draw_hero(game_t *game UNUSED, entity_t *entity)
{
    hero_t *hero = entity->instance;

    sfRenderWindow_drawSprite(game->window, hero->sprite, NULL);
}
