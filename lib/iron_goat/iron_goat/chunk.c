/*
** EPITECH PROJECT, 2021
** chunk
** File description:
** chunk
*/

#include <iron_goat/deser.h>

static bool load_iron_goat_chunk_data(struct json *conf,
                                struct iron_goat_chunk *self)
{
    VECTOR(ig_u64) *vec = NULL;
    struct json_array *real_data = conf->v.array;
    u64_t v = 0;

    if ((vec = VECTOR_CREATE(ig_u64)) == NULL) {
        ASSERT("IronGoat", "Allocation error");
        return (false);
    }
    for (size_t i = 0; i < real_data->size; i++) {
        v = real_data->data[i].v.number;
        if (vec->push_back(&vec, v) == -1) {
            ASSERT("IronGoat", "Allocation error");
            return (false);
        }
    }
    self->data = vec;
    return (true);
}

static const struct json_deser_data IG_CHUNK_DATA[] = {
    {
        .data = ".data",
        .size_data = sizeof(VECTOR(ig_u64) *),
        .offset = offsetof(struct iron_goat_chunk, data),
        .intern = {
            .callback = load_iron_goat_chunk_data,
            .woff = false
        },
        .type = JSON_ARR,
        .opt = false
    },
    {
        .data = ".height",
        .size_data = sizeof(u64_t),
        .offset = offsetof(struct iron_goat_chunk, height),
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
        .offset = offsetof(struct iron_goat_chunk, width),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    },
    {
        .data = ".x",
        .size_data = sizeof(i64_t),
        .offset = offsetof(struct iron_goat_chunk, x),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    },
    {
        .data = ".y",
        .size_data = sizeof(i64_t),
        .offset = offsetof(struct iron_goat_chunk, y),
        .intern =  {
            .callback = NULL,
            .woff = false
        },
        .opt = false,
        .type = JSON_NUM
    }
};

void destroy_iron_goat_chunk(struct iron_goat_chunk *self)
{
    if (self->data)
        self->data->clear(&self->data);
}

bool init_iron_goat_chunk(struct json *conf, struct iron_goat_chunk *new)
{
    DESER_LOOP(conf, new, IG_CHUNK_DATA);
}