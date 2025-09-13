#ifndef CTRL_SHADER_VERTEX_h
#define CTRL_SHADER_VERTEX_h
#include "defs.h"

#include "model.h"
#include "face.h"
#include "camera.h"

void shaderVertex_do(
    IN U1           idx,
    IN MODEL_t*     pModel,
    IN FACE_t*      pFace,
    IN MATRIX44_t*  pMatTrans,
    IN MATRIX44_t*  pMatViewProjTrans,
    IN VECTOR3_t*   pVecLight,
    OUT VECTOR4_t*  pVertex,
    OUT VECTOR4_t*  pNormal,
    OUT VECTOR4_t*  pPosToLight);



#endif // CTRL_SHADER_VERTEX_h