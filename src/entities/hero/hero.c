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

void create_hero(game_t *game UNUSED, entity_t *entity)
{
    hero_t *hero = malloc(sizeof(hero_t));
    sfIntRect rect = IRECT(0, 0, 300, 400);
    sfTexture *texture = create_texture(game, "asset/hero/bard_movement.png", &rect);
    sfVector2u window = sfRenderWindow_getSize(game->window);

    hero->entity = entity;
    hero->animation_clock = create_pausable_clock(game);
    hero->movement_clock = create_pausable_clock(game);
    hero->sprite = create_sprite(texture, &IRECT(0, 0 , 100, 100));
    hero->entity->pos = VEC2F((window.x/2 - 50), (window.y/2 - 50));
    entity->instance = hero;
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