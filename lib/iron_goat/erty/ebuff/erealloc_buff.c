/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** erealloc_buff
*/

#include <erty/ebuffer.h>


static void *do_internal_ebuffer_realloc(
        void *old_ptr, size_t new_size, size_t old_size)
{
    void *ptr = ecalloc(new_size, 1);

    if (ptr)
        ememcpy(ptr, old_ptr, old_size);
    efree(old_ptr);
    old_ptr = ptr;
    return (old_ptr);
}

static void *internal_ebuffer_realloc(
        void *old_ptr, size_t old_size, size_t new_size)
{
    if (!new_size)
        return (NULL);
    if (new_size <= old_size)
        return (old_ptr);
    else
        return (do_internal_ebuffer_realloc(old_ptr, new_size, old_size));
}

ssize_t erealloc_buff(ebuff_t **buff_info, size_t toadd)
{
    if (!(*buff_info))
        return (-1);
    (*buff_info)->buff = internal_ebuffer_realloc(
            (*buff_info)->buff, (*buff_info)->buff_size,
            (*buff_info)->buff_size + toadd + BUFF_CHUNK);
    if (!(*buff_info)->buff)
        return (-1);
    (*buff_info)->buff_size += toadd + BUFF_CHUNK;
    return (1);
}
