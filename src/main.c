/*
** EPITECH PROJECT, 2020
** main
** File description:
** Source code
*/

#include <iron_goat/deser.h>
#include "myrpg/game.h"
#include "distract/window.h"
#include "distract/graphics.h"
#include "distract/resources.h"
#include "distract/game.h"
#include "myrpg/map/map.h"
#include <stdio.h>
#include <SFML/Graphics.h>
#include <iron_goat/deser.h>
#include "myrpg/util.h"
#include "myrpg/pnj.h"
#include "erty/string/ecstring.h"
#include "myrpg/cinema.h"

int usage(void)
{
    eprintf("%s", USAGE);
    return (0);
}

int main(int ac, char **av UNUSED)
{
    if (ac >= 2)
        return (usage());
    return (load_game());
}
