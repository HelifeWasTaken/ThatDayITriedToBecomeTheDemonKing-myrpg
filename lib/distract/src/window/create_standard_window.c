/*
** EPITECH PROJECT, 2020
** create_standard_window
** File description:
** Source code
*/

#include "SFML/Graphics.h"
#include "stdio.h"

sfRenderWindow *create_standard_window(sfVideoMode mode, char const *title)
{
    return (sfRenderWindow_create(mode, title, sfDefaultStyle, NULL));
}
