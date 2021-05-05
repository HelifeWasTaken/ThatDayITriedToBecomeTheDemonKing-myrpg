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
#include "myrpg/state.h"

static const enum entity_type ENTITY_INITTER_PLAY[] = {
    VIEW, DIALOGBOX, ATH,
    INVENTORY,
    LAYER_MANAGER, HERO, PNJ,
#if ENABLE_DEBUG_MENU
    DEBUGMENU
#endif
};

bool init_music(game_state_t *state, game_t *game)
{
    char *file = NULL;

    if (load_property_string(state->map.properties, &file, "song",
        "could not load music") == false)
        return (false);
    play_music(game, MUSIC, file);
    return (true);
}

int init_play_lifecycle(game_t *game)
{
    game_state_t *state = game->state;

    set_game_view(game, sfView_createFromRect((sfFloatRect){0, 0,
        game->mode.width / 3.f, game->mode.height / 3.f}));
    D_ASSERT(load_map_from_file(game, &state->map), false,
            "Could not init map", 84)
    for (unsigned int i = 0; i < ARRAY_SIZE(ENTITY_INITTER_PLAY); i++)
        if (create_entity(game, ENTITY_INITTER_PLAY[i]) == NULL) {
            destroy_iron_goat_map(&state->map);
            return (84);
        }
    if (init_music(state, game) == false) {
        destroy_iron_goat_map(&state->map);
        return (84);
    }
    destroy_iron_goat_map(&state->map);
    return (0);
}

int play_lifecycle(game_t *game)
{
    sfEvent event;

    if (init_play_lifecycle(game) == 84)
        return (84);
    reset_game_events(game);
    while (is_scene_updated(game)) {
        while (sfRenderWindow_pollEvent(game->window, &event))
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(game->window);
            else
                transmit_event_to_scene(game, &event);
        update_scene(game);
        draw_scene(game);
        sfRenderWindow_display(game->window);
        sfRenderWindow_clear(game->window, sfBlack);
    }
    destroy_scene(game, true);
    return (0);
}
