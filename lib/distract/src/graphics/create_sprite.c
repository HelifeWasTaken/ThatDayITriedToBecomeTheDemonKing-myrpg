/*
** EPITECH PROJECT, 2020
** create_sprite
** File description:
** Source code
*/

#include "SFML/Graphics.h"
#include "distract/debug.h"

sfSprite *create_sprite(sfTexture *texture, sfIntRect *rect)
{
    sfSprite *sprite = sfSprite_create();

    if (sprite == NULL) {
        print_error("Sprite could not be initted");
        return (NULL);
    }
    if (texture != NULL)
        sfSprite_setTexture(sprite, texture, sfFalse);
    if (rect != NULL)
        sfSprite_setTextureRect(sprite, *rect);
    return (sprite);
}