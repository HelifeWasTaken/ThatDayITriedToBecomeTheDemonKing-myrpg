/*
** EPITECH PROJECT, 2021
** map
** File description:
** map
*/

#include <iron_goat/deser.h>

void destroy_iron_goat_map(struct iron_goat_map *self)
{
    if (self->layers)
        self->layers->clear(&self->layers);
    if (self->properties)
        self->properties->clear(&self->properties);
    FREE(self->tiledversion);
    if (self->tilesets)
        self->tilesets->clear(&self->tilesets);
}

bool load_iron_goat_map_layers(struct json *conf,
    struct iron_goat_map *self)
{
    struct json_array *data = conf->v.array;
    struct iron_goat_layer layer = {0};

    if ((self->layers = VECTOR_CREATE(ig_layer)) == NULL)
        return (false);
    for (size_t i = 0; i < data->size; i++) {
        layer = (struct iron_goat_layer){0};
        if (init_iron_goat_layer(&data->data[i], &layer) == false)
            return (false);
        if (self->layers->push_back(&self->layers, layer) == -1)
            return (false);
    }
    return (true);
}

bool load_iron_goat_map_properties(struct json *conf,
    struct iron_goat_map *self)
{
    struct json_array *data = conf->v.array;
    struct iron_goat_property prop = {0};

    if ((self->properties = VECTOR_CREATE(ig_prop)) == NULL)
        return (false);
    for (size_t i = 0; i < data->size; i++) {
        prop = (struct iron_goat_property){0};
        if (init_iron_goat_props(&data->data[i], &prop) == false)
            return (false);
        if (self->properties->push_back(&self->properties, prop) == -1)
            return (false);
    }
    return (true);
}

struct iron_goat_orientation_parser {
    ig_map_orient_t type;
    char *match;
};

static const struct iron_goat_orientation_parser IG_ORI_TOKENS_PARSER[] = {
    {MAP_ORTHOGONAL, "orthogonal"},
    {MAP_ISOMETRIC, "isometric"},
    {MAP_STAGGERED, "staggered"},
    {MAP_HEXAGONAL, "hexagonal"}
};

bool load_iron_goat_map_orientation(struct json *conf,
    struct iron_goat_map *self)
{
    char *s = conf->v.string;

    for (size_t i = 0; i < ARRAY_SIZE(IG_ORI_TOKENS_PARSER); i++) {
        if (estrcmp(s, IG_ORI_TOKENS_PARSER[i].match) == 0) {
            self->orientation = IG_ORI_TOKENS_PARSER[i].type;
            return (true);
        }
    }
    ASSERT("Json", "Orientation has a invalid or corrupted value");
    return (false);
}

struct iron_goat_renderorder_parser {
    ig_map_renderorder_t type;
    char *match;
};

static const struct iron_goat_renderorder_parser IG_RORD_TOKENS_PARSER[] = {
    {MAP_RIGHT_DOWN, "right-down"},
    {MAP_RIGHT_UP, "right-up"},
    {MAP_LEFT_DOWN, "left-down"},
    {MAP_LEFT_UP, "left-up"}
};

bool load_iron_goat_map_renderorder(struct json *conf,
    struct iron_goat_map *self)
{
    char *s = conf->v.string;

    for (size_t i = 0; i < ARRAY_SIZE(IG_RORD_TOKENS_PARSER); i++) {
        if (estrcmp(s, IG_RORD_TOKENS_PARSER[i].match) == 0) {
            self->renderorder = IG_RORD_TOKENS_PARSER[i].type;
            return (true);
        }
    }
    ASSERT("Json", "Renderorder has a invalid or corrupted value");
    return (false);
}

struct iron_goat_staggeraxis_parser {
    ig_map_staggeraxis_t type;
    char *match;
};

static const struct iron_goat_staggeraxis_parser IG_STAX_TOKENS_PARSER[] = {
    {MAP_STAG_X, "x"},
    {MAP_STAG_Y, "y"}
};

bool load_iron_goat_map_staggeraxis(struct json *conf,
    struct iron_goat_map *self)
{
    char *s = conf->v.string;

    for (size_t i = 0; i < ARRAY_SIZE(IG_STAX_TOKENS_PARSER); i++) {
        if (estrcmp(s, IG_STAX_TOKENS_PARSER[i].match) == 0) {
            self->staggeraxis = IG_STAX_TOKENS_PARSER[i].type;
            return (true);
        }
    }
    ASSERT("Json", "StaggerAxis has a invalid or corrupted value");
    return (false);
}

struct iron_goat_staggerindex_parser {
    ig_map_staggerindex_t type;
    char *match;
};

static const struct iron_goat_staggerindex_parser IG_STAI_TOKENS_PARSER[] = {
    {MAP_STAG_ODD, "odd"},
    {MAP_STAG_EVEN, "even"}
};

bool load_iron_goat_map_staggerindex(struct json *conf,
    struct iron_goat_map *self)
{
    char *s = conf->v.string;

    for (size_t i = 0; i < ARRAY_SIZE(IG_STAI_TOKENS_PARSER); i++) {
        if (estrcmp(s, IG_STAI_TOKENS_PARSER[i].match) == 0) {
            self->staggerindex = IG_STAI_TOKENS_PARSER[i].type;
            return (true);
        }
    }
    ASSERT("Json", "Staggerindex has a invalid or corrupted value");
    return (false);
}

bool load_iron_goat_map_tilesets(struct json *conf,
    struct iron_goat_map *self)
{
    struct json_array *data = conf->v.array;
    struct iron_goat_tile tile = {0};

    if ((self->tilesets = VECTOR_CREATE(ig_tile)) == NULL)
        return (false);
    for (size_t i = 0; i < data->size; i++) {
        tile = (struct iron_goat_tile){0};
        if (init_iron_goat_tile(&data->data[i], &tile) == false)
            return (false);
        if (self->tilesets->push_back(&self->tilesets, tile) == -1)
            return (false);
    }
    return (true);
}

static const struct json_deser_data IG_MAP[] = {
    {
        .data = ".backgroundcolor",
        .size_data = sizeof(u32_t),
        .offset = offsetof(struct iron_goat_map, backgroundcolor),
        .intern = {
            .callback = iron_goat_get_color,
            .woff = true
        },
        .type = JSON_STR,
        .opt = true
    },
    {
        .data = ".compressionlevel",
        .size_data = sizeof(i64_t),
        .offset = offsetof(struct iron_goat_map, compressionlevel),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    },
    {
        .data = ".height",
        .size_data = sizeof(u64_t),
        .offset = offsetof(struct iron_goat_map, height),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    },
    {
        .data = ".hexsidelenght",
        .size_data = sizeof(i64_t),
        .offset = offsetof(struct iron_goat_map, hexsidelenght),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = true
    },
    {
        .data = ".infinite",
        .size_data = sizeof(bool),
        .offset = offsetof(struct iron_goat_map, infinite),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_BOOL,
        .opt = false
    },
    {
        .data = ".layers",
        .size_data = sizeof(VECTOR(ig_layer) *),
        .offset = offsetof(struct iron_goat_map, layers),
        .intern = {
            .callback = load_iron_goat_map_layers,
            .woff = false
        },
        .type = JSON_ARR,
        .opt = false
    },
    {
        .data = ".nextlayerid",
        .size_data = sizeof(i64_t),
        .offset = offsetof(struct iron_goat_map, nextlayerid),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    },
    {
        .data = ".nextobjectid",
        .size_data = sizeof(i64_t),
        .offset = offsetof(struct iron_goat_map, nextobjectid),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    },
    {
        .data = ".orientation",
        .size_data = sizeof(ig_map_orient_t),
        .offset = offsetof(struct iron_goat_map, orientation),
        .intern = {
            .callback = load_iron_goat_map_orientation,
            .woff = false
        },
        .type = JSON_STR,
        .opt = false
    },
    {
        .data = ".properties",
        .size_data = sizeof(VECTOR(ig_prop) *),
        .offset = offsetof(struct iron_goat_map, properties),
        .intern = {
            .callback = load_iron_goat_map_properties,
            .woff = false
        },
        .type = JSON_ARR,
        .opt = true
    },
    {
        .data = ".renderorder",
        .size_data = sizeof(ig_map_renderorder_t),
        .offset = offsetof(struct iron_goat_map, renderorder),
        .intern = {
            .callback = load_iron_goat_map_renderorder,
            .woff = false
        },
        .type = JSON_STR,
        .opt = false
    },
    {
        .data = ".staggeraxis",
        .size_data = sizeof(ig_map_staggeraxis_t),
        .offset = offsetof(struct iron_goat_map, staggeraxis),
        .intern = {
            .callback = load_iron_goat_map_staggeraxis,
            .woff = false
        },
        .type = JSON_STR,
        .opt = true
    },
    {
        .data = ".staggerindex",
        .size_data = sizeof(ig_map_staggerindex_t),
        .offset = offsetof(struct iron_goat_map, staggerindex),
        .intern = {
            .callback = load_iron_goat_map_staggerindex,
            .woff = false
        },
        .type = JSON_STR,
        .opt = true
    },
    {
        .data = ".tiledversion",
        .size_data = sizeof(char *),
        .offset = offsetof(struct iron_goat_map, tiledversion),
        .intern = {
            .callback = iron_goat_get_string,
            .woff = true
        },
        .type = JSON_STR,
        .opt = false
    },
    {
        .data = ".tileheight",
        .size_data = sizeof(u64_t),
        .offset = offsetof(struct iron_goat_map, tileheight),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    },
    {
        .data = ".tilesets",
        .size_data = sizeof(VECTOR(ig_tile) *),
        .offset = offsetof(struct iron_goat_map, tilesets),
        .intern = {
            .callback = load_iron_goat_map_tilesets,
            .woff = false
        },
        .type = JSON_ARR,
        .opt = false
    },
    {
        .data = ".tilewidth",
        .size_data = sizeof(u64_t),
        .offset = offsetof(struct iron_goat_map, tilewidth),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    },
    {
        .data = ".type",
        .size_data = sizeof(char *),
        .offset = offsetof(struct iron_goat_map, type),
        .intern = {
            .callback = iron_goat_get_string,
            .woff = true
        },
        .type = JSON_STR,
        .opt = false
    },
    {
        .data = ".version",
        .size_data = sizeof(i64_t),
        .offset = offsetof(struct iron_goat_map, version),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    },
    {
        .data = ".width",
        .size_data = sizeof(u64_t),
        .offset = offsetof(struct iron_goat_map, width),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    }
};

bool init_iron_goat_map(struct json *conf, struct iron_goat_map *self)
{
    DESER_LOOP(conf, self, IG_MAP);
}