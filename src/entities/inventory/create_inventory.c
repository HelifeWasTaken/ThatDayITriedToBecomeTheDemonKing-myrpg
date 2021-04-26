/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** create_inventory
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

sfSprite *init_inventory(game_t *game, entity_t *entity)
{
    inventory_t *inventory = entity->instance;
    inventory->texture = create_texture(game, INV_TEX, NULL);
    sfSprite *sprite = NULL;

    (void)entity;
    inventory->over = create_texture(game, INV_TEX_OVER, NULL);
    D_ASSERT(inventory->texture, NULL, "error texture inventory", NULL);
    D_ASSERT(inventory->over, NULL, "error texture over inventory", NULL);
    sprite = create_sprite(inventory->texture, NULL);
    D_ASSERT(sprite, NULL, "error texture", NULL);
    sfSprite_setScale(sprite, VEC2F(2.5, 2.5));
    return (sprite);
}