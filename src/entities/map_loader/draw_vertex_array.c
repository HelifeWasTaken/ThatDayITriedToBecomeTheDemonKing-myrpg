/*
** EPITECH PROJECT, 2021
** draw_vertex_array_map
** File description:
** draw
*/

#include "myrpg/map.h"

void draw_vertex_map(sfRenderWindow *window, struct vertex_array_map *self)
{
    for (usize_t i = 0; i < self->v_vertex.size; i++) {
        sfRenderWindow_drawVertexArray(window, self->v_vertex.vec[i].vertex,
            &DEFAULT_RENDERSTATE(
                self->v_texture.tileset[self->v_vertex.vec[i].tileset]));
    }
}