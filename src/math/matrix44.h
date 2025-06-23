#ifndef MATH_MAT44_H
#define MATH_MAT44_H

#include <stdio.h>
#include <string.h>
#include "macros.h"

typedef struct MATRIX44_s
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
} MATRIX44_t;

void matrix44_multiply(
    IN const MATRIX44_t* pk_matA, 
    IN const MATRIX44_t* pk_matB,
    OUT MATRIX44_t* p_matC); 

void matrix44_add(
    IN const MATRIX44_t* pk_matA, 
    IN const MATRIX44_t* pk_matB,
    OUT MATRIX44_t* p_matC);

void matrix44_subtract(
    IN const MATRIX44_t* pk_matA, 
    IN const MATRIX44_t* pk_matB,
    OUT MATRIX44_t* p_matC);

void matrix44_transpose(
    IN const MATRIX44_t* pk_matA, 
    OUT MATRIX44_t* p_matB);

void matrix44_scale(
    INOUT MATRIX44_t* pk_matA, 
    IN R8 s);

void matrix44_copy(
    IN const MATRIX44_t* pk_matA,
    OUT MATRIX44_t* p_matB);

void matrix44_setToZero(
    INOUT MATRIX44_t* p_matA);

void matrix44_setToIdentity(
    INOUT MATRIX44_t* p_matA);

void matrix44_print(
    IN const MATRIX44_t* pk_matA);

#endif // MATH_MAT44_H