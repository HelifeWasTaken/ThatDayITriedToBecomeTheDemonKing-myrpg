/*
** EPITECH PROJECT, 2020
** view
** File description:
** Entity
*/

#include "stdlib.h"
#include "distract/game.h"
#include "distract/entity.h"
#include "distract/resources.h"
#include "distract/graphics.h"
#include "distract/debug.h"
#include "SFML/Window.h"
#include "SFML/Graphics.h"
#include "myrpg/entities.h"
#include "myrpg/asset.h"
#include "myrpg/define.h"
#include "distract/util.h"

bool create_view(game_t *game UNUSED, entity_t *entity)
{
    view_t *view = dcalloc(sizeof(view_t), 1);

    D_ASSERT(view, NULL, "view could not be init", false);
    view->entity = entity;
    view->view = sfView_createFromRect((sfFloatRect){0, 0,
        game->mode.width / 3.f, game->mode.height / 3.f});
    view->hud_view = sfView_createFromRect(FRECT(0, 0,
        game->mode.width, game->mode.height));
    entity->instance = view;
    return (true);
}

void set_view_type(game_t *game, view_t *view, view_type_t type)
{
    sfRenderWindow_setView(game->window, type == HUD_VIEW ? view->hud_view
        : view->view);
}

void destroy_view(game_t *game UNUSED, entity_t *entity)
{
    view_t *view = entity->instance;

    sfView_destroy(view->view);
    free(view);
}

void update_view(game_t *game UNUSED, entity_t *entity)
{
    entity_t *player_entity = NULL;
    view_t *view = entity->instance;

    if (view->hero == NULL) {
        player_entity = GET_ENTITY(game, HERO);
        view->hero = player_entity->instance;
        return;
    }
    sfView_setCenter(view->view, view->hero->entity->pos);
    set_view_type(game, view, WORLD_VIEW);
}
