/*
** EPITECH PROJECT, 2021
** json_parse
** File description:
** withespace
*/

#include <erty/json.h>

void json_parse_withe_space(char const **buff)
{
    if (buff && *buff)
        for (; IS_JSON_WITHESPACE(**buff); (*buff)++);
}