#include "matrix44.h"

void matrix44_multiply(
    IN const MATRIX44_t* pk_matA,
    IN const MATRIX44_t* pk_matB,
    OUT MATRIX44_t* p_matC)
{
    p_matC->e0 = pk_matA->e0 * pk_matB->e0 + pk_matA->e1 * pk_matB->e4 + pk_matA->e2 * pk_matB->e8 + pk_matA->e3 * pk_matB->e12;
    p_matC->e1 = pk_matA->e0 * pk_matB->e1 + pk_matA->e1 * pk_matB->e5 + pk_matA->e2 * pk_matB->e9 + pk_matA->e3 * pk_matB->e13;
    p_matC->e2 = pk_matA->e0 * pk_matB->e2 + pk_matA->e1 * pk_matB->e6 + pk_matA->e2 * pk_matB->e10 + pk_matA->e3 * pk_matB->e14;
    p_matC->e3 = pk_matA->e0 * pk_matB->e3 + pk_matA->e1 * pk_matB->e7 + pk_matA->e2 * pk_matB->e11 + pk_matA->e3 * pk_matB->e15;

    p_matC->e4 = pk_matA->e4 * pk_matB->e0 + pk_matA->e5 * pk_matB->e4 + pk_matA->e6 * pk_matB->e8 + pk_matA->e7 * pk_matB->e12;
    p_matC->e5 = pk_matA->e4 * pk_matB->e1 + pk_matA->e5 * pk_matB->e5 + pk_matA->e6 * pk_matB->e9 + pk_matA->e7 * pk_matB->e13;
    p_matC->e6 = pk_matA->e4 * pk_matB->e2 + pk_matA->e5 * pk_matB->e6 + pk_matA->e6 * pk_matB->e10 + pk_matA->e7 * pk_matB->e14;
    p_matC->e7 = pk_matA->e4 * pk_matB->e3 + pk_matA->e5 * pk_matB->e7 + pk_matA->e6 * pk_matB->e11 + pk_matA->e7 * pk_matB->e15;

    p_matC->e8 = pk_matA->e8 * pk_matB->e0 + pk_matA->e9 * pk_matB->e4 + pk_matA->e10 * pk_matB->e8 + pk_matA->e11 * pk_matB->e12;
    p_matC->e9 = pk_matA->e8 * pk_matB->e1 + pk_matA->e9 * pk_matB->e5 + pk_matA->e10 * pk_matB->e9 + pk_matA->e11 * pk_matB->e13;
    p_matC->e10 = pk_matA->e8 * pk_matB->e2 + pk_matA->e9 * pk_matB->e6 + pk_matA->e10 * pk_matB->e10 + pk_matA->e11 * pk_matB->e14;
    p_matC->e11 = pk_matA->e8 * pk_matB->e3 + pk_matA->e9 * pk_matB->e7 + pk_matA->e10 * pk_matB->e11 + pk_matA->e11 * pk_matB->e15;

    p_matC->e12 = pk_matA->e12 * pk_matB->e0 + pk_matA->e13 * pk_matB->e4 + pk_matA->e14 * pk_matB->e8 + pk_matA->e15 * pk_matB->e12;
    p_matC->e13 = pk_matA->e12 * pk_matB->e1 + pk_matA->e13 * pk_matB->e5 + pk_matA->e14 * pk_matB->e9 + pk_matA->e15 * pk_matB->e13;
    p_matC->e14 = pk_matA->e12 * pk_matB->e2 + pk_matA->e13 * pk_matB->e6 + pk_matA->e14 * pk_matB->e10 + pk_matA->e15 * pk_matB->e14;
    p_matC->e15 = pk_matA->e12 * pk_matB->e3 + pk_matA->e13 * pk_matB->e7 + pk_matA->e14 * pk_matB->e11 + pk_matA->e15 * pk_matB->e15;
}

void matrix44_add(
    IN const MATRIX44_t* pk_matA, 
    IN const MATRIX44_t* pk_matB,
    OUT MATRIX44_t* p_matC) 
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
    p_matC->e9 = pk_matA->e9 + pk_matB->e9;
    p_matC->e10 = pk_matA->e10 + pk_matB->e10;
    p_matC->e11 = pk_matA->e11 + pk_matB->e11;
    p_matC->e12 = pk_matA->e12 + pk_matB->e12;
    p_matC->e13 = pk_matA->e13 + pk_matB->e13;
    p_matC->e14 = pk_matA->e14 + pk_matB->e14;
    p_matC->e15 = pk_matA->e15 + pk_matB->e15;
}

void matrix44_subtrack(
    IN const MATRIX44_t* pk_matA, 
    IN const MATRIX44_t* pk_matB,
    OUT MATRIX44_t* p_matC) 
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
    p_matC->e9 = pk_matA->e9 - pk_matB->e9;
    p_matC->e10 = pk_matA->e10 - pk_matB->e10;
    p_matC->e11 = pk_matA->e11 - pk_matB->e11;
    p_matC->e12 = pk_matA->e12 - pk_matB->e12;
    p_matC->e13 = pk_matA->e13 - pk_matB->e13;
    p_matC->e14 = pk_matA->e14 - pk_matB->e14;
    p_matC->e15 = pk_matA->e15 - pk_matB->e15;
}

void matrix44_transpose(
    IN const MATRIX44_t* pk_matA, 
    OUT MATRIX44_t* p_matB) 
{   
    p_matB->e0 = p_matB->e0;
    p_matB->e1 = p_matB->e4;
    p_matB->e2 = p_matB->e8;
    p_matB->e3 = p_matB->e12;
    p_matB->e4 = p_matB->e1;
    p_matB->e5 = p_matB->e5;
    p_matB->e6 = p_matB->e9;
    p_matB->e7 = p_matB->e13;
    p_matB->e8 = p_matB->e2;
    p_matB->e9 = p_matB->e6;
    p_matB->e10 = p_matB->e10;
    p_matB->e11 = p_matB->e14;
    p_matB->e12 = p_matB->e0;
    p_matB->e13 = p_matB->e0;
    p_matB->e14 = p_matB->e0;
    p_matB->e15 = p_matB->e0;
}

void matrix44_scale(
    INOUT MATRIX44_t* p_matA, 
    IN float s)
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
    p_matA->e9 *= s;
    p_matA->e10 *= s;
    p_matA->e11 *= s;
    p_matA->e12 *= s;
    p_matA->e13 *= s;
    p_matA->e14 *= s;
    p_matA->e15 *= s;
}

void matrix44_copy(
    IN const MATRIX44_t* pk_matA,
    OUT MATRIX44_t* p_matB)
{
    memcpy(p_matB, pk_matA, sizeof(MATRIX44_t));
}

void matrix44_setToZero(
    INOUT MATRIX44_t* p_matA)
{
    memset(p_matA, 0, sizeof(MATRIX44_t));
}
void matrix44_

void matrix44_print(
    IN const MATRIX44_t* pk_matA)
{   
    printf("\n| %.2f %.2f %.2f %.2f |\n", pk_matA->e0, pk_matA->e1, pk_matA->e2, pk_matA->e3);
    printf("| %.2f %.2f %.2f %.2f|\n", pk_matA->e4, pk_matA->e5, pk_matA->e6, pk_matA->e7);
    printf("| %.2f %.2f %.2f %.2f|\n", pk_matA->e8, pk_matA->e9, pk_matA->e10, pk_matA->e11);
    printf("| %.2f %.2f %.2f %.2f|\n", pk_matA->e12, pk_matA->e13, pk_matA->e14, pk_matA->e15);
}
