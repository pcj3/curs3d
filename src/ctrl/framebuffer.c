#include "framebuffer.h"
#include "defs.h"
#include <string.h>

void framebuffer_clear(
    IN const GLYPH_t k_glyph,
    OUT FRAMEBUFFER_t* p_framebuffer)
{
    p_framebuffer->height = 0;
    p_framebuffer->width = 0;
    memset(p_framebuffer->depths, FRAMEBUFFER_MAX_DEPTH, sizeof(DEPTH_t) * FRAMEBUFFER_DEPTHS_SIZE_MAX);
    memset(p_framebuffer->glyphs, k_glyph, sizeof(GLYPH_t) * FRAMEBUFFER_DEPTHS_SIZE_MAX);
}

void framebuffer_setSize(
    IN U4 width,
    IN U4 height,
    OUT FRAMEBUFFER_t* p_framebuffer)
{
    p_framebuffer->width = width;
    p_framebuffer->height = height;
}

void framebuffer_setPixel(
    IN const U4 k_x,
    IN const U4 k_y,
    IN const GLYPH_t k_glyph,
    IN const DEPTH_t k_depth,
    INOUT FRAMEBUFFER_t* p_framebuffer)
{
    U4 idx = XY_TO_FRAMEBUFFER_IDX(k_x, k_y, p_framebuffer->width);

    if (k_depth >= p_framebuffer->depths[idx])
    {
        return;
    }
    p_framebuffer->glyphs[idx] = k_glyph;
    p_framebuffer->depths[idx] = k_depth;
}

void framebuffer_rasterizeTriangle(
    IN TRIANGLE_t* pTriangle,
    OUT FRAMEBUFFER_t* pFramebuffer)
{
    TRIANGLE_t triangleXY;
    triangle_transformToPixelXY(pTriangle,
        pFramebuffer->width,
        pFramebuffer->height,
        &triangleXY);

    U4 minY = (U4) MAX(0, MIN(triangleXY.ptA.y, MIN(triangleXY.ptB.y, triangleXY.ptC.y)));
    U4 minX = (U4) MAX(0, MIN(triangleXY.ptA.x, MIN(triangleXY.ptB.x, triangleXY.ptC.x)));
    U4 maxY = (U4) MIN(pFramebuffer->height, (U4) MAX(triangleXY.ptA.y, MAX(triangleXY.ptB.y, triangleXY.ptC.y))+1);
    U4 maxX = (U4) MIN(pFramebuffer->width, (U4) MAX(triangleXY.ptA.x, MAX(triangleXY.ptB.x, triangleXY.ptC.x))+1);

    for (U4 y = minY; y < maxY; y++)
    {
        for (U4 x = minX; x < maxX; x++)
        {
            if (triangle_isPointIn(x, y, &triangleXY))
            {   
                U1 mask = 0x00;
                mask |= triangle_isPointIn((R4) x-.166f, (R4) y-.168f, &triangleXY) << 0;
                mask |= triangle_isPointIn((R4) x-.166f, (R4) y-.002f, &triangleXY) << 1;
                mask |= triangle_isPointIn((R4) x-.166f, (R4) y+.164f, &triangleXY) << 2;
                mask |= triangle_isPointIn((R4) x-.166f, (R4) y+.330f, &triangleXY) << 6;
                
                mask |= triangle_isPointIn((R4) x+.166f, (R4) y-.168f, &triangleXY) << 3;
                mask |= triangle_isPointIn((R4) x+.166f, (R4) y-.002f, &triangleXY) << 4;
                mask |= triangle_isPointIn((R4) x+.166f, (R4) y+.164f, &triangleXY) << 5;
                mask |= triangle_isPointIn((R4) x+.166f, (R4) y+.330f, &triangleXY) << 7;
                framebuffer_setPixel(x, y, mask, 0, pFramebuffer);
            }
        }
    }
}

