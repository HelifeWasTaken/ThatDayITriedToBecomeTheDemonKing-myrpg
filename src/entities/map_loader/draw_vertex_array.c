/*
** EPITECH PROJECT, 2021
** draw_vertex_array_map
** File description:
** draw
*/

#include "myrpg/map.h"
#include "distract/debug.h"

void draw_map_layers_from_to(sfRenderWindow *window,
    struct vertex_array_map *self, size_t start, size_t end)
{
    if (start > self->v_vertex.size || end > self->v_vertex.size) {
        print_error("Tried to draw a invalid layer");
        return;
    }
    for (usize_t i = start; i <= end; i++) {
        sfRenderWindow_drawVertexArray(window, self->v_vertex.vec[i].vertex,
            &DEFAULT_RENDERSTATE(
                self->v_texture.tileset[self->v_vertex.vec[i].tileset]));
    }
}

void draw_all_vertex_map(sfRenderWindow *window,
    struct vertex_array_map *self)
{
    for (usize_t i = 0; i < self->v_vertex.size; i++) {
        sfRenderWindow_drawVertexArray(window, self->v_vertex.vec[i].vertex,
            &DEFAULT_RENDERSTATE(
                self->v_texture.tileset[self->v_vertex.vec[i].tileset]));
    }
}

void draw_map_layer(sfRenderWindow *window,
    struct vertex_array_map *self, size_t n)
{
    if (n > self->v_vertex.size) {
        print_error("Tried to draw a invalid layer");
        return;
    }
    sfRenderWindow_drawVertexArray(window, self->v_vertex.vec[n].vertex,
        &DEFAULT_RENDERSTATE(
            self->v_texture.tileset[self->v_vertex.vec[n].tileset]));
}