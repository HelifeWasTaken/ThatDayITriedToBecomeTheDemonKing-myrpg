/*
** EPITECH PROJECT, 2020
** font
** File description:
** Source code
*/

#include "distract/game.h"
#include "distract/debug.h"
#include "distract/resources.h"
#include "SFML/Graphics.h"
#include "stdio.h"
#include "stdarg.h"

sfFont *create_font(game_t *game, char *filepath)
{
    resource_t *resource = get_resource(game, filepath);

    if (resource == NULL) {
        resource = create_resource(game, filepath, R_FONT);
        resource->font = sfFont_createFromFile(filepath);
    }
    return (resource->font);
}

void destroy_fonts(int count, ...)
{
    va_list ap;
    sfFont *font;

    va_start(ap, count);
    for (int i = 0; i < count; i++) {
        font = va_arg(ap, sfFont *);
        sfFont_destroy(font);
    }
    va_end(ap);
}