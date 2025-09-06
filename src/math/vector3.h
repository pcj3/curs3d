#ifndef MATH_VECTOR3_H
#define MATH_VECTOR3_H

#include "defs.h"
#include "matrix33.h"


typedef struct VECTOR3_s {
    R4 x;
    R4 y;
    R4 z;
} VECTOR3_t;

void vector3_print(
    IN const VECTOR3_t* pk_vecA);

void vector3_normalize(
    IN const VECTOR3_t* pk_vecA,
    OUT VECTOR3_t* p_vecB);

void vector3_outerProduct(
    IN const VECTOR3_t* pk_vecA,
    IN const VECTOR3_t* pk_vecB,
    OUT MATRIX33_t* p_matA);

#endif // MATH_VECTOR3_H