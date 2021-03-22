/*
** EPITECH PROJECT, 2020
** create_sprite
** File description:
** Source code
*/

#include "SFML/Graphics.h"

sfSprite *create_sprite(sfTexture *texture, sfIntRect *rect)
{
    sfSprite *sprite = sfSprite_create();

    if (texture != NULL)
        sfSprite_setTexture(sprite, texture, sfFalse);
    if (rect != NULL)
        sfSprite_setTextureRect(sprite, *rect);
    return (sprite);
}