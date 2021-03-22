/*
** EPITECH PROJECT, 2020
** game
** File description:
** Source code
*/

#include "distract/game.h"
#include "distract/window.h"
#include "distract/scene.h"
#include "distract/entity.h"
#include "distract/debug.h"
#include "myrpg/entities.h"
#include "myrpg/scenes.h"
#include "stdlib.h"

static void configure_window(game_t *game)
{
    game->mode = MODE(1280, 720, 32);
    game->window = create_standard_window(game->mode, "My RPG");
    sfRenderWindow_setFramerateLimit(game->window, 60);
}

static void configure_entities(game_t *game UNUSED)
{
    REGISTER_ENTITIES(game,
        &ENTITY(PLAYER, &create_player, &draw_player,
                        &destroy_player, &update_player, &handle_player_events)
    );
}

void configure_game(game_t *game)
{
    configure_window(game);
    register_scene(game, PLAY_SCENE, &play_lifecycle);
    register_scene(game, MENU_SCENE, &menu_lifecycle);
    configure_entities(game);
}

int load_game(void)
{
    int code = 0;
    game_t *game = create_game();

    if (game == NULL)
        return (84);
    configure_game(game);
    set_pending_scene(game, MENU_SCENE);
    do {
        code = load_pending_scene(game);
        if (code != 0)
            return (code);
    } while (has_pending_scene(game));
    free(game->state);
    destroy_game(game);
    return (code);
}