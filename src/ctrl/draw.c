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
            GLYPH_t glyph = pData->pFramebuffer->glyphs[idx];
            if (!glyph)
            {
                continue;
            }

            wchar_t braille[] = {(wchar_t)(glyph + 0x2800), L'\0'};
            mvaddwstr((I)y, (I)x, braille);

        }
    }
    mvprintw(0, 0, "hiho Peiczus");
    refresh();
}