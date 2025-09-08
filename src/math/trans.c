#include "trans.h"
#include <math.h>
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
    IN const R4 k_angle, // in radians
    OUT MATRIX44_t* p_matB)
{
    VECTOR3_t axis;
    vector3_normalize(pk_vecA, &axis);

    const R4 c = cosf(k_angle);
    const R4 s = sinf(k_angle);
    const R4 t = 1.f - c;

    MATRIX44_t rotMatrix;
    matrix44_setToZero(&rotMatrix);
    rotMatrix.e0 = t * axis.x * axis.x + c; 
    rotMatrix.e1 = t * axis.x * axis.y - s * axis.z;
    rotMatrix.e2 = t * axis.x * axis.y + s * axis.y;
    rotMatrix.e4 = t * axis.x * axis.y + s * axis.z;
    rotMatrix.e5 = t * axis.y * axis.y + c; 
    rotMatrix.e6 = t * axis.y * axis.z - s * axis.x;
    rotMatrix.e8 = t * axis.x * axis.y - s * axis.y;
    rotMatrix.e9 = t * axis.y * axis.z + s * axis.x;    
    rotMatrix.e10 = t * axis.z * axis.z + c;   
    rotMatrix.e15 = 1.f;

    matrix44_multiply(&rotMatrix, pk_matA, p_matB);
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