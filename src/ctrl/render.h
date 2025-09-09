#ifndef CTRL_RENDER_h
#define CTRL_RENDER_h

#include "defs.h"
#include "framebuffer.h"

typedef struct RENDER_DATA_s {
    FRAMEBUFFER_t*  pFramebuffer;
} RENDER_DATA_t;

void render_do(
    INOUT RENDER_DATA_t* pData);

#endif // CTRL_RENDER_h