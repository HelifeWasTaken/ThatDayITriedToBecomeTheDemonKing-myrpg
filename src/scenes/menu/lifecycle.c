/*
** EPITECH PROJECT, 2021
** lifecycle
** File description:
** Source code
*/

#include "distract/game.h"
#include "distract/entity.h"
#include "distract/resources.h"
#include "myrpg/entities.h"

void init_menu_scene(game_t *game, sfMusic *song)
{
    set_game_view(game, game->gui_view);
    sfMusic_setLoop(song, true);
    sfMusic_play(song);
}

int menu_lifecycle(game_t *game)
{
    sfEvent event;
    create_entity(game, MENU);
    sfMusic *song = sfMusic_createFromFile("asset/song/main_menu_theme.ogg");

    init_menu_scene(game, song);
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
    sfMusic_destroy(song);
    destroy_scene(game, true);
    return (0);
}
