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

static bool init_menu(game_t *game)
{
    sfMusic *song = NULL;

    if (create_entity(game, MENU) == NULL)
        return (false);
    song = create_music(game, "asset/song/main_menu_theme.ogg");
    if (song == NULL)
        return (false);
    sfMusic_setLoop(song, true);
    sfMusic_play(song);
    return (true);
}

int menu_lifecycle(game_t *game)
{
    sfEvent event;

    if (init_menu(game) == false)
        return (84);
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
