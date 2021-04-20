/*
** EPITECH PROJECT, 2020
** warpzone
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
#include "myrpg/util.h"

bool create_warpzone(game_t *game UNUSED, entity_t *entity)
{
    warpzone_t *warpzone = dcalloc(sizeof(warpzone_t), 1);

    D_ASSERT(warpzone, NULL, "Warpzone could not be initted", false);
    warpzone->entity = entity;
    entity->instance = warpzone;
    return (true);
}

void destroy_warpzone(game_t *game UNUSED, entity_t *entity)
{
    warpzone_t *warpzone = entity->instance;

    free(warpzone);
}

void update_warpzone(game_t *game UNUSED, entity_t *entity)
{
    warpzone_t *warpzone = entity->instance;

    if (warpzone->hero == NULL) {
        warpzone->hero = get_instance(game, HERO);
        return;
    }
    if (sfFloatRect_contains(&CAST_R(sfFloatRect, warpzone->rect),
        warpzone->hero->entity->pos.x, warpzone->hero->entity->pos.y) == true)
        switch_to_world(game, warpzone->warp.world);
}