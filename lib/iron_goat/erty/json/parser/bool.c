/*
** EPITECH PROJECT, 2021
** LibErty
** File description:
** json_bool
*/

#include <erty/json.h>

bool json_parse_boolean(struct json *conf, char const **buff)
{
    if (estrncmp(*buff, "true", 4) != 0) {
        if (estrncmp(*buff, "false", 5) != 0)
            return (false);
        *buff += 5;
        conf->v.boolean = false;
        conf->t = JSON_BOOL;
        return (true);
    }
    *buff += 4;
    conf->v.boolean = true;
    conf->t = JSON_BOOL;
    return (true);
}