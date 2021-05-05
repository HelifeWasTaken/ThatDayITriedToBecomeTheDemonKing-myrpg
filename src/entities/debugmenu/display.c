/*
** EPITECH PROJECT, 2021
** keybind
** File description:
** Source code
*/

#include "distract/entity.h"
#include "distract/game.h"
#include "myrpg/entities.h"
#include "myrpg/map/map.h"
#include <SFML/Window/Event.h>
#include <SFML/Window/Keyboard.h>
#include "myrpg/util.h"

static int count_entities(game_t *game)
{
    int count = 0;

    entity_t *entity = game->scene->entities;
    for (; entity != NULL; entity = entity->next)
        count++;
    return (count);
}

char *get_debug_message(game_t *game UNUSED, debugmenu_t *debugmenu UNUSED)
{
    hero_t *hero = get_entity(game, HERO)->instance;

    count_entities(game);
    return (eformat("position: %f, %f\n"
        "map file: %s\n", hero->entity->pos.x, hero->entity->pos.y,
        game->scene->world_file));
    return (estrdup(""));
}
