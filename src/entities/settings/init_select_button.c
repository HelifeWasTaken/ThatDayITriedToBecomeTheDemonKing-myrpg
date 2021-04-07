/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init_select_button
*/

#include "stdlib.h"
#include "distract/game.h"
#include "distract/entity.h"
#include "distract/resources.h"
#include "distract/graphics.h"
#include "SFML/Window.h"
#include "SFML/Graphics.h"
#include "myrpg/entities.h"
#include "myrpg/asset.h"
#include "myrpg/define.h"
#include "myrpg/parameters.h"

void set_bool_mus(game_t *game, bool vol)
{
    parameters_t *param = game->state;

    param->music_muted = vol;
}

void set_bool_vox(game_t *game, bool vol)
{
    parameters_t *param = game->state;

    param->voice_muted = vol;
}

void set_bool_vfx(game_t *game, bool vol)
{
    parameters_t *param = game->state;

    param->vfx_muted = vol;
}

void init_select_btn(game_t *game)
{
    mute_button_t *mute_vfx = create_entity(game, SELECT)->instance;
    mute_button_t *mute_mus = create_entity(game, SELECT)->instance;
    mute_button_t *mute_vox = create_entity(game, SELECT)->instance;
    parameters_t *param = game->state;

    mute_vfx->mute = param->vfx_muted;
    mute_vfx->fonc = set_bool_vfx;
    mute_vox->fonc = set_bool_vox;
    mute_mus->fonc = set_bool_mus;
    mute_vfx->text = "mute effect:";
    mute_vox->text = "mute voice:";
    mute_mus->text = "mute music:";
    mute_mus->mute = param->music_muted;
    mute_vox->mute = param->voice_muted;
    mute_vfx->entity->pos = VEC2F(WINDOW_W / 4 * 2, 700 + 10);
    mute_vox->entity->pos = VEC2F(WINDOW_W / 4 * 2, 500 + 10);
    mute_mus->entity->pos = VEC2F(WINDOW_W / 4 * 2, 300 + 10);
}