#ifndef MATH_MAT33_H
#define MATH_MAT33_H

#include <stdio.h>
#include <string.h>
#include "macros.h"

typedef struct MATRIX33_s
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
    IN float s);

void matrix33_copy(
    IN const MATRIX33_t* pk_matA,
    OUT MATRIX33_t* p_matB);

void matrix33_setToZero(
    INOUT MATRIX33_t* p_matA);

void matrix33_print(
    IN const MATRIX33_t* pk_matA);

#endif // MATH_MAT33_H