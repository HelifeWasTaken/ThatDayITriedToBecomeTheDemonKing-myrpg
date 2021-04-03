/*
** EPITECH PROJECT, 2020
** generate_map
** File description:
** Map
*/

#include "myrpg/map.h"
#include "myrpg/entities.h"
#include "distract/debug.h"

bool generate_map(game_t *game)
{
    entity_t *managerentity = create_entity(game, LAYER_MANAGER);
    layer_manager_t *manager = NULL;

    D_ASSERT(managerentity, NULL, "Could not get managerentity", false);
    manager = managerentity->instance;
    for (size_t i = 0; i < manager->map.v_vertex.size; i++)
        if (create_entity(game, LAYER) == NULL)
            return (false);
    return (true);
}