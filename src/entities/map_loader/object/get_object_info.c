/*
** EPITECH PROJECT, 2020
** layer_object_manager
** File description:
** Entity
*/

#include "stdlib.h"
#include "distract/game.h"
#include "distract/entity.h"
#include "distract/resources.h"
#include "distract/graphics.h"
#include "distract/debug.h"
#include "SFML/Window.h"
#include "SFML/Graphics.h"
#include "myrpg/entities.h"
#include "myrpg/asset.h"
#include "myrpg/define.h"
#include "myrpg/map/map.h"

static const struct layer_parser_object L_PARSER_OBJ[] = {
    {
        .match = "warpzone",
        .parser = load_warpzone,
        .type = LO_WARP
    },
    {
        .match = "pnj",
        .parser = load_pnj,
        .type = LO_PNJ
    },
    {
        .match = "npc",
        .parser = load_pnj,
        .type = LO_NPC
    }
};

static bool get_object_data(game_t *game,
    layer_object_info_t *object, ig_object_t *obj_layer)
{
    D_ASSERT(obj_layer->properties, NULL, "Expected to have at least one"
        " custom properties in the object data", false);
    object->obj.rect = IRECT(obj_layer->x, obj_layer->y,
        obj_layer->width, obj_layer->height);
    for (usize_t i = 0; i < ARRAY_SIZE(L_PARSER_OBJ); i++) {
        if (estrcmp(obj_layer->type, L_PARSER_OBJ[i].match) == 0) {
            object->obj.type = L_PARSER_OBJ[i].type;
            return (L_PARSER_OBJ[i].parser(game, &object->obj, obj_layer));
        }
    }
    DEBUG_PRINTF("Layer object info loader did not"
        " recognized this type of object: %s", obj_layer->type);
    return (false);
}

static bool load_one_object_group(game_t *game UNUSED,
    layer_object_manager_t **manager, ig_layer_t *layer, usize_t z)
{
    layer_object_info_t obj_info = {0};

    obj_info.z = z;
    D_ASSERT(layer->objects, NULL, "Layer was a object layer"
        " but layer->object is null", false);
    for (usize_t i = 0; i < layer->objects->size; i++) {
        obj_info = (layer_object_info_t){0};
        if (get_object_data(game, &obj_info, &layer->objects->data[i]) == false)
            return (false);
        if ((*manager)->layer->push_back(&(*manager)->layer, obj_info) == -1)
            return (false);
    }
    return (true);
}

bool load_layers_object(game_t *game UNUSED, layer_object_manager_t **manager, ig_map_t *map)
{
    (*manager)->layer = VECTOR_CREATE(lobject_info);
    D_ASSERT((*manager)->layer, NULL, "Could not init layer data"
        "in object manager", false);
    for (usize_t i = 0; i < map->layers->size; i++) {
        if (map->layers->data[i].type == LAYER_OBJECTGROUP) {
            if (load_one_object_group(game, manager, &map->layers->data[i], i) == false)
                return (false);
        }
    }
    return (true);
}