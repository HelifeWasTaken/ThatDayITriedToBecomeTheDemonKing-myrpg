/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** eoverflow
*/

#ifndef __LIBERTY__EOVERFLOW__H__
    #define __LIBERTY__EOVERFLOW__H__

    //   _____                     __ _
    //  |  ___|                   / _| |
    //  | |__  _____   _____ _ __| |_| | _____      __
    //  |  __|/ _ \ \ / / _ \ '__|  _| |/ _ \ \ /\ / /
    //  | |__| (_) \ V /  __/ |  | | | | (_) \ V  V /
    //  \____/\___/ \_/ \___|_|  |_| |_|\___/ \_/\_/
    //

    ////////////////////////////////////////////////////////////
    ///
    /// \brief These built-in functions are similar to __builtin_add_overflow,
    ///        builtin_sub_overflow, or __builtin_mul_overflow,
    ///        except that they don’t store the result of the arithmetic
    ///        operation anywhere and the last argument is not a pointer,
    ///        but some expression with integral type other
    ///        than enumerated or boolean type.
    ///        The built-in functions promote the first two operands into
    ///        infinite precision signed type and perform addition on those
    ///        promoted operands. The result is then cast to the type of the
    ///        third argument. If the cast result is equal to the infinite
    ///        precision result, the built-in functions return false,
    ///        otherwise they return true. The value of the third argument
    ///        is ignored, just the side effects in the third argument are
    ///        evaluated, and no integral argument promotions are performed
    ///        on the last argument. If the third argument is a bit-field,
    ///        the type used for the result cast has the precision and
    ///        signedness of the given bit-field, rather than precision and
    ///        signedness of the underlying type.
    ///
    /// \param a Integer one
    ///
    /// \param b Integer two
    ///
    /// \return true if overflow is detected false if not
    ///
    ////////////////////////////////////////////////////////////

    #define ADD_OVERFLOW_CHECK(a, b) \
        __builtin_add_overflow_p(a, b, (__typeof__((a) + (b))) 0)

    ////////////////////////////////////////////////////////////
    ///
    /// \brief These built-in functions are similar to __builtin_add_overflow,
    ///        builtin_sub_overflow, or __builtin_mul_overflow,
    ///        except that they don’t store the result of the arithmetic
    ///        operation anywhere and the last argument is not a pointer,
    ///        but some expression with integral type other
    ///        than enumerated or boolean type.
    ///        The built-in functions promote the first two operands into
    ///        infinite precision signed type and perform addition on those
    ///        promoted operands. The result is then cast to the type of the
    ///        third argument. If the cast result is equal to the infinite
    ///        precision result, the built-in functions return false,
    ///        otherwise they return true. The value of the third argument
    ///        is ignored, just the side effects in the third argument are
    ///        evaluated, and no integral argument promotions are performed
    ///        on the last argument. If the third argument is a bit-field,
    ///        the type used for the result cast has the precision and
    ///        signedness of the given bit-field, rather than precision and
    ///        signedness of the underlying type.
    ///
    /// \param a Integer one
    ///
    /// \param b Integer two
    ///
    /// \return true if overflow is detected false if not
    ///
    ////////////////////////////////////////////////////////////

    #define SUB_OVERFLOW_CHECK(a, b) \
        __builtin_sub_overflow_p(a, b, (__typeof__((a) + (b))) 0)

    ////////////////////////////////////////////////////////////
    ///
    /// \brief These built-in functions are similar to __builtin_add_overflow,
    ///        builtin_sub_overflow, or __builtin_mul_overflow,
    ///        except that they don’t store the result of the arithmetic
    ///        operation anywhere and the last argument is not a pointer,
    ///        but some expression with integral type other
    ///        than enumerated or boolean type.
    ///        The built-in functions promote the first two operands into
    ///        infinite precision signed type and perform addition on those
    ///        promoted operands. The result is then cast to the type of the
    ///        third argument. If the cast result is equal to the infinite
    ///        precision result, the built-in functions return false,
    ///        otherwise they return true. The value of the third argument
    ///        is ignored, just the side effects in the third argument are
    ///        evaluated, and no integral argument promotions are performed
    ///        on the last argument. If the third argument is a bit-field,
    ///        the type used for the result cast has the precision and
    ///        signedness of the given bit-field, rather than precision and
    ///        signedness of the underlying type.
    ///
    /// \param a Integer one
    ///
    /// \param b Integer two
    ///
    /// \return true if overflow is detected false if not
    ///
    ////////////////////////////////////////////////////////////

    #define MUL_OVERFLOW_CHECK(a, b) \
        __builtin_mul_overflow_p(a, b, (__typeof__((a) + (b))) 0)

#endif /* !__LIBERTY__EOVERFLOW__H__ */