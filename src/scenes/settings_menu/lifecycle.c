/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** lifecycle
*/

#include "distract/entity.h"
#include "myrpg/entities.h"
#include "myrpg/parameters.h"
#include "myrpg/game.h"
#include "myrpg/asset.h"
#include "distract/game.h"
#include "distract/entity.h"
#include "distract/resources.h"

void music_on_scroll(game_t *game, vfx_scroll_t *scroll)
{
    parameters_t *param = game->state;

    param->music_vol = scroll->percentage;
}

void vox_on_scroll(game_t *game, vfx_scroll_t *scroll)
{
    parameters_t *param = game->state;

    param->voice_vol = scroll->percentage;
}

void vfx_on_scroll(game_t *game, vfx_scroll_t *scroll)
{
    parameters_t *param = game->state;

    param->vfx_vol = scroll->percentage;
}

void init_scroll_bar(game_t *game)
{
    vfx_scroll_t *scroll = create_entity(game, VFX_SC)->instance;
    vfx_scroll_t *scroll_mus = create_entity(game, VFX_SC)->instance;
    vfx_scroll_t *scroll_vox = create_entity(game, VFX_SC)->instance;

    sfSprite_setPosition(scroll->sprite_bar, VEC2F(WINDOW_W / 4 * 2.2, 700));
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
}

int setting_lifecycle(game_t *game)
{
    sfEvent event;

    init_scroll_bar(game);
    init_select_btn(game);
    create_entity(game, SETTING);
    while (is_scene_updated(game)) {
        while (sfRenderWindow_pollEvent(game->window, &event))
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(game->window);
            else
                transmit_event_to_scene(game, &event);
        update_scene(game);
        sfRenderWindow_clear(game->window, sfWhite);
        draw_scene(game);
        sfRenderWindow_display(game->window);
    }
    destroy_scene(game, true);
    return (0);
}