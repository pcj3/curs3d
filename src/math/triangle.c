#include "defs.h"
#include "triangle.h"
#include "vector4.h"

#define POINT_IN_TRIANGLE_TOLERANCE -1e-3f


BOOL triangle_isPointIn(
    IN U4 x,
    IN U4 y,
    IN TRIANGLE_t* p_triangle)
{   
    VECTOR4_t ptA = p_triangle->ptA;
    VECTOR4_t ptB = p_triangle->ptB;
    VECTOR4_t ptC = p_triangle->ptC;

    R4 weightPtA = ((ptB.y - ptC.y) * (x - ptC.x) + (ptC.x - ptB.x) * (y - ptC.y)) / 
                ((ptB.y - ptC.y) * (ptA.x - ptC.x) + (ptC.x - ptB.x) * (ptA.y - ptC.y));

    R4 weightPtB = ((ptC.y - ptA.y) * (x - ptC.x) + (ptA.x - ptC.x) * (y - ptC.y)) / 
                ((ptC.y - ptA.y) * (ptB.x - ptC.x) + (ptA.x - ptC.x) * (ptB.y - ptC.y));
    
    R4 weightPtC = 1.f - weightPtA - weightPtB;

    BOOL resPtA = weightPtA < POINT_IN_TRIANGLE_TOLERANCE;
    BOOL resPtB = weightPtB < POINT_IN_TRIANGLE_TOLERANCE;
    BOOL resPtC = weightPtC < POINT_IN_TRIANGLE_TOLERANCE;
    return (resPtA == resPtB) && (resPtB == resPtC);
}

void triangle_transformToPixelXY(
    IN const TRIANGLE_t* pk_triangleIn,
    IN const FRAMEBUFFER_t* pk_frambuffer,
    OUT TRIANGLE_t* p_triangleOut)
{
    VECTOR4_t ptA0;
    VECTOR4_t ptB0;
    VECTOR4_t ptC0;

    VECTOR4_t ptA;
    VECTOR4_t ptB;
    VECTOR4_t ptC;
    VECTOR4_t vecPixelXY = {pk_frambuffer->width / 2, -1.f * pk_frambuffer->height / 2, 1, 1};
    VECTOR4_t vecPixelXY0 = {pk_frambuffer->width / 2, pk_frambuffer->height / 2, 0, 0};
    vector4_multiplyElementWiseByVector4(&pk_triangleIn->ptA, &vecPixelXY, &ptA0);
    vector4_multiplyElementWiseByVector4(&pk_triangleIn->ptB, &vecPixelXY, &ptB0);
    vector4_multiplyElementWiseByVector4(&pk_triangleIn->ptC, &vecPixelXY, &ptC0);
    vector4_addElementWiseVector4(&ptA0, &vecPixelXY0, &ptA);
    vector4_addElementWiseVector4(&ptB0, &vecPixelXY0, &ptB);
    vector4_addElementWiseVector4(&ptC0, &vecPixelXY0, &ptC);
    p_triangleOut->ptA = ptA;
    p_triangleOut->ptB = ptB;
    p_triangleOut->ptC = ptC;
}