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
#include "distract/debug.h"
#include "SFML/Window.h"
#include "SFML/Graphics.h"
#include "myrpg/entities.h"
#include "myrpg/asset.h"
#include "myrpg/define.h"
#include "myrpg/state.h"

void set_bool_mus(game_t *game, bool vol)
{
    game_state_t *state = game->state;

    state->params.music_muted = vol;
}

void set_bool_vox(game_t *game, bool vol)
{
    game_state_t *state =  game->state;

    if (vol == true) {
        state->params.voice_muted = true;
    }
}

void set_bool_vfx(game_t *game, bool vol)
{
    game_state_t *state = game->state;

    state->params.vfx_muted = vol;
}

void set_var_btn(game_state_t *state, char *text, int type,
    mute_button_t *mute)
{
    mute->text = text;
    if (type == SFX)
        mute->mute = state->params.vfx_muted;
    else if (type == MUSIC)
        mute->mute = state->params.music_muted;
    else
        mute->mute = state->params.voice_muted;
}

bool init_select_btn(game_t *game)
{
    mute_button_t *mute_vfx = create_entity(game, SELECT)->instance;
    mute_button_t *mute_mus = create_entity(game, SELECT)->instance;
    mute_button_t *mute_vox = create_entity(game, SELECT)->instance;
    game_state_t *state = game->state;

    D_ASSERT(mute_vfx, NULL, "error mute vfx", false);
    D_ASSERT(mute_mus, NULL, "error mute music", false);
    D_ASSERT(mute_vox, NULL, "error mute voice", false);
    mute_vfx->fonc = set_bool_vfx;
    mute_vox->fonc = set_bool_vox;
    mute_mus->fonc = set_bool_mus;
    set_var_btn(state, "mute effect:", SFX, mute_vfx);
    set_var_btn(state, "mute music:", MUSIC, mute_mus);
    set_var_btn(state, "mute voice:", VOX, mute_vox);
    mute_vfx->entity->pos = VEC2F(WINDOW_W / 4 * 2, 700 + 10);
    mute_vox->entity->pos = VEC2F(WINDOW_W / 4 * 2, 500 + 10);
    mute_mus->entity->pos = VEC2F(WINDOW_W / 4 * 2, 300 + 10);
    return (true);
}