/*
** EPITECH PROJECT, 2021
** lifecycle
** File description:
** Source code
*/
#include "distract/entity.h"
#include "myrpg/entities.h"
#include "distract/game.h"
#include "distract/entity.h"
#include "distract/resources.h"
#include "distract/debug.h"

static const enum entity_type ENTITY_INITTER_PLAY[] = {
    ATH, HERO, VIEW
};

int init_play_lifecycle(game_t *game)
{
    if (generate_map(game) == false)
        return (84);
    for (unsigned int i = 0; i < ARRAY_SIZE(ENTITY_INITTER_PLAY); i++) {
        if (create_entity(game, ENTITY_INITTER_PLAY[i]) == NULL)
            return (84);
    }
    return (0);
}

int play_lifecycle(game_t *game)
{
    sfEvent event;

    if (init_play_lifecycle(game) == 84)
        return (84);
    #if ENABLE_DEBUG_MENU
        create_entity(game, DEBUGMENU);
    #endif
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
