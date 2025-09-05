#include <math.h>
#include <string.h>
#include<stdio.h>

#include "vector4.h"
#include "matrix33.h"

void vector4_print(
    IN const VECTOR4_t* pk_vecA)
{
    printf("| %.2f |\n", pk_vecA->e0);
    printf("| %.2f |\n", pk_vecA->e1);
    printf("| %.2f |\n", pk_vecA->e2);
    printf("| %.2f |\n", pk_vecA->e3);
}

void vector4U4_print(
    IN const VECTOR4U4_t* pk_vecA)
{
    printf("| %lu |\n", pk_vecA->e0);
    printf("| %lu |\n", pk_vecA->e1);
    printf("| %lu |\n", pk_vecA->e2);
    printf("| %lu |\n", pk_vecA->e3);
}
