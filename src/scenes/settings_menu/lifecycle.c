/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** lifecycle
*/

#include "distract/entity.h"
#include "myrpg/entities.h"
#include "distract/game.h"
#include "distract/entity.h"
#include "distract/resources.h"

int setting_lifecycle(game_t *game)
{
    sfEvent event;

    create_entity(game, VFX_SC);
    create_entity(game, SETTING);
    while (is_scene_updated(game)) {
        while (sfRenderWindow_pollEvent(game->window, &event))
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(game->window);
            else
                transmit_event_to_scene(game, &event);
        update_scene(game);
        sfRenderWindow_clear(game->window, sfWhite);
        draw_scene(game);
        sfRenderWindow_display(game->window);
    }
    destroy_scene(game, true);
    return (0);
}