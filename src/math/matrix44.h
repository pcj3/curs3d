#ifndef MATH_MAT44_H
#define MATH_MAT44_H


#include "defs.h"

typedef struct MATRIX44_s
{
    R4 e00;
    R4 e01;
    R4 e02;
    R4 e03;

    R4 e10;
    R4 e11;
    R4 e12;
    R4 e13;

    R4 e20;
    R4 e21;
    R4 e22;
    R4 e23;

    R4 e30;
    R4 e31;
    R4 e32;
    R4 e33;
} MATRIX44_t;

void matrix44_multiply(
    IN const MATRIX44_t* pkMatA,
    IN const MATRIX44_t* pkMatB,
    OUT MATRIX44_t* pMatC);

void matrix44_setToIdentity(
    OUT MATRIX44_t* pMatA);

#endif // MATH_MAT44_H