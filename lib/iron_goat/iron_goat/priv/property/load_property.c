/*
** EPITECH PROJECT, 2021
** load
** File description:
** property
*/

#include "property.h"

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
    ememcpy(ptr + offset, conf->v.null, IG_PROPS_TOKENS_PARSER[i].size_arg);
    return (true);
}

bool iron_goat_get_property(struct json *conf, struct iron_goat_property *self)
{
    for (size_t i = 0; i < ARRAY_SIZE(IG_PROPS_TOKENS_PARSER); i++) {
        if (conf->t == IG_PROPS_TOKENS_PARSER[i].type) {
            return (iron_goat_set_property(conf, self, i));
        }
    }
    ASSERT("Json", "Error while parsing property");
    return (false);
}
