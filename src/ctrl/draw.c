#include "defs.h"
#include "draw.h"
#include "framebuffer.h"

void draw_do(INOUT DRAW_DATA_t* pData)
{
    erase();
    U4 idx;
    for (U4 y = 0; y < pData->pFramebuffer->height; y++)
    {
        for (U4 x = 0; x < pData->pFramebuffer->width; x++)
        {
            idx = XY_TO_FRAMEBUFFER_IDX(x, y, pData->pFramebuffer->width);
            COLOR_t color = pData->pFramebuffer->colors[idx];
            if (!color)
            {
                continue;
            }
            attron(COLOR_PAIR(2));
            mvaddch((I) y, (I) x, color);
            attroff(COLOR_PAIR(2));
        }
    }
    mvaddch(0, 0, 'A');
    refresh();
}