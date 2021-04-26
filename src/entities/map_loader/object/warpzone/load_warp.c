/*
** EPITECH PROJECT, 2021
** a
** File description:
** a
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

static bool load_warpzone_world(struct layer_object_data *data,
        ig_object_t *obj)
{
    for (usize_t i = 0; i < obj->properties->size; i++) {
        if ((obj->properties->data[i].type == PROP_STRING ||
                    obj->properties->data->type == PROP_FILE) &&
                estrcmp(obj->properties->data[i].name, "world") == 0) {
            data->object.warp.world = estrdup(
                    obj->properties->data[i].value.str);
            return (data->object.warp.world != NULL);
        }
    }
    return (false);
}

static bool load_warpzone_coordinates_spawn(struct layer_object_data *data,
        ig_object_t *obj)
{
    bool hasx = false;

    for (usize_t i = 0; i < obj->properties->size; i++) {
        if ((obj->properties->data[i].type == PROP_INT ||
                    obj->properties->data->type == PROP_FLOAT) &&
                estrcmp(obj->properties->data[i].name, "spawnx") == 0) {
            data->object.warp.spawn.x = obj->properties->data[i].value.i;
            hasx = true;
        }
    }
    for (usize_t i = 0; i < obj->properties->size; i++) {
        if ((obj->properties->data[i].type == PROP_INT ||
                    obj->properties->data->type == PROP_FLOAT) &&
                estrcmp(obj->properties->data[i].name, "spawny") == 0) {
            data->object.warp.spawn.y = obj->properties->data[i].value.i;
            return (hasx == true);
        }
    }
    return (false);
}

bool load_warpzone(game_t *game,
        struct layer_object_data *data, ig_object_t *obj)
{
    entity_t *entity = NULL;
    warpzone_t *warp = NULL;

    D_ASSERT(load_warpzone_world(data, obj), false,
            "Expected to load a property of string or "
            "file with a name world giving the next"
            " world to load for the warpzone", false);
    D_ASSERT(load_warpzone_coordinates_spawn(data, obj), false,
            "Expected to have an x and y coordinates called spawnx, and spawny to"
            " load the spawn for the \"afterwarp\"", false);
    if ((entity = create_entity(game, WARP)) == NULL)
        return (false);
    warp = entity->instance;
    warp->warp.spawn = data->object.warp.spawn;
    warp->rect = data->rect;
    warp->warp.world = data->object.warp.world;
    warp->rect = data->rect;
    return (true);
}
