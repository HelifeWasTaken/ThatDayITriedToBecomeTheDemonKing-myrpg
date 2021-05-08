/*
** EPITECH PROJECT, 2020
** MY_RPG_PUBLIC
** File description:
** hero.c
*/

#include "distract/game.h"
#include "distract/entity.h"
#include "distract/resources.h"
#include "distract/graphics.h"
#include "distract/window.h"
#include "SFML/Window.h"
#include "myrpg/asset.h"
#include "SFML/Graphics.h"
#include "myrpg/entities.h"
#include "myrpg/define.h"
#include "stdlib.h"
#include "distract/debug.h"
#include "distract/util.h"
#include "myrpg/util.h"
#include "myrpg/cinema.h"

bool create_hero(game_t *game UNUSED, entity_t *entity)
{
    hero_t *hero = dcalloc(sizeof(hero_t), 1);
    sfIntRect rect = IRECT(0, 0, 135, 332);
    sfTexture *texture = create_texture(game, HERO_PATH, &rect);

    hero->layers = get_instance(game, LAYER_MANAGER);
    hero->dialogbox = get_instance(game, DIALOGBOX);
    D_ASSERT(hero, NULL, "Hero could not be created", false);
    D_ASSERT(texture, NULL, "Tetxure could not be created", false);
    D_ASSERT(hero->layers, NULL, "Layer could not be found", false);
    D_ASSERT(hero->dialogbox, NULL, "Dialogbox could not be found", false);
    hero->entity = entity;
    hero->animation_clock = create_pausable_clock(game);
    hero->movement_clock = create_pausable_clock(game);
    hero->sprite = create_sprite(texture, &IRECT(0, 0 , 45, 83));
    hero->entity->pos = get_game_state(game)->save.player_pos;
    entity->instance = hero;
    hero->entity->z = hero->layers->manager.z;
    hero->speed = 1.5;
    sfSprite_setScale(hero->sprite, VEC2F(0.35, 0.35));
    return (true);
}

void destroy_hero(game_t *game UNUSED, entity_t *entity)
{
    hero_t *hero = entity->instance;

    sfSprite_destroy(hero->sprite);
    destroy_pausable_clock(hero->animation_clock);
    destroy_pausable_clock(hero->movement_clock);
    free(hero);
}

void update_hero(game_t *game UNUSED, entity_t *entity UNUSED)
{
    hero_t *hero = entity->instance;

    sfSprite_setPosition(hero->sprite, entity->pos);
    if (GBL_IS_IN_CINEMATIC == true || hero->dialogbox->is_visible)
        return;
    update_hero_move(game, hero);
    tick_pausable_clock(hero->animation_clock);
    tick_pausable_clock(hero->movement_clock);
}

static void draw_hero_collision_points(game_t *game, hero_t *hero)
{
    unsigned int tilesize = hero->layers->manager.tilesize;
    sfFloatRect rect = sfSprite_getGlobalBounds(hero->sprite);
    sfVector2f entitypos = hero->entity->pos;
    sfVector2u pos_l = GET_REAL_POSITION_XY(
        entitypos, 0, (rect.height / 2) - 2, tilesize);
    sfVector2u pos_r = GET_REAL_POSITION_XY(
        entitypos, (rect.width / 2) + 4, (rect.height / 2) - 2, tilesize);
    sfVector2u pos_d = GET_REAL_POSITION_XY(entitypos,
        rect.width / 2, rect.height / 2, tilesize);
    sfVector2u pos_u =  GET_REAL_POSITION_XY(
        entitypos, rect.width / 2, rect.height / 3, tilesize);

    draw_rectangle_at_point(game->window,
        &VEC2F(pos_r.x * tilesize, pos_r.y * tilesize));
    draw_rectangle_at_point(game->window,
        &VEC2F(pos_l.x * tilesize, pos_l.y * tilesize));
    draw_rectangle_at_point(game->window,
        &VEC2F(pos_d.x * tilesize, pos_d.y * tilesize));
    draw_rectangle_at_point(game->window,
        &VEC2F(pos_u.x * tilesize, pos_u.y * tilesize));
}

void draw_hero(game_t *game UNUSED, entity_t *entity)
{
    hero_t *hero = entity->instance;

    sfRenderWindow_drawSprite(game->window, hero->sprite, NULL);
    IN_DEBUG_MENU(
        draw_hero_collision_points(game, hero)
    );
}
