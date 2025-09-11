#include <math.h>
#include <string.h>
#include<stdio.h>

#include "vector4.h"


void vector4_multiplyElementWiseByVector4(
    IN const VECTOR4_t* pkVecA,
    IN const VECTOR4_t* pkVecB,
    OUT VECTOR4_t* pVecC
)
{
    VECTOR4_t tmpVec;

    tmpVec.x = pkVecA->x * pkVecB->x;
    tmpVec.y = pkVecA->y * pkVecB->y;
    tmpVec.z = pkVecA->z * pkVecB->z;
    tmpVec.w = pkVecA->w * pkVecB->w;

    *pVecC = tmpVec;
}

void vector4_addElementWiseVector4(
    IN const VECTOR4_t* pkVecA,
    IN const VECTOR4_t* pkVecB,
    OUT VECTOR4_t* pVecC)
{
    VECTOR4_t tmpVec;

    tmpVec.x = pkVecA->x + pkVecB->x;
    tmpVec.y = pkVecA->y + pkVecB->y;
    tmpVec.z = pkVecA->z + pkVecB->z;
    tmpVec.w = pkVecA->w + pkVecB->w;

    *pVecC = tmpVec;
}

void vector4_divideXYByZ(
    INOUT VECTOR4_t* pVec)
{
    if (pVec->z != 0)
    {
        pVec->x /= pVec->z;
        pVec->y /= pVec->z;
    }
}