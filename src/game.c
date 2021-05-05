/*
** EPITECH PROJECT, 2020
** game
** File description:
** Source code
*/

#include "distract/game.h"
#include "distract/util.h"
#include "distract/window.h"
#include "distract/scene.h"
#include "myrpg/asset.h"
#include "distract/entity.h"
#include "distract/debug.h"
#include "myrpg/entities.h"
#include "myrpg/scenes.h"
#include "myrpg/state.h"
#include "stdlib.h"
#include "myrpg/scenes.h"
#include "myrpg/util.h"
#include "distract/util.h"
#include "myrpg/cinema.h"

static const entity_info_t ENTITIES[] = {
    ENTITY(SCROLL, &create_scroll_bar, &draw_scroll_bar,
        &destroy_scroll_bar, &update_scroll_bar,
        &handle_scroll_bar_events),
    ENTITY(MENU, &create_menu, &draw_menu,
        &destroy_menu, NULL, &handle_menu_events),
    ENTITY(ATH, &create_ath, &draw_ath,
        &destroy_ath, &update_button_handler, &handle_ath_events),
    ENTITY(HERO, &create_hero, &draw_hero,
        &destroy_hero, &update_hero, NULL),
    ENTITY(VIEW, &create_view, NULL,
        &destroy_view, &update_view, NULL),
    ENTITY(SETTING, &create_settings, &draw_settings,
        &destroy_settings, &update_settings, &handle_settings_events),
    ENTITY(VFX_SC, &create_vfx_scroll, &draw_vfx_scroll,
        &destroy_vfx_scroll, &update_vfx_scroll, &handle_vfx_scroll_events),
    ENTITY(DIALOGBOX, &create_dialogbox, &draw_dialogbox,
        &destroy_dialogbox, &update_dialogbox, &handle_dialogbox_events),
    ENTITY(DIALOG, &create_dialog, &draw_dialog,
        &destroy_dialog, &update_dialog, &handle_dialog_events),
    ENTITY(WARP, &create_warpzone, &update_warpzone,
        &destroy_warpzone, NULL, NULL),
    ENTITY(DEBUGMENU, &create_debugmenu, &draw_debugmenu,
        &destroy_debugmenu, &update_debugmenu, &handle_debugmenu_events),
    ENTITY(LAYER_MANAGER, &create_map_loader, NULL,
        &destroy_map_loader, NULL, NULL),
    ENTITY(COLLISION_LAYER, &create_layer_collision,
        &draw_layer_collision, &destroy_layer_collision, NULL, NULL),
    ENTITY(OBJECT_LAYER_MANAGER, &create_layer_object_manager,
        NULL, &destroy_layer_object_manager, NULL, NULL),
    ENTITY(TILESET_LAYER_MANAGER, &create_tileset_manager,
        NULL, &destroy_tileset_manager, NULL, NULL),
    ENTITY(TILESET_LAYER, &create_layer_tileset, &draw_layer_tileset,
        &destroy_layer_tileset, NULL, NULL),
    ENTITY(INVENTORY, &create_inventory, &draw_inventory,
            &destroy_inventory, &update_inventory, &handle_inventory_events),
    ENTITY(SELECT, &create_mute_button, &draw_mute_button,
        &destroy_mute_button, &update_mute_button, &handle_mute_button_events),

    ENTITY(BATTLEHUD, &create_battlehud, &draw_battlehud,
            &destroy_battlehud, &update_battlehud, &handle_battlehud_events),
    ENTITY(BATTLEMANAGER, &create_battlemanager, &draw_battlemanager,
            &destroy_battlemanager, &update_battlemanager,
            &handle_battlemanager_events),
    ENTITY(GUI_BUTTON, &create_button, &draw_button,
            &destroy_button, &update_button, &handle_button_events),
    ENTITY(GUI_LABEL, &create_label, &draw_label,
            &destroy_label, &update_label, NULL),
    ENTITY(PNJ, &create_pnj, &draw_pnj,
            &destroy_pnj, NULL, NULL),
    ENTITY(CINEMA, &create_cinema, NULL,
        &destroy_cinema, &update_cinema, NULL)
};

static bool configure_window(game_t *game)
{
    game->mode = MODE(WINDOW_W, WINDOW_H, 32);
    game->window = create_standard_window(game->mode, "My RPG");
    game->view = sfView_create();
    game->gui_view = sfView_createFromRect(FRECT(0, 0, WINDOW_W, WINDOW_H));
    game->renderer = DEFAULT_RENDERSTATE(NULL);
    if (!game->window || !game->view || !game->gui_view) {
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

void configure_state(game_t *game)
{
    game_state_t *state = dcalloc(sizeof(game_state_t), 1);

    state->params.music_vol = 1;
    state->params.vfx_vol = 1;
    state->params.voice_vol = 1;
    state->params.music_muted = false;
    state->params.vfx_muted = false;
    state->params.voice_muted = false;
    for (int index = 0; index != 15; index++) {
        state->save.item[index].type = EMPTY;
        state->save.item[index].id = 0;
        state->save.item[index].nb = 0;
    }
    state->save.item[0].type = ITEM;
    state->save.item[0].id = 1;
    state->save.item[0].type = 1;
    state->save.player_hp = 100;
    state->save.player_lv = 1;
    state->save.player_mana = 30;
    game->state = state;
}

void configure_game(game_t *game)
{
    configure_window(game);
    register_scene(game, PLAY_SCENE, &play_lifecycle);
    register_scene(game, MENU_SCENE, &menu_lifecycle);
    register_scene(game, KEY_CONFIG, &key_lifecycle);
    register_scene(game, SETTING_SCENE, &setting_lifecycle);
    register_scene(game, BATTLE_SCENE, &battle_lifecycle);
    configure_state(game);
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
    game->scene->world_file = "asset/map_asset/map_files/map_village.json";
    get_game_state(game)->save.player_pos = VEC2F(1535, 42);
    do {
        code = load_pending_scene(game);
        if (code != 0)
            return (code);
    } while (has_pending_scene(game));
    free(game->state);
    destroy_game(game);
    return (code);
}
