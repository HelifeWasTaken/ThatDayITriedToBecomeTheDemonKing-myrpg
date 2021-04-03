/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** ewchar
*/

#ifndef __LIBERTY__EWCHAR_T__H__
    #define __LIBERTY__EWCHAR_T__H__

    ////////////////////////////////////////////////////////////
    // Headers
    ////////////////////////////////////////////////////////////

    #include <wchar.h>
    #include <erty/ectypes.h>

    //   _    _ _     _      _____ _
    //  | |  | (_)   | |    /  ___| |
    //  | |  | |_  __| | ___\ `--.| |_ _ __
    //  | |/\| | |/ _` |/ _ \`--. \ __| '__|
    //  \  /\  / | (_| |  __/\__/ / |_| |
    //   \/  \/|_|\__,_|\___\____/ \__|_|
    //

    ////////////////////////////////////////////////////////////
    ///
    /// \brief Compute the size of a wide string
    ///
    /// \param wcs widestring to compute size
    ///
    /// \return the size of the widestring
    ///
    ////////////////////////////////////////////////////////////

    size_t ewcslen(wchar_t const *wcs);

    ////////////////////////////////////////////////////////////
    ///
    /// \brief Compute the size of a wide string and returns it in bytes
    ///
    /// \param str widestring to compute size
    ///
    /// \return ewcslen(wcs) * (sizeof(wchar_t))
    ///
    ////////////////////////////////////////////////////////////

    size_t convert_ewcslen(wchar_t const *wcs);

    ////////////////////////////////////////////////////////////
    ///
    /// \brief Converts a wide char to a char
    ///
    /// \param c char to convert
    ///
    /// \return wide char converted
    ///
    ////////////////////////////////////////////////////////////

    char convert_wchr_to_chr(wchar_t c);

    ////////////////////////////////////////////////////////////
    ///
    /// \brief Converts a wide string to a string up to buffsize
    ///        buff must have enough allocated space to contain
    ///        the widestring len + 1
    ///
    /// \param buff buffer to fill with conversion
    ///
    /// \param wcs wide string to convert
    ///
    /// \param nb bytes
    ///
    /// \return wide char converted that might have 0 terminated
    ///
    ////////////////////////////////////////////////////////////

    cstr_t ewcstombs(cstr_t buf, const wchar_t *wcs, size_t buffsize);

    ////////////////////////////////////////////////////////////
    ///
    /// \brief Converts a wide string to a string up to buffsize
    ///        buff and prints it
    ///
    /// \param fd file descriptor
    ///
    /// \param buf wide string to print
    ///
    /// \return nb of bytes written (returns -1 if write failed)
    ///
    ////////////////////////////////////////////////////////////

    size_t ewcsputs(fd_t fd, void const *buf);

#endif /* !__LIBERTY__EWCHAR_T__H__ */