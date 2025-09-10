#include "matrix44.h"

void matrix44_multiply(
    IN const MATRIX44_t* pkMatA,
    IN const MATRIX44_t* pkMatB,
    OUT MATRIX44_t* pMatC)
{
    MATRIX44_t tmpMat;

    tmpMat.e00 = pkMatA->e00 * pkMatB->e00 + pkMatA->e10 * pkMatB->e01 + pkMatA->e20 * pkMatB->e02 + pkMatA->e30 * pkMatB->e03;
    tmpMat.e01 = pkMatA->e01 * pkMatB->e00 + pkMatA->e11 * pkMatB->e01 + pkMatA->e21 * pkMatB->e02 + pkMatA->e31 * pkMatB->e03;
    tmpMat.e02 = pkMatA->e02 * pkMatB->e00 + pkMatA->e12 * pkMatB->e01 + pkMatA->e22 * pkMatB->e02 + pkMatA->e32 * pkMatB->e03;
    tmpMat.e03 = pkMatA->e03 * pkMatB->e00 + pkMatA->e13 * pkMatB->e01 + pkMatA->e23 * pkMatB->e02 + pkMatA->e33 * pkMatB->e03;

    tmpMat.e10 = pkMatA->e00 * pkMatB->e10 + pkMatA->e10 * pkMatB->e11 + pkMatA->e20 * pkMatB->e12 + pkMatA->e30 * pkMatB->e13;
    tmpMat.e11 = pkMatA->e01 * pkMatB->e10 + pkMatA->e11 * pkMatB->e11 + pkMatA->e21 * pkMatB->e12 + pkMatA->e31 * pkMatB->e13;
    tmpMat.e12 = pkMatA->e02 * pkMatB->e10 + pkMatA->e12 * pkMatB->e11 + pkMatA->e22 * pkMatB->e12 + pkMatA->e32 * pkMatB->e13;
    tmpMat.e13 = pkMatA->e03 * pkMatB->e10 + pkMatA->e13 * pkMatB->e11 + pkMatA->e23 * pkMatB->e12 + pkMatA->e33 * pkMatB->e13;

    tmpMat.e20 = pkMatA->e00 * pkMatB->e20 + pkMatA->e10 * pkMatB->e21 + pkMatA->e20 * pkMatB->e22 + pkMatA->e30 * pkMatB->e23;
    tmpMat.e21 = pkMatA->e01 * pkMatB->e20 + pkMatA->e11 * pkMatB->e21 + pkMatA->e21 * pkMatB->e22 + pkMatA->e31 * pkMatB->e23;
    tmpMat.e22 = pkMatA->e02 * pkMatB->e20 + pkMatA->e12 * pkMatB->e21 + pkMatA->e22 * pkMatB->e22 + pkMatA->e32 * pkMatB->e23;
    tmpMat.e23 = pkMatA->e03 * pkMatB->e20 + pkMatA->e13 * pkMatB->e21 + pkMatA->e23 * pkMatB->e22 + pkMatA->e33 * pkMatB->e23;

    tmpMat.e30 = pkMatA->e00 * pkMatB->e30 + pkMatA->e10 * pkMatB->e31 + pkMatA->e20 * pkMatB->e32 + pkMatA->e30 * pkMatB->e33;
    tmpMat.e31 = pkMatA->e01 * pkMatB->e30 + pkMatA->e11 * pkMatB->e31 + pkMatA->e21 * pkMatB->e32 + pkMatA->e31 * pkMatB->e33;
    tmpMat.e32 = pkMatA->e02 * pkMatB->e30 + pkMatA->e12 * pkMatB->e31 + pkMatA->e22 * pkMatB->e32 + pkMatA->e32 * pkMatB->e33;
    tmpMat.e33 = pkMatA->e03 * pkMatB->e30 + pkMatA->e13 * pkMatB->e31 + pkMatA->e23 * pkMatB->e32 + pkMatA->e33 * pkMatB->e33;

   *pMatC = tmpMat;
}

void matrix44_setToIdentity(
    OUT MATRIX44_t* pMatA)
{
    pMatA->e00 = 1.f;
    pMatA->e01 = 0.f;
    pMatA->e02 = 0.f;
    pMatA->e03 = 0.f;
    pMatA->e10 = 0.f;
    pMatA->e11 = 1.f;
    pMatA->e12 = 0.f;
    pMatA->e13 = 0.f;
    pMatA->e20 = 0.f;
    pMatA->e21 = 0.f;
    pMatA->e22 = 1.f;
    pMatA->e23 = 0.f;
    pMatA->e30 = 0.f;
    pMatA->e31 = 0.f;
    pMatA->e32 = 0.f;
    pMatA->e33 = 1.f;
}

void matrix44_scaleByVector3(
    IN const MATRIX44_t* pkMatA,
    IN const VECTOR3_t* pkVecB,
    OUT MATRIX44_t* pMatC)
{
    MATRIX44_t tmpMat;

    tmpMat.e00 = pkMatA->e00 * pkVecB->x;
    tmpMat.e01 = pkMatA->e01 * pkVecB->x;
    tmpMat.e02 = pkMatA->e02 * pkVecB->x;
    tmpMat.e03 = pkMatA->e03 * pkVecB->x;

    tmpMat.e10 = pkMatA->e10 * pkVecB->y;
    tmpMat.e11 = pkMatA->e11 * pkVecB->y;
    tmpMat.e12 = pkMatA->e12 * pkVecB->y;
    tmpMat.e13 = pkMatA->e13 * pkVecB->y;

    tmpMat.e20 = pkMatA->e20 * pkVecB->z;
    tmpMat.e21 = pkMatA->e21 * pkVecB->z;
    tmpMat.e22 = pkMatA->e22 * pkVecB->z;
    tmpMat.e23 = pkMatA->e23 * pkVecB->z;

    tmpMat.e30 = pkMatA->e30;
    tmpMat.e31 = pkMatA->e31;
    tmpMat.e32 = pkMatA->e32;
    tmpMat.e33 = pkMatA->e33;

    *pMatC = tmpMat;
}

void matrix44_rotateByVector3(
    IN const MATRIX44_t* pkMatA,
    IN const VECTOR3_t* pkVecA,
    IN const R4 kAngle, // in radians
    OUT MATRIX44_t* pMatB)
{
    VECTOR3_t axis;
    vector3_normalize(pkVecA, &axis);

    const R4 c = cosf(kAngle);
    const R4 s = sinf(kAngle);
    const R4 t = 1.f - c;

    R4 txy = t * axis.x * axis.y;
    R4 txz = t * axis.x * axis.z;
    R4 tyz = t * axis.y * axis.z;

    R4 sx = s * axis.x;
    R4 sy = s * axis.y;
    R4 sz = s * axis.z;

    /*
    Rodrigues rotation matrix formulation

        | txx + c   txy - sz    txz + sy    0 |
    R = | txt + sz  tyy + c     tyz - sx    0 |
        | txz - sy  tyz + sx    tzz + c     0 |
        |   0           0           0       1 |

    */
    R4 r00 = r00 = t * axis.x * axis.x + c;
    R4 r01 = txy + sz;
    R4 r02 = txz - sy;
    R4 r10 = txy - sz;
    R4 r11 = t * axis.y * axis.y + c;
    R4 r12 = tyz + sx;
    R4 r20 = txz + sy;
    R4 r21 = tyz - sx;
    R4 r22 = t * axis.z * axis.z + c;

    R4 e00 = pkMatA->e00 * r00 + pkMatA->e10 * r01 + pkMatA->e20 * r02;
    R4 e01 = pkMatA->e01 * r00 + pkMatA->e11 * r01 + pkMatA->e21 * r02;
    R4 e02 = pkMatA->e02 * r00 + pkMatA->e12 * r01 + pkMatA->e22 * r02;
    R4 e03 = pkMatA->e03 * r00 + pkMatA->e13 * r01 + pkMatA->e23 * r02;
    R4 e10 = pkMatA->e00 * r10 + pkMatA->e10 * r11 + pkMatA->e20 * r12;
    R4 e11 = pkMatA->e01 * r10 + pkMatA->e11 * r11 + pkMatA->e21 * r12;
    R4 e12 = pkMatA->e02 * r10 + pkMatA->e12 * r11 + pkMatA->e22 * r12;
    R4 e13 = pkMatA->e03 * r10 + pkMatA->e13 * r11 + pkMatA->e23 * r12;
    pMatB->e20 = pkMatA->e00 * r20 + pkMatA->e10 * r21 + pkMatA->e20 * r22;
    pMatB->e21 = pkMatA->e01 * r20 + pkMatA->e11 * r21 + pkMatA->e21 * r22;
    pMatB->e22 = pkMatA->e02 * r20 + pkMatA->e12 * r21 + pkMatA->e22 * r22;
    pMatB->e23 = pkMatA->e03 * r20 + pkMatA->e13 * r21 + pkMatA->e23 * r22;
    pMatB->e00 = e00;
    pMatB->e01 = e01;
    pMatB->e02 = e02;
    pMatB->e03 = e03;
    pMatB->e10 = e10;
    pMatB->e11 = e11;
    pMatB->e12 = e12;
    pMatB->e13 = e13;

}

void matrix44_translateByVector3(
    IN const MATRIX44_t* pkMatA,
    IN const VECTOR3_t* pkVecA,
    OUT MATRIX44_t* pMatB)
{
    MATRIX44_t tmpMat;

    tmpMat = *pkMatA;
    tmpMat.e30 += pkMatA->e00 * pkVecA->x + pkMatA->e10 * pkVecA->y + pkMatA->e20 * pkVecA->z;
    tmpMat.e31 += pkMatA->e01 * pkVecA->x + pkMatA->e11 * pkVecA->y + pkMatA->e21 * pkVecA->z;
    tmpMat.e32 += pkMatA->e02 * pkVecA->x + pkMatA->e12 * pkVecA->y + pkMatA->e22 * pkVecA->z;
    tmpMat.e33 += pkMatA->e03 * pkVecA->x + pkMatA->e13 * pkVecA->y + pkMatA->e23 * pkVecA->z;

    *pMatB = tmpMat;
}

void matrix44_multiplyByVector4(
    IN const MATRIX44_t* pkMatA,
    IN const VECTOR4_t* pkVecB,
    OUT VECTOR4_t* pVecC)
{
    VECTOR4_t tmpVec;

    tmpVec.x = pkMatA->e00 * pkVecB->x + pkMatA->e10 * pkVecB->y + pkMatA->e20 * pkVecB->z + pkMatA->e30 * pkVecB->w;
    tmpVec.y = pkMatA->e01 * pkVecB->x + pkMatA->e11 * pkVecB->y + pkMatA->e21 * pkVecB->z + pkMatA->e31 * pkVecB->w;
    tmpVec.z = pkMatA->e02 * pkVecB->x + pkMatA->e12 * pkVecB->y + pkMatA->e22 * pkVecB->z + pkMatA->e32 * pkVecB->w;
    tmpVec.w = pkMatA->e03 * pkVecB->x + pkMatA->e13 * pkVecB->y + pkMatA->e23 * pkVecB->z + pkMatA->e33 * pkVecB->w;

    *pVecC = tmpVec;
}


void matrix44_print(
    IN const MATRIX44_t* pkMat)
{
    printf("| %.4f %.4f %.4f %.4f |\n", pkMat->e00, pkMat->e10, pkMat->e20, pkMat->e30);
    printf("| %.4f %.4f %.4f %.4f |\n", pkMat->e01, pkMat->e11, pkMat->e21, pkMat->e31);
    printf("| %.4f %.4f %.4f %.4f |\n", pkMat->e02, pkMat->e12, pkMat->e22, pkMat->e32);
    printf("| %.4f %.4f %.4f %.4f |\n", pkMat->e03, pkMat->e13, pkMat->e23, pkMat->e33);
}