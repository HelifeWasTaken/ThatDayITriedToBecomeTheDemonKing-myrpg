/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** lifecycle
*/

#include "distract/animable.h"
#include "distract/debug.h"
#include "distract/game.h"
#include "distract/entity.h"
#include "distract/resources.h"
#include "myrpg/entities.h"
#include "myrpg/state.h"
#include "myrpg/asset.h"
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Sprite.h>

static battlemanager_t *initialize_manager(game_t *game)
{
    entity_t *tmp;
    battlemanager_t *manager;
    battlehud_t *hud;

    set_game_view(game, sfView_createFromRect((sfFloatRect){0, 0,
        game->mode.width / 3.f, game->mode.height / 3.f}));
    tmp = create_entity(game, BATTLEMANAGER);
    D_ASSERT(tmp, NULL, "Cannot create battle manager", NULL);
    manager = tmp->instance;
    tmp = create_entity(game, BATTLEHUD);
    D_ASSERT(tmp, NULL, "Cannot create battle hud", NULL);
    hud = tmp->instance;
    hud->manager = manager;
    manager->hud = hud;
    return (manager);
}

int battle_lifecycle(game_t *game)
{
    sfEvent event;
    battlemanager_t *manager = initialize_manager(game);
    int exit_code;
    sfMusic *music = sfMusic_createFromFile("asset/song/battle_theme.ogg");

    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
    D_ASSERT(manager, NULL, "Cannot create battle", 84);
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
    sfMusic_destroy(music);
    exit_code = manager->exit_code;
    destroy_scene(game, true);
    return (exit_code);
}