#include <math.h>
#include <string.h>
#include<stdio.h>

#include "vector3.h"
#include "matrix33.h"

void vector3_print(
    IN const VECTOR3_t* pk_vecA)
{
    printf("| %.2f |\n", pk_vecA->e0);
    printf("| %.2f |\n", pk_vecA->e1);
    printf("| %.2f |\n", pk_vecA->e2);
}

void vector3U4_print(
    IN const VECTOR3U4_t* pk_vecA)
{
    printf("| %lu |\n", pk_vecA->e0);
    printf("| %lu |\n", pk_vecA->e1);
    printf("| %lu |\n", pk_vecA->e2);
}

void vector3_normalize(
    IN const VECTOR3_t* pk_vecA,
    OUT VECTOR3_t* p_vecB)
{
    R4 magnitude = sqrtf(powf(pk_vecA->e0, 2) + \
                            powf(pk_vecA->e1, 2) + \
                            powf(pk_vecA->e2, 2));
    if (magnitude == 0)
    {
        memcpy(p_vecB, pk_vecA, sizeof(VECTOR3_t));
    }
    else
    {
        R4 magnitudeInverse = 1.f / magnitude;
        p_vecB->e0 = pk_vecA->e0 * magnitudeInverse;
        p_vecB->e1 = pk_vecA->e1 * magnitudeInverse;
        p_vecB->e2 = pk_vecA->e2 * magnitudeInverse;

    }
}

void vector3_outerProduct(
    IN const VECTOR3_t* pk_vecA,
    IN const VECTOR3_t* pk_vecB,
    OUT MATRIX33_t* p_matA)
{
    p_matA->e0 = pk_vecA->e0 * pk_vecB->e0;
    p_matA->e1 = pk_vecA->e0 * pk_vecB->e1;
    p_matA->e2 = pk_vecA->e0 * pk_vecB->e2;
    p_matA->e3 = pk_vecA->e1 * pk_vecB->e0;
    p_matA->e4 = pk_vecA->e1 * pk_vecB->e1;
    p_matA->e5 = pk_vecA->e1 * pk_vecB->e2;
    p_matA->e6 = pk_vecA->e2 * pk_vecB->e0;
    p_matA->e7 = pk_vecA->e2 * pk_vecB->e1;
    p_matA->e8 = pk_vecA->e2 * pk_vecB->e2;
}