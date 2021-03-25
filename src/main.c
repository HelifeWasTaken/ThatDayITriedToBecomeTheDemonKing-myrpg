/*
** EPITECH PROJECT, 2020
** main
** File description:
** Source code
*/

//#include "my/io.h"
#include "myrpg/game.h"

static void print_help(void)
{
    //my_printf("RPG created with CSFML.\n\n");
    //my_printf("USAGE\n ./my_rpg\n\n\n");
    //my_printf("USER INTERACTIONS\n");
    //my_printf(" SPACE_KEY\tdoes something??\n");
}

int main(void)
{
    //parsed_args_t args = my_parse_args(argc, argv);

    //if (my_char_in(args.flags, 'h')) {
    print_help();
    //    return (0);
    //}
    return (load_game());
}
