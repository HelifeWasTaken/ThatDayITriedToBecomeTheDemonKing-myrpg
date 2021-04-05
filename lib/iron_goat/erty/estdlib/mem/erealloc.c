/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** erealloc
*/

#include <erty/string/ecstring.h>

static void *do_erealloc(void *old_ptr, size_t new_size, size_t old_size)
{
    void *ptr = emalloc(new_size);

    if (ptr)
        ememcpy(ptr, old_ptr, old_size);
    efree(old_ptr);
    old_ptr = ptr;
    return (old_ptr);
}

void *erealloc(void *old_ptr, size_t old_size, size_t new_size)
{
    if (!new_size)
        return (NULL);
    if (new_size <= old_size)
        return (old_ptr);
    else
        return (do_erealloc(old_ptr, new_size, old_size));
}