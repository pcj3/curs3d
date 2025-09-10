#ifndef CTRL_RENDER_h
#define CTRL_RENDER_h

#include "defs.h"
#include "framebuffer.h"
#include "triangle.h"
#include "matrix44.h"
#include "vector3.h"
#include "model.h"

typedef struct RENDER_DATA_s {
    FRAMEBUFFER_t*  pFramebuffer;
    MATRIX44_t*     pMatViewProjected;
    MODEL_t*        pModel;
    VECTOR3_t*      pVecTrans;
    VECTOR3_t*      pVecScale;
    VECTOR3_t*      pVecRotate;
    R4*             pAngleRotate;
} RENDER_DATA_t;

void render_do(
    INOUT RENDER_DATA_t* pData);

#endif // CTRL_RENDER_h