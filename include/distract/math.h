/*
** EPITECH PROJECT, 2020
** math
** File description:
** Source code
*/

#ifndef DISTRACT_MATH_H
#define DISTRACT_MATH_H
#include "SFML/Graphics.h"

///
/// Linear interpolation between two floats
///
float lerp(float a, float b, float t);

///
/// Linear interpolation between two vectors
///
sfVector2f v2flerp(sfVector2f *v1, sfVector2f *v2, float t);

///
/// Linear interpolation between two vectors
///
sfVector2i v2ilerp(sfVector2i *v1, sfVector2i *v2, float t);

///
/// Magnitude of a vector
///
float v2fmagnitude(sfVector2f *vector);

///
/// Magnitude of a vector
///
float v2imagnitude(sfVector2i *vector);

///
/// Normalized vector
///
sfVector2f v2fnormalized(sfVector2f *vector);

///
/// Normalized vector
///
sfVector2i v2inormalized(sfVector2i *vector);


///
/// Distance between v1 and v2
///
float v2fdistance(sfVector2f *v1, sfVector2f *v2);

///
/// Distance between v1 and v2
///
float v2idistance(sfVector2i *v1, sfVector2i *v2);

///
/// Add v1 with v2
///
sfVector2f v2fadd(sfVector2f v1, sfVector2f v2);

///
/// Add v1 with v2
///
sfVector2i v2iadd(sfVector2i v1, sfVector2i v2);

///
/// Substract v1 with v2
///
sfVector2f v2fsub(sfVector2f v1, sfVector2f v2);

///
/// Substract v1 with v2
///
sfVector2i v2isub(sfVector2i v1, sfVector2i v2);

///
/// Multiply v1 with f
///
sfVector2f v2fmulf(sfVector2f v1, float f);

///
/// Multiply v1 with f
///
sfVector2i v2imulf(sfVector2i v1, float f);

///
/// Add v2 to v1, returns v1
///
sfVector2f *pv2fadd(sfVector2f *v1, sfVector2f *v2);

///
/// Add v2 to v1, returns v1
///
sfVector2i *pv2iadd(sfVector2i *v1, sfVector2i *v2);

///
/// Substract v2 to v1, returns v1
///
sfVector2f *pv2fsub(sfVector2f *v1, sfVector2f *v2);

///
/// Substract v2 to v1, returns v1
///
sfVector2i *pv2isub(sfVector2i *v1, sfVector2i *v2);

///
/// Multiply f to v1, returns v1
///
sfVector2f *pv2fmulf(sfVector2f *v1, float f);

///
/// Multiply f to v1, returns v1
///
sfVector2i *pv2imulf(sfVector2i *v1, float f);

#ifndef ABS
    #define ABS(x) (x < 0 ? -x : x)
#endif

#endif //DISTRACT_MATH_H