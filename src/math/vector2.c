#include <math.h>
#include <string.h>
#include<stdio.h>

#include "vector2.h"

void vector2_print(
    IN const VECTOR2_t* pk_vecA)
{
    printf("| %.2f |\n", pk_vecA->x);
    printf("| %.2f |\n", pk_vecA->y);
}

void vector2U4_print(
    IN const VECTOR2U4_t* pk_vecA)
{
    printf("| %lu |\n", pk_vecA->e0);
    printf("| %lu |\n", pk_vecA->e1);
}

