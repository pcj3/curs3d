#include "defs.h"
#include "triangle.h"
#include "vector4.h"

#define POINT_IN_TRIANGLE_TOLERANCE (-1e-3f)


BOOL triangle_isPointIn(
    IN const U4 kX,
    IN const U4 kY,
    IN const TRIANGLE_t* pkTriangle)
{   
    VECTOR4_t ptA = pkTriangle->ptA;
    VECTOR4_t ptB = pkTriangle->ptB;
    VECTOR4_t ptC = pkTriangle->ptC;
    
    R4 denom = (ptB.y - ptC.y) * (ptA.x - ptC.x) + (ptC.x - ptB.x) * (ptA.y - ptC.y);
    R4 weightPtA = ((ptB.y - ptC.y) * (kX - ptC.x) + (ptC.x - ptB.x) * (kY - ptC.y)) / denom;
    R4 weightPtB = ((ptC.y - ptA.y) * (kX - ptC.x) + (ptA.x - ptC.x) * (kY - ptC.y)) / denom;
    
    R4 weightPtC = 1.f - weightPtA - weightPtB;

    BOOL resPtA = weightPtA < POINT_IN_TRIANGLE_TOLERANCE;
    BOOL resPtB = weightPtB < POINT_IN_TRIANGLE_TOLERANCE;
    BOOL resPtC = weightPtC < POINT_IN_TRIANGLE_TOLERANCE;
    return (resPtA == resPtB) && (resPtB == resPtC);

}

void triangle_transformToPixelXY(
    IN const TRIANGLE_t* pkTriangleIn,
    IN const R4 kWidth,
    IN const R4 kHeight,
    OUT TRIANGLE_t* pTriangleOut)
{

    R4 halfWidth = (R4) (kWidth / 2);
    R4 halfHeight = (R4) (kHeight / 2);

    VECTOR4_t vecToMult = {halfWidth, -halfHeight, 1, 1};
    VECTOR4_t vecToAdd = {halfWidth, halfHeight, 0, 0};

    vector4_multiplyElementWiseByVector4(&pkTriangleIn->ptA, 
        &vecToMult, 
        &pTriangleOut->ptA);
    vector4_multiplyElementWiseByVector4(&pkTriangleIn->ptB, 
        &vecToMult, 
        &pTriangleOut->ptB);
    vector4_multiplyElementWiseByVector4(&pkTriangleIn->ptC, 
        &vecToMult, 
        &pTriangleOut->ptC);
    
    vector4_addElementWiseVector4(&pTriangleOut->ptA,
         &vecToAdd, 
         &pTriangleOut->ptA);
    vector4_addElementWiseVector4(&pTriangleOut->ptB, 
        &vecToAdd,
        &pTriangleOut->ptB);
    vector4_addElementWiseVector4(&pTriangleOut->ptC, 
        &vecToAdd, 
        &pTriangleOut->ptC);
}