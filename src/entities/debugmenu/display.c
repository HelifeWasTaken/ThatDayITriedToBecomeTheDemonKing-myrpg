/*
** EPITECH PROJECT, 2021
** keybind
** File description:
** Source code
*/

#include "distract/entity.h"
#include "distract/game.h"
#include "myrpg/entities.h"
#include "myrpg/map.h"
#include <SFML/Window/Event.h>
#include <SFML/Window/Keyboard.h>

static int count_entities(game_t *game)
{
    int count = 0;
    entity_t *entity = game->scene->entities;
    for (; entity != NULL; entity = entity->next)
        count++;
    return (count);
}

char *get_debug_message(game_t *game UNUSED, debugmenu_t *debugmenu)
{
    hero_t *hero = get_entity(game, HERO)->instance;
    sfVector2f pos = sfSprite_getPosition(hero->sprite);
    const vertex_map_t *map = &hero->collision->map;

    return (eformat(
        "Is game paused: %s\n"
        "Time: %.2f\n"
        "Player position: %.2f %.2f\n"
        "Vertex: %u, collisions: %u, textures: %u\n"
        "Map size: %u %u\n"
        "Player clock: { Anim time: %.2f, Move time: %.2f }\n"
        "Entities loaded: %d",
        game->is_paused ? "yes" : "no",
        debugmenu->clock->time,
        pos.x, pos.y,
        map->v_vertex.size, map->v_collision.size, map->v_texture.size,
        map->map_size.x, map->map_size.y,
        hero->animation_clock->time, hero->movement_clock->time,
        count_entities(game)
    ));
}