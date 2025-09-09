#ifndef CTRL_UPDATE_h
#define CTRL_UPDATE_h

#include "defs.h"
#include "framebuffer.h"
#include "triangle.h"
#include "matrix44.h"
#include "vector3.h"

typedef struct UPDATE_DATA_s {
    FRAMEBUFFER_t*  pFramebuffer;
    TRIANGLE_t*     pTrianglePre;
    TRIANGLE_t*     pTriangleAfter;
    MATRIX44_t*     pMatTrans;
    VECTOR3_t*      pVecScale;
    VECTOR3_t*      pVecRotate;
    R4*             pAngleRotate;
} UPDATE_DATA_t;

void update_do(
    INOUT UPDATE_DATA_t* pData);

#endif // CTRL_UPDATE_h