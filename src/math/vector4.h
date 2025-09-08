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

void vector4_multiplyElementWiseByVector4(
    IN const VECTOR4_t* pkVecA,
    IN const VECTOR4_t* pkVecB,
    OUT VECTOR4_t* pVecC);

void vector4_addElementWiseVector4(
    IN const VECTOR4_t* pkVecA,
    IN const VECTOR4_t* pkVecB,
    OUT VECTOR4_t* pVecC);

#endif // MATH_VECTOR4_H