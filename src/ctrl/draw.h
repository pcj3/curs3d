#ifndef CTRL_DRAW_h
#define CTRL_DRAW_h

#include "defs.h"
#include "framebuffer.h"

typedef struct DRAW_DATA_s {
    FRAMEBUFFER_t*  pFramebuffer;
} DRAW_DATA_t;

void draw_do(
    INOUT DRAW_DATA_t* pData);

#endif // CTRL_DRAW_h