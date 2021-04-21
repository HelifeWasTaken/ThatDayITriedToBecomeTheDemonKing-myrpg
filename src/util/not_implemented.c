/*
** EPITECH PROJECT, 2021
** not_implemented
** File description:
** Source code
*/

#include "distract/sound.h"
#include "distract/entity.h"
#include "myrpg/asset.h"
#include <SFML/Graphics.h>

void not_implemented(game_t *game, entity_t *entity UNUSED)
{
    play_sound(game, MUSIC, "asset/song/what.ogg");
    sfRenderWindow_clear(game->window, sfGreen);
    sfRenderWindow_display(game->window);
    sfSleep((sfTime) { 2000000 });
    sfRenderWindow_clear(game->window, sfRed);
    sfRenderWindow_display(game->window);
    sfSleep((sfTime) { 2500000 });
    sfRenderWindow_clear(game->window, sfBlue);
    sfRenderWindow_display(game->window);
    sfSleep((sfTime) { 2000000 });
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_display(game->window);
    sfSleep((sfTime) { 2000000 });
    switch_to_scene(game, -1);
}