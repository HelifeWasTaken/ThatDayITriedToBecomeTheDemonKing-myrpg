/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** eassert
*/

#ifndef __LIBERTY__ASSERT__H__
    #define __LIBERTY__ASSERT__H__

    ////////////////////////////////////////////////////////////
    // Headers
    ////////////////////////////////////////////////////////////

    #include <erty/eprintf.h>
    #include <erty/ecolors.h>

    //    ___                    _
    //   / _ \                  | |
    //  / /_\ \___ ___  ___ _ __| |_
    //  |  _  / __/ __|/ _ \ '__| __|
    //  | | | \__ \__ \  __/ |  | |_
    //  \_| |_/___/___/\___|_|   \__|
    //

    ////////////////////////////////////////////////////////////
    ///
    /// \brief Eassert_t is a strcture that contains info
    ///         for assertion / log error
    ///
    /// \param prg The program name
    ///
    /// \param expr Expression assert
    ///
    /// \param file File of the current assert
    ///
    /// \param func Function where the assert has been created
    ///
    /// \param line Line where the assert has been created
    ///
    /// Usage:
    ///
    /// DEBUG_ASSERT(prg, erxpression) : Gives a debug log in stderr in color
    ///
    /// ASSERT(prg, expression) : Gives an error log in stderr in POSIX format
    ///
    ////////////////////////////////////////////////////////////

    typedef struct eassert_expr {
        const_cstr_t prg;
        const_cstr_t expr;
        const_cstr_t file;
        const_cstr_t func;
        i32_t line;
    } eassert_t;

    ////////////////////////////////////////////////////////////
    ///
    /// \brief Facilitate assertions
    ///
    /// \param assertinf structure that has assertion info
    ///
    ////////////////////////////////////////////////////////////

    static inline void edebugassert(eassert_t assertinf)
    {
        efprintf(stderr,
            "\033[31m%s: \033[0;33m%s [file: %s | func: %s |"
            " line: %d]\033[0;m\n",
            assertinf.prg, assertinf.expr, assertinf.file, assertinf.func,
            assertinf.line);
    }

    ////////////////////////////////////////////////////////////
    ///
    /// \brief Facilitate POSIX assertions
    ///
    /// \param assert structure that has assertion info
    ///
    ////////////////////////////////////////////////////////////

    static inline void eassert(eassert_t assertinf)
    {
        efprintf(stderr, "%s: %s\n", assertinf.prg, assertinf.expr);
    }

    #define HYPER_ASSERT

    #define DEBUG_ASSERT(prg, expr) \
        edebugassert((eassert_t){prg, expr, __FILE__, __func__, __LINE__})

    #ifndef HYPER_ASSERT
        #define ASSERT(prg, expr) \
            eassert((eassert_t){prg, expr, NULL, NULL, 0})
    #else
        #define ASSERT(prg, expr) DEBUG_ASSERT(prg, expr)
        #define ASSERT_RET(prg, expr, retv) \
            DEBUG_ASSERT(prg, expr); \
            return (retv)
    #endif

    #define DEBUG_PRINTF(format, ...) \
        efprintf(stderr, GREEN"%s:%d -> "BLUE"["format"]\n"DEFAULT, \
            __FILE__, __LINE__, ## __VA_ARGS__)

#endif /* !__LIBERTY__ASSERT__H__ */