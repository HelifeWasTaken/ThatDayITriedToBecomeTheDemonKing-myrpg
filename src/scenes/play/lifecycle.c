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
#include <SFML/System/Vector2.h>

int play_lifecycle(game_t *game)
{
    sfEvent event;

    if (create_entity(game, VIEW) == NULL)
        return (84);
    if (create_entity(game, DIALOGBOX) == NULL)
        return (84);
    if (create_entity(game, ATH) == NULL)
        return (84);
    if (create_entity(game, LAYER) == NULL)
        return (84);
    if (create_entity(game, HERO) == NULL)
        return (84);
    npc_t *npc = create_entity(game, NPC)->instance;
    npc->name = "Grass";
    npc->messages = (char *[]){ "You can see the wind going through the leaves "
        "peacefully. There is a ladybug between the leaves, it flies quietly. "
        "Looking at the grass fills you with DETERMINATION.",
        "foo bar blablabla", NULL };
    npc->entity->pos = (sfVector2f) { 1280, 800 };
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
