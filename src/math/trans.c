#include "trans.h"

void trans_scaleMatrix44ByVector3(
    IN const MATRIX44_t* pk_matA,
    IN const VECTOR3_t* pk_vecB,
    OUT MATRIX44_t* p_matC)
{
    p_matC->e0 = pk_matA->e0 * pk_vecB->e0;
    p_matC->e1 = pk_matA->e1 * pk_vecB->e0;
    p_matC->e2 = pk_matA->e2 * pk_vecB->e0;
    p_matC->e3 = pk_matA->e3 * pk_vecB->e0;
    p_matC->e4 = pk_matA->e4 * pk_vecB->e1;
    p_matC->e5 = pk_matA->e5 * pk_vecB->e1;
    p_matC->e6 = pk_matA->e6 * pk_vecB->e1;
    p_matC->e7 = pk_matA->e7 * pk_vecB->e1;
    p_matC->e8 = pk_matA->e8 * pk_vecB->e2;
    p_matC->e9 = pk_matA->e9 * pk_vecB->e2;
    p_matC->e10 = pk_matA->e10 * pk_vecB->e2;
    p_matC->e11 = pk_matA->e11 * pk_vecB->e2;
    p_matC->e12 = pk_matA->e12;
    p_matC->e13 = pk_matA->e13;
    p_matC->e14 = pk_matA->e14;
    p_matC->e15 = pk_matA->e15;
}

void trans_rotateMatrix44ByVector3(
    IN const MATRIX44_t* pk_matA,
    IN const VECTOR3_t* pk_vecA,
    IN const R8 k_angle,
    OUT MATRIX44_t* p_matB)
{
    VECTOR3_t axis;

    vector3_normalize(pk_vecA, &axis);
    vector3_print(&axis);
    
    MATRIX33_t axisMatrix = {0.f, -axis.e2, axis.e1, \
                            axis.e2, 0.f, -axis.e0, \
                            -axis.e1, axis.e0, 0.f};
    matrix33_print(&axisMatrix);

    MATRIX33_t axisOuterProduct;
    vector3_outerProduct(&axis, &axis, &axisOuterProduct);
    matrix33_print(&axisOuterProduct);
}