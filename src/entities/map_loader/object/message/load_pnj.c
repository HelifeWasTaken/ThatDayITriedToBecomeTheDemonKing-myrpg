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

bool load_pnj(struct layer_object_data *data, ig_object_t *obj)
{
    for (usize_t i = 0; i < obj->properties->size; i++) {
        if (estrcmp(obj->properties->data[i].type, "string") == 0 &&
            estrcmp(obj->properties->data[i].name, "message") == 0) {
            data->object.message = estrdup(obj->properties->data[i].value.str);
            return (data->object.message != NULL);
        }
    }
    DEBUG_ASSERT("Loader pnj", "Expected an object of type string with"
        " a name message to load the pnj textbox");
    return (false);
}