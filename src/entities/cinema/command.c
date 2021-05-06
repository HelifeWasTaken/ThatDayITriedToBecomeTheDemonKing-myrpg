/*
** EPITECH PROJECT, 2021
** cinema
** File description:
** cine
*/

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
#include "myrpg/cinema.h"

void cinema_set(game_t *game, cinema_t *cine)
{
    sfView_setCenter(game->view,
        (sfVector2f){ cine->u.set.x, cine->u.set.y });
    set_game_view(game, game->view);
}

void cinema_move(game_t *game, cinema_t *cine)
{
    sfVector2f move = VEC2F(cine->u.move.x, cine->u.move.y);

    move.x /= 100;
    move.y /= 100;
    sfView_move(game->view, move);
    set_game_view(game, game->view);
}

void cinema_new_scene(game_t *game, cinema_t *cine)
{
    switch_to_world(game, cine->u.scene);
    get_game_state(game)->save.player_pos = VEC2F(0, 0);
}
