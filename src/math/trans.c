#include "trans.h"

void trans_scaleMatrix44ByVector3(
    IN const MATRIX44_t* pk_matA,
    IN const VECTOR3_t* pk_vecB,
    OUT MATRIX44_t* p_matC)
{
    p_matC->e0 = pk_matA->e0 * pk_vecB->x;
    p_matC->e1 = pk_matA->e1 * pk_vecB->x;
    p_matC->e2 = pk_matA->e2 * pk_vecB->x;
    p_matC->e3 = pk_matA->e3 * pk_vecB->x;
    p_matC->e4 = pk_matA->e4 * pk_vecB->y;
    p_matC->e5 = pk_matA->e5 * pk_vecB->y;
    p_matC->e6 = pk_matA->e6 * pk_vecB->y;
    p_matC->e7 = pk_matA->e7 * pk_vecB->y;
    p_matC->e8 = pk_matA->e8 * pk_vecB->z;
    p_matC->e9 = pk_matA->e9 * pk_vecB->z;
    p_matC->e10 = pk_matA->e10 * pk_vecB->z;
    p_matC->e11 = pk_matA->e11 * pk_vecB->z;
    p_matC->e12 = pk_matA->e12;
    p_matC->e13 = pk_matA->e13;
    p_matC->e14 = pk_matA->e14;
    p_matC->e15 = pk_matA->e15;
}

void trans_rotateMatrix44ByVector3(
    IN const MATRIX44_t* pk_matA,
    IN const VECTOR3_t* pk_vecA,
    IN const R4 k_angle,
    OUT MATRIX44_t* p_matB)
{
    VECTOR3_t axis;
    UNUSED(pk_matA);
    UNUSED(k_angle);
    UNUSED(p_matB);
    vector3_normalize(pk_vecA, &axis);
    vector3_print(&axis);

    MATRIX33_t axisMatrix = {0.f, -axis.z, axis.y, \
                            axis.z, 0.f, -axis.x, \
                            -axis.y, axis.x, 0.f};
    matrix33_print(&axisMatrix);

    MATRIX33_t axisOuterProduct;
    vector3_outerProduct(&axis, &axis, &axisOuterProduct);
    matrix33_print(&axisOuterProduct);
}

void trans_multiplyMatrix44ByVector4(
    IN const MATRIX44_t* pk_matA,
    IN const VECTOR4_t* pk_vecB,
    OUT VECTOR4_t* p_vecC)
{
    p_vecC->x = pk_matA->e0 * pk_vecB->x + pk_matA->e1 * pk_vecB->y + pk_matA->e2 * pk_vecB->z + pk_matA->e3 * pk_vecB->y;
    p_vecC->y = pk_matA->e4 * pk_vecB->x + pk_matA->e5 * pk_vecB->y + pk_matA->e6 * pk_vecB->z + pk_matA->e7 * pk_vecB->y;
    p_vecC->z = pk_matA->e8 * pk_vecB->x + pk_matA->e9 * pk_vecB->y + pk_matA->e10 * pk_vecB->z + pk_matA->e11 * pk_vecB->y;
    p_vecC->w = pk_matA->e12 * pk_vecB->x + pk_matA->e13 * pk_vecB->y + pk_matA->e14 * pk_vecB->z + pk_matA->e15 * pk_vecB->y;
}