/*
** EPITECH PROJECT, 2021
** LibErty
** File description:
** json_get_buff
*/

#include <erty/json.h>

OPT(string) json_get_buffer(const int fd)
{
    sstr_t string = init_string(NULL);
    char tmp[BUFF_CHUNK_JSON];

    if (fd == -1)
        return (EXPLICIT_ERR(string, string));
    ebzero(tmp, BUFF_CHUNK_JSON);
    while (read(fd, tmp, BUFF_CHUNK_JSON - 1) > 0) {
        if (string.append(&string, tmp) == -1)
            return (EXPLICIT_ERR(string, string));
        ebzero(tmp, BUFF_CHUNK_JSON);
    }
    return (OK(string, string));
}