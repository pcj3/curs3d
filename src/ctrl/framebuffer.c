#include "framebuffer.h"
#include "defs.h"
#include <string.h>

void framebuffer_clear(
    OUT FRAMEBUFFER_t* p_framebuffer)
{
    p_framebuffer->height = 0;
    p_framebuffer->width = 0;
    memset(p_framebuffer->depths, FRAMEBUFFER_MAX_DEPTH, sizeof(DEPTH_t) * FRAMEBUFFER_DEPTHS_SIZE_MAX);
    memset(p_framebuffer->glyphs, 0, sizeof(GLYPH_t) * FRAMEBUFFER_DEPTHS_SIZE_MAX);
}

void framebuffer_setSize(
    IN U4 width,
    IN U4 height,
    OUT FRAMEBUFFER_t* p_framebuffer)
{
    p_framebuffer->width = width;
    p_framebuffer->height = height;
}
unsigned int popcount8(uint8_t x) {
    x = x - ((x >> 1) & 0x55);
    x = (x & 0x33) + ((x >> 2) & 0x33);
    return (((x + (x >> 4)) & 0x0F) * 0x01);
}

void framebuffer_setPixel(
    IN const U4 k_x,
    IN const U4 k_y,
    IN const GLYPH_t k_glyph,
    IN const DEPTH_t k_depth,
    INOUT FRAMEBUFFER_t* p_framebuffer)
{
    U4 idx = XY_TO_FRAMEBUFFER_IDX(k_x, k_y, p_framebuffer->width);
    if ((k_depth >= p_framebuffer->depths[idx])
        //&& (popcount8(k_glyph) < popcount8(p_framebuffer->glyphs[idx]))
    ) 
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

    BARRYCENTRIC_DATA_t dataBarrycentric;
    VECTOR3_t vecBarrycentric;
    triangle_getDataBarrycentric(&triangleXY, &dataBarrycentric);

    for (U4 y = minY; y < maxY; y++)
    {
        for (U4 x = minX; x < maxX; x++)
        {   
                        
            triangle_getVecBarrycentric((R4)x, 
                    (R4)y,
                    &dataBarrycentric,
                    &triangleXY.ptC,
                    &vecBarrycentric);

            if (triangle_isPointIn(&vecBarrycentric))
            {
                framebuffer_setPixel(x, y, 0xFF, 0, pFramebuffer); 
            }


            // static const struct {
            // R4 dx, dy;
            // U1 bit;
            // } dots[8] = {
            //     {-0.166f, -0.168f, 0},
            //     {-0.166f, -0.002f, 1},
            //     {-0.166f, +0.164f, 2},
            //     {-0.166f, +0.330f, 6},
            //     {+0.166f, -0.168f, 3},
            //     {+0.166f, -0.002f, 4},
            //     {+0.166f, +0.164f, 5},
            //     {+0.166f, +0.330f, 7},
            // };

            // GLYPH_t glyph = 0;
            // R4 depth = 0;
            // U1 dotsCount = 0;
            // for (int i = 0; i < 8; i++) 
            // {   
            //     triangle_getVecBarrycentric((R4)x+dots[i].dx, 
            //         (R4)y+dots[i].dy,
            //         &dataBarrycentric,
            //         &triangleXY.ptC,
            //         &vecBarrycentric);
                
            //     if (triangle_isPointIn(&vecBarrycentric))
            //     {
            //         glyph |= (1u << dots[i].bit);
            //         depth +=      (pTriangle->ptA.z / pTriangle->ptA.w) * vecBarrycentric.x \
            //                     + (pTriangle->ptB.z / pTriangle->ptB.w) * vecBarrycentric.y \
            //                     + (pTriangle->ptC.z / pTriangle->ptC.w) * vecBarrycentric.z;
            //         dotsCount++;
            //     }     
            // }
            // if (dotsCount)
            // {
            //     depth /= dotsCount;
            //     depth *= FRAMEBUFFER_MAX_DEPTH;
            //     framebuffer_setPixel(x, y, 0xFF, depth, pFramebuffer); 
            // }
        }
    }
}

