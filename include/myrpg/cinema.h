/*
** EPITECH PROJECT, 2021
** cinema
** File description:
** rpg
*/

#ifndef E6D588AA_7D6D_4915_A5DE_40860486DCD3
    #define E6D588AA_7D6D_4915_A5DE_40860486DCD3

    #include <stdlib.h>
    #include "myrpg/entities.h"
    #include "erty/ectypes.h"
    #include <stdbool.h>
    #include <stdint.h>

    extern bool GBL_IS_IN_CINEMATIC;

    enum cinema_type {
        SET_CAMERA,
        MOVE_CAMERA,
        DISP_TEXT
    };

    typedef struct cinema {
        enum cinema_type type;
        int cycle_count;
        union {
            struct {
                int64_t x;
                int64_t y;
            } set;
            struct {
                int64_t x;
                int64_t y;
            } move;
            char *disp;
        } u;
        struct cinema *next;
    } cinema_t;

    bool push_back_cinema(struct cinema **head, struct cinema *data);
    void pop_front_cinema(struct cinema **head);
    long long rpg_strtoll(char *str, char **endptr);
    void parse_space(char **buf);
    bool parse_move_camera(struct cinema **head, char *buf);
    bool parse_set_camera(struct cinema **head, char *buf);
    bool parse_disp_text(struct cinema **head, char *buf);

    bool cinema_reader_command(struct cinema **head, char const *filepath);

    typedef struct cinema_entity {
        entity_t *entity;
        struct cinema *cine;
        pausable_clock_t *clock;
    } cinema_entity_t;

    bool create_cinema(game_t *game, entity_t *entity);
    void update_cinema(game_t *game, entity_t *entity);
    void destroy_cinema(game_t *game, entity_t *entity);

#endif /* E6D588AA_7D6D_4915_A5DE_40860486DCD3 */