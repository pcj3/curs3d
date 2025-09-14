#include <math.h>
#include <string.h>
#include<stdio.h>

#include "vector3.h"


void vector3_normalize(
    IN const VECTOR3_t* pkVecA,
    OUT VECTOR3_t* pVecB)
{   
    VECTOR3_t tmpVec;

    R4 magnitude = sqrtf(pkVecA->x*pkVecA->x 
        + pkVecA->y*pkVecA->y 
        + pkVecA->z*pkVecA->z);
        
    if ((fabsf(magnitude) < FLT_EPSILON))
    {
        memcpy(pVecB, pkVecA, sizeof(VECTOR3_t));
        return;
    }
    else
    {
        R4 magnitudeInverse = 1.f / magnitude;
        tmpVec.x = pkVecA->x * magnitudeInverse;
        tmpVec.y = pkVecA->y * magnitudeInverse;
        tmpVec.z = pkVecA->z * magnitudeInverse;

    }
    *pVecB = tmpVec;
}

void vector3_crossProd(
    IN const VECTOR3_t* pkVecA,
    IN const VECTOR3_t* pkVecB,
    OUT VECTOR3_t* pVecC)
{
    VECTOR3_t tmpVec;

    tmpVec.x = pkVecA->y * pkVecB->z - pkVecA->z * pkVecB->y;
    tmpVec.y = pkVecA->z * pkVecB->x - pkVecA->x * pkVecB->z;
    tmpVec.z = pkVecA->x * pkVecB->y - pkVecA->y * pkVecB->x;

    *pVecC = tmpVec;
}

void vector3_subtract(
    IN const VECTOR3_t* pkVecA,
    IN const VECTOR3_t* pkVecB,
    OUT VECTOR3_t* pVecC)
{
    VECTOR3_t tmpVec;

    tmpVec.x = pkVecA->x - pkVecB->x;
    tmpVec.y = pkVecA->y - pkVecB->y;
    tmpVec.z = pkVecA->z - pkVecB->z;

    *pVecC = tmpVec;
}