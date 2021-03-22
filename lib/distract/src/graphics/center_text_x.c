/*
** EPITECH PROJECT, 2020
** center_text
** File description:
** Source code
*/

#include "SFML/Graphics.h"

sfText *center_text_x(sfText *text, int start_x, int end_x)
{
    sfFloatRect bounds = sfText_getGlobalBounds(text);
    sfVector2f pos = sfText_getPosition(text);

    pos.x = (end_x / 2 - start_x) - (bounds.width / 2);
    sfText_setPosition(text, pos);
    return (text);
}