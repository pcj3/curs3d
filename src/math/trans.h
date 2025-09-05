#ifndef MATH_TRANS_H
#define MATH_TRANS_H

#include "matrix44.h"
#include "matrix33.h"
#include "vector3.h"

void trans_scaleMatrix44ByVector3(
    IN const MATRIX44_t* pk_matA,
    IN const VECTOR3_t* pk_vecB,
    OUT MATRIX44_t* p_matC);

void trans_rotateMatrix44ByVector3(
    IN const MATRIX44_t* pk_matA,
    IN const VECTOR3_t* pk_vecA,
    IN const R4 k_angle,
    OUT MATRIX44_t* p_matB);

#endif // MATH_TRANS_H