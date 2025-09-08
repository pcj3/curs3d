#ifndef MATH_VECTOR3_H
#define MATH_VECTOR3_H

#include "defs.h"

typedef struct VECTOR3_s {
    R4 x;
    R4 y;
    R4 z;
} VECTOR3_t;

void vector3_normalize(
    IN const VECTOR3_t* pkVecA,
    OUT VECTOR3_t* pVecB);

#endif // MATH_VECTOR3_H