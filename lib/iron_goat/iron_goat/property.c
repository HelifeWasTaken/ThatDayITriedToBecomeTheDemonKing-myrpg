/*
** EPITECH PROJECT, 2021
** property
** File description:
** prop
*/

#include <iron_goat/deser.h>

void destroy_iron_goat_property(struct iron_goat_property *self)
{
    FREE(self->name);
    switch (self->type) {
        case PROP_STRING:
            FREE(self->value.str);
            break;
        case PROP_FILE:
            FREE(self->value.file);
            break;
        default:
            break;
    }
}

struct iron_goat_get_property_parser {
    enum json_type type;
    size_t size_arg;
    bool (*callback)();
    ig_property_type_t prop;
};

static const struct iron_goat_get_property_parser IG_PROPS_TOKENS_PARSER[] = {
    {JSON_STR, sizeof(char *), iron_goat_get_string, PROP_STRING},
    {JSON_NUM, sizeof(int64_t), NULL, PROP_INT}
};

static bool iron_goat_set_property(struct json *conf,
    struct iron_goat_property *self, size_t i)
{
    char *ptr = (char *)self;
    size_t offset = offsetof(struct iron_goat_property, value);

    self->type = IG_PROPS_TOKENS_PARSER[i].prop;
    if (IG_PROPS_TOKENS_PARSER[i].callback != NULL)
        return (IG_PROPS_TOKENS_PARSER[i].callback(conf,
            offset, ptr));
    ememcpy(ptr + offset, &conf->v.number, IG_PROPS_TOKENS_PARSER[i].size_arg);
    return (true);
}

static bool iron_goat_get_property(struct json *conf,
                                    struct iron_goat_property *self)
{
    for (size_t i = 0; i < ARRAY_SIZE(IG_PROPS_TOKENS_PARSER); i++) {
        if (conf->t == IG_PROPS_TOKENS_PARSER[i].type) {
            return (iron_goat_set_property(conf, self, i));
        }
    }
    ASSERT("Json", "Error while parsing property");
    return (false);
}

// Here type is not defined
// because it will be defined in the .value internal function
static const struct json_deser_data IG_PROPS[] = {
    {
        .data = ".name",
        .size_data = sizeof(char *),
        .offset = offsetof(struct iron_goat_property, name),
        .intern = {
            .callback = iron_goat_get_string,
            .woff = true
        },
        .type = JSON_STR
    },
    {
        .data = ".value",
        .size_data = sizeof(union iron_goat_property_value),
        .offset = offsetof(struct iron_goat_property, value),
        .intern = {
            .callback = iron_goat_get_property,
            .woff = false
        },
        .type = JSON_ANY
    }
};

bool init_iron_goat_props(struct json *conf, struct iron_goat_property *self)
{
    DESER_LOOP(conf, self, IG_PROPS);
}