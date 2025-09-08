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

void vector4_multiplyElementWiseByVector4(
    IN const VECTOR4_t* pk_vecA,
    IN const VECTOR4_t* pk_vecB,
    OUT VECTOR4_t* p_vecC);

void vector4_addElementWiseVector4(
    IN const VECTOR4_t* pk_vecA,
    IN const VECTOR4_t* pk_vecB,
    OUT VECTOR4_t* p_vecC);

#endif // MATH_VECTOR4_H