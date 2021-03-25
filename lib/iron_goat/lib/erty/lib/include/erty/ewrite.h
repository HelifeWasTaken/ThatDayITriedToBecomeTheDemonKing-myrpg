/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** ewrite
*/

#ifndef __LIBERTY__EWRITE__H__
    #define __LIBERTY__EWRITE__H__

    ////////////////////////////////////////////////////////////
    // Headers
    ////////////////////////////////////////////////////////////

    #include <unistd.h>
    #include <stdio.h>

    typedef int fd_t;

    ////////////////////////////////////////////////////////////
    ///
    /// \brief  Alias to syscall write
    ///
    /// \param fd     file descriptor to write in
    ///
    /// \param buf    buffer to print
    ///
    /// \param n      size to print
    ///
    /// \return Returns n in case of success -1 if write failed
    ///
    ////////////////////////////////////////////////////////////

    ssize_t ewrite(fd_t fd, void const *buf, size_t n);

    ////////////////////////////////////////////////////////////
    ///
    /// \brief  Alias to write syscall with file stream
    ///
    /// \param streal     file stream to write in
    ///
    /// \param buf    buffer to print
    ///
    /// \param n      size to print
    ///
    /// \return Returns n in case of success -1 if write failed
    ///
    ////////////////////////////////////////////////////////////

    ssize_t efwrite(FILE *stream, void const *buf, size_t n);

#endif /* !__LIBERTY__EWRITE__H__ */