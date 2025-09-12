#include "defs.h"
#include "draw.h"
#include "framebuffer.h"
#include "braille.h"

void draw_do(INOUT DRAW_DATA_t* pData)
{
    erase();
    U4 idx;
    U4 set = 0;
    for (U4 y = 0; y < pData->pFramebuffer->height; y++)
    {
        for (U4 x = 0; x < pData->pFramebuffer->width; x++)
        {
            idx = XY_TO_FRAMEBUFFER_IDX(x, y, pData->pFramebuffer->width);
            GLYPH_t brailleDotMask = pData->pFramebuffer->glyphs[idx];
            if (!brailleDotMask)
            {
                continue;
            }
            set++;
            wchar_t braille[] = {(wchar_t)(brailleDotMask + BRAILLE_UNICODE_OFFSET), L'\0'};
            mvaddwstr((I)y, (I)x, braille);
        }
    }
    mvprintw(0, 0, "W: %lu H: %lu SET: %lu", pData->pFramebuffer->width, pData->pFramebuffer->height, set);
    refresh();
}