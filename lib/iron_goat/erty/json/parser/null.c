/*
** EPITECH PROJECT, 2021
** LibErty
** File description:
** json_null
*/

#include <erty/json.h>

bool json_parse_null(struct json *conf, char const **buff)
{
    if (estrncmp(*buff, "null", 4) != 0)
        return (false);
    *buff += 4;
    conf->v.null = NULL;
    conf->t = JSON_NULL;
    return (true);
}