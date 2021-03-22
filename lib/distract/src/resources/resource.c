/*
** EPITECH PROJECT, 2020
** resource
** File description:
** Source code
*/

#include "distract/debug.h"
#include "distract/game.h"
#include "distract/resources.h"
#include "stdlib.h"

int distract_util_strcmp(char const *s1, char const *s2);

resource_t *create_resource(game_t *game, char *file, enum resource_type type)
{
    resource_t *resource = malloc(sizeof(resource_t));

    resource->prev = NULL;
    resource->next = game->scene->resources;
    resource->type = type;
    resource->path = file;
    if (resource->next != NULL)
        resource->next->prev = resource;
    game->scene->resources = resource;
    return (resource);
}

resource_t *get_resource(game_t *game, char *file)
{
    resource_t *resource = game->scene->resources;

    for (; resource != NULL; resource = resource->next) {
        if (resource->path != NULL
            && distract_util_strcmp(resource->path, file) == 0)
                return (resource);
    }
    return (NULL);
}

void destroy_resource_asset(resource_t *resource)
{
    switch(resource->type) {
        case R_TEXTURE:
            sfTexture_destroy(resource->texture);
            break;
        case R_SOUND:
            sfSound_destroy(resource->sound);
            break;
        case R_SOUND_BUFFER:
            sfSoundBuffer_destroy(resource->sound_buffer);
            break;
        case R_MUSIC:
            sfMusic_destroy(resource->music);
            break;
        case R_FONT:
            sfFont_destroy(resource->font);
            break;
        default:
            print_error("Unknown asset");
    }
}

void destroy_resource(game_t *game, resource_t *resource)
{
    if (resource == NULL)
        return;
    if (resource->prev != NULL)
        resource->prev->next = resource->next;
    if (resource->next != NULL)
        resource->next->prev = resource->prev;
    if (game->scene->resources == resource) {
        game->scene->resources = resource->next;
    }
    destroy_resource_asset(resource);
    free(resource);
}

void destroy_resource_by_name(game_t *game, char *file)
{
    destroy_resource(game, get_resource(game, file));
}