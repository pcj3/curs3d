#include "defs.h"
#include "draw.h"
#include "framebuffer.h"
#include "braille.h"

void draw_do(INOUT DRAW_DATA_t* pData)
{
    werase(pData->pWindow);
#ifdef DEBUG
    mvprintw(0, 0, "W: %lu H: %lu",  pData->pFramebuffer->width, pData->pFramebuffer->height);
#endif //DEBUG
    for (U4 y = 0; y < pData->pFramebuffer->height; y++)
    {
        for (U4 x = 0; x < pData->pFramebuffer->width; x++)
        {
            U4 idxPixel = XY_TO_FRAMEBUFFER_IDX(x, y, pData->pFramebuffer->width);
            U4 idxColor = idxPixel * BRAILLE_DOTS_COUNT;
            GLYPH_t brailleDotMask = pData->pFramebuffer->glyphs[idxPixel];
            if (!brailleDotMask)
            {
                continue;
            }
            U4 color = 0;
            for (U1 idxDot = 0; idxDot < BRAILLE_DOTS_COUNT; idxDot++)
            {
                if (braille_getDotState(brailleDotMask, idxDot))
                {
                    color += pData->pFramebuffer->colors[idxColor+idxDot];
                }
            }
            color /= braille_countDots(brailleDotMask);
            wchar_t braille[] = {(wchar_t)(brailleDotMask + BRAILLE_UNICODE_OFFSET), L'\0'};
            attron(COLOR_PAIR(color+SHADE_OFFSET_IDX));
            mvwaddwstr(pData->pWindow, (I)y, (I)x, braille);
            attron(COLOR_PAIR(color+SHADE_OFFSET_IDX));
        }
    }
    wrefresh(pData->pWindow);
}