/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** eunblen
*/

#include <erty/ectypes.h>

u64_t eunb_baselen(u64_t nb, u8_t base_size)
{
    return ((nb >= base_size) ?
        eunb_baselen(nb / base_size, base_size) + 1 : 1);
}