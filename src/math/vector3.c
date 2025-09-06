#include <math.h>
#include <string.h>
#include<stdio.h>

#include "vector3.h"
#include "matrix33.h"

void vector3_print(
    IN const VECTOR3_t* pk_vecA)
{
    printf("| %.2f |\n", pk_vecA->x);
    printf("| %.2f |\n", pk_vecA->y);
    printf("| %.2f |\n", pk_vecA->z);
}


void vector3_normalize(
    IN const VECTOR3_t* pk_vecA,
    OUT VECTOR3_t* p_vecB)
{
    R4 magnitude = sqrtf(powf(pk_vecA->x, 2) + \
                            powf(pk_vecA->y, 2) + \
                            powf(pk_vecA->z, 2));
    if (magnitude == 0)
    {
        memcpy(p_vecB, pk_vecA, sizeof(VECTOR3_t));
    }
    else
    {
        R4 magnitudeInverse = 1.f / magnitude;
        p_vecB->x = pk_vecA->x * magnitudeInverse;
        p_vecB->y = pk_vecA->y * magnitudeInverse;
        p_vecB->z = pk_vecA->z * magnitudeInverse;

    }
}

void vector3_outerProduct(
    IN const VECTOR3_t* pk_vecA,
    IN const VECTOR3_t* pk_vecB,
    OUT MATRIX33_t* p_matA)
{
    p_matA->e0 = pk_vecA->x * pk_vecB->x;
    p_matA->e1 = pk_vecA->x * pk_vecB->y;
    p_matA->e2 = pk_vecA->x * pk_vecB->z;
    p_matA->e3 = pk_vecA->y * pk_vecB->x;
    p_matA->e4 = pk_vecA->y * pk_vecB->y;
    p_matA->e5 = pk_vecA->y * pk_vecB->z;
    p_matA->e6 = pk_vecA->z * pk_vecB->x;
    p_matA->e7 = pk_vecA->z * pk_vecB->y;
    p_matA->e8 = pk_vecA->z * pk_vecB->z;
}