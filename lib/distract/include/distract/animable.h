/*
** EPITECH PROJECT, 2020
** MY_RPG_PUBLIC
** File description:
** animable.h
*/

#ifndef CAAC7402_55EF_480E_9385_40AE10D883F5
    #define CAAC7402_55EF_480E_9385_40AE10D883F5

    #include <SFML/System.h>
    #include <SFML/Graphics.h>
    #include <stdbool.h>

    typedef struct animation {
        int start_id;
        int end_id;
    } animation_t;

    typedef struct animable_info {
        sfSprite *sprite;
        sfVector2f frame_size;
        int frames_per_line;
        animation_t animations[50];
    } animable_info_t;

    typedef struct animable {
        int current_anim;
        int current_sheet_frame;
        animable_info_t info;
    } animable_t;

    void set_animable_frame(animable_t *animable, int id);
    void set_animable_animation(animable_t *animable, int id);

    int get_animable_frame(animable_t *animable);
    int get_animable_animation(animable_t *animable);

    bool is_animation_done(animable_t *animable);

    void set_animable_info(animable_t *animable, animable_info_t *info);

#endif /* CAAC7402_55EF_480E_9385_40AE10D883F5 */
