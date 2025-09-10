#include "defs.h"
#include "render.h"
#include "trans.h"

void render_do(INOUT RENDER_DATA_t* pData)
{      
    MATRIX44_t matTrans;
    // Set transformation matrix to identity
    matrix44_setToIdentity(&matTrans);

    // Scale 
    trans_scaleMatrix44ByVector3(&matTrans, 
        pData->pVecScale, 
        &matTrans);

    // // Translate
    // trans_tranlateMatrix44ByVector3(&matTrans,
    //     pData->pVecTrans,
    //     &matTrans);

    // Rotate
    trans_rotateMatrix44ByVector3(&matTrans, 
        pData->pVecRotate, 
        *pData->pAngleRotate, 
        &matTrans);

    // Apply view projected matrix
    matrix44_multiply(
        pData->pMatViewProjected,
        &matTrans,
        &matTrans);

    // Apply transfomation to triangle
    trans_multiplyMatrix44ByVector4(&matTrans, 
        &pData->pTrianglePre->ptA, 
        &pData->pTriangleAfter->ptA);
    trans_multiplyMatrix44ByVector4(&matTrans, 
        &pData->pTrianglePre->ptB, 
        &pData->pTriangleAfter->ptB);
    trans_multiplyMatrix44ByVector4(&matTrans, 
        &pData->pTrianglePre->ptC, 
        &pData->pTriangleAfter->ptC);
    
    // Distance scaling
    trans_divideVector4ByW(&pData->pTriangleAfter->ptA);
    trans_divideVector4ByW(&pData->pTriangleAfter->ptB);
    trans_divideVector4ByW(&pData->pTriangleAfter->ptC);

    // Rasterize
    framebuffer_clear(0, pData->pFramebuffer);
    framebuffer_setSize(WINDOW_WIDTH, 
        WINDOW_HEIGHT, 
        pData->pFramebuffer);
    framebuffer_rasterizeTriangle(pData->pTriangleAfter, 
        pData->pFramebuffer);
}