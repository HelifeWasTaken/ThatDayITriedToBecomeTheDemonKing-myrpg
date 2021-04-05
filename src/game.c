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

static const entity_info_t ENTITIES[] = {
    ENTITY(PLAYER, &create_player, &draw_player,
        &destroy_player, &update_player, &handle_player_events),
    ENTITY(SCROLL, &create_scroll_bar, &draw_scroll_bar,
        &destroy_scroll_bar, &update_scroll_bar,
        &handle_scroll_bar_events),
    ENTITY(MENU, &create_menu, &draw_menu,
        &destroy_menu, NULL, &handle_menu_events),
    ENTITY(ATH, &create_ath, &draw_ath,
        &destroy_ath, NULL, &handle_ath_events),
    ENTITY(LAYER_MANAGER, &create_layer_manager, NULL,
        &destroy_layer_manager, NULL, NULL),
    ENTITY(LAYER, &create_layer, &draw_layer,
        &destroy_layer, NULL, NULL),
    ENTITY(HERO, &create_hero, &draw_hero,
        &destroy_hero, &update_hero, NULL),
    ENTITY(VIEW, &create_view, NULL,
        &destroy_view, &update_view, NULL),
    ENTITY(SETTING, &create_settings, &draw_settings,
        &destroy_settings, &update_settings, &handle_settings_events),
    ENTITY(VFX_SC, &create_vfx_scroll, &draw_vfx_scroll,
        &destroy_vfx_scroll, &update_vfx_scroll, &handle_vfx_scroll_events),
    ENTITY(WARP, &create_warp, NULL, &destroy_warp, NULL, NULL),
    ENTITY(DEBUGMENU, &create_debugmenu, &draw_debugmenu,
            &destroy_debugmenu, &update_debugmenu, &handle_debugmenu_events)
};

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
    unsigned long size = ARRAY_SIZE(ENTITIES);

    for (unsigned long i = 0; i < size; i++) {
        if (!register_entity(game, &ENTITIES[i]))
            return (false);
    }
    return (true);
}

void configure_sound(game_t *game)
{
    parameters_t *param = malloc(sizeof(parameters_t) * 1);

    param->music_vol = 1;
    param->vfx_vol = 1;
    param->voice_vol = 1;
    param->music_muted = false;
    param->vfx_muted = false;
    param->voice_muted = false;
    game->state = param;
}

void configure_game(game_t *game)
{
    configure_window(game);
    register_scene(game, PLAY_SCENE, &play_lifecycle);
    register_scene(game, MENU_SCENE, &menu_lifecycle);
    register_scene(game, KEY_CONFIG, &key_lifecycle);
    register_scene(game, SETTING_SCENE, &setting_lifecycle);
    configure_sound(game);
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
