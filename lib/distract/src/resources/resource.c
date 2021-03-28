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
#include "distract/util.h"
#include "stdlib.h"

int distract_util_strcmp(char const *s1, char const *s2);

resource_t *create_resource(game_t *game, char *file, enum resource_type type)
{
    resource_t *resource = dmalloc(sizeof(resource_t));

    if (resource == NULL) {
        print_error("Failed to init resource");
        return (NULL);
    }
    resource->type = type;
    resource->path = file;
    if (hashmap_set(&game->scene->resources, file, resource) < 0) {
        free(resource);
        print_error("Failed to set in hashmap resource");
        return (NULL);
    }
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
            SAFE_RESOURCE_DESTROY(sfTexture_destroy, resource->texture);
            break;
        case R_SOUND:
            SAFE_RESOURCE_DESTROY(sfSound_destroy, resource->sound);
            break;
        case R_SOUND_BUFFER:
            SAFE_RESOURCE_DESTROY(sfSoundBuffer_destroy,
                resource->sound_buffer);
            break;
        case R_MUSIC:
            SAFE_RESOURCE_DESTROY(sfMusic_destroy, resource->music);
            break;
        case R_FONT:
            SAFE_RESOURCE_DESTROY(sfFont_destroy, resource->font);
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