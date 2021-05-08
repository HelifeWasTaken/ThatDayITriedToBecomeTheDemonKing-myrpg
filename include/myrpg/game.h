/*
** EPITECH PROJECT, 2021
** game
** File description:
** Source code
*/

#ifndef C2B24367_058C_4C72_ADEA_FD6702E90B19
    #define C2B24367_058C_4C72_ADEA_FD6702E90B19

    #include "distract/entity.h"
    #include "distract/game.h"

    #include <fcntl.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <stddef.h>
    #include <stdlib.h>

    int load_game(void);
    bool configure_state(game_t *game);
    void save_current(game_t *game);
    void default_save(game_t *game, int fd);
    void not_implemented(game_t *game, entity_t *entity);

    enum {
        DEFAULT_SEED = 0xa1edCafe
    };

    union time_u {
        char s[sizeof(int64_t)];
        int64_t value;
    };

    static inline void seed_generator(void)
    {
        union time_u ptr;
        int fd = open("/dev/urandom", O_RDONLY);

        if (fd == -1 || read(fd, ptr.s, sizeof(int64_t)) == -1) {
            if (fd != -1)
                close(fd);
            srand(DEFAULT_SEED);
            return;
        }
        close(fd);
        srand(ptr.value);
    }

#endif /* C2B24367_058C_4C72_ADEA_FD6702E90B19 */
