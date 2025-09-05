#ifndef MATH_VECTOR4_H
#define MATH_VECTOR4_H

#include "defs.h"
#include "matrix33.h"

typedef struct VECTOR4U4_s {
    U4 e0;
    U4 e1;
    U4 e2;
    U4 e3;
} VECTOR4U4_t;

typedef struct VECTOR4_s {
    R4 e0;
    R4 e1;
    R4 e2;
    R4 e3;
} VECTOR4_t;

void vector4_print(
    IN const VECTOR4_t* pk_vecA);

void vector4U4_print(
    IN const VECTOR4U4_t* pk_vecA);

#endif // MATH_VECTOR4_H