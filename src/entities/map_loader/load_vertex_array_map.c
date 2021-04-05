/*
** EPITECH PROJECT, 2021
** load_vertex_array_map
** File description:
** load
*/

#include "myrpg/map.h"
#include "distract/resources.h"
#include "SFML/Graphics.h"

static bool load_vertex_array_map_data(ig_map_t *map,
    struct iron_goat_layer *layer, struct vector_texture *textures,
    struct vector_vertex_array_data *vertexmap)
{
    if (load_vertex_array_map_get_tileset(map, layer,
                &vertexmap->tileset) == false)
        return (false);
    if (check_tileset_and_data(
        layer, &map->tilesets->data[vertexmap->tileset]) == false)
        return (false);
    load_vertex_data(textures->tileset[vertexmap->tileset],
        &MAP_RECT(map, textures, vertexmap->tileset),
        &(vertice_data_loader_t){vertexmap->vertex, layer->data.data,
        map->tilesets->data[vertexmap->tileset].firstgid});
    return (true);
}

static bool load_vertex_array_map_verticies(ig_map_t *map,
        struct vertex_array_map *self)
{
    self->v_vertex.size = map->layers->size;

    self->v_vertex.vec = ecalloc(sizeof(struct vector_vertex_array_data),
            map->layers->size);
    for (usize_t i = 0; i < self->v_vertex.size; i++) {
        self->v_vertex.vec[i].vertex = sfVertexArray_create();
        if (self->v_vertex.vec[i].vertex == NULL) {
            ASSERT("Vertex load", "Allocation error");
            return (false);
        }
        if (load_vertex_array_map_data(map, &map->layers->data[i],
                    &self->v_texture, &self->v_vertex.vec[i]) == false)
            return (false);
    }
    return (true);
}

static bool load_vertex_array_map_tilesets(game_t *game,
    ig_map_t *map, struct vector_texture *self, char const *pathfolder)
{
    char *file = NULL;

    self->size = map->tilesets->size;
    self->tileset = ecalloc(sizeof(sfTexture *), self->size);
    for (usize_t i = 0; i < self->size; i++) {
        file = ECONCAT(pathfolder, map->tilesets->data[i].image);
        if (file == NULL) {
            ASSERT("Vertex load", "Allocation error");
            return (false);
        }
        self->tileset[i] = create_texture(game, file, NULL);
        if (self->tileset[i] == NULL) {
            ASSERT("Vertex load", "Allocation error");
            return (false);
        }
        FREE(file);
    }
    return (true);
}

static bool load_collision_layer(ig_map_t *map,
    struct vertex_array_map *self)
{
    self->v_collision.size = map->layers->data[map->layers->size - 1].data.size;
    self->v_collision.layer = emalloc(sizeof(bool) * self->v_collision.size);
    if (self->v_collision.layer == NULL) {
        ASSERT("Vertex load", "Could not init collision layer");
        return (false);
    }
    for (usize_t i = 0; i < self->v_collision.size; i++) {
        self->v_collision.layer[i] = map->layers->data[
            map->layers->size - 1].data.data[i];
    }
    return (true);
}

bool load_vertex_array_map(game_t *game, ig_map_t *map,
    struct vertex_array_map *self, char const *pathfolder)
{
    if (pathfolder == false) {
        ASSERT("Vertex load", "File passed as argument was null");
        return (false);
    }
    self->map_size = (sfVector2u){map->width, map->height};
    if (load_collision_layer(map, self) == false)
        return (false);
    if (load_vertex_array_map_tilesets(game, map,
                &self->v_texture, pathfolder) == false)
        return (false);
    if (load_vertex_array_map_verticies(map, self) == false)
        return (false);
    self->states = DEFAULT_RENDERSTATE(NULL);
    return (true);
}
