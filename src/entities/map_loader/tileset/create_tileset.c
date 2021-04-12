/*
** EPITECH PROJECT, 2020
** layer_tileset
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

bool create_layer_tileset(game_t *game UNUSED, entity_t *entity)
{
    layer_tileset_t *layer_tileset = dcalloc(sizeof(layer_tileset_t), 1);
    layer_tileset_manager_t *manager =
        get_instance(game, TILESET_LAYER_MANAGER);

    D_ASSERT(manager, NULL, "Could not get tileset layer manager", false)
    D_ASSERT(layer_tileset, NULL, "Could not init layer tileset", false)
    layer_tileset->entity = entity;
    entity->instance = layer_tileset;
    layer_tileset->layer.texture =
        manager->tileset->data[manager->actual_layer].texture;
    layer_tileset->layer.vtx =
        manager->tileset->data[manager->actual_layer].vtx;
    entity->z = manager->tileset->data[manager->actual_layer].z;
    manager->actual_layer++;
    return (true);
}

void destroy_layer_tileset(game_t *game UNUSED, entity_t *entity)
{
    layer_tileset_t *layer_tileset = entity->instance;

    free(layer_tileset);
}

void draw_layer_tileset(game_t *game UNUSED, entity_t *entity)
{
    layer_tileset_t *layer_tileset = entity->instance;

    game->renderer.texture = layer_tileset->layer.texture;
    sfRenderWindow_drawVertexArray(game->window,
        layer_tileset->layer.vtx, &game->renderer);
}
