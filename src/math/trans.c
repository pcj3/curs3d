#include "trans.h"
#include <math.h>

void trans_scaleMatrix44ByVector3(
    IN const MATRIX44_t* pkMatA,
    IN const VECTOR3_t* pkVecB,
    OUT MATRIX44_t* pMatC)
{   
    MATRIX44_t tmpMat;

    tmpMat.e0 = pkMatA->e0 * pkVecB->x;
    tmpMat.e1 = pkMatA->e1 * pkVecB->x;
    tmpMat.e2 = pkMatA->e2 * pkVecB->x;
    tmpMat.e3 = pkMatA->e3 * pkVecB->x;
    tmpMat.e4 = pkMatA->e4 * pkVecB->y;
    tmpMat.e5 = pkMatA->e5 * pkVecB->y;
    tmpMat.e6 = pkMatA->e6 * pkVecB->y;
    tmpMat.e7 = pkMatA->e7 * pkVecB->y;
    tmpMat.e8 = pkMatA->e8 * pkVecB->z;
    tmpMat.e9 = pkMatA->e9 * pkVecB->z;
    tmpMat.e10 = pkMatA->e10 * pkVecB->z;
    tmpMat.e11 = pkMatA->e11 * pkVecB->z;
    tmpMat.e12 = pkMatA->e12;
    tmpMat.e13 = pkMatA->e13;
    tmpMat.e14 = pkMatA->e14;
    tmpMat.e15 = pkMatA->e15;

    *pMatC = tmpMat;
}

void trans_rotateMatrix44ByVector3(
    IN const MATRIX44_t* pkMatA,
    IN const VECTOR3_t* pkVecA,
    IN const R4 kAngle, // in radians
    OUT MATRIX44_t* pMatB)
{
    VECTOR3_t axis;
    vector3_normalize(pkVecA, &axis);

    const R4 c = cosf(kAngle);
    const R4 s = sinf(kAngle);
    const R4 t = 1.f - c;

    MATRIX44_t rotMatrix;

    R4 txy = t * axis.x * axis.y;
    R4 txz = t * axis.x * axis.z;
    R4 tyz = t * axis.y * axis.z;

    R4 sx = s * axis.x;
    R4 sy = s * axis.y;
    R4 sz = s * axis.z;

    rotMatrix.e0 = t * axis.x * axis.x + c; 
    rotMatrix.e1 = txy - sz;
    rotMatrix.e2 = txz + sy;
    rotMatrix.e3 = 0.f;

    rotMatrix.e4 = txy + sz;
    rotMatrix.e5 = t * axis.y * axis.y + c; 
    rotMatrix.e6 = tyz - sx;
    rotMatrix.e7 = 0.f;

    rotMatrix.e8 = txz - sy;
    rotMatrix.e9 = tyz + sx;    
    rotMatrix.e10 = t * axis.z * axis.z + c;
    rotMatrix.e11 = 0.f;
    
    rotMatrix.e12 = 0.f;
    rotMatrix.e13 = 0.f;
    rotMatrix.e14 = 0.f;
    rotMatrix.e15 = 1.f;

    matrix44_multiply(&rotMatrix, pkMatA, pMatB);
}

void trans_multiplyMatrix44ByVector4(
    IN const MATRIX44_t* pkMatA,
    IN const VECTOR4_t* pkVecB,
    OUT VECTOR4_t* pVecC)
{
    VECTOR4_t tmpVec;

    tmpVec.x = pkMatA->e0 * pkVecB->x + pkMatA->e1 * pkVecB->y + pkMatA->e2 * pkVecB->z + pkMatA->e3 * pkVecB->w;
    tmpVec.y = pkMatA->e4 * pkVecB->x + pkMatA->e5 * pkVecB->y + pkMatA->e6 * pkVecB->z + pkMatA->e7 * pkVecB->w;
    tmpVec.z = pkMatA->e8 * pkVecB->x + pkMatA->e9 * pkVecB->y + pkMatA->e10 * pkVecB->z + pkMatA->e11 * pkVecB->w;
    tmpVec.w = pkMatA->e12 * pkVecB->x + pkMatA->e13 * pkVecB->y + pkMatA->e14 * pkVecB->z + pkMatA->e15 * pkVecB->w;

    *pVecC = tmpVec;
}