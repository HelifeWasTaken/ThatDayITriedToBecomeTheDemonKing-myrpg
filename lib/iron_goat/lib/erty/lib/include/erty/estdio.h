/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** estdio
*/

#ifndef __LIBERTY__ESTDIO__H__
    #define __LIBERTY__ESTDIO__H__

    ////////////////////////////////////////////////////////////
    // Headers
    ////////////////////////////////////////////////////////////

    #include <erty/efile.h>
    #include <erty/eprintf.h>
    #include <erty/eassert.h>

    //   _____ _      _             _
    //  /  ___| |    | |           | |
    //  \ `--.| |_ __| | ___  _   _| |_
    //   `--. \ __/ _` |/ _ \| | | | __|
    //  /\__/ / || (_| | (_) | |_| | |_
    //  \____/ \__\__,_|\___/ \__,_|\__|
    //

    ////////////////////////////////////////////////////////////
    ///
    /// \brief prints a char in stdout filestream
    ///
    /// \param c    char to print
    ///
    /// \return Returns 1 in case of success -1 if write failed
    ///
    ////////////////////////////////////////////////////////////

    ssize_t eputchar(i32_t c);

    ////////////////////////////////////////////////////////////
    ///
    /// \brief prints a string with a line break in a stdout filestream
    ///
    /// \param str  string to print
    ///
    /// \return Returns the size of the string + 2
    ///         in case of success or -1 if write failed
    ///
    ////////////////////////////////////////////////////////////

    ssize_t eputs(const_cstr_t str);

    //   _____ _      _
    //  /  ___| |    | |
    //  \ `--.| |_ __| | ___ _ __ _ __
    //   `--. \ __/ _` |/ _ \ '__| '__|
    //  /\__/ / || (_| |  __/ |  | |
    //  \____/ \__\__,_|\___|_|  |_|
    //

    ////////////////////////////////////////////////////////////
    ///
    /// \brief prints a char in stderr filestream
    ///
    /// \param c    char to print
    ///
    /// \return Returns 1 in case of success -1 if write failed
    ///
    ////////////////////////////////////////////////////////////

    ssize_t e_errputchar(i32_t c);

    ////////////////////////////////////////////////////////////
    ///
    /// \brief prints a string with a line break in a stderr filestream
    ///
    /// \param str  string to print
    ///
    /// \return Returns the size of the string + 2
    ///         in case of success or -1 if write failed
    ///
    ////////////////////////////////////////////////////////////

    ssize_t e_errputs(const_cstr_t str);

#endif /* !__LIBERTY__ESTDIO__H__ */