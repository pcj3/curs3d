#ifndef MATH_TRANS_H
#define MATH_TRANS_H

#include "matrix44.h"
#include "vector4.h"
#include "vector3.h"

void trans_scaleMatrix44ByVector3(
    IN const MATRIX44_t* pkMatA,
    IN const VECTOR3_t* pkVecB,
    OUT MATRIX44_t* pMatC);

void trans_rotateMatrix44ByVector3(
    IN const MATRIX44_t* pkMatA,
    IN const VECTOR3_t* pkVecA,
    IN const R4 kAngle,
    OUT MATRIX44_t* pMatB);

void trans_tranlateMatrix44ByVector3(
    IN const MATRIX44_t* pkMatA,
    IN const VECTOR3_t* pkVecA,
    OUT MATRIX44_t* pMatB);

void trans_multiplyMatrix44ByVector4(
    IN const MATRIX44_t* pkMatA,
    IN const VECTOR4_t* pkVecB,
    OUT VECTOR4_t* pVecC);

void trans_divideVector4ByW(
    INOUT VECTOR4_t* pVec);

#endif // MATH_TRANS_H