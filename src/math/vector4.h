#ifndef MATH_VECTOR4_H
#define MATH_VECTOR4_H

#include "defs.h"
#include "matrix44.h"


typedef struct VECTOR4_s {
    R4 x;
    R4 y;
    R4 z;
    R4 w;
} VECTOR4_t;

void vector4_print(
    IN const VECTOR4_t* pk_vecA);

void vector4_normalize(
    IN const VECTOR4_t* pk_vecA,
    OUT VECTOR4_t* p_vecB);

void vector4_outerProduct(
    IN const VECTOR4_t* pk_vecA,
    IN const VECTOR4_t* pk_vecB,
    OUT MATRIX44_t* p_matA);

#endif // MATH_VECTOR4_H