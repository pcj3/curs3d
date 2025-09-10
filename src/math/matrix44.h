#ifndef MATH_MAT44_H
#define MATH_MAT44_H


#include "defs.h"
#include "vector3.h"
#include "vector4.h"

/*
    Matrix 4x4 defined with column-wise order

        | e00 e10 e20 e30 |
        | e01 e11 e21 e31 |
        | e02 e12 e22 e32 |
        | e03 e13 e23 e33 |
*/
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

void matrix44_rotateByVector3(
    IN const MATRIX44_t* pkMatA,
    IN const VECTOR3_t* pkVecA,
    IN const R4 kAngle,
    OUT MATRIX44_t* pMatB);

void matrix44_scaleByVector3(
    IN const MATRIX44_t* pkMatA,
    IN const VECTOR3_t* pkVecB,
    OUT MATRIX44_t* pMatC);

void matrix44_translateByVector3(
    IN const MATRIX44_t* pkMatA,
    IN const VECTOR3_t* pkVecA,
    OUT MATRIX44_t* pMatB);

void matrix44_multiplyByVector4(
    IN const MATRIX44_t* pkMatA,
    IN const VECTOR4_t* pkVecB,
    OUT VECTOR4_t* pVecC);

void matrix44_print(
    IN const MATRIX44_t* pkMat);

#endif // MATH_MAT44_H