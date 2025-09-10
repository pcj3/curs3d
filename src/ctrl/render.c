#include "defs.h"
#include "render.h"
#include "face.h"

void render_do(INOUT RENDER_DATA_t* pData)
{
    MATRIX44_t matTrans;
    // Set transformation matrix to identity
    matrix44_setToIdentity(&matTrans);

    // Scale
    matrix44_scaleByVector3(&matTrans,
        pData->pVecScale,
        &matTrans);

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
    
    // Clear buffer
    framebuffer_clear(0, pData->pFramebuffer);
    framebuffer_setSize(WINDOW_WIDTH,
        WINDOW_HEIGHT,
        pData->pFramebuffer);
    
    // Render each face
    TRIANGLE_t triangle;
    FACE_t* pFace = pData->pModel->faces;
    for (U4 i = 0; i < pData->pModel->numberFaces; i++, pFace++)
    {
        triangle.ptA = pData->pModel->vertices[pFace->idxVertices[0]];
        triangle.ptB = pData->pModel->vertices[pFace->idxVertices[1]];
        triangle.ptC = pData->pModel->vertices[pFace->idxVertices[2]];
    
        // Apply transfomation to triangle
        matrix44_multiplyByVector4(&matTrans,
            &triangle.ptA,
            &triangle.ptA);
        matrix44_multiplyByVector4(&matTrans,
            &triangle.ptB,
            &triangle.ptB);
        matrix44_multiplyByVector4(&matTrans,
            &triangle.ptC,
            &triangle.ptC);

        // Distance scaling
        vector4_divideByW(&triangle.ptA);
        vector4_divideByW(&triangle.ptB);
        vector4_divideByW(&triangle.ptC);

        // Rasterize
        framebuffer_rasterizeTriangle(&triangle,
            pData->pFramebuffer);
    }
}