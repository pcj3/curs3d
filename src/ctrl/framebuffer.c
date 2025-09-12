#include "framebuffer.h"

void framebuffer_clear(
    OUT FRAMEBUFFER_t* p_framebuffer)
{
    p_framebuffer->height = 0;
    p_framebuffer->width = 0;
    memset(p_framebuffer->depths, FRAMEBUFFER_MAX_DEPTH, sizeof(DEPTH_t) * FRAMEBUFFER_DEPTHS_SIZE_MAX);
    memset(p_framebuffer->glyphs, 0, sizeof(GLYPH_t) * FRAMEBUFFER_GLYPHS_SIZE_MAX);
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
    IN const U4 kX,
    IN const U4 kY,
    IN const BRAILLE_t kBraille,
    INOUT FRAMEBUFFER_t* pFramebuffer)
{
    U4 idxPixel = XY_TO_FRAMEBUFFER_IDX(kX, kY, pFramebuffer->width);
    U4 idxDepth = idxPixel * BRAILLE_DOTS_COUNT;
    for (U1 idxDot = 0; idxDot < BRAILLE_DOTS_COUNT; idxDot++)
    {
        if (    (braille_getDotState(kBraille.dotMask, idxDot))
                && (kBraille.depths[idxDot] < pFramebuffer->depths[idxDepth+idxDot])
        )
        {
            braille_setDot(&pFramebuffer->glyphs[idxPixel], idxDot);
            pFramebuffer->depths[idxDepth+idxDot] = kBraille.depths[idxDot];
        }
    }
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

    BARRYCENTRIC_DATA_t dataBarrycentric;
    triangle_getDataBarrycentric(&triangleXY, &dataBarrycentric);
    for (U4 y = minY; y < maxY; y++)
    {
        for (U4 x = minX; x < maxX; x++)
        {
            BRAILLE_t braille = {0};
            for (int idxDot = 0; idxDot < BRAILLE_DOTS_COUNT; idxDot++)
            {
                VECTOR3_t vecBarrycentric = {0};

                R4 cornerTopLeftX = (R4)x + BRAILLE_LUT[idxDot].dx;
                R4 cornerTopLeftY = (R4)y + BRAILLE_LUT[idxDot].dy;
                if (   (cornerTopLeftX < 0.f) || (cornerTopLeftX >= (R4)pFramebuffer->width)
                    || (cornerTopLeftY < 0.f) || (cornerTopLeftY >= (R4)pFramebuffer->height))
                {
                    continue;
                }       
                triangle_setVecBarrycentric(
                    (R4)x + BRAILLE_LUT[idxDot].dx,
                    (R4)y + BRAILLE_LUT[idxDot].dy,
                    &dataBarrycentric,
                    &triangleXY.ptC,
                    &vecBarrycentric);

                if (triangle_isPointIn(&vecBarrycentric))
                {
                    braille_setDot(&braille.dotMask, idxDot);
                    braille.depths[idxDot] = ( \
                        (pTriangle->ptA.z / pTriangle->ptA.w) * vecBarrycentric.x \
                        + (pTriangle->ptB.z / pTriangle->ptB.w) * vecBarrycentric.y \
                        + (pTriangle->ptC.z / pTriangle->ptC.w) * vecBarrycentric.z) \
                        * FRAMEBUFFER_MAX_DEPTH;
                }
            }
            framebuffer_setPixel(x, y, braille, pFramebuffer);
        }
    }
}
