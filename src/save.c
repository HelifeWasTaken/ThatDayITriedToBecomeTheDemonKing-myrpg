/*
** EPITECH PROJECT, 2021
** save
** File description:
** save
*/

#include "distract/game.h"
#include "distract/util.h"
#include "distract/window.h"
#include "distract/scene.h"
#include "myrpg/asset.h"
#include "distract/entity.h"
#include "distract/debug.h"
#include "myrpg/entities.h"
#include "myrpg/scenes.h"
#include "myrpg/state.h"
#include "stdlib.h"
#include "myrpg/scenes.h"
#include "myrpg/util.h"
#include "distract/util.h"
#include "myrpg/cinema.h"

static const int SAVE_MAGIC_NUMBER = 0xa1edcafe;

void default_save(game_t *game, int fd)
{
    if (fd != -1)
        close(fd);
    ememset(&get_game_state(game)->save, 0, sizeof(game_save_t));
    for (int index = 0; index != 15; index++) {
        get_game_state(game)->save.item[index].type =
            game->item_loaded[index].type;
        get_game_state(game)->save.item[index].id = index;
        get_game_state(game)->save.item[index].nb = 1;
    }
    game->scene->world_file = DEFAULT_WORLD_FILE;
    get_game_state(game)->save.player_pos = DEFAULT_PLAYER_POS;
    get_game_state(game)->save.player_hp = 20;
    get_game_state(game)->save.player_lv = 99999;
}

static void read_save(game_t *game)
{
    int fd = open("save", O_RDONLY);
    int magic = 0;
    ssize_t size = 0;

    if (fd == -1)
        return ((void)default_save(game, fd));
    size = read(fd, &magic, sizeof(int));
    if (magic != SAVE_MAGIC_NUMBER || size == -1)
        return ((void)default_save(game, fd));
    size = read(fd, &get_game_state(game)->save, sizeof(game_save_t));
    if (size != sizeof(game_save_t) || size == -1)
        return ((void)default_save(game, fd));
    if (read(fd, &magic, 1) != 0)
        return ((void)default_save(game, fd));
    close(fd);
    game->scene->world_file = estrdup(get_game_state(game)->save.map_id);
    if (game->scene->world_file == NULL)
        return ((void)default_save(game, fd));
}

void save_current(game_t *game)
{
    FILE *file = NULL;

    if (IS_GAME_FINISHED(game))
        return;
    file = fopen("save", "w");
    if (file == NULL)
        return;
    estrncpy(get_game_state(game)->save.map_id, game->scene->world_file, 255);
    fwrite(&SAVE_MAGIC_NUMBER, sizeof(int), 1, file);
    fwrite(&get_game_state(game)->save, sizeof(game_save_t), 1, file);
    fclose(file);
    return;
}

bool configure_state(game_t *game)
{
    game_state_t *state = dcalloc(sizeof(game_state_t), 1);

    D_ASSERT(state, NULL, "", false);
    game->state = state;
    state->params.music_vol = 1;
    state->params.vfx_vol = 1;
    state->params.voice_vol = 1;
    read_save(game);
    return (true);
}
