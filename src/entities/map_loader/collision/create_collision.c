/*
** EPITECH PROJECT, 2021
** create_collisoin
** File description:
** create
*/

/*
** EPITECH PROJECT, 2020
** layer_collision
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
#include "distract/util.h"

bool create_layer_collision(game_t *game UNUSED, entity_t *entity)
{
    layer_collision_t *layer_collision = dcalloc(sizeof(layer_collision_t), 1);
    layer_collision_data_t data = {0};
    ig_map_t mapconf = {0};

    D_ASSERT(layer_collision, NULL,
        "Collision layer could not be allocated", false);
    D_ASSERT(load_map_from_file(game, &mapconf), false, "", false);
    if (load_collision_layer(game, &mapconf, &data) == false) {
        destroy_iron_goat_map(&mapconf);
        return (false);
    }
    destroy_iron_goat_map(&mapconf);
    layer_collision->entity = entity;
    entity->instance = layer_collision;
    layer_collision->data = data;
    entity->z = layer_collision->data.z;
    return (true);
}

void destroy_layer_collision(game_t *game UNUSED, entity_t *entity)
{
    layer_collision_t *layer_collision = entity->instance;

    free(layer_collision);
}

void draw_layer_collision(game_t *game UNUSED, entity_t *entity)
{
    layer_collision_t *collision = entity->instance;

    (void)(collision);
   // sfRenderWindow_drawVertexArray(game->window,
   //     collision->data.vtx, NULL);
}