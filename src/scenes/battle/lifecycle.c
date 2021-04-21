/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** lifecycle
*/

#include "distract/game.h"
#include "distract/entity.h"
#include "distract/resources.h"
#include "myrpg/entities.h"
#include "myrpg/state.h"
#include "myrpg/asset.h"
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Sprite.h>

int battle_lifecycle(game_t *game)
{
    sfEvent event;

    battledummy_t *dummy = create_entity(game, BATTLEDUMMY)->instance;
    dummy->can_attack = true;

    sfSprite_setTexture(dummy->sprite, create_texture(game, HERO_FIGHT_PATH, &FULL_HERO_FIGHT_RECT), true);

    dummy->entity->pos = VEC2F(150, 100);
    dummy->anim.animations[0] = (battledummy_animation_t){ .start_id=11, .end_id=13 };
    dummy->anim.animations[0] = (battledummy_animation_t){ .start_id=0, .end_id=3 };
    dummy->anim.animations[1] = (battledummy_animation_t){ .start_id=5, .end_id=7 };
    dummy->anim.frame_size = VEC2F(ONE_HERO_FIGHT_RECT.width,
        ONE_HERO_FIGHT_RECT.height);
    dummy->scale = HERO_SCALE;
    dummy->anim.frames_per_line = 5;
    dummy->current_anim = 1;
    dummy->current_frame = dummy->anim.animations[1].start_id;
    dummy->health = 10;
    dummy->attack = 100;
    dummy->level = 5;
    dummy->max_mana = 10;
    dummy->mana = dummy->max_mana;

    
    set_game_view(game, sfView_createFromRect((sfFloatRect){0, 0,
        game->mode.width / 3.f, game->mode.height / 3.f}));
    create_entity(game, BATTLEHUD);
    while (is_scene_updated(game)) {
        while (sfRenderWindow_pollEvent(game->window, &event))
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(game->window);
            else
                transmit_event_to_scene(game, &event);
        update_scene(game);
        sfRenderWindow_clear(game->window, sfBlack);
        draw_scene(game);
        sfRenderWindow_display(game->window);
    }
    destroy_scene(game, true);
    return (0);
}