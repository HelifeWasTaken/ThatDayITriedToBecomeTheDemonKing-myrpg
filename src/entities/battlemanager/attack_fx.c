/*
** EPITECH PROJECT, 2021
** attack_fx
** File description:
** Source code
*/

#include "distract/animable.h"
#include "distract/debug.h"
#include "distract/game.h"
#include "distract/resources.h"
#include "myrpg/entities.h"
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>

static const animable_info_t CLASSIC_HIT_FX = {
    .animations = {
        { 0, 9 }
    },
    .frame_size = { 600, 600 },
    .frames_per_line = 5
};

bool create_attack_fx(game_t *game, battlemanager_t *manager)
{
    animable_info_t fx_info = CLASSIC_HIT_FX;
    sfTexture *texture = create_texture(game, "asset/fx/classic_hit.png",
        &IRECT(0, 0, 3000, 1200));
    D_ASSERT(texture, NULL, "Can't create attack fx texture", false);

    fx_info.sprite = create_sprite(texture, &IRECT(0, 0, 3000, 1200));
    D_ASSERT(fx_info.sprite, NULL, "Can't create attack fx sprite", false);
    manager->classic_hit_fx.info = fx_info;
    set_animable_info(&manager->classic_hit_fx, &fx_info);
    sfSprite_setScale(fx_info.sprite, VEC2F(0.25, 0.25));
    manager->attack_fx_clock = create_pausable_clock(game);
        sfSprite_setPosition(manager->classic_hit_fx.info.sprite,
            VEC2F(-1000, -1000));
    D_ASSERT(manager->attack_fx_clock, NULL,
        "Can't create attack fx clock", false);
    return (true);
}

void update_attack_fx(game_t *game UNUSED, battlemanager_t *battlemanager)
{
    tick_pausable_clock(battlemanager->attack_fx_clock);
    if (battlemanager->attack_fx_clock->time >= 0.05f) {
        if (!is_animation_done(&battlemanager->classic_hit_fx)) {
            set_animable_frame(&battlemanager->classic_hit_fx,
                get_animable_frame(&battlemanager->classic_hit_fx) + 1);
        }
        battlemanager->attack_fx_clock->time = 0;
    }
    tick_pausable_clock(battlemanager->attack_fx_clock);
}

void show_attack_fx(battlemanager_t *battlemanager)
{
    sfVector2f pos = battlemanager->target->pos;
    sfFloatRect rect = sfSprite_getGlobalBounds(
        battlemanager->classic_hit_fx.info.sprite);

    pos.x -= rect.width / 2;
    pos.y -= rect.height / 2;
    sfSprite_setPosition(battlemanager->classic_hit_fx.info.sprite, pos);
    set_animable_frame(&battlemanager->classic_hit_fx, 0);
}

void draw_attack_fx(game_t *game UNUSED, battlemanager_t *battlemanager)
{
    if (!is_animation_done(&battlemanager->classic_hit_fx)) {
        sfRenderWindow_drawSprite(game->window,
            battlemanager->classic_hit_fx.info.sprite, NULL);
    }
}

void destroy_attack_fx(game_t *game UNUSED, battlemanager_t *battlemanager)
{
    sfSprite_destroy(battlemanager->classic_hit_fx.info.sprite);
    destroy_pausable_clock(battlemanager->attack_fx_clock);
}