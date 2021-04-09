/*
** EPITECH PROJECT, 2021
** vertex
** File description:
** vertex
*/

#include "distract/resources.h"
#include "distract/debug.h"

sfVertexArray *create_vertex(game_t *game, char *filepath)
{
    resource_t *resource = get_resource(game, filepath);

    if (resource == NULL) {
        resource = create_resource(game, filepath, R_VERTEX);
        if (resource == NULL)
            return (NULL);
        if ((resource->vao = sfVertexArray_create()) == NULL)
            print_error("Failed to init vao");
    }
    return (resource->vao);
}
