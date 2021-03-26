/*
** EPITECH PROJECT, 2021
** load
** File description:
** layer
*/

#include "layer.h"

static const struct iron_goat_layer_type_parser LAYER_TOKEN_TYPE_PARSER[] = {
    {LAYER_TILELAYER, "tilelayer"},
    {LAYER_OBJECTGROUP, "objectgroup"},
    {LAYER_IMAGELAYER, "imagelayer"},
    {LAYER_GROUP, "group"}
};

static const struct iron_goat_layer_encoding_parser IG_ENCOD_TKNS_PARSER[] = {
    {LAYER_CSV, "csv"},
    {LAYER_BASE64, "base64"}
};

static const struct iron_goat_layer_draworder_parser IG_DRORD_TKNS_PARSER[] = {
    {LAYER_TOPDOWN, "topdown"},
    {LAYER_INDEX,     "index"}
};

bool load_iron_goat_layer_type(struct json *conf, struct iron_goat_layer *self)
{
    for (size_t i = 0; i < ARRAY_SIZE(LAYER_TOKEN_TYPE_PARSER); i++) {
        if (estrcmp(conf->v.string, LAYER_TOKEN_TYPE_PARSER[i].match) == 0) {
            self->type = LAYER_TOKEN_TYPE_PARSER[i].type;
            return (true);
        }
    }
    ASSERT("Json", "Layer type is unrecognized");
    return (false);
}

bool load_iron_goat_layer_chunks(struct json *conf,
        struct iron_goat_layer *self)
{
    struct json_array *data = conf->v.array;
    struct iron_goat_chunk chnk = {0};

    if ((self->chunks = VECTOR_CREATE(ig_chunk)) == NULL)
        return (false);
    for (size_t i = 0; i < data->size; i++) {
        chnk = (struct iron_goat_chunk){0};
        if (init_iron_goat_chunk(&data->data[i], &chnk) == false)
            return (false);
        if (self->chunks->push_back(&self->chunks, chnk) == -1)
            return (false);
    }
    return (true);
}

bool load_iron_goat_layer_data(struct json *conf,
    struct iron_goat_layer *self)
{
    struct json_array *data = conf->v.array;

    if ((self->data.data = emalloc(sizeof(u64_t) * (data->size))) == NULL)
        return (false);
    self->data.size = data->size;
    for (usize_t i = 0; i < self->data.size; i++) {
        self->data.data[i] = data->data[i].v.number;
    }
    return (true);
}

bool load_iron_goat_layer_encoding(struct json *conf,
    struct iron_goat_layer *self)
{
    for (size_t i = 0; i < ARRAY_SIZE(IG_ENCOD_TKNS_PARSER); i++) {
        if (estrcmp(conf->v.string, IG_ENCOD_TKNS_PARSER[i].match) == 0) {
            self->encoding = IG_ENCOD_TKNS_PARSER[i].type;
            return (true);
        }
    }
    ASSERT("Json", "Layer encoding data is corrupted");
    return (false);
}

bool load_iron_goat_layer_draworder(struct json *conf,
    struct iron_goat_layer *self)
{
    for (size_t i = 0; i < ARRAY_SIZE(IG_DRORD_TKNS_PARSER); i++) {
        if (estrcmp(conf->v.string, IG_DRORD_TKNS_PARSER[i].match) == 0) {
            self->draworder = IG_DRORD_TKNS_PARSER[i].type;
            return (true);
        }
    }
    ASSERT("Json", "Layer draworder data is corrupted");
    return (false);
}
