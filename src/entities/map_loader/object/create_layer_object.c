/*
** EPITECH PROJECT, 2021
** create
** File description:
** lauer
*/

/*
** EPITECH PROJECT, 2020
** layer_object
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


bool create_layer_object(game_t *game UNUSED, entity_t *entity)
{
    layer_object_t *layer_object = dcalloc(sizeof(layer_object_t), 1);
    layer_object_manager_t *manager = get_instance(game, OBJECT_LAYER_MANAGER);

    D_ASSERT(manager, NULL, "Could not get object"
        " layer manager instance", false);
    D_ASSERT(layer_object, NULL, "Layer object could not be initted", false);
    layer_object->obj = &manager->layer->data[manager->actual_layer];
    layer_object->entity->z = layer_object->obj->z;
    layer_object->entity = entity;
    entity->instance = layer_object;
    manager->actual_layer++;
}

void destroy_layer_object_info(layer_object_info_t *obj)
{
    destroy_layer_object_data(&obj->obj);
}

void destroy_layer_object(game_t *game UNUSED, entity_t *entity)
{
    layer_object_t *layer_object = entity->instance;

    free(layer_object);
}