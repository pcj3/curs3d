#ifndef MATH_MAT33_H
#define MATH_MAT33_H

#include <stdio.h>
#include <string.h>
#include "macros.h"

typedef struct MATRIX33_s
{
    R8 e0;
    R8 e1;
    R8 e2;
    R8 e3;
    R8 e4;
    R8 e5;
    R8 e6;
    R8 e7;
    R8 e8;
    R8 e9;
    R8 e10;
    R8 e11;
    R8 e12;
    R8 e13;
    R8 e14;
    R8 e15;
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
    IN R8 s);

void matrix33_copy(
    IN const MATRIX33_t* pk_matA,
    OUT MATRIX33_t* p_matB);

void matrix33_setToZero(
    INOUT MATRIX33_t* p_matA);

void matrix33_print(
    IN const MATRIX33_t* pk_matA);

#endif // MATH_MAT33_H