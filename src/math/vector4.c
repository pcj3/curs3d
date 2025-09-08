#include <math.h>
#include <string.h>
#include<stdio.h>

#include "vector4.h"
#include "matrix44.h"

void vector4_print(
    IN const VECTOR4_t* pk_vecA)
{
    printf("| %.2f |\n", pk_vecA->x);
    printf("| %.2f |\n", pk_vecA->y);
    printf("| %.2f |\n", pk_vecA->z);
}

void vector4_multiplyElementWiseByVector4(
    IN const VECTOR4_t* pk_vecA,
    IN const VECTOR4_t* pk_vecB,
    OUT VECTOR4_t* p_vecC
)
{
    p_vecC->x = pk_vecA->x * pk_vecB->x;
    p_vecC->y = pk_vecA->y * pk_vecB->y;
    p_vecC->z = pk_vecA->z * pk_vecB->z;
    p_vecC->w = pk_vecA->w * pk_vecB->w;  
}

void vector4_addElementWiseVector4(
    IN const VECTOR4_t* pk_vecA,
    IN const VECTOR4_t* pk_vecB,
    OUT VECTOR4_t* p_vecC)
{
    p_vecC->x = pk_vecA->x + pk_vecB->x;
    p_vecC->y = pk_vecA->y + pk_vecB->y;
    p_vecC->z = pk_vecA->z + pk_vecB->z;
    p_vecC->w = pk_vecA->w + pk_vecB->w;  
}