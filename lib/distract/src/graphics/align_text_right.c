/*
** EPITECH PROJECT, 2020
** align_text_right
** File description:
** Source code
*/

#include "SFML/Graphics.h"

sfText *align_text_right(sfText *text, int x_pos)
{
    int left_padding = sfText_getGlobalBounds(text).width;
    sfVector2f pos = sfText_getPosition(text);

    pos.x = x_pos - left_padding;
    sfText_setPosition(text, pos);
    return (text);
}