#include "defs.h"
#include "draw.h"
#include "framebuffer.h"
#include "braille.h"

void draw_do(INOUT DRAW_DATA_t* pData)
{
    erase();
    U4 idx;
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
            mvaddwstr((I)y, (I)x, braille);
#ifdef DEBUG
            refresh();
            mvprintw(1, 0, "W: %lu H: %lu",  pData->pFramebuffer->width, pData->pFramebuffer->height);
            //getch();
#endif //DEBUG
        }
    }
    mvprintw(0, 0, "W: %lu H: %lu", pData->pFramebuffer->width, pData->pFramebuffer->height);
    refresh();
}