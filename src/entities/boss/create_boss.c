/*
** EPITECH PROJECT, 2020
** pnj
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
#include "myrpg/pnj.h"
#include "myrpg/battle.h"
#include "myrpg/util.h"

static bool creat_loader_part(game_t *game, boss_t **boss)
{
    struct json pnj_conf = {0};
    ig_map_t map = get_game_state(game)->map;
    char *file = NULL;

    if (!load_property_string(map.properties, &file, "boss_files",
        "could not load map property in boss.c")) {
        if (((*boss)->boss_vector = VECTOR_CREATE(boss_vector)) == NULL)
            return (false);
        return (true);
    }
    D_ASSERT(json_parser(&pnj_conf, file),
            false, "could not json parse boss_conf", false);
    if (load_boss_data_loop(&pnj_conf, &(*boss)->boss_vector) == false) {
        destroy_json(&pnj_conf);
        return (false);
    }
    destroy_json(&pnj_conf);
    return (true);
}

bool set_boss_loop(game_t *game, boss_t **boss)
{
    sfTexture *texture;

    for (usize_t i = 0; i < (*boss)->boss_vector->size; i++) {
        texture = create_texture(game, (*boss)->boss_vector->data[i].file_path,
                NULL);
        (*boss)->boss_vector->data[i].rect_size =
            VEC2F((*boss)->boss_vector->data[i].rect.width,
                    (*boss)->boss_vector->data[i].rect.height);
        D_ASSERT(texture, NULL, "could not load pnj texture", false);
        (*boss)->boss_vector->data[i].sprite = create_sprite(texture,
                &(*boss)->boss_vector->data[i].rect);
        sfSprite_setPosition((*boss)->boss_vector->data[i].sprite,
                (*boss)->boss_vector->data[i].pos);
    }
    return (true);
}

bool create_boss(game_t *game UNUSED, entity_t *entity)
{
    boss_t *boss = ecalloc(sizeof(pnj_t), 1);
    map_loader_t *map = get_instance(game, LAYER_MANAGER);
    boss->hero = get_instance(game, HERO);

    D_ASSERT(map, NULL, "Layer could not be found", false);
    D_ASSERT(boss, NULL, "error on ecalloc on pnj", false);
    D_ASSERT(boss->hero, NULL, "Could not load hero in create pnj", false);
    if (!creat_loader_part(game, &boss) || !set_boss_loop(game, &boss))
        return (false);
    boss->clock = create_pausable_clock(game);
    D_ASSERT(boss->clock, NULL, "could not create pnj clock", false);
    boss->entity = entity;
    boss->entity->z = map->manager.z;
    entity->instance = boss;
    return (true);
}

void destroy_boss(game_t *game UNUSED, entity_t *entity)
{
    boss_t *boss = entity->instance;

    destroy_pausable_clock(boss->clock);
    if (boss->boss_vector != NULL)
        boss->boss_vector->clear(&boss->boss_vector);
    free(boss);
}
