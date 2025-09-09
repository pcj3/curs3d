#ifndef MATH_TRIANGLE_h
#define MATH_TRIANGLE_h

#include "defs.h"
#include "vector4.h"

typedef struct TRIANGLE_s {
    VECTOR4_t ptA;
    VECTOR4_t ptB;
    VECTOR4_t ptC;
} TRIANGLE_t;

BOOL triangle_isPointIn(
    IN const U4 kX,
    IN const U4 ky,
    IN const TRIANGLE_t* pkTriangle
);

void triangle_transformToPixelXY(
    IN const TRIANGLE_t* pkTriangleIn,
    IN const R4 kWidth,
    IN const R4 kHeight,
    OUT TRIANGLE_t* pTriangleOut);

#endif // MATH_TRIANGLE_h