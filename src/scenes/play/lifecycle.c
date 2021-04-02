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

int play_lifecycle(game_t *game)
{
    sfEvent event;

    if (!create_entity(game, ATH) || !create_entity(game, LAYER) ||
        !create_entity(game, HERO) || !create_entity(game, VIEW))
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
