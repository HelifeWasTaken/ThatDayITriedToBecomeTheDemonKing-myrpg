/*
** EPITECH PROJECT, 2021
** keybind
** File description:
** Source code
*/

#include "distract/entity.h"
#include "distract/game.h"
#include "myrpg/entities.h"
#include <SFML/Window/Event.h>
#include <SFML/Window/Keyboard.h>

void handle_debug_keybind(game_t *game UNUSED,
    sfKeyEvent *key UNUSED, debugmenu_t *dbmenu)
{
    if (key->control && key->code == sfKeyP)
        game->is_paused = !game->is_paused;
    if (key->code == sfKeyEqual)
        dbmenu->hero->speed += (key->control) ? 0.1F : -0.1F;
    if (key->control && key->code == sfKeyR)
        switch_to_world(game, game->scene->world_id);
    if (key->control && key->code == sfKeyC)
        dbmenu->hero->disable_collision = !dbmenu->hero->disable_collision;
}