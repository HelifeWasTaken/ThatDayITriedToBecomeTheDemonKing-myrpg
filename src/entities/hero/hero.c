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
#include "distract/util.h"
#include "myrpg/util.h"

bool create_hero(game_t *game UNUSED, entity_t *entity)
{
    hero_t *hero = dcalloc(sizeof(hero_t), 1);
    sfIntRect rect = FULL_HERO_RECT;
    sfTexture *texture = create_texture(game, HERO_PATH,
            &rect);
    entity_t *map_entity = GET_ENTITY(game, LAYER);
    layer_t *layers = NULL;

    D_ASSERT(hero, NULL, "Hero could not be created", false);
    D_ASSERT(texture, NULL, "Tetxure could not be created", false);
    D_ASSERT(map_entity, NULL, "Layer could not be found", false);
    layers = map_entity->instance;
    hero->collision = layers;
    hero->entity = entity;
    hero->animation_clock = create_pausable_clock(game);
    hero->movement_clock = create_pausable_clock(game);
    hero->sprite = create_sprite(texture, &ONE_HERO_RECT);
    hero->entity->pos = VEC2F(500, 300);
    entity->instance = hero;
    hero->entity->z = 1000;
    sfSprite_setScale(hero->sprite, HERO_SCALE);
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
    IN_DEBUG_MENU(
        draw_rectangle_shape_global_bound(game->window, hero->sprite, false)
    );
}
