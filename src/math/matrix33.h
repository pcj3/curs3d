#ifndef MATH_MAT33_H
#define MATH_MAT33_H

#include <stdio.h>
#include <string.h>
#include "defs.h"

typedef struct MATRIX33_s
{
    R4 e0;
    R4 e1;
    R4 e2;
    R4 e3;
    R4 e4;
    R4 e5;
    R4 e6;
    R4 e7;
    R4 e8;
    R4 e9;
    R4 e10;
    R4 e11;
    R4 e12;
    R4 e13;
    R4 e14;
    R4 e15;
} MATRIX33_t;

void matrix33_multiply(
    IN const MATRIX33_t* pk_matA,
    IN const MATRIX33_t* pk_matB,
    OUT MATRIX33_t* p_matC);

void matrix33_add(
    IN const MATRIX33_t* pk_matA,
    IN const MATRIX33_t* pk_matB,
    OUT MATRIX33_t* p_matC);

void matrix33_subtract(
    IN const MATRIX33_t* pk_matA,
    IN const MATRIX33_t* pk_matB,
    OUT MATRIX33_t* p_matC);

void matrix33_transpose(
    IN const MATRIX33_t* pk_matA,
    OUT MATRIX33_t* p_matB);

void matrix33_scale(
    INOUT MATRIX33_t* pk_matA,
    IN R4 s);

void matrix33_copy(
    IN const MATRIX33_t* pk_matA,
    OUT MATRIX33_t* p_matB);

void matrix33_setToZero(
    INOUT MATRIX33_t* p_matA);

void matrix33_print(
    IN const MATRIX33_t* pk_matA);

#endif // MATH_MAT33_H