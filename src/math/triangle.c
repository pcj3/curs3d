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