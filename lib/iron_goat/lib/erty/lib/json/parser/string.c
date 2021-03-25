/*
** EPITECH PROJECT, 2021
** string
** File description:
** LibErty
*/

#include <erty/json.h>

struct escapes_equivalences {
    char code;
    char escape;
};

static const struct escapes_equivalences TOKENS_ESCAPE[] = {
    {'\"', '\"'},
    {'\\', '\\'},
    {'/', '/'},
    {'b', '\b'},
    {'f', '\f'},
    {'n', '\n'},
    {'r', '\r'},
    {'t', '\t'},
    {'u', 'u'}
};

static bool parse_escape(char const **buffer, char *c)
{
    (*buffer)++;
    for (usize_t i = 0; i < ARRAY_SIZE(TOKENS_ESCAPE); i++) {
        if (TOKENS_ESCAPE[i].code == **buffer) {
            *c = TOKENS_ESCAPE[i].escape;
            (*buffer)++;
            return (true);
        }
    }
    ASSERT("LibSeraph", "had trouble finding the good escape code");
    return (false);
}

bool json_parse_string_internal_end(char **res, char const **buffer,
                                    struct string_class *str)
{
    if (**buffer != '\"') {
        ASSERT("LibSeraph", "had trouble finding the end of the string");
        return (false);
    }
    *res = str->to_buf(str);
    (*buffer)++;
    return (true);
}

bool json_parse_string_internal(char **res, char const **buffer)
{
    char tmp[2] = {0};
    struct string_class str = init_string(NULL);

    while (**buffer) {
        if (**buffer == '\\') {
            if (parse_escape(buffer, &tmp[0]) == false)
                return (false);
            if (str.append(&str, tmp) == -1)
                return (false);
            continue;
        }
        if (**buffer == '\"')
            return (json_parse_string_internal_end(res, buffer, &str));
        tmp[0] = **buffer;
        (*buffer)++;
        if (str.append(&str, tmp) == -1)
            return (false);
    }
    return (json_parse_string_internal_end(res, buffer, &str));
}

bool json_parse_string(struct json *conf, char const **buffer)
{
    char *res = NULL;

    if (**buffer != '\"')
        return (false);
    (*buffer)++;
    if (json_parse_string_internal(&res, buffer) == false)
        return (false);
    conf->t = JSON_STR;
    conf->v.string = res;
    return (true);
}