/*
** EPITECH PROJECT, 2020
** texture
** File description:
** Source code
*/

#include "distract/game.h"
#include "distract/debug.h"
#include "distract/resources.h"
#include "SFML/Graphics.h"
#include "stdio.h"
#include "stdarg.h"

sfTexture *create_texture(game_t *game, char *filepath, sfIntRect *rect)
{
    resource_t *resource = get_resource(game, filepath);

    if (resource == NULL) {
        resource = create_resource(game, filepath, R_TEXTURE);
        if (resource == NULL)
            return (NULL);
        resource->texture = sfTexture_createFromFile(filepath, rect);
    }
    return (resource->texture);
}

void destroy_textures(int count, ...)
{
    va_list ap;
    sfTexture *texture;

    va_start(ap, count);
    for (int i = 0; i < count; i++) {
        texture = va_arg(ap, sfTexture *);
        sfTexture_destroy(texture);
    }
    va_end(ap);
}