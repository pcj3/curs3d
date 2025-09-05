#include "matrix33.h"

void matrix33_multiply(
    IN const MATRIX33_t* pk_matA,
    IN const MATRIX33_t* pk_matB,
    OUT MATRIX33_t* p_matC)
{
    p_matC->e0 = pk_matA->e0 * pk_matB->e0 + pk_matA->e1 * pk_matB->e3 + pk_matA->e2 * pk_matB->e6;
    p_matC->e1 = pk_matA->e0 * pk_matB->e1 + pk_matA->e1 * pk_matB->e4 + pk_matA->e2 * pk_matB->e7;
    p_matC->e2 = pk_matA->e0 * pk_matB->e2 + pk_matA->e1 * pk_matB->e5 + pk_matA->e2 * pk_matB->e8;
    p_matC->e3 = pk_matA->e3 * pk_matB->e0 + pk_matA->e4 * pk_matB->e3 + pk_matA->e5 * pk_matB->e6;
    p_matC->e4 = pk_matA->e3 * pk_matB->e1 + pk_matA->e4 * pk_matB->e4 + pk_matA->e5 * pk_matB->e7;
    p_matC->e5 = pk_matA->e3 * pk_matB->e2 + pk_matA->e4 * pk_matB->e5 + pk_matA->e5 * pk_matB->e8;
    p_matC->e6 = pk_matA->e6 * pk_matB->e0 + pk_matA->e7 * pk_matB->e3 + pk_matA->e8 * pk_matB->e6;
    p_matC->e7 = pk_matA->e6 * pk_matB->e1 + pk_matA->e7 * pk_matB->e4 + pk_matA->e8 * pk_matB->e7;
    p_matC->e8 = pk_matA->e6 * pk_matB->e2 + pk_matA->e7 * pk_matB->e5 + pk_matA->e8 * pk_matB->e8;
}

void matrix33_add(
    IN const MATRIX33_t* pk_matA,
    IN const MATRIX33_t* pk_matB,
    OUT MATRIX33_t* p_matC)
{
    p_matC->e0 = pk_matA->e0 + pk_matB->e0;
    p_matC->e1 = pk_matA->e1 + pk_matB->e1;
    p_matC->e2 = pk_matA->e2 + pk_matB->e2;
    p_matC->e3 = pk_matA->e3 + pk_matB->e3;
    p_matC->e4 = pk_matA->e4 + pk_matB->e4;
    p_matC->e5 = pk_matA->e5 + pk_matB->e5;
    p_matC->e6 = pk_matA->e6 + pk_matB->e6;
    p_matC->e7 = pk_matA->e7 + pk_matB->e7;
    p_matC->e8 = pk_matA->e8 + pk_matB->e8;
}

void matrix33_subtract(
    IN const MATRIX33_t* pk_matA,
    IN const MATRIX33_t* pk_matB,
    OUT MATRIX33_t* p_matC)
{
    p_matC->e0 = pk_matA->e0 - pk_matB->e0;
    p_matC->e1 = pk_matA->e1 - pk_matB->e1;
    p_matC->e2 = pk_matA->e2 - pk_matB->e2;
    p_matC->e3 = pk_matA->e3 - pk_matB->e3;
    p_matC->e4 = pk_matA->e4 - pk_matB->e4;
    p_matC->e5 = pk_matA->e5 - pk_matB->e5;
    p_matC->e6 = pk_matA->e6 - pk_matB->e6;
    p_matC->e7 = pk_matA->e7 - pk_matB->e7;
    p_matC->e8 = pk_matA->e8 - pk_matB->e8;
}

void matrix33_transpose(
    IN const MATRIX33_t* pk_matA,
    OUT MATRIX33_t* p_matB)
{
    p_matB->e0 = pk_matA->e0;
    p_matB->e1 = pk_matA->e3;
    p_matB->e2 = pk_matA->e6;
    p_matB->e3 = pk_matA->e1;
    p_matB->e4 = pk_matA->e4;
    p_matB->e5 = pk_matA->e7;
    p_matB->e6 = pk_matA->e2;
    p_matB->e7 = pk_matA->e5;
    p_matB->e8 = pk_matA->e8;
}

void matrix33_scale(
    INOUT MATRIX33_t* p_matA,
    IN R4 s)
{
    p_matA->e0 *= s;
    p_matA->e1 *= s;
    p_matA->e2 *= s;
    p_matA->e3 *= s;
    p_matA->e4 *= s;
    p_matA->e5 *= s;
    p_matA->e6 *= s;
    p_matA->e7 *= s;
    p_matA->e8 *= s;
}

void matrix33_copy(
    IN const MATRIX33_t* pk_matA,
    OUT MATRIX33_t* p_matB)
{
    memcpy(p_matB, pk_matA, sizeof(MATRIX33_t));
}

void matrix33_setToZero(
    INOUT MATRIX33_t* p_matA)
{
    memset(p_matA, 0, sizeof(MATRIX33_t));
}

void matrix33_print(
    IN const MATRIX33_t* pk_matA)
{
    printf("| %.2f %.2f %.2f |\n", pk_matA->e0, pk_matA->e1, pk_matA->e2);
    printf("| %.2f %.2f %.2f |\n", pk_matA->e3, pk_matA->e4, pk_matA->e5);
    printf("| %.2f %.2f %.2f |\n", pk_matA->e6, pk_matA->e7, pk_matA->e8);
}
