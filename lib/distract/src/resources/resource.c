/*
** EPITECH PROJECT, 2020
** resource
** File description:
** Source code
*/

#include "distract/debug.h"
#include "distract/game.h"
#include "distract/resources.h"
#include "distract/hashmap.h"
#include "stdlib.h"

int distract_util_strcmp(char const *s1, char const *s2);

resource_t *create_resource(game_t *game, char *file, enum resource_type type)
{
    resource_t *resource = malloc(sizeof(resource_t));

    if (resource == NULL)
        return (NULL);
    resource->type = type;
    resource->path = file;
    hashmap_set(&game->scene->resources, file, resource);
    return (resource);
}

resource_t *get_resource(game_t *game, char *file)
{
    return (hashmap_get(game->scene->resources, file));
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
    hashmap_unset(&game->scene->resources, resource->path);
    destroy_resource_asset(resource);
    free(resource);
}

void destroy_resource_by_name(game_t *game, char *file)
{
    destroy_resource(game, get_resource(game, file));
}