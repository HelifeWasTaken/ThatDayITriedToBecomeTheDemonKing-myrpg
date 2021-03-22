/*
** EPITECH PROJECT, 2020
** center_text
** File description:
** Source code
*/

#include "SFML/Graphics.h"

sfText *center_text_y(sfText *text, int start_y, int end_y)
{
    sfFloatRect bounds = sfText_getGlobalBounds(text);
    sfVector2f pos = sfText_getPosition(text);

    pos.y = ((end_y - start_y) / 2 + start_y) - (bounds.height / 2);
    sfText_setPosition(text, pos);
    return (text);
}