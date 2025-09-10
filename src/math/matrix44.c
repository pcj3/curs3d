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
