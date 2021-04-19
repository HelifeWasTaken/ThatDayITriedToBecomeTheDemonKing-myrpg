/*
** EPITECH PROJECT, 2021
** mapdata
** File description:
** map
*/

#ifndef AF4E2DDF_6714_4AA1_AC07_EEBB4F57217B
    #define AF4E2DDF_6714_4AA1_AC07_EEBB4F57217B

    #include <SFML/Graphics.h>

    struct player_info {
        const int z_player;
        const sfVector2f pos;
    };

    struct map_files {
        const char *mapfile;
        const char *warpfile;
    };

    struct map_manager {
        const struct player_info p_info;
        const struct map_files m_files;
    };

    #define MAP_FILE_DIR "asset/map_asset/map_files"

    static const struct map_manager MAP_FILES[] = {
        {
            .p_info = {
                .z_player = 5,
                .pos = { 300, 309 }
            },
            .m_files = {
                .mapfile = MAP_FILE_DIR"/map_village.json",
                .warpfile = MAP_FILE_DIR"/warp_village.json"
            }
        },
        {
            .p_info = {
                .z_player = 2,
                .pos = { 530, 400 }
            },
            .m_files = {
                .mapfile = MAP_FILE_DIR"/map_monde.json",
                .warpfile = MAP_FILE_DIR"/warp_map_monde.json"
            }
        },
        {
            .p_info = {
                .z_player = 6,
                .pos = { 300, 309 }
            },
            .m_files = {
                .mapfile = MAP_FILE_DIR"/cattle.json",
                .warpfile = MAP_FILE_DIR"/castle_warp.json"
            }
        },
        {
            .p_info = {
                .z_player = 3,
                .pos = { 722, 119 }
            },
            .m_files = {
                .mapfile = MAP_FILE_DIR"/forest_map.json",
                .warpfile = MAP_FILE_DIR"/forest_warp.json"
            }
        },
        {
            .p_info = {
                .z_player = 4,
                .pos = { 408, 743 }
            },
            .m_files = {
                .mapfile = MAP_FILE_DIR"/desert.json",
                .warpfile = MAP_FILE_DIR"/warp_desert.json"
            }
        },
    };

    // If -1 is called there is a major problem
    // in the code as it should never be called at all
    static inline int get_matching_world(char *file)
    {
        for (unsigned int i = 0; i < ARRAY_SIZE(MAP_FILES); i++) {
            if (estrcmp(file, MAP_FILES[i].m_files.mapfile) == 0)
                return (i);
        }
        return (-1);
    }

#endif /* AF4E2DDF_6714_4AA1_AC07_EEBB4F57217B */
