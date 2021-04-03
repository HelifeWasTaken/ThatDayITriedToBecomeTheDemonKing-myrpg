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
#include "myrpg/mapdata.h"

bool create_hero(game_t *game UNUSED, entity_t *entity)
{
    hero_t *hero = dcalloc(sizeof(hero_t), 1);
    sfIntRect rect = IRECT(0, 0, 135, 332);
    sfTexture *texture = create_texture(game, "asset/hero/bard_movement.png",
            &rect);
    entity_t *map_entity = GET_ENTITY(game, LAYER_MANAGER);
    layer_manager_t *layers = NULL;

    D_ASSERT(hero, NULL, "Hero could not be created", false);
    D_ASSERT(texture, NULL, "Tetxure could not be created", false);
    D_ASSERT(map_entity, NULL, "Layer could not be found", false);
    layers = map_entity->instance;
    hero->collision = layers;
    hero->entity = entity;
    hero->animation_clock = create_pausable_clock(game);
    hero->movement_clock = create_pausable_clock(game);
    hero->sprite = create_sprite(texture, &IRECT(0, 0 , 45, 83));
    hero->entity->pos = MAP_FILES[game->scene->world_id].p_info.pos;
    entity->instance = hero;
    hero->entity->z = MAP_FILES[game->scene->world_id].p_info.z_player;
    sfSprite_setScale(hero->sprite, VEC2F(0.5, 0.5));
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
    sfIntRect warp = {0};

    sfSprite_setPosition(hero->sprite, entity->pos);
    tick_pausable_clock(hero->animation_clock);
    tick_pausable_clock(hero->movement_clock);
    for (usize_t i = 0; i < hero->collision->warp_list->warp->size; i++) {
        warp = hero->collision->warp_list->warp->data[i].warpzone;
        if (sfIntRect_contains(&warp, hero->entity->pos.x, hero->entity->pos.y)) {
            switch_to_world(game, get_matching_world(
                hero->collision->warp_list->warp->data[i].warploader));
            return;
        }
    }
}

void draw_hero(game_t *game UNUSED, entity_t *entity)
{
    hero_t *hero = entity->instance;

    sfRenderWindow_drawSprite(game->window, hero->sprite, NULL);
    draw_rectangle_shape_global_bound(game->window, hero->sprite, false);
    PRINT_V2F(hero->entity->pos);
}
