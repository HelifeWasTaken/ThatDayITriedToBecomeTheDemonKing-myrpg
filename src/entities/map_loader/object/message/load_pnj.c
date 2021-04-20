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

static bool load_pnj_entity(game_t *game, struct layer_object_data *data)
{
    entity_t *entity = NULL;
    npc_t *npc = NULL;

    if ((entity = create_entity(game, NPC)) == NULL)
        return (false);
    npc = entity->instance;
    npc->messages = data->object.message;
    npc->name = estrdup("Undefined name");
    npc->entity->pos = VEC2F(data->rect.left, data->rect.top);
    return (true);
}

bool load_pnj(game_t *game, struct layer_object_data *data, ig_object_t *obj)
{

    for (usize_t i = 0; i < obj->properties->size; i++) {
        if ((obj->properties->data[i].type == PROP_STRING ||
            obj->properties->data[i].type == PROP_FILE) &&
            estrcmp(obj->properties->data[i].name, "message") == 0) {
            data->object.message = esplit(
                obj->properties->data[i].value.str, '\n');
            return (data->object.message != NULL &&
                load_pnj_entity(game, data));
        }
    }
    DEBUG_ASSERT("Loader pnj", "Expected an object of type string with"
        " a name message to load the pnj textbox");
    return (false);
}