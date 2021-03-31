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
    entity_t *player_entity = NULL;

    D_ASSERT(view, NULL, "view could not be init", false);
    view->entity = entity;
    player_entity = GET_ENTITY(game, HERO);
    D_ASSERT(player_entity, NULL, "could not get hero info in view", false);
    view->hero = player_entity->instance;
    view->view = sfView_createFromRect((sfFloatRect){0, 0, game->mode.width / 1.75f, game->mode.height / 1.75f});
    sfView_setCenter(view->view, view->hero->entity->pos);
    entity->instance = view;
    return (true);
}

void destroy_view(game_t *game UNUSED, entity_t *entity)
{
    view_t *view = entity->instance;

    sfView_destroy(view->view);
    free(view);
}

void update_view(game_t *game UNUSED, entity_t *entity)
{
    view_t *view = entity->instance;

    sfView_setCenter(view->view, view->hero->entity->pos);
    sfRenderWindow_setView(game->window, view->view);
}