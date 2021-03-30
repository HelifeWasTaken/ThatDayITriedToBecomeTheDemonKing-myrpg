/*
** EPITECH PROJECT, 2020
** main
** File description:
** Source code
*/

//#include "my/io.h"
#include <iron_goat/deser.h>
#include "myrpg/game.h"
#include "distract/window.h"
#include "distract/graphics.h"
#include "distract/resources.h"
#include "distract/game.h"
#include "myrpg/map.h"
#include <stdio.h>
#include <SFML/Graphics.h>

int main(void)
{
    //parsed_args_t args = my_parse_args(argc, argv);

    //if (my_char_in(args.flags, 'h')) {
    //       print_help();
    //    return (0);
    //}
    return(load_game());
}
