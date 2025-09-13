#include "defs.h"
#include "draw.h"
#include "framebuffer.h"
#include "braille.h"

void draw_do(INOUT DRAW_DATA_t* pData)
{
    werase(pData->pWindow);
    U4 idx;
#ifdef DEBUG
    mvprintw(0, 0, "W: %lu H: %lu",  pData->pFramebuffer->width, pData->pFramebuffer->height);
    mvwaddch(pData->pWindow, 13, 0, 'Y');
    mvwaddch(pData->pWindow, 10, 67, 'X');
#endif //DEBUG
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
            wchar_t braille[] = {(wchar_t)(brailleDotMask + BRAILLE_UNICODE_OFFSET), L'\0'};
            mvwaddwstr(pData->pWindow, (I)y, (I)x, braille);
        }
    }
    wrefresh(pData->pWindow);
}