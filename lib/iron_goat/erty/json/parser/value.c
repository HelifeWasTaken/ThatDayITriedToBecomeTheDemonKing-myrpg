/*
** EPITECH PROJECT, 2021
** json_parse_value
** File description:
** LibErty
*/

#include <erty/json.h>

struct json_token_parser {
    bool (*parser)(struct json *, char const **);
};

static const struct json_token_parser TOKENS_PARSER[] = {
    {json_parse_object},
    {json_parse_boolean},
    {json_parse_null},
    {json_parse_string},
    {json_parse_number},
    {json_parse_array}
};

static bool failure_parse_value(void)
{
    return (false);
}

bool json_parse_value(struct json *conf, char const **buff)
{
    usize_t i = 0;

    json_parse_withe_space(buff);
    for (; i < ARRAY_SIZE(TOKENS_PARSER) && buff && *buff; i++) {
        if (TOKENS_PARSER[i].parser(conf, buff) == true)
            return (true);
    }
    ASSERT("LibSeraph", "No parser accepted the conf");
    return (failure_parse_value());
}