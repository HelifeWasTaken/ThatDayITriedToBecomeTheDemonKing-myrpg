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

void test(ig_map_t *map, game_t *game)
{
    sfRenderWindow *window;
    sfVideoMode mode = (sfVideoMode){1920, 1080, 32};
    window = create_standard_window(mode, "My RPG");
    sfRenderWindow_setFramerateLimit(window, 60);
    vertex_map_t ver_map = {0};
    sfEvent event;

    if (load_vertex_array_map(game, map, &ver_map, "asset/map_asset/") == false)
        return;
    destroy_iron_goat_map(map);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfBlack);
        draw_vertex_map(window, &ver_map);
        sfRenderWindow_display(window);
    }
}

int main(void)
{
    ig_map_t map = {0};
    json_t json_file = {0};

    if(json_parser(&json_file, "asset/map_asset/map.json") == false)
        return (84);
    if (init_iron_goat_map(&json_file, &map) == false)
        return (84);
    destroy_json(&json_file);
    //parsed_args_t args = my_parse_args(argc, argv);

    //if (my_char_in(args.flags, 'h')) {
    //       print_help();
    //    return (0);
    //}
    game_t *game = create_game();
    test(&map, game);
    eprintf_free_buff();
    destroy_iron_goat_map(&map);
    //return(load_game());
    return (0);
}
