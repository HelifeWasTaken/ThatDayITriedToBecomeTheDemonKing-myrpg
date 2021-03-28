/*
** EPITECH PROJECT, 2020
** game
** File description:
** Source code
*/

#include "distract/game.h"
#include "distract/window.h"
#include "distract/scene.h"
#include "myrpg/asset.h"
#include "distract/entity.h"
#include "distract/debug.h"
#include "myrpg/entities.h"
#include "myrpg/scenes.h"
#include "stdlib.h"

static bool configure_window(game_t *game)
{
    game->mode = MODE(WINDOW_W, WINDOW_H, 32);
    game->window = create_standard_window(game->mode, "My RPG");
    if (!game->window) {
        print_error("Could not init window");
        return (false);
    }
    sfRenderWindow_setFramerateLimit(game->window, 60);
    return (true);
}

static bool configure_entities(game_t *game UNUSED)
{
    return (REGISTER_ENTITIES(game,
        &ENTITY(PLAYER, &create_player, &draw_player,
                        &destroy_player, &update_player, &handle_player_events),
        &ENTITY(SCROLL, &create_scroll_bar, &draw_scroll_bar,
                &destroy_scroll_bar, &update_scroll_bar,
                    &handle_scroll_bar_events),
        &ENTITY(MENU, &create_menu, &draw_menu,
                &destroy_menu, NULL, &handle_menu_events),
        &ENTITY(ATH, &create_ath, &draw_ath,
                &destroy_ath, NULL, &handle_ath_events)
    ));
}

void configure_game(game_t *game)
{
    configure_window(game);
    register_scene(game, PLAY_SCENE, &play_lifecycle);
    register_scene(game, MENU_SCENE, &menu_lifecycle);
    register_scene(game, KEY_CONFIG, &key_lifecycle);
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