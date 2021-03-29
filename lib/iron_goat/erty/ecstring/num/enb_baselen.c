/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** enblen
*/

#include <erty/ectypes.h>

static u64_t do_enb_baselen(i64_t nb, u8_t base_size)
{
    return ((nb >= base_size) ?
        do_enb_baselen(nb / base_size, base_size) + 1 : 1);
}

u64_t enb_baselen(i64_t nb, u8_t base_size)
{
    return ((nb > 0) ?
        do_enb_baselen(nb, base_size) : do_enb_baselen(-nb, base_size) + 1);
}