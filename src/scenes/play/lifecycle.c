/*
** EPITECH PROJECT, 2021
** lifecycle
** File description:
** Source code
*/
#include "distract/entity.h"
#include "distract/sound.h"
#include "erty/eprintf.h"
#include "myrpg/entities.h"
#include "myrpg/asset.h"
#include "distract/game.h"
#include "distract/entity.h"
#include "distract/resources.h"
#include "distract/debug.h"
#include "distract/util.h"

static const enum entity_type ENTITY_INITTER_PLAY[] = {
    VIEW, DIALOGBOX, ATH,
    LAYER_MANAGER, VIEW, ATH, HERO,
#if ENABLE_DEBUG_MENU
    DEBUGMENU
#endif
};

static const char *WORLD_FILES[] = {
    "asset/map_asset/map_files/map_village.json",
    "asset/map_asset/map_files/map_monde.json",
    "asset/map_asset/map_files/cattle.json",
    "asset/map_asset/map_files/forest_map.json",
    "asset/map_asset/map_files/desert.json"
};

static const char *WORLD_SONG[] = {
    "asset/song/village_audio_cut.ogg",
    "asset/song/travel_cut.ogg",
    "asset/song/castle_cut.ogg",
    "asset/song/forest_cut.ogg",
    "asset/song/desert_village_cut.ogg"
};

int init_play_lifecycle(game_t *game)
{
    set_game_view(game, sfView_createFromRect((sfFloatRect){0, 0,
        game->mode.width / 3.f, game->mode.height / 3.f}));
    for (unsigned int i = 0; i < ARRAY_SIZE(ENTITY_INITTER_PLAY); i++) {
        if (create_entity(game, ENTITY_INITTER_PLAY[i]) == NULL)
            return (84);
    }
    for (int i = 0; i < 5; i++)
        if (estrcmp(game->scene->world_file, WORLD_FILES[i]) == 0) {
            play_music(game, MUSIC, (char *)WORLD_SONG[i]);
            return (0);
        }
    return (0);
}

int play_lifecycle(game_t *game)
{
    sfEvent event;

    eprintf("LOADED GAME SCENE\n");
    if (init_play_lifecycle(game) == 84)
        return (84);
    while (is_scene_updated(game)) {
        while (sfRenderWindow_pollEvent(game->window, &event))
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(game->window);
            else
                transmit_event_to_scene(game, &event);
        update_scene(game);
        sfRenderWindow_clear(game->window, sfBlack);
        draw_scene(game);
        sfRenderWindow_display(game->window);
    }
    destroy_scene(game, true);
    return (0);
}