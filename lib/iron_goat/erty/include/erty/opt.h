/*
** EPITECH PROJECT, 2021
** LibErty
** File description:
** opt
*/

#ifndef __LIBERTY__OPT__H__
    #define __LIBERTY__OPT__H__

    #include <erty/ectypes.h>

    #define OPT(name) struct my_opt_##name

    #define INIT_OPT(name, type) \
        OPT(name) { \
            type value; \
            bool is_ok; \
        };

    #define OK(name, val) \
        (OPT(name)){.value=val, .is_ok=true}

    #define ERR(name, ...) \
        (OPT(name)){.value=(0, ##__VA_ARGS__), .is_ok=false}

    #define EXPLICIT_ERR(name, v) \
        (OPT(name)){.value=v, .is_ok=false}

    INIT_OPT(i8, int8_t)
    INIT_OPT(u8, u_int8_t)
    INIT_OPT(i16, int16_t)
    INIT_OPT(u16, u_int16_t)
    INIT_OPT(i32, int32_t)
    INIT_OPT(u32, u_int32_t)
    INIT_OPT(i64, int64_t)
    INIT_OPT(u64, u_int64_t)

#endif /* !__LIBERTY__OPT__H__ */