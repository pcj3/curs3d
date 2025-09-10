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

