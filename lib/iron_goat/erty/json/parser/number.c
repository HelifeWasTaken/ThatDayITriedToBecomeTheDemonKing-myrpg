/*
** EPITECH PROJECT, 2021
** LibErty
** File description:
** num
*/

#include <erty/json.h>
#include <stdlib.h>

static bool json_strtoll(char const **ptr, int64_t *value)
{
    if (eis_num(**ptr) == false)
        return (false);
    while (eis_num(**ptr)) {
        *value = *value * 10 + (**ptr - '0');
        (*ptr)++;
    }
    return (true);
}

static bool json_parse_exponent(char const **ptr, struct json *conf)
{
    bool negative = false;
    int64_t value = 0;

    (*ptr)++;
    if (**ptr != '+' && **ptr != '-')
        return (false);
    if (**ptr == '-')
        negative = true;
    (*ptr)++;
    if (json_strtoll(ptr, &value) == false)
        return (false);
    for (int64_t i = 0; i < value; i++) {
        if (negative == true) {
            conf->v.number /= 10;
        } else {
            conf->v.number *= 10;
        }
    }
    return (true);
}

static bool json_parse_float_completely(struct json *conf, char const **ptr)
{
    int64_t number = 0;
    int64_t decimal = 0;
    f64_t divided = 0;

    if (json_strtoll(ptr, &number) == false)
        return (false);
    if (**ptr != '.')
        return (false);
    (*ptr)++;
    if (json_strtoll(ptr, &decimal) == false)
        return (false);
    divided = decimal;
    while (divided >= 10)
        divided /= 10;
    divided /= 10;
    conf->v.number = number + divided;
    return (true);
}

bool json_parse_integer(struct json *conf, char const **buffer)
{
    char const *ptr = *buffer;
    bool minus = false;
    int64_t v = 0;

    if (*ptr == '-') {
        ptr++;
        minus = true;
    }
    if (json_strtoll(&ptr, &v) == false)
        return (false);
    conf->v.number = v;
    if (*ptr == 'e' || *ptr == 'E')
        if (json_parse_exponent(&ptr, conf) == false)
            return (false);
    if (minus == true)
        conf->v.number = -conf->v.number;
    *buffer = ptr;
    conf->t = JSON_NUM;
    return (true);
}

bool json_parse_number(struct json *conf, char const **buffer)
{
    char const *ptr = *buffer;
    bool minus = false;

    if (*ptr == '-') {
        ptr++;
        minus = true;
    }
    if (json_parse_float_completely(conf, &ptr) == false)
        return (json_parse_integer(conf, buffer));
    if (*ptr == 'e' || *ptr == 'E') {
        if (json_parse_exponent(&ptr, conf) == false)
            return (false);
    }
    if (minus == true)
        conf->v.number = -conf->v.number;
    *buffer = ptr;
    conf->t = JSON_NUM;
    return (true);
}