/*
** EPITECH PROJECT, 2021
** collision
** File description:
** loader
*/

#include "myrpg/map/map.h"
#include "distract/resources.h"
#include "distract/util.h"
#include "distract/debug.h"

static const unsigned int TILESIZE_COLLSION = 16;

static void set_vao_collision_color(sfVertex *vao, bool collide)
{
    for (short int i = 0; i < 4; i++) {
        if (collide)
            vao[i].color = sfColor_fromRGBA(255, 0, 0, 125);
        else
            vao[i].color = sfColor_fromRGBA(0, 0, 0, 0);
    }
}

static void load_collision_layer_vtx(ig_layer_t *layer,
    layer_collision_data_t *data)
{
    sfVertex *vao = NULL;

    sfVertexArray_setPrimitiveType(data->vtx, sfQuads);
    sfVertexArray_resize(data->vtx, layer->width * layer->height * 4);
    for (usize_t i = 0; i < layer->width; i++) {
        for (usize_t j = 0; j < layer->height; j++) {
            vao = sfVertexArray_getVertex(data->vtx,
                (i + j * layer->width) * 4);
            vao[0].position = VEC2F(i * TILESIZE_COLLSION,
                j * TILESIZE_COLLSION);
            vao[1].position = VEC2F((i + 1) * TILESIZE_COLLSION,
                j * TILESIZE_COLLSION);
            vao[2].position = VEC2F((i + 1) * TILESIZE_COLLSION,
                (j + 1) * TILESIZE_COLLSION);
            vao[3].position = VEC2F(i * TILESIZE_COLLSION,
                (j + 1) * TILESIZE_COLLSION);
            set_vao_collision_color(vao, data->map[i + j * layer->width]);
        }
    }
}

static bool load_collision_layer_map(game_t *game, ig_layer_t *layer,
    layer_collision_data_t *data, usize_t i)
{
    D_ASSERT(layer->data.data, NULL, "Collision layer has"
        " no field data", false);
    data->z = i;
    data->size = layer->data.size;
    data->mapsize = VEC2U(layer->width, layer->height);
    data->map = dcalloc(sizeof(bool), data->size);
    D_ASSERT(data->map, NULL, "Failed to init layer", false);
    for (usize_t l = 0; l < data->size; l++) {
        if (layer->data.data[l] != false)
            data->map[l] = true;
    }
    data->vtx = create_vertex(game, layer->name);
    D_ASSERT(data->vtx, NULL, "Could not init vertex", false);
    load_collision_layer_vtx(layer, data);
    return (true);
}

bool load_collision_layer(game_t *game, ig_map_t *map,
    layer_collision_data_t *data)
{
    usize_t i = 0;

    for (; i < map->layers->size; i++) {
        if (estrcmp("collision", map->layers->data[i].name) == 0) {
            if (load_collision_layer_map(game,
                &map->layers->data[i], data, i) == false)
                return (false);
            break;
        }
    }
    if (i++ == map->layers->size) {
        print_error("Warning: Map layer does not have any collision layer");
        return (false);
    }
    for (; i < map->layers->size; i++) {
        if (estrcmp("collision", map->layers->data[i].name) == 0)
            print_error("Multiple unused collision layer found");
    }
    return (true);
}
