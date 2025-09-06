#ifndef MATH_VECTOR2_H
#define MATH_VECTOR2_H

#include "defs.h"


typedef struct VECTOR2U4_s {
    U4 e0;
    U4 e1;
} VECTOR2U4_t;

typedef struct VECTOR2_s {
    R4 x;  // x
    R4 y;  // y
} VECTOR2_t;

void vector2_print(
    IN const VECTOR2_t* pk_vecA);

void vector2U4_print(
    IN const VECTOR2U4_t* pk_vecA);


#endif // MATH_VECTOR2_H