/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** lifecycle
*/

#include "distract/animable.h"
#include "distract/debug.h"
#include "distract/game.h"
#include "distract/entity.h"
#include "distract/resources.h"
#include "distract/sound.h"
#include "erty/estdlib.h"
#include "myrpg/entities.h"
#include "myrpg/state.h"
#include "myrpg/asset.h"
#include "myrpg/util.h"
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Sprite.h>

static const char *BOSS_MUSIC[] = {
    "asset/song/volcano_boss_theme.ogg",
    "asset/song/forest_boss_theme.ogg",
    "asset/song/sand_boss_theme.ogg",
    "asset/song/final_boss_theme.ogg"
};

static char *select_music(game_t *game)
{
    int boss_id = get_game_state(game)->last_boss_id;
    char **music = (void *)(char const **)BOSS_MUSIC;

    if (boss_id <= -1 || boss_id >= (int)(ARRAY_SIZE(BOSS_MUSIC)))
        return ("asset/song/battle_theme.ogg");
    return (music[boss_id]);
}

static battlemanager_t *initialize_manager(game_t *game)
{
    entity_t *tmp;
    battlemanager_t *manager;
    battlehud_t *hud;

    set_game_view(game, sfView_createFromRect((sfFloatRect){0, 0,
        game->mode.width / 3.f, game->mode.height / 3.f}));
    tmp = create_entity(game, BATTLEHUD);
    D_ASSERT(tmp, NULL, "Cannot create battle hud", NULL);
    hud = tmp->instance;
    tmp = create_entity(game, BATTLEMANAGER);
    D_ASSERT(tmp, NULL, "Cannot create battle manager", NULL);
    manager = tmp->instance;
    hud->manager = manager;
    manager->hud = hud;
    return (manager);
}

static void update_battle_lifecycle(game_t *game, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(game->window, event))
        if (event->type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        else
            transmit_event_to_scene(game, event);
    update_scene(game);
    sfRenderWindow_clear(game->window, sfBlack);
    draw_scene(game);
    sfRenderWindow_display(game->window);
}

int battle_lifecycle(game_t *game)
{
    battlemanager_t *manager = initialize_manager(game);
    int exit_code;
    sfEvent event;
    char *music_name = select_music(game);

    D_ASSERT(music_name, false, "Can't find music", 84);
    D_ASSERT(play_music(game, MUSIC, music_name), false,
        "Can't play music", 84);
    D_ASSERT(manager, NULL, "Cannot create battle", 84);
    while (is_scene_updated(game)) {
        update_battle_lifecycle(game, &event);
    }
    exit_code = manager->exit_code;
    destroy_scene(game, true);
    return (exit_code);
}