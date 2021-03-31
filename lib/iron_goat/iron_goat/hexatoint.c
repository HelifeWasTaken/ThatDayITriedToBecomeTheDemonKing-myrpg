/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** hexatoint.c
*/

#include <iron_goat/deser.h>

static bool check_base(char c, char const *base, u32_t *index)
{
    for (*index = 0; base[*index] != '\0'; (*index)++) {
        if (base[*index] == c)
            return (true);
    }
    return (false);
}

bool hextoint(char const *str, u32_t *nb)
{
    char const base[17] = "0123456789ABCDEF\0";
    u32_t tmp = 0;
    usize_t i = 0;

    *nb = 0;
    for (; str[i] != '\0'; i++) {
        *nb *= 16;
        if (check_base(str[i], base, &tmp) == false)
            return (false);
        *nb += tmp;
    }
    return (str[i] == '\0');
}

bool iron_goat_get_color(struct json *conf, size_t offset, void *data)
{
    char *s = conf->v.string;
    u32_t nb = 0;

    if (*s != '#')
        ASSERT("Json", "Color does not start with a #");
    s++;
    if (hextoint(s, &nb) == false) {
        ASSERT("Json", "Hex was not correctly formatted");
        return (false);
    }
    SET_ATTRIBUTE(data, offset, sizeof(nb), nb);
    return (true);
}