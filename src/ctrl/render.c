#include "defs.h"
#include "render.h"
#include "framebuffer.h"

void render_do(INOUT RENDER_DATA_t* pData)
{   
    erase();
    framebuffer_print(pData->pFramebuffer);
    refresh();
}