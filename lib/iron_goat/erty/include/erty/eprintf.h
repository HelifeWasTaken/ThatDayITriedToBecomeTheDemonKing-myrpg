/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** eprintf
*/

#ifndef __LIBERTY__EPRINTF__H__
    #define __LIBERTY__EPRINTF__H__

    ////////////////////////////////////////////////////////////
    // Headers
    ////////////////////////////////////////////////////////////

    #include <stdarg.h>
    #include <erty/ebuffer.h>
    #include <erty/ectypes.h>
    #include <erty/ewchar.h>
    #include <inttypes.h>

    ////////////////////////////////////////////////////////////
    // Structures
    ////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////
    ///
    /// \brief Enum for each type of len modifiers
    ///
    ////////////////////////////////////////////////////////////

    enum {
        EPRINTF_MOD_CHAR,
        EPRINTF_MOD_SHORT,
        EPRINTF_MOD_LONG,
        EPRINTF_MOD_LONG_LONG,
        EPRINTF_MOD_LONG_DOUBLE,
        EPRINTF_MOD_INTMAX,
        EPRINTF_MOD_SIZE_T,
        EPRINTF_MOD_PTRDIFF_T,
        EPRINTF_MOD_DEFAULT
    };

    ////////////////////////////////////////////////////////////
    ///
    /// \brief Union having each type of variables that eprintf uses
    ///
    ////////////////////////////////////////////////////////////

    union eprintf_arg {
        i8_t chr;
        u8_t uchr;
        i16_t shrt;
        u16_t ushrt;
        i32_t i;
        u32_t ui;
        i64_t lng;
        u64_t ulng;
        long long llng;
        unsigned long long ullng;
        f64_t dble;
        wchar_t wchr;
        cstr_t str;
        wchar_t *wstr;
        intmax_t imax;
        uintmax_t uimax;
        size_t st;
        usize_t ptr;
        ptrdiff_t ptrdiff;
    };

    ////////////////////////////////////////////////////////////
    ///
    /// \brief Structure to keep the padding info
    ///
    /// \param size how much should be padded
    ///
    /// \param left if it should be on the left
    ///
    /// \param right if it should be on the right
    ///
    ////////////////////////////////////////////////////////////

    struct eprintf_padding {
        i32_t size;
        bool left;
        bool right;
    };

    ////////////////////////////////////////////////////////////
    ///
    /// \brief Structure to keep the padding info and type of padding
    ///
    /// \param precision precision chosen (is -1 when is default)
    ///
    /// \param pad reference to padding info struct
    ///
    /// \param hashtag has hashtag flag
    ///
    /// \param zero has zero flag
    ///
    /// \param minus has minus flag
    ///
    /// \param space has space flag
    ///
    /// \param plus has plus flag
    ///
    ////////////////////////////////////////////////////////////

    typedef struct eprintf_flag_modifier {
        i32_t precision;
        struct eprintf_padding pad;
        bool hashtag;
        bool zero;
        bool minus;
        bool space;
        bool plus;
    } eprintf_modflag_t;

    ////////////////////////////////////////////////////////////
    ///
    /// \brief Structure to keep the global tranformation info
    ///
    /// \param modflag reference to flag modifiers structure
    ///
    /// \param len  reference to the len modifier type
    ///
    /// \param offset offset for parsing
    ///
    ////////////////////////////////////////////////////////////

    typedef struct eprintf_modif_st {
        eprintf_modflag_t modflag;
        u8_t len;
        size_t offset;
    } eprintf_mod_t;

    ////////////////////////////////////////////////////////////
    ///
    /// \brief Structure to chose a function pointer
    ///
    /// \param flag flag type 1
    ///
    /// \param flag flag type 2
    ///
    /// \param fptr_local function pointer associated
    ///
    ////////////////////////////////////////////////////////////

    struct eprintf_flag_st {
        u8_t flag;
        u8_t flag2;
        void (*fptr_local)(ebuff_t **, va_list *, eprintf_mod_t *);
    };

    #ifdef __GNUC__
        #define CHECK_EPRINTF_FORMAT(variadic, format_str) \
            __attribute__((format(printf, variadic, format_str)))
        #define CHECK_FORMAT_WITH_GNU_C
    #endif

    #ifdef __DOXY
        #undef CHECK_FORMAT_WITH_GNU_C
        #undef CHECK_EPRINTF_FORMAT
    #endif

    #define EPRINTF_SUCCESS         (signed int)0
    #define EPRINTF_FAILURE         (signed int)-1
    #define EPRINTF_ERROR_FORMAT    (signed int)-2

    //   _____ _                  _               _
    //  /  ___| |                | |             | |
    //  \ `--.| |_ __ _ _ __   __| | __ _ _ __ __| |
    //   `--. \ __/ _` | '_ \ / _` |/ _` | '__/ _` |
    //  /\__/ / || (_| | | | | (_| | (_| | | | (_| |
    //  \____/ \__\__,_|_| |_|\__,_|\__,_|_|  \__,_|
    //

    ////////////////////////////////////////////////////////////
    ///
    /// \brief eprintf function functions nearly the same as printf prints the
    ///        formatted string to stdout
    ///
    /// \param format format of the output
    ///
    /// \param ... variadic list
    ///
    /// \return size of the formatted output (returns -1 in case of error)
    ///
    ////////////////////////////////////////////////////////////

    #ifdef CHECK_FORMAT_WITH_GNU_C
        i32_t eprintf(const_cstr_t format, ...)
            CHECK_EPRINTF_FORMAT(1, 2);
    #else
        i32_t eprintf(const_cstr_t format, ...);
    #endif

    ////////////////////////////////////////////////////////////
    ///
    /// \brief edprintf function functions nearly the same as dprintf prints the
    ///        formatted string to the specified fd
    ///        if the fd is between 0 and 2 chose to redirect it to file stream
    ///        stdin stdout or stderr
    ///
    /// \param fd file descriptor to write in
    ///
    /// \param format format of the output
    ///
    /// \param ... variadic list
    ///
    /// \return size of the formatted output (returns -1 in case of error)
    ///
    ////////////////////////////////////////////////////////////

    #ifdef CHECK_FORMAT_WITH_GNU_C
        i32_t edprintf(fd_t fd, const_cstr_t format, ...)
            CHECK_EPRINTF_FORMAT(2, 3);
    #else
        i32_t edprintf(fd_t fd, const_cstr_t format, ...);
    #endif

    ////////////////////////////////////////////////////////////
    ///
    /// \brief Own implementation of easprintf (does not work the same way)
    ///        if the given buffer is non NULL asprintf will free it before
    ///        setting everything in the new one
    ///
    /// \param buff buffer to write in
    ///
    /// \param format format of the output
    ///
    /// \param ... variadic list
    ///
    /// \return size of the formatted output (returns -1 in case of error)
    ///
    ////////////////////////////////////////////////////////////

    #ifdef CHECK_FORMAT_WITH_GNU_C
        i32_t easprintf(cstr_t *buff, const_cstr_t format, ...)
            CHECK_EPRINTF_FORMAT(2, 3);
    #else
        i32_t easprintf(cstr_t *buff, const_cstr_t format, ...);
    #endif

    ////////////////////////////////////////////////////////////
    ///
    /// \brief Is a an alias to edprintf writes directly on stream.__fileno
    ///
    /// \param stream file stream to write in
    ///
    /// \param format format of the output
    ///
    /// \param ... variadic list
    ///
    /// \return size of the formatted output (returns -1 in case of error)
    ///
    ////////////////////////////////////////////////////////////

    #ifdef CHECK_FORMAT_WITH_GNU_C
        i32_t efprintf(FILE *stream, const_cstr_t format, ...)
            CHECK_EPRINTF_FORMAT(2, 3);
    #else
        i32_t efprintf(FILE *stream, const_cstr_t format, ...);
    #endif

    //   _   _            _           _ _
    //  | | | |          (_)         | (_)
    //  | | | | __ _ _ __ _  __ _  __| |_  ___
    //  | | | |/ _` | '__| |/ _` |/ _` | |/ __|
    //  \ \_/ / (_| | |  | | (_| | (_| | | (__
    //   \___/ \__,_|_|  |_|\__,_|\__,_|_|\___|
    //

    ////////////////////////////////////////////////////////////
    ///
    /// \brief evprintf function functions nearly the same as vprintf
    ///        prints the formatted string to stdout
    ///
    /// \param format format of the output
    ///
    /// \param ap variadic list
    ///
    /// \return size of the formatted output (returns -1 in case of error)
    ///
    ////////////////////////////////////////////////////////////

    #ifdef CHECK_FORMAT_WITH_GNU_C
        i32_t evprintf(const_cstr_t format, va_list *ap)
            CHECK_EPRINTF_FORMAT(1, 0);
    #else
        i32_t evprintf(const_cstr_t format, va_list *ap);
    #endif

    ////////////////////////////////////////////////////////////
    ///
    /// \brief evdprintf function functions nearly the same as
    ///        dprintf prints the formatted string to the specified fd
    ///        if the fd is between 0 and 2 chose to redirect it to file stream
    ///        stdin stdout or stderr
    ///
    /// \param stream file stream to write in
    ///
    /// \param format format of the output
    ///
    /// \param ap variadic list
    ///
    /// \return size of the formatted output (returns -1 in case of error)
    ///
    ////////////////////////////////////////////////////////////

    #ifdef CHECK_FORMAT_WITH_GNU_C
        i32_t evdprintf(fd_t fd, const_cstr_t format, va_list *ap)
            CHECK_EPRINTF_FORMAT(2, 0);
    #else
        i32_t evdprintf(fd_t fd, const_cstr_t format, va_list *ap);
    #endif

    ////////////////////////////////////////////////////////////
    ///
    /// \brief Own implementation of vasprintf (does not work the same way)
    ///        if the given buffer is non NULL asprintf will free it before
    ///        setting everything in the new one
    ///
    /// \param buff buffer to write in
    ///
    /// \param format format of the output
    ///
    /// \param ap variadic list
    ///
    /// \return size of the formatted output (returns -1 in case of error)
    ///
    ////////////////////////////////////////////////////////////

    #ifdef CHECK_FORMAT_WITH_GNU_C
        i32_t evasprintf(cstr_t *buff, const_cstr_t format, va_list *ap)
            CHECK_EPRINTF_FORMAT(2, 0);
    #else
        i32_t evasprintf(cstr_t *buff, const_cstr_t format, va_list *ap);
    #endif

    ////////////////////////////////////////////////////////////
    ///
    /// \brief Is a an alias to evdprintf writes directly on stream.__fileno
    ///
    /// \param stream file stream to write in
    ///
    /// \param format format of the output
    ///
    /// \param ap variadic list
    ///
    /// \return size of the formatted output (returns -1 in case of error)
    ///
    ////////////////////////////////////////////////////////////

    #ifdef CHECK_FORMAT_WITH_GNU_C
        i32_t evfprintf(FILE *stream, const_cstr_t format, va_list *ap)
            CHECK_EPRINTF_FORMAT(2, 0);
    #else
        i32_t evfprintf(FILE *stream, const_cstr_t format, va_list *ap);
    #endif


/// HEADER

    ////////////////////////////////////////////////////////////
    ///
    /// \brief Gets the global buffer and returns the address of it
    ///
    /// \return The adress of the global printf buffer
    ///
    ////////////////////////////////////////////////////////////

    ebuff_t **eprintf_global_buff(void);

    ////////////////////////////////////////////////////////////
    ///
    /// \brief Gets the global buffer and frees it
    ///
    ////////////////////////////////////////////////////////////

    void eprintf_free_buff(void);

    ////////////////////////////////////////////////////////////
    ///
    /// \brief Should only be used localy (is used to reset the eprintf buffer)
    ///        (or create it when is NULL)
    ///
    /// \param buff pointer to the global eprintf buffer
    ///
    ////////////////////////////////////////////////////////////

    void eprintf_buffer_reset(ebuff_t **buff, bool flush, fd_t fd);

    ////////////////////////////////////////////////////////////
    ///
    /// \brief Formats a string in a buffer and returns it
    ///        (basically an automatic easprintf)
    ///
    /// \param format format of the output
    ///
    /// \param ... variadic list
    ///
    /// \return Returns the formatted buffer (Returns null if something failed)
    ///
    ////////////////////////////////////////////////////////////

    #ifdef CHECK_FORMAT_WITH_GNU_C
        cstr_t eformat(const_cstr_t format, ...)
            CHECK_EPRINTF_FORMAT(1, 2);
    #else
        cstr_t eformat(const_cstr_t format, ...);
    #endif

    //  ______
    //  | ___ |
    //  | |_/ /_ _ _ __ ___  ___ _ __
    //  |  __/ _` | '__/ __|/ _ \ '__|
    //  | | | (_| | |  \__ \  __/ |
    //  \_|  \__,_|_|  |___/\___|_|
    //

    ////////////////////////////////////////////////////////////
    ///
    /// \brief alias to keep code clean from weird pointer arithmetic
    ///        get the pointer at format + n
    ///
    /// \param format format string
    ///
    /// \param n size to go forward
    ///
    /// \return a pointer to format + n
    ///
    ////////////////////////////////////////////////////////////

    __always_inline static inline const_cstr_t get_format_at_index(
        const_cstr_t *format, size_t n)
    {
        return ((*format) + n);
    }

    ////////////////////////////////////////////////////////////
    ///
    /// \brief alias to keep code clean from weird pointer arithmetic
    ///        set format pointer as format + n
    ///
    /// \param format format string
    ///
    /// \param n size to go forward
    ///
    ////////////////////////////////////////////////////////////

    __always_inline static inline void consume_format_char(
        const_cstr_t *format, size_t n)
    {
        *format = get_format_at_index(format, n);
    }

    ////////////////////////////////////////////////////////////
    ///
    /// \brief alias to keep code clean from weird pointer arithmetic
    ///        get the char at format + n
    ///
    /// \param format format string
    ///
    /// \param n size to go forward
    ///
    /// \return the char at format + n
    ///
    ////////////////////////////////////////////////////////////

    __always_inline static inline char get_char_format_at_index(
        const_cstr_t *format,size_t n)
    {
        return (*(get_format_at_index(format, n)));
    }

    ////////////////////////////////////////////////////////////
    ///
    /// \brief where the parsing of the format string is done
    ///
    /// \param format format string
    ///
    /// \param ap variadic lits
    ///
    /// \return EPRINTF_SUCCESS on sucess or EPRINTF_FAILURE on failure
    ///
    ////////////////////////////////////////////////////////////

    ebuff_t **eprintf_parser(const_cstr_t format, bool flush,
                            fd_t fd, va_list *ap);

    ////////////////////////////////////////////////////////////
    ///
    /// \brief get the flag modifiers padding info and len modifier
    ///
    /// \param format format string
    ///
    /// \param ap variadic lits
    ///
    /// \return eprintf_mod_t structure containing parsing info
    ///
    ////////////////////////////////////////////////////////////

    eprintf_mod_t get_eprintf_modifications(const_cstr_t *format, va_list *ap);

    ////////////////////////////////////////////////////////////
    ///
    /// \brief get the flag modifiers and padding info
    ///
    /// \param format format string
    ///
    /// \param mod structure containing padding info
    ///
    /// \param ap variadic lits
    ///
    ////////////////////////////////////////////////////////////

    void get_eprintf_flag_modifiers(const_cstr_t *format,
        eprintf_mod_t *mod, va_list *ap);

    ////////////////////////////////////////////////////////////
    ///
    /// \brief get the len modifiers
    ///
    /// \param format format string
    ///
    /// \param mod structure containing padding info
    ///
    ////////////////////////////////////////////////////////////

    void mod_eprintf_len_flags(const_cstr_t *format, eprintf_mod_t *mod);

    ////////////////////////////////////////////////////////////
    ///
    ///  Check wheter is the same flag in parsing
    ///
    /// Example : %3.f   ? Does it find 'f'
    ///
    ////////////////////////////////////////////////////////////

    #define IS_SAME_FLAG(format, offset, flag_array, index) \
        get_char_format_at_index(format, offset) == flag_array[index].flag || \
        get_char_format_at_index(format, offset) == flag_array[index].flag2

    ////////////////////////////////////////////////////////////
    ///
    ///  Check wheter is the same format
    ///
    ///  is used the for the len modifier check
    ///
    ////////////////////////////////////////////////////////////

    #define HAS_SAME_FORMAT(format, offset, flag, len) \
        estrncmp(get_format_at_index(format, offset), flag, len) == 0

    //   _                     _
    //  | |                   | |
    //  | |     ___   ___ __ _| |
    //  | |    / _ \ / __/ _` | |
    //  | |___| (_) | (_| (_| | |
    //  \_____/\___/ \___\__,_|_|
    //

    ////////////////////////////////////////////////////////////
    ///
    /// \brief Append the padding for printf
    ///
    /// \param size how many spaces or zero
    ///
    /// \param iszero should append space or zeroes
    ///
    /// \param buff the buffer to append to
    ///
    ////////////////////////////////////////////////////////////

    void eprintf_append_padding(ebuff_t **buff, i32_t size, bool iszero);

    ////////////////////////////////////////////////////////////
    ///
    /// \brief Does arithmetic on signed conversion for padding
    ///
    /// \param v   the int value (in case of a number)
    ///
    /// \param len  how much is going to be printed obligatory
    ///
    /// \param mod  structure to do arithmetic conversion
    ///
    ////////////////////////////////////////////////////////////

    void get_signed_conversion_padding(i64_t v, i32_t len, eprintf_mod_t *mod);

    ////////////////////////////////////////////////////////////
    ///
    /// \brief Does arithmetic on unsigned conversion for padding
    ///
    /// \param len  how much is going to be printed obligatory
    ///
    /// \param mod  structure to do arithmetic conversion
    ///
    ////////////////////////////////////////////////////////////

    void get_unsigned_conversion_padding(i32_t len, eprintf_mod_t *mod);

    ////////////////////////////////////////////////////////////
    ///
    /// Facilitate conversion for padding on signed numbers
    ///
    ////////////////////////////////////////////////////////////

    #define GET_NEW_SIGNED_PADDING(actual, to_remove) \
        actual = (actual - to_remove > 0) ? actual - to_remove : 0

    ////////////////////////////////////////////////////////////
    ///
    /// Facilitate conversion for padding on unsigned numbers
    ///
    ////////////////////////////////////////////////////////////

    #define GET_NEW_UNSIGNED_PADDING(actual, to_remove) \
        actual = ((int64_t)actual - (int64_t)to_remove > 0) ? \
            actual - to_remove : 0

    ////////////////////////////////////////////////////////////
    ///
    ///  Set the precision at default given if precsion
    ///  is still equivalent to -1
    ///
    ////////////////////////////////////////////////////////////

    #define SET_PRECISION(precision, default) \
        precision = (precision != -1) ? precision : default;

    ////////////////////////////////////////////////////////////
    ///
    /// \brief Get the pointer to variadic argument and sets it in the union arg
    ///
    /// \param ap variadic list
    ///
    /// \return union with value set at uintptr_t pointer value
    ///
    ////////////////////////////////////////////////////////////

    union eprintf_arg get_eprintf_ptr(va_list *ap);

    ////////////////////////////////////////////////////////////
    ///
    /// \brief Get the pointer to an int * and sets the value at how much
    ///        has been already append to the buffer
    ///
    /// \param ap variadic list
    ///
    ////////////////////////////////////////////////////////////

    void eprintf_local_getsize(ebuff_t **buff, va_list *ap);

    ////////////////////////////////////////////////////////////
    ///
    /// \brief Get char value trough union arg set it to the buffer
    ///        along with necessary padding
    ///
    /// \param ap variadic list
    ///
    /// \param mod structure containing padding info
    ///
    /// \param buff the buffer to search in
    ///
    ////////////////////////////////////////////////////////////

    void eprintf_local_char(ebuff_t **buff, va_list *ap, eprintf_mod_t *mod);

    ////////////////////////////////////////////////////////////
    ///
    /// \brief Get int value trough union arg set it to the buffer
    ///        along with necessary padding
    ///
    /// \param ap variadic list
    ///
    /// \param mod structure containing padding info
    ///
    /// \param buff the buffer to append to
    ///
    ////////////////////////////////////////////////////////////

    void eprintf_local_int(ebuff_t **buff, va_list *ap, eprintf_mod_t *mod);

    ////////////////////////////////////////////////////////////
    ///
    /// \brief Get str pointer trough union arg set it to the buffer
    ///        along with necessary padding
    ///
    /// \param ap variadic list
    ///
    /// \param mod structure containing padding info
    ///
    /// \param buff the buffer to append to
    ///
    ////////////////////////////////////////////////////////////

    void eprintf_local_str(ebuff_t **buff, va_list *ap, eprintf_mod_t *mod);

    ////////////////////////////////////////////////////////////
    ///
    /// \brief Get uint value trough union arg set it to the buffer
    ///        along with necessary padding
    ///
    /// \param ap variadic list
    ///
    /// \param mod structure containing padding info
    ///
    /// \param buff the buffer to append to
    ///
    ////////////////////////////////////////////////////////////

    void eprintf_local_uint(ebuff_t **buff, va_list *ap, eprintf_mod_t *mod);

    ////////////////////////////////////////////////////////////
    ///
    /// \brief Get uint value
    ///        trough union transform it in base 8 arg set it to the buffer
    ///        along with necessary padding
    ///
    /// \param ap variadic list
    ///
    /// \param mod structure containing padding info
    ///
    /// \param buff the buffer to append to
    ///
    ////////////////////////////////////////////////////////////

    void eprintf_local_oct(ebuff_t **buff, va_list *ap, eprintf_mod_t *mod);

    ////////////////////////////////////////////////////////////
    ///
    /// \brief Get uint value
    ///        trough union transform it in base 16 arg set it to the buffer
    ///        along with necessary padding (set in lowercase)
    ///
    /// \param ap variadic list
    ///
    /// \param mod structure containing padding info
    ///
    /// \param buff the buffer to append to
    ///
    ////////////////////////////////////////////////////////////

    void eprintf_local_hex_min(ebuff_t **buff, va_list *ap, eprintf_mod_t *mod);

    ////////////////////////////////////////////////////////////
    ///
    /// \brief Get uint value
    ///        trough union transform it in base 16 arg set it to the buffer
    ///        along with necessary padding (set in uppercase)
    ///
    /// \param ap variadic list
    ///
    /// \param mod structure containing padding info
    ///
    /// \param buff the buffer to append to
    ///
    ////////////////////////////////////////////////////////////

    void eprintf_local_hex_max(ebuff_t **buff, va_list *ap, eprintf_mod_t *mod);

    ////////////////////////////////////////////////////////////
    ///
    /// \brief Get double value
    ///        directly through va_arg() macro
    ///        and set it to the buffer
    ///        along with necessary padding (set in uppercase)
    ///
    /// \param ap variadic list
    ///
    /// \param mod structure containing padding info
    ///
    /// \param buff the buffer to append to
    ///
    ////////////////////////////////////////////////////////////

    void eprintf_local_double(ebuff_t **buff, va_list *ap, eprintf_mod_t *mod);

    ////////////////////////////////////////////////////////////
    ///
    /// \brief Get uint value
    ///        trough union transform it in base 16 arg set "0x" to the buffer
    ///        then set value to the buffer
    ///        along with necessary padding (set in uppercase)
    ///
    /// \param ap variadic list
    ///
    /// \param mod structure containing padding info
    ///
    /// \param buff the buffer to append to
    ///
    ////////////////////////////////////////////////////////////

    void eprintf_local_ptr(ebuff_t **buff, va_list *ap, eprintf_mod_t *mod);

    ////////////////////////////////////////////////////////////
    ///
    /// \brief Get unsigned value trough union and returns it
    ///
    /// \param ap variadic list
    ///
    /// \param mod structure containing padding info
    ///
    /// \param buff the buffer to append to
    ///
    ////////////////////////////////////////////////////////////

    uint64_t get_unsigned_arg(va_list *ap, u8_t mod);

    ////////////////////////////////////////////////////////////
    ///
    /// \brief Get signed value trough union and returns it
    ///
    /// \param ap variadic list
    ///
    /// \param mod structure containing padding info
    ///
    /// \return value chosen with len modifier
    ///
    ////////////////////////////////////////////////////////////

    int64_t get_signed_arg(va_list *ap, u8_t mod);

    ////////////////////////////////////////////////////////////
    ///
    /// \brief Get pointer value trough union and returns it
    ///
    /// \param ap variadic list
    ///
    /// \param mod structure containing padding info
    ///
    /// \return value chosen with len modifier
    ///
    ////////////////////////////////////////////////////////////

    void *get_ptr_arg(va_list *ap, u8_t mod);

    ////////////////////////////////////////////////////////////
    ///
    ///  Constant to determine the number of flags
    ///
    ////////////////////////////////////////////////////////////

    #define NB_EPRINTF_FLAGS    9

    //  ___  ____
    //  |  \/  (_)
    //  | .  . |_ ___  ___
    //  | |\/| | / __|/ __|
    //  | |  | | \__ \ (__
    //  \_|  |_/_|___/\___|
    //

    ////////////////////////////////////////////////////////////
    ///
    /// \brief check format string
    ///
    /// \param format
    ///
    /// \return returns false if the string can just be writed directly
    ///         (has no '%' char)
    ///
    ////////////////////////////////////////////////////////////

    bool check_eprintf_format(const_cstr_t format);

    ////////////////////////////////////////////////////////////
    ///
    /// \brief Write on stderr without eprintf (not fast and not bufferised)
    ///        Is only there when printf failed and a output should be shown
    ///
    /// \param prg the program name
    /// \param file the file where it failed
    /// \param line the line where it failed
    ///
    /// \return returns always EPRINTF_FAILURE
    ///
    ////////////////////////////////////////////////////////////

    int eprintf_failure(char *prg, char *file, int line);

    #define PRINTF_FAIL(prg) \
        eprintf_failure(prg, __FILE__, __LINE__)

#endif /* !__LIBERTY__EPRINTF__H__ */