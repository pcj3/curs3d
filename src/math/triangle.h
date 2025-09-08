#ifndef MATH_TRIANGLE_h
#define MATH_TRIANGLE_h

#include "defs.h"
#include "vector4.h"
#include "framebuffer.h"

typedef struct TRIANGLE_s {
    VECTOR4_t ptA;
    VECTOR4_t ptB;
    VECTOR4_t ptC;
} TRIANGLE_t;

BOOL triangle_isPointIn(
    IN U4 x,
    IN U4 y,
    IN TRIANGLE_t* p_triangle
);

void triangle_transformToPixelXY(
    IN const TRIANGLE_t* pk_triangleIn,
    IN const FRAMEBUFFER_t* pk_frambuffer,
    OUT TRIANGLE_t* p_triangleOut);

#endif // MATH_TRIANGLE_h