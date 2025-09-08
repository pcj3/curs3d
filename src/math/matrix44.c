#include "matrix44.h"

void matrix44_multiply(
    IN const MATRIX44_t* pkMatA,
    IN const MATRIX44_t* pkMatB,
    OUT MATRIX44_t* pMatC)
{   
    MATRIX44_t tmpMat;

    tmpMat.e0 = pkMatA->e0 * pkMatB->e0 + pkMatA->e1 * pkMatB->e4 + pkMatA->e2 * pkMatB->e8 + pkMatA->e3 * pkMatB->e12;
    tmpMat.e1 = pkMatA->e0 * pkMatB->e1 + pkMatA->e1 * pkMatB->e5 + pkMatA->e2 * pkMatB->e9 + pkMatA->e3 * pkMatB->e13;
    tmpMat.e2 = pkMatA->e0 * pkMatB->e2 + pkMatA->e1 * pkMatB->e6 + pkMatA->e2 * pkMatB->e10 + pkMatA->e3 * pkMatB->e14;
    tmpMat.e3 = pkMatA->e0 * pkMatB->e3 + pkMatA->e1 * pkMatB->e7 + pkMatA->e2 * pkMatB->e11 + pkMatA->e3 * pkMatB->e15;

    tmpMat.e4 = pkMatA->e4 * pkMatB->e0 + pkMatA->e5 * pkMatB->e4 + pkMatA->e6 * pkMatB->e8 + pkMatA->e7 * pkMatB->e12;
    tmpMat.e5 = pkMatA->e4 * pkMatB->e1 + pkMatA->e5 * pkMatB->e5 + pkMatA->e6 * pkMatB->e9 + pkMatA->e7 * pkMatB->e13;
    tmpMat.e6 = pkMatA->e4 * pkMatB->e2 + pkMatA->e5 * pkMatB->e6 + pkMatA->e6 * pkMatB->e10 + pkMatA->e7 * pkMatB->e14;
    tmpMat.e7 = pkMatA->e4 * pkMatB->e3 + pkMatA->e5 * pkMatB->e7 + pkMatA->e6 * pkMatB->e11 + pkMatA->e7 * pkMatB->e15;

    tmpMat.e8 = pkMatA->e8 * pkMatB->e0 + pkMatA->e9 * pkMatB->e4 + pkMatA->e10 * pkMatB->e8 + pkMatA->e11 * pkMatB->e12;
    tmpMat.e9 = pkMatA->e8 * pkMatB->e1 + pkMatA->e9 * pkMatB->e5 + pkMatA->e10 * pkMatB->e9 + pkMatA->e11 * pkMatB->e13;
    tmpMat.e10 = pkMatA->e8 * pkMatB->e2 + pkMatA->e9 * pkMatB->e6 + pkMatA->e10 * pkMatB->e10 + pkMatA->e11 * pkMatB->e14;
    tmpMat.e11 = pkMatA->e8 * pkMatB->e3 + pkMatA->e9 * pkMatB->e7 + pkMatA->e10 * pkMatB->e11 + pkMatA->e11 * pkMatB->e15;

    tmpMat.e12 = pkMatA->e12 * pkMatB->e0 + pkMatA->e13 * pkMatB->e4 + pkMatA->e14 * pkMatB->e8 + pkMatA->e15 * pkMatB->e12;
    tmpMat.e13 = pkMatA->e12 * pkMatB->e1 + pkMatA->e13 * pkMatB->e5 + pkMatA->e14 * pkMatB->e9 + pkMatA->e15 * pkMatB->e13;
    tmpMat.e14 = pkMatA->e12 * pkMatB->e2 + pkMatA->e13 * pkMatB->e6 + pkMatA->e14 * pkMatB->e10 + pkMatA->e15 * pkMatB->e14;
    tmpMat.e15 = pkMatA->e12 * pkMatB->e3 + pkMatA->e13 * pkMatB->e7 + pkMatA->e14 * pkMatB->e11 + pkMatA->e15 * pkMatB->e15;

   *pMatC = tmpMat;
}

void matrix44_add(
    IN const MATRIX44_t* pkMatA,
    IN const MATRIX44_t* pkMatB,
    OUT MATRIX44_t* pMatC)
{
    MATRIX44_t tmpMat;

    tmpMat.e0 = pkMatA->e0 + pkMatB->e0;
    tmpMat.e1 = pkMatA->e1 + pkMatB->e1;
    tmpMat.e2 = pkMatA->e2 + pkMatB->e2;
    tmpMat.e3 = pkMatA->e3 + pkMatB->e3;
    tmpMat.e4 = pkMatA->e4 + pkMatB->e4;
    tmpMat.e5 = pkMatA->e5 + pkMatB->e5;
    tmpMat.e6 = pkMatA->e6 + pkMatB->e6;
    tmpMat.e7 = pkMatA->e7 + pkMatB->e7;
    tmpMat.e8 = pkMatA->e8 + pkMatB->e8;
    tmpMat.e9 = pkMatA->e9 + pkMatB->e9;
    tmpMat.e10 = pkMatA->e10 + pkMatB->e10;
    tmpMat.e11 = pkMatA->e11 + pkMatB->e11;
    tmpMat.e12 = pkMatA->e12 + pkMatB->e12;
    tmpMat.e13 = pkMatA->e13 + pkMatB->e13;
    tmpMat.e14 = pkMatA->e14 + pkMatB->e14;
    tmpMat.e15 = pkMatA->e15 + pkMatB->e15;

    *pMatC = tmpMat;
}

void matrix44_subtract(
    IN const MATRIX44_t* pkMatA,
    IN const MATRIX44_t* pkMatB,
    OUT MATRIX44_t* pMatC)
{   
    MATRIX44_t tmpMat;

    tmpMat.e0 = pkMatA->e0 - pkMatB->e0;
    tmpMat.e1 = pkMatA->e1 - pkMatB->e1;
    tmpMat.e2 = pkMatA->e2 - pkMatB->e2;
    tmpMat.e3 = pkMatA->e3 - pkMatB->e3;
    tmpMat.e4 = pkMatA->e4 - pkMatB->e4;
    tmpMat.e5 = pkMatA->e5 - pkMatB->e5;
    tmpMat.e6 = pkMatA->e6 - pkMatB->e6;
    tmpMat.e7 = pkMatA->e7 - pkMatB->e7;
    tmpMat.e8 = pkMatA->e8 - pkMatB->e8;
    tmpMat.e9 = pkMatA->e9 - pkMatB->e9;
    tmpMat.e10 = pkMatA->e10 - pkMatB->e10;
    tmpMat.e11 = pkMatA->e11 - pkMatB->e11;
    tmpMat.e12 = pkMatA->e12 - pkMatB->e12;
    tmpMat.e13 = pkMatA->e13 - pkMatB->e13;
    tmpMat.e14 = pkMatA->e14 - pkMatB->e14;
    tmpMat.e15 = pkMatA->e15 - pkMatB->e15;

    *pMatC = tmpMat;
}

void matrix44_transpose(
    IN const MATRIX44_t* pkMatA,
    OUT MATRIX44_t* pMatB)
{   
    MATRIX44_t tmpMat;

    tmpMat.e0  = pkMatA->e0;
    tmpMat.e1  = pkMatA->e4;
    tmpMat.e2  = pkMatA->e8;
    tmpMat.e3  = pkMatA->e12;
    tmpMat.e4  = pkMatA->e1;
    tmpMat.e5  = pkMatA->e5;
    tmpMat.e6  = pkMatA->e9;
    tmpMat.e7  = pkMatA->e13;
    tmpMat.e8  = pkMatA->e2;
    tmpMat.e9  = pkMatA->e6;
    tmpMat.e10 = pkMatA->e10;
    tmpMat.e11 = pkMatA->e14;
    tmpMat.e12 = pkMatA->e3;
    tmpMat.e13 = pkMatA->e7;
    tmpMat.e14 = pkMatA->e11;
    tmpMat.e15 = pkMatA->e15;

    *pMatB = tmpMat;
}

void matrix44_scaleByFactor(
    INOUT MATRIX44_t* pMatA,
    IN R4 s)
{
    pMatA->e0 *= s;
    pMatA->e1 *= s;
    pMatA->e2 *= s;
    pMatA->e3 *= s;
    pMatA->e4 *= s;
    pMatA->e5 *= s;
    pMatA->e6 *= s;
    pMatA->e7 *= s;
    pMatA->e8 *= s;
    pMatA->e9 *= s;
    pMatA->e10 *= s;
    pMatA->e11 *= s;
    pMatA->e12 *= s;
    pMatA->e13 *= s;
    pMatA->e14 *= s;
    pMatA->e15 *= s;
}

void matrix44_copy(
    IN const MATRIX44_t* pkMatA,
    OUT MATRIX44_t* pMatB)
{
    memcpy(pMatB, pkMatA, sizeof(MATRIX44_t));
}

void matrix44_setToZero(
    OUT MATRIX44_t* pMatA)
{
    memset(pMatA, 0, sizeof(MATRIX44_t));
}

void matrix44_setToIdentity(
    OUT MATRIX44_t* pMatA)
{
    pMatA->e0 = 1.f;
    pMatA->e1 = 0.f;
    pMatA->e2 = 0.f;
    pMatA->e3 = 0.f;
    pMatA->e4 = 0.f;
    pMatA->e5 = 1.f;
    pMatA->e6 = 0.f;
    pMatA->e7 = 0.f;
    pMatA->e8 = 0.f;
    pMatA->e9 = 0.f;
    pMatA->e10 = 1.f;
    pMatA->e11 = 0.f;
    pMatA->e12 = 0.f;
    pMatA->e13 = 0.f;
    pMatA->e14 = 0.f;
    pMatA->e15 = 1.f;
}

void matrix44_print(
    IN const MATRIX44_t* pkMatA)
{
    printf("| %.2f %.2f %.2f %.2f |\n", pkMatA->e0, pkMatA->e1, pkMatA->e2, pkMatA->e3);
    printf("| %.2f %.2f %.2f %.2f |\n", pkMatA->e4, pkMatA->e5, pkMatA->e6, pkMatA->e7);
    printf("| %.2f %.2f %.2f %.2f |\n", pkMatA->e8, pkMatA->e9, pkMatA->e10, pkMatA->e11);
    printf("| %.2f %.2f %.2f %.2f |\n", pkMatA->e12, pkMatA->e13, pkMatA->e14, pkMatA->e15);
}
