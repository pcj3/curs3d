#ifndef MATH_VECTOR3_H
#define MATH_VECTOR3_H

#include "defs.h"
#include "matrix33.h"

typedef struct VECTOR3U4_s {
    U4 e0;
    U4 e1;
    U4 e2;
} VECTOR3U4_t;

typedef struct VECTOR3_s {
    R4 e0;
    R4 e1;
    R4 e2;
} VECTOR3_t;

void vector3_print(
    IN const VECTOR3_t* pk_vecA);

void vector3U4_print(
    IN const VECTOR3U4_t* pk_vecA);

void vector3_normalize(
    IN const VECTOR3_t* pk_vecA,
    OUT VECTOR3_t* p_vecB);

void vector3_outerProduct(
    IN const VECTOR3_t* pk_vecA,
    IN const VECTOR3_t* pk_vecB,
    OUT MATRIX33_t* p_matA);

#endif // MATH_VECTOR3_H