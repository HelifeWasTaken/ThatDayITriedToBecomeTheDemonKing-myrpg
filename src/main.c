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
#include <stdio.h>
#include <SFML/Graphics.h>

#define V2F(x, y) (sfVector2f){x, y}

static void print_help(void)
{
    //my_printf("RPG created with CSFML.\n\n");
    //my_printf("USAGE\n ./my_rpg\n\n\n");
    //my_printf("USER INTERACTIONS\n");
    //my_printf(" SPACE_KEY\tdoes something??\n");
}

void load_vertex(ig_map_t *map, sfTexture *texture, sfVertexArray **vertex)
{
    sfVector2f tileSize = V2F(16, 16);
    i64_t width = map->layers->data[0].width;
    i64_t height = map->layers->data[0].height;
    sfVertexArray_setPrimitiveType(*vertex, sfQuads);
    sfVertexArray_resize(*vertex, width * height * 4);

        for (unsigned int i = 0; i < width; ++i)
            for (unsigned int j = 0; j < height; ++j) {
                int tileNumber = map->layers->data[0].data->data[i + j * width];
                int tu = tileNumber % (i64_t)(sfTexture_getSize(texture).x / tileSize.x);
                int tv = tileNumber / (sfTexture_getSize(texture).x / tileSize.x);
                sfVertex *quad = sfVertexArray_getVertex(*vertex, (i + j * width) * 4);
                quad[0].position = V2F(i * tileSize.x, j * tileSize.y);
                quad[1].position = V2F((i + 1) * tileSize.x, j * tileSize.y);
                quad[2].position = V2F((i + 1) * tileSize.x, (j + 1) * tileSize.y);
                quad[3].position = V2F(i * tileSize.x, (j + 1) * tileSize.y);
                quad[0].texCoords = V2F(tu * tileSize.x, tv * tileSize.y);
                quad[1].texCoords = V2F((tu + 1) * tileSize.x, tv * tileSize.y);
                quad[2].texCoords = V2F((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
                quad[3].texCoords = V2F(tu * tileSize.x, (tv + 1) * tileSize.y);
            }
}

void test(ig_map_t *map)
{
    sfRenderWindow *window;
    sfVideoMode mode = (sfVideoMode){1920, 1080, 32};
    window = create_standard_window(mode, "My RPG");
    sfRenderWindow_setFramerateLimit(window, 60);
    char *file = eformat("asset/map_asset/%s", map->tilesets->data[0].image);
    sfTexture *texture = sfTexture_createFromFile(file, NULL);
    sfVertexArray *vertex = sfVertexArray_create();
    sfRenderStates state = ;
    load_vertex(map, texture, &vertex);
    sfEvent event;
    sfSprite *sp = sfSprite_create();
    sfSprite_setTexture(sp, texture, sfFalse);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawVertexArray(window, vertex, NULL);
        //sfRenderWindow_drawSprite(window, sp, NULL);
        sfRenderWindow_display(window);
    }
    sfVertexArray_destroy(vertex);
    sfTexture_destroy(texture);
}

int main(void)
{
    ig_map_t map = {0};
    json_t json_file = {0};

    if(json_parser(&json_file, "asset/map_asset/fuck.json") == false)
        return (84);
    if (init_iron_goat_map(&json_file, &map) == false)
        return (84);
    destroy_json(&json_file);
    //parsed_args_t args = my_parse_args(argc, argv);

    //if (my_char_in(args.flags, 'h')) {
        print_help();
        eprintf_free_buff();
    //    return (0);
    //}
    test(&map);
    destroy_iron_goat_map(&map);
   // return (load_game());
   return (0);
}