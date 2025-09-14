#include "shader_vertex.h"
#include "defs.h"

void shaderVertex_do(
    IN U1           idx,
    IN MODEL_t*     pModel,
    IN FACE_t*      pFace,
    IN MATRIX44_t*  pMatTrans,
    IN MATRIX44_t*  pMatViewProjTrans,
    IN VECTOR3_t*   pVecLight,
    OUT VECTOR4_t*  pVertex,
    OUT VECTOR4_t*  pNormal,
    OUT VECTOR4_t*  pPosToLight)
{
    VECTOR4_t vertex = pModel->vertices[pFace->idxVertices[idx]];
    VECTOR4_t normal = {
            .x = pModel->normals[pFace->idxNormals[idx]].x,
            .y = pModel->normals[pFace->idxNormals[idx]].y,
            .z = pModel->normals[pFace->idxNormals[idx]].z,
            .w = 0.f};
    VECTOR4_t posLight = {
            .x = pVecLight->x,
            .y = pVecLight->y,
            .z = pVecLight->z,
            .w = 1.f};
    
    
    // Apply transfomation to vertex
    matrix44_multiplyByVector4(pMatViewProjTrans,
        &vertex,
        pVertex);
    vector4_divideXYByZ(pVertex);

    //Apply transformation to triangle normal
    matrix44_multiplyByVector4(pMatTrans,
        &normal,
        pNormal);

    // Apply transformation to word position
    matrix44_multiplyByVector4(pMatTrans,
        &vertex,
        pPosToLight);
    // Make it a vector to light source
    vector4_subtract(&posLight, 
        pPosToLight,
        pPosToLight);

}