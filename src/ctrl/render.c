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
    matrix44_multiply(&pData->pCamera->matViewProjected,
        &matTrans,
        &matViewProjTrans);
    
    // Clear buffer
    framebuffer_clear(pData->pFramebuffer);
    framebuffer_setSize(WINDOW_WIDTH,
        WINDOW_HEIGHT,
        pData->pFramebuffer);
    

    // Check if normals are there and calulate if needed
    if ((pData->pModel->faceAttr == FACE_ATTR_VERTICES)
        || (pData->pModel->faceAttr == FACE_ATTR_VERTICES_TEXTURES))
    {   
        
        FACE_t* pFace = pData->pModel->faces;
        for (U4 idxFace = 0; idxFace < pData->pModel->numberFaces; idxFace++, pFace++) 
        {
            VECTOR3_t ptA = {
                .x = pData->pModel->vertices[pFace->idxVertices[0]].x,
                .y = pData->pModel->vertices[pFace->idxVertices[0]].y,
                .z = pData->pModel->vertices[pFace->idxVertices[0]].z
            };
            VECTOR3_t ptB = {
                .x = pData->pModel->vertices[pFace->idxVertices[1]].x,
                .y = pData->pModel->vertices[pFace->idxVertices[1]].y,
                .z = pData->pModel->vertices[pFace->idxVertices[1]].z
            };
            VECTOR3_t ptC = {
                .x = pData->pModel->vertices[pFace->idxVertices[2]].x,
                .y = pData->pModel->vertices[pFace->idxVertices[2]].y,
                .z = pData->pModel->vertices[pFace->idxVertices[2]].z
            };

            VECTOR3_t normal;
            VECTOR3_t vecAB;
            VECTOR3_t vecAC;
            VECTOR3_t crossProd;

            vector3_subtract(&ptB, &ptA, &vecAB);
            vector3_subtract(&ptC, &ptA, &vecAC);
            vector3_crossProd(&vecAB, &vecAC, &crossProd);
            vector3_normalize(&crossProd, &normal);

            pData->pModel->normals[idxFace] = normal;

            for (U1 idxVertex = 0;  idxVertex < pFace->numberVertices; idxVertex++)
            {
                pFace->idxNormals[idxVertex] = idxFace;
            }

        }
        pData->pModel->faceAttr = FACE_ATTR_VERTICES_NORMALS;
    }



    // Render each face
    TRIANGLE_t triangleVertices;
    TRIANGLE_t triangleNormals;
    TRIANGLE_t trianglePosToLight;
    FACE_t* pFace = pData->pModel->faces;
    for (U4 i = 0; i < pData->pModel->numberFaces; i++, pFace++)
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
            
        // Rasterize
        framebuffer_rasterizeTriangle(&triangleVertices,
            &triangleNormals,
            &trianglePosToLight,
            pData->pFramebuffer);
    }
}