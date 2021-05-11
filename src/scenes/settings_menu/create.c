/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** lifecycle
*/

#include "distract/entity.h"
#include "distract/debug.h"
#include "myrpg/entities.h"
#include "myrpg/state.h"
#include "myrpg/game.h"
#include "myrpg/asset.h"
#include "distract/game.h"
#include "distract/entity.h"
#include "distract/resources.h"
#include "distract/sound.h"

void music_on_scroll(game_t *game, vfx_scroll_t *scroll)
{
    game_state_t *state = game->state;

    state->params.music_vol = scroll->percentage;
    set_sound_volume(game, MUSIC, scroll->percentage * 100);
}

void vox_on_scroll(game_t *game, vfx_scroll_t *scroll)
{
    game_state_t *state = game->state;

    state->params.voice_vol = scroll->percentage;
    set_sound_volume(game, VOX, scroll->percentage * 100);
}

void vfx_on_scroll(game_t *game, vfx_scroll_t *scroll)
{
    game_state_t *state = game->state;

    state->params.vfx_vol = scroll->percentage;
    set_sound_volume(game, SFX, scroll->percentage * 100);
}

bool config_scroll_bar(game_t *game, vfx_scroll_t *scroll,
    vfx_scroll_t *scroll_mus, vfx_scroll_t *scroll_vox)
{
    sfSprite_setPosition(scroll->sprite_bar,
        VEC2F(WINDOW_W / 4 * 2.2, 700));
    scroll->on_scroll = &vfx_on_scroll;
    sfText_setString(scroll->text, "vfx:");
    set_size_vfx(game, scroll);
    sfSprite_setPosition(scroll_vox->sprite_bar,
        VEC2F(WINDOW_W / 4 * 2.2, 500));
    scroll_vox->on_scroll = &vox_on_scroll;
    sfText_setString(scroll_vox->text, "voice:");
    set_size_vox(game, scroll_vox);
    sfSprite_setPosition(scroll_mus->sprite_bar,
        VEC2F(WINDOW_W / 4 * 2.2, 300));
    scroll_mus->on_scroll = &music_on_scroll;
    sfText_setString(scroll_mus->text, "music:");
    set_size_mus(game, scroll_mus);
    return (true);
}

bool init_scroll_bar(game_t *game)
{
    entity_t *scroll = create_entity(game, VFX_SC);
    entity_t *scroll_mus = create_entity(game, VFX_SC);
    entity_t *scroll_vox = create_entity(game, VFX_SC);

    D_ASSERT((scroll && scroll_mus && scroll_vox), false, "Scrollbar", false)
    return (config_scroll_bar(game, scroll->instance, scroll_mus->instance,
        scroll_vox->instance));
}