#include "defs.h"
#include "render.h"
#include "trans.h"

void render_do(INOUT RENDER_DATA_t* pData)
{   
    // Set transformation matrix to identity
    matrix44_setToIdentity(pData->pMatTrans);

    // Scale 
    trans_scaleMatrix44ByVector3(pData->pMatTrans, 
        pData->pVecScale, 
        pData->pMatTrans);
    // Rotate
    trans_rotateMatrix44ByVector3(pData->pMatTrans, 
        pData->pVecRotate, 
        *pData->pAngleRotate, 
        pData->pMatTrans);

    // Apply transfomation
    trans_multiplyMatrix44ByVector4(pData->pMatTrans, 
        &pData->pTrianglePre->ptA, 
        &pData->pTriangleAfter->ptA);
    trans_multiplyMatrix44ByVector4(pData->pMatTrans, 
        &pData->pTrianglePre->ptB, 
        &pData->pTriangleAfter->ptB);
    trans_multiplyMatrix44ByVector4(pData->pMatTrans, 
        &pData->pTrianglePre->ptC, 
        &pData->pTriangleAfter->ptC);

    framebuffer_clear(0, pData->pFramebuffer);
    framebuffer_setSize(WINDOW_WIDTH, 
        WINDOW_HEIGHT, 
        pData->pFramebuffer);
    framebuffer_rasterizeTriangle(pData->pTriangleAfter, 
        pData->pFramebuffer);
}