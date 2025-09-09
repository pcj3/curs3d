#ifndef MATH_MAT44_H
#define MATH_MAT44_H


#include "defs.h"

typedef struct MATRIX44_s
{
    R4 e0;
    R4 e1;
    R4 e2;
    R4 e3;
    R4 e4;
    R4 e5;
    R4 e6;
    R4 e7;
    R4 e8;
    R4 e9;
    R4 e10;
    R4 e11;
    R4 e12;
    R4 e13;
    R4 e14;
    R4 e15;
} MATRIX44_t;

void matrix44_multiply(
    IN const MATRIX44_t* pkMatA,
    IN const MATRIX44_t* pkMatB,
    OUT MATRIX44_t* pMatC);

void matrix44_add(
    IN const MATRIX44_t* pkMatA,
    IN const MATRIX44_t* pkMatB,
    OUT MATRIX44_t* pMatC);

void matrix44_subtract(
    IN const MATRIX44_t* pkMatA,
    IN const MATRIX44_t* pkMatB,
    OUT MATRIX44_t* pMatC);

void matrix44_transpose(
    IN const MATRIX44_t* pkMatA,
    OUT MATRIX44_t* pMatB);

void matrix44_copy(
    IN const MATRIX44_t* pkMatA,
    OUT MATRIX44_t* pMatB);

void matrix44_setToZero(
    OUT MATRIX44_t* pMatA);

void matrix44_setToIdentity(
    OUT MATRIX44_t* pMatA);

void matrix44_print(
    IN const MATRIX44_t* pkMatA);

#endif // MATH_MAT44_H