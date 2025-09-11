#ifndef MATH_TRIANGLE_h
#define MATH_TRIANGLE_h

#include "defs.h"
#include "vector4.h"
#include "vector3.h"

typedef struct TRIANGLE_s {
    VECTOR4_t ptA;
    VECTOR4_t ptB;
    VECTOR4_t ptC;
} TRIANGLE_t;

typedef struct BARRYCENTRIC_DATA_s {
    R4 denom;
    R4 bcy;
    R4 cbx;
    R4 cay;
    R4 acx;
    R4 acy;
} BARRYCENTRIC_DATA_t;

void triangle_transformToPixelXY(
    IN const TRIANGLE_t* pkTriangleIn,
    IN const U4 kWidth,
    IN const U4 kHeight,
    OUT TRIANGLE_t* pTriangleOut);

BOOL triangle_isPointIn(
    IN const VECTOR3_t* pkVecBarrycentric);

void triangle_getDataBarrycentric(
    IN const TRIANGLE_t* pTriangle,
    OUT BARRYCENTRIC_DATA_t* pData);

void triangle_getVecBarrycentric(
    IN const R4 kX,
    IN const R4 kY,
    IN const BARRYCENTRIC_DATA_t* pkData,
    IN const VECTOR4_t* pkVertexC,
    OUT VECTOR3_t* pVecBarrycentric);

#endif // MATH_TRIANGLE_h