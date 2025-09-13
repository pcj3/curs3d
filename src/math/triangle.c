#include "defs.h"
#include "triangle.h"
#include "vector4.h"

#define POINT_IN_TRIANGLE_TOLERANCE (-1.e-3)

void triangle_transformToPixelXY(
    IN const TRIANGLE_t* pkTriangleIn,
    IN const U4 kWidth,
    IN const U4 kHeight,
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

BOOL triangle_isPointIn(
    IN const VECTOR3_t* pkVecBarrycentric)
{
    BOOL resPtA = pkVecBarrycentric->x < POINT_IN_TRIANGLE_TOLERANCE;
    BOOL resPtB = pkVecBarrycentric->y < POINT_IN_TRIANGLE_TOLERANCE;
    BOOL resPtC = pkVecBarrycentric->z < POINT_IN_TRIANGLE_TOLERANCE;
    return (resPtA == resPtB) && (resPtB == resPtC);
}

void triangle_getDataBarrycentric(
    IN const TRIANGLE_t* pkTriangle,
    OUT BARRYCENTRIC_DATA_t* pData)
{
    VECTOR4_t ptA = pkTriangle->ptA;
    VECTOR4_t ptB = pkTriangle->ptB;
    VECTOR4_t ptC = pkTriangle->ptC;
    pData->bcy = ptB.y - ptC.y;
    pData->cbx = ptC.x - ptB.x;
    pData->acy = ptA.y - ptC.y;
    pData->acx = ptA.x - ptC.x;
    pData->cay = ptC.y - ptA.y;
    pData->denom = pData->bcy * pData->acx + pData->cbx *  pData->acy;
}

void triangle_setVecBarrycentric(
    IN const R4 kX,
    IN const R4 kY,
    IN const BARRYCENTRIC_DATA_t* pkData,
    IN const VECTOR4_t* pkVertexC,
    OUT VECTOR3_t* pVecBarrycentric)
{
    pVecBarrycentric->x = (pkData->bcy * (kX - pkVertexC->x) + pkData->cbx * (kY - pkVertexC->y)) / pkData->denom;
    pVecBarrycentric->y = (pkData->cay * (kX - pkVertexC->x) + pkData->acx * (kY - pkVertexC->y)) / pkData->denom;
    pVecBarrycentric->z = 1.f - pVecBarrycentric->x - pVecBarrycentric->y;
}