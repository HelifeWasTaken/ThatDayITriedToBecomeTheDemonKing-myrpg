/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** ealloc
*/

#ifndef __LIBERTY__EALLOC__H__
    #define __LIBERTY__EALLOC__H__

    ////////////////////////////////////////////////////////////
    // Headers
    ////////////////////////////////////////////////////////////

    #include <stddef.h>

    //  ___  ___                       _ _                 _   _
    //  |  \/  |                      | | |               | | (_)
    //  | .  . | ___ _ __ ___     __ _| | | ___   ___ __ _| |_ _  ___  _ __
    //  | |\/| |/ _ \ '_ ` _ \   / _` | | |/ _ \ / __/ _` | __| |/ _ \| '_  |
    //  | |  | |  __/ | | | | | | (_| | | | (_) | (_| (_| | |_| | (_) | | | |
    //  \_|  |_/\___|_| |_| |_|  \__,_|_|_|\___/ \___\__,_|\__|_|\___/|_| |_|
    //

    ////////////////////////////////////////////////////////////
    ///
    /// \brief Alias to malloc system call
    ///
    /// \param size size in bytes to allocate
    ///
    /// \return Allocated pointer (returns null in case of failure)
    ///
    ////////////////////////////////////////////////////////////

    void *emalloc(size_t size);

    ////////////////////////////////////////////////////////////
    ///
    /// \brief Alias to free system call
    ///
    /// \param ptr Pointer to free
    ///
    /// \return Free the previsously ellocated
    ///         pointer (undefined behaviour may occur if pointer was not
    ///         allocated with malloc)
    ///
    ////////////////////////////////////////////////////////////

    void efree(void *ptr);

    ////////////////////////////////////////////////////////////
    ///
    /// \brief Allocates and sets at zero
    ///
    /// \param nmemb how many variables
    ///
    /// \param size variable size
    ///
    /// \return Allocates a pointer with emalloc and set it to zero
    ///         with ememset (ecstring.h)
    ///         In case of failure returns null
    ///
    ////////////////////////////////////////////////////////////

    void *ecalloc(size_t nmemb, size_t size);

    ////////////////////////////////////////////////////////////
    ///
    /// \brief Allocates a new pointer of new_size and copies the old pointer
    ///
    /// \param old_ptr The pointer that needs to be reallocated
    ///
    /// \param old_size Actual pointer size
    ///
    /// \param new_size Expected new_size
    ///
    /// \return Allocates a newpointer and copies the old pointer
    ///         If new_size is less than old_size so old_ptr is given back
    ///         If new_size == 0 a pointer to NULL is sent back and the old_ptr
    ///         is free
    ///         If allocation fail a pointer to NULL is sent back old_ptr will
    ///         be free
    ///
    ////////////////////////////////////////////////////////////

    void *erealloc(void *old_ptr, size_t old_size, size_t new_size);

    static inline void my_free(int n, ...)
    {
        __builtin_va_list ap;
        void *tmp = NULL;

        __builtin_va_start(ap, n);
        for (int i = 0; i < n; i++) {
            tmp = __builtin_va_arg(ap, void *);
            efree(tmp);
        }
    }

    #define new(var, size, nb) \
        var = (__typeof__(var))my_calloc(size, nb)

#endif /* !__LIBERTY__EALLOC__H__ */