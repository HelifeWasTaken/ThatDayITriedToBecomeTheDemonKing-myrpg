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
    VIEW, DIALOGBOX, ATH, HERO
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

bool spawn_npc(game_t *game)
{
    npc_t *npc;
    entity_t *entity = create_entity(game, NPC);
    
    if (entity == NULL)
        return (false);
    npc = entity->instance;
    npc->name = "Grass";
    npc->messages = (char *[]){ "You can see the wind going through the leaves "
        "peacefully. There is a ladybug between the leaves, it flies quietly. "
        "Looking at the grass fills you with DETERMINATION.",
        "foo bar blablabla", NULL };
    npc->entity->pos = VEC2F(1280, 700);
    return (true);
}

int play_lifecycle(game_t *game)
{
    sfEvent event;

    if (init_play_lifecycle(game) == 84)
        return (84);
    if (!spawn_npc(game))
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
