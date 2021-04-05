/*
** EPITECH PROJECT, 2020
** layer
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

bool create_layer(game_t *game UNUSED, entity_t *entity)
{
    layer_t *layer = dcalloc(sizeof(layer_t), 1);
    entity_t *managerentity = get_entity(game, LAYER_MANAGER);

    D_ASSERT(managerentity, NULL, "null", false);
    layer->manager = managerentity->instance;
    D_ASSERT(layer, NULL, "Layer could not be initted", false);
    layer->entity = entity;
    entity->instance = layer;
    layer->id = layer->manager->layers_count++;
    entity->z = layer->id;
    return (true);
}

void destroy_layer(game_t *game UNUSED, entity_t *entity)
{
    layer_t *layer = entity->instance;

    free(layer);
}

void draw_layer(game_t *game UNUSED, entity_t *entity)
{
    layer_t *layer = entity->instance;
    vertex_map_t *map = &layer->manager->map;
    usize_t tilesetid = map->v_vertex.vec[layer->id].tileset;

    map->states.texture = map->v_texture.tileset[tilesetid];
    if (layer->id == map->v_vertex.size - 1) {
        IN_DEBUG_MENU(
            sfRenderWindow_drawVertexArray(game->window,
                map->v_vertex.vec[layer->id].vertex, &map->states)
        );
        return;
    }
    sfRenderWindow_drawVertexArray(game->window,
        map->v_vertex.vec[layer->id].vertex, &map->states);
}
