#include "defs.h"
#include "render.h"
#include "face.h"
#include "shader_vertex.h"
#include "shader_fragment.h"
void render_do(INOUT RENDER_DATA_t* pData)
{    
    MATRIX44_t matTrans;
    MATRIX44_t matViewProjTrans;
    // Set transformation matrix to identity
    matrix44_setToIdentity(&matTrans);

    // Translate
    matrix44_translateByVector3(&matTrans,
        pData->pVecTrans,
        &matTrans);

    // Rotate
    matrix44_rotateByVector3(&matTrans,
        pData->pVecRotate,
        *pData->pAngleRotate,
        &matTrans);

    // Scale
    matrix44_scaleByVector3(&matTrans,
        pData->pVecScale,
        &matTrans);
        
    // Apply view projected matrix
    matrix44_multiply(
        &pData->pCamera->matViewProjected,
        &matTrans,
        &matViewProjTrans);
    
    // Clear buffer
    framebuffer_clear(pData->pFramebuffer);
    framebuffer_setSize(WINDOW_WIDTH,
        WINDOW_HEIGHT,
        pData->pFramebuffer);
    
    // Render each face
    TRIANGLE_t triangleVertices;
    TRIANGLE_t triangleNormals;
    TRIANGLE_t trianglePosToLight;
    VECTOR3_t brightness;
    FACE_t* pFace = pData->pModel->faces;
    for (U4 i = 0; i < pData->pModel->numberFaces; i++, pFace++)
    {   
        // Only triangles are supported
        if (pFace->numberVertices == 3)
        {
            shaderVertex_do(0,
                pData->pModel,
                pFace,
                &matTrans,
                &matViewProjTrans,
                &pData->pCamera->vecLight,
                &triangleVertices.ptA,
                &triangleNormals.ptA,
                &trianglePosToLight.ptA);
            shaderVertex_do(1,
                pData->pModel,
                pFace,
                &matTrans,
                &matViewProjTrans,
                &pData->pCamera->vecLight,
                &triangleVertices.ptB,
                &triangleNormals.ptB,
                &trianglePosToLight.ptB);
            shaderVertex_do(2,
                pData->pModel,
                pFace,
                &matTrans,
                &matViewProjTrans,
                &pData->pCamera->vecLight,
                &triangleVertices.ptC,
                &triangleNormals.ptC,
                &trianglePosToLight.ptC);
            
            shaderFragment_do(&triangleNormals.ptA,
                &trianglePosToLight.ptA,
                &brightness.x);
            shaderFragment_do(&triangleNormals.ptB,
                &trianglePosToLight.ptB,
                &brightness.y);
            shaderFragment_do(&triangleNormals.ptC,
                &trianglePosToLight.ptC,
                &brightness.z);
        }
        // Rasterize
        framebuffer_rasterizeTriangle(&triangleVertices,
            &brightness,
            pData->pFramebuffer);
    }
}