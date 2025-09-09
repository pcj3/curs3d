#include "defs.h"
#include "draw.h"
#include "framebuffer.h"

void draw_do(INOUT DRAW_DATA_t* pData)
{   
    erase();
    framebuffer_draw(pData->pFramebuffer);
    refresh();
}