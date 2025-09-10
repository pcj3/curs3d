#include "defs.h"
#include "render.h"

void render_do(INOUT RENDER_DATA_t* pData)
{
    MATRIX44_t matTrans;
    // Set transformation matrix to identity
    matrix44_setToIdentity(&matTrans);

    // Scale
    // matrix44_scaleByVector3(&matTrans,
    //     pData->pVecScale,
    //     &matTrans);

    // Translate
    matrix44_translateByVector3(&matTrans,
        pData->pVecTrans,
        &matTrans);

    // Rotate
    matrix44_rotateByVector3(&matTrans,
        pData->pVecRotate,
        *pData->pAngleRotate,
        &matTrans);

    // Apply view projected matrix
    matrix44_multiply(
        pData->pMatViewProjected,
        &matTrans,
        &matTrans);

    // Apply transfomation to triangle
    matrix44_multiplyByVector4(&matTrans,
        &pData->pTrianglePre->ptA,
        &pData->pTriangleAfter->ptA);
    matrix44_multiplyByVector4(&matTrans,
        &pData->pTrianglePre->ptB,
        &pData->pTriangleAfter->ptB);
    matrix44_multiplyByVector4(&matTrans,
        &pData->pTrianglePre->ptC,
        &pData->pTriangleAfter->ptC);

    // Distance scaling
    vector4_divideByW(&pData->pTriangleAfter->ptA);
    vector4_divideByW(&pData->pTriangleAfter->ptB);
    vector4_divideByW(&pData->pTriangleAfter->ptC);

    // Rasterize
    framebuffer_clear(0, pData->pFramebuffer);
    framebuffer_setSize(WINDOW_WIDTH,
        WINDOW_HEIGHT,
        pData->pFramebuffer);
    framebuffer_rasterizeTriangle(pData->pTriangleAfter,
        pData->pFramebuffer);
}