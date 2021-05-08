/*
** EPITECH PROJECT, 2021
** loadmessage
** File description:
** msg
*/

#include "myrpg/map/object.h"
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

bool load_pnj_type(struct layer_object_data *data,
                            ig_object_t *obj)
{
    data->object.pnj.npc_type = 0;
    for (usize_t i = 0; i < obj->properties->size; i++) {
        if ((obj->properties->data[i].type == PROP_INT) &&
            estrcmp(obj->properties->data[i].name, "npc_type") == 0) {
            data->object.pnj.npc_type =
                obj->properties->data[i].value.i;
        }
    }
    return (true);
}
