/*
** EPITECH PROJECT, 2021
** hero_battle_rand
** File description:
** Source code
*/
#include "distract/game.h"
#include "distract/scene.h"
#include "erty/string/ecstring.h"
#include "myrpg/scenes.h"
#include "myrpg/entities.h"
#include "myrpg/state.h"
#include <SFML/Graphics/View.h>
#include <stdlib.h>

void trigger_battle_rand(game_t *game, hero_t *hero)
{
    bool is_scene_attackable = (
        estrcmp(game->scene->world_file,
            "asset/map_asset/map_files/map_monde.json") == 0
        || estrcmp(game->scene->world_file,
            "asset/map_asset/map_files/battle_desert.json") == 0
        || estrcmp(game->scene->world_file,
            "asset/map_asset/map_files/forest_map.json") == 0);

    if (hero->animation_clock->time > 0.01f
        && rand() % 250 == 0
        && is_scene_attackable && hero->cannot_be_attacked == false)
        start_battle(game, -1);
}