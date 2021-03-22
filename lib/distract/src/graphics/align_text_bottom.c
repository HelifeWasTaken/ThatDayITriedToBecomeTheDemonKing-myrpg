/*
** EPITECH PROJECT, 2020
** align_text_bottom
** File description:
** Source code
*/

#include "SFML/Graphics.h"

sfText *align_text_bottom(sfText *text, int y_pos)
{
    int left_padding = sfText_getGlobalBounds(text).height;
    sfVector2f pos = sfText_getPosition(text);

    pos.y = y_pos - left_padding;
    sfText_setPosition(text, pos);
    return (text);
}