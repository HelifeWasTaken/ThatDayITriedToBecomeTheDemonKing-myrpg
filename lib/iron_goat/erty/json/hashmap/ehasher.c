/*
** EPITECH PROJECT, 2021
** LibErty
** File description:
** ehasher
*/

#include <erty/json.h>

u64_t ehasher(const void *data)
{
    const u8_t *data_cs = (const u8_t*) data;
    u64_t hash = 0;

    for (usize_t i = 0; data_cs[i]; i++)
        hash = data_cs[i] + (hash << 6) + (hash << 16) - hash;
    return (hash);
}
