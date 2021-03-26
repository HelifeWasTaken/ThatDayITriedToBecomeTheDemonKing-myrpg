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
#include <stdio.h>
#include <SFML/Graphics.h>

#define V2F(x, y) (sfVector2f){x, y}

struct vector_vertex_array_data {
    usize_t tileset;
    sfVertexArray *vertex;
};

struct vector_vertex_array {
    struct vector_vertex_array_data *vec;
    size_t size;
};

struct vector_texture {
    sfTexture **tileset;
    size_t size;
};

typedef struct vertex_array_map {
    struct vector_vertex_array v_vertex;
    struct vector_texture v_texture;
}vertex_map_t;

typedef struct map_rect {
    uint64_t mapx;
    uint64_t mapy;
    uint64_t tilex;
    uint64_t tiley;
} map_rect_t;

struct tile_id_rot {
    u16_t rot;
    u64_t id;
};

static const uint64_t FLIP_H_FLAG = 0x80000000;
static const uint64_t FLIP_V_FLAG = 0x40000000;
static const uint64_t FLIP_D_FLAG = 0x20000000;

struct tile_id_rot get_real_tile_id_and_rotation(u64_t id)
{
    if (id < FLIP_H_FLAG)
        return ((struct tile_id_rot){0, id});
    id &= ~(FLIP_H_FLAG | FLIP_V_FLAG | FLIP_D_FLAG);
    if ((id & FLIP_H_FLAG) && (id & FLIP_D_FLAG))
        return ((struct tile_id_rot){90, id});
    if ((id & FLIP_H_FLAG) && (id & FLIP_V_FLAG))
        return ((struct tile_id_rot){180, id});
    return ((struct tile_id_rot){270, id});
}

// it ignores tile rotation for now
void load_vertex(sfTexture *tileset, map_rect_t *size,
        sfVertexArray **vertex, u64_t *data)
{
    struct tile_id_rot id_rot = {0};
    sfVertexArray_setPrimitiveType(*vertex, sfQuads);
    sfVertexArray_resize(*vertex, size->mapx * size->mapy * 4);

    printf("%ld, %ld, %ld %ld\n", size->mapx, size->mapy, size->tilex, size->tiley);
    for (usize_t i = 0; i < size->mapx; ++i) {
        for (usize_t j = 0; j < size->mapy; ++j) {
            id_rot = get_real_tile_id_and_rotation(data[i + j * size->mapx]);
            int tu = id_rot.id % (i64_t)(sfTexture_getSize(tileset).x / size->tilex);
            int tv = id_rot.id / (sfTexture_getSize(tileset).x / size->tilex);
            sfVertex *quad = sfVertexArray_getVertex(*vertex, (i + j * size->mapx) * 4);
            quad[0].position = V2F(i * size->tilex, j * size->tiley);
            quad[1].position = V2F((i + 1) * size->tilex, j * size->tiley);
            quad[2].position = V2F((i + 1) * size->tilex, (j + 1) * size->tiley);
            quad[3].position = V2F(i * size->tilex, (j + 1) * size->tiley);

            quad[0].texCoords = V2F(tu * size->tilex, tv * size->tiley);
            quad[1].texCoords = V2F((tu + 1) * size->tilex, tv * size->tiley);
            quad[2].texCoords = V2F((tu + 1) * size->tilex, (tv + 1) * size->tiley);
            quad[3].texCoords = V2F(tu * size->tilex, (tv + 1) * size->tiley);
        }
    }
}

bool load_vertex_array_map_get_tileset_process(ig_map_t *map,
        usize_t v_check, usize_t *tileset)
{
    for (usize_t i = 0; i < map->tilesets->size; i++) {
        if (map->tilesets->data[i].firstgid <= v_check &&
                v_check <= map->tilesets->data[i].firstgid +
                map->tilesets->data[i].tilecount) {
            *tileset = i;
            break;
        }
    }
    if (*tileset == map->tilesets->size) {
        ASSERT("Vertex array", "Tileset not found");
        return (false);
    }
    return (true);
}

bool load_vertex_array_map_get_tileset(ig_map_t *map,
        struct iron_goat_layer *layer, usize_t *tileset)
{
    int64_t v = 0;

    for (usize_t i = 0; 1; i++) {
        if (layer->data->data[i] != 0) {
            v = get_real_tile_id_and_rotation(layer->data->data[i]).id;
            break;
        }
        if (layer->data->size == i) {
            ASSERT("Vertex array", "One layer is empty");
            return (false);
        }
    }
    return (load_vertex_array_map_get_tileset_process(map, v, tileset));
}

bool check_tileset_and_data(struct iron_goat_layer *layer,
        struct iron_goat_tileset *tileset)
{
    for (usize_t i = 0; i < layer->data->size; i++) {
        if (layer->data->data[i] == 0)
            continue;
        if (!(tileset->firstgid <= layer->data->data[i] &&
                    layer->data->data[i] <= tileset->firstgid +
                    tileset->tilecount)) {
            ASSERT("Vertex array", "Two layer might certainly be merged");
            return (false);
        }
    }
    return (true);
}

#define MAP_RECT(map, textures, tilesetv) \
    (map_rect_t){map->height, map->width, \
        16, 16}

bool load_vertex_array_map_data(ig_map_t *map, struct iron_goat_layer *layer,
        struct vector_texture *textures, struct vector_vertex_array_data *vertexmap)
{
    if (load_vertex_array_map_get_tileset(map, layer,
                &vertexmap->tileset) == false)
        return (false);
    if (check_tileset_and_data(
                layer, &map->tilesets->data[vertexmap->tileset]) == false)
        return (false);
    load_vertex(textures->tileset[vertexmap->tileset],
            &MAP_RECT(map, textures, vertexmap->tileset),
            &vertexmap->vertex, layer->data->data);
    return (true);
}

bool load_vertex_array_map_verticies(ig_map_t *map,
        struct vertex_array_map *self)
{
    self->v_vertex.size = map->layers->size;

    self->v_vertex.vec = ecalloc(sizeof(struct vector_vertex_array_data),
            map->layers->size);
    for (usize_t i = 0; i < self->v_vertex.size; i++) {
        self->v_vertex.vec[i].vertex = sfVertexArray_create();
        if (self->v_vertex.vec[i].vertex == NULL) {
            ASSERT("Vertex load", "Allocation error");
            return (false);
        }
        if (load_vertex_array_map_data(map, &map->layers->data[i],
                    &self->v_texture, &self->v_vertex.vec[i]) == false)
            return (false);
    }
    return (true);
}

bool load_vertex_array_map_tilesets(game_t *game,
        ig_map_t *map, struct vector_texture *self, char *pathfolder)
{
    char *file = NULL;

    
    self->size = map->tilesets->size;
    self->tileset = ecalloc(sizeof(sfTexture *), self->size);
    for (usize_t i = 0; i < self->size; i++) {
        file = eformat("%s%s", pathfolder, map->tilesets->data[i].image);
        if (file == NULL) {
            ASSERT("Vertex load", "Allocation error");
            return (false);
        }
        self->tileset[i] = create_texture(game, file, NULL);
        if (self->tileset[i] == NULL) {
            ASSERT("Vertex load", "Allocation error");
            return (false);
        }
        FREE(file);
    }
    return (true);
}

bool load_vertex_array_map(game_t *game, ig_map_t *map,
        struct vertex_array_map *self, char *pathfolder)
{
    if (load_vertex_array_map_tilesets(game, map,
                &self->v_texture, pathfolder) == false)
        return (false);
    if (load_vertex_array_map_verticies(map, self) == false)
        return (false);
    return (true);
}

#define DEFAULT_RENDERSTATE(texturedata) \
    (sfRenderStates){ \
        .blendMode = sfBlendAlpha, \
        .shader = NULL, \
        .transform = sfTransform_Identity, \
        .texture = texturedata \
    }

void draw_vertex(sfRenderWindow *window, struct vertex_array_map *self)
{
    for (usize_t i = 0; i < self->v_vertex.size; i++) {
        sfRenderWindow_drawVertexArray(window, self->v_vertex.vec[i].vertex,
            &DEFAULT_RENDERSTATE(
                self->v_texture.tileset[self->v_vertex.vec[i].tileset]));
    }
}

void test(ig_map_t *map, game_t *game)
{
    sfRenderWindow *window;
    sfVideoMode mode = (sfVideoMode){1920, 1080, 32};
    window = create_standard_window(mode, "My RPG");
    sfRenderWindow_setFramerateLimit(window, 60);
    vertex_map_t ver_map = {0};
    sfEvent event;

    if (load_vertex_array_map(game, map, &ver_map, "asset/map_asset/"))
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfBlack);
        draw_vertex(window, &ver_map);
        sfRenderWindow_display(window);
    }
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
    //       print_help();
    eprintf_free_buff();
    //    return (0);
    //}
    game_t *game = create_game();
        test(&map, game);
    destroy_iron_goat_map(&map);
    //return(load_game());
    return (0);
}
