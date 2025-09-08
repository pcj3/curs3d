#include <math.h>
#include <string.h>
#include<stdio.h>

#include "vector3.h"


void vector3_normalize(
    IN const VECTOR3_t* pkVecA,
    OUT VECTOR3_t* pVecB)
{   
    VECTOR3_t tmpVec;

    R4 magnitude = sqrtf(powf(pkVecA->x, 2) + \
                            powf(pkVecA->y, 2) + \
                            powf(pkVecA->z, 2));
    if (magnitude == 0)
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

