/*
** EPITECH PROJECT, 2021
** loadmessage
** File description:
** msg
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
    entity_t *entity = NULL;

    for (usize_t i = 0; i < obj->properties->size; i++) {
        if ((obj->properties->data[i].type == PROP_STRING ||
            obj->properties->data[i].type == PROP_FILE) &&
            estrcmp(obj->properties->data[i].name, "message") == 0) {
            data->object.message = estrdup(obj->properties->data[i].value.str);
            return (data->object.message != NULL && );
        }
    }
    DEBUG_ASSERT("Loader pnj", "Expected an object of type string with"
        " a name message to load the pnj textbox");
    // load pnj entity
    return (false);
}