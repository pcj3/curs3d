#ifndef MATH_MAT44_H
#define MATH_MAT44_H

#include <stdio.h>
#include <string.h>
#include "macros.h"

typedef struct MATRIX44_s
{
    float e0;
    float e1;
    float e2;
    float e3;
    float e4;
    float e5;
    float e6;
    float e7;
    float e8;
    float e9;
    float e10;
    float e11;
    float e12;
    float e13;
    float e14;
    float e15;
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
    IN float s);

void matrix44_copy(
    IN const MATRIX44_t* pk_matA,
    OUT MATRIX44_t* p_matB);

void matrix44_setToZero(
    INOUT MATRIX44_t* p_matA);

void matrix44_print(
    IN const MATRIX44_t* pk_matA);

#endif // MATH_MAT44_H