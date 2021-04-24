/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** lifecycle
*/

#include "distract/animable.h"
#include "distract/game.h"
#include "distract/entity.h"
#include "distract/resources.h"
#include "myrpg/entities.h"
#include "myrpg/state.h"
#include "myrpg/asset.h"
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Sprite.h>

int battle_lifecycle(game_t *game)
{
    sfEvent event;

    set_game_view(game, sfView_createFromRect((sfFloatRect){0, 0,
        game->mode.width / 3.f, game->mode.height / 3.f}));
    create_entity(game, BATTLEMANAGER);
    create_entity(game, BATTLEHUD);
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