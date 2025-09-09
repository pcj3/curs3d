#include "framebuffer.h"
#include "defs.h"
#include <string.h>

void framebuffer_clear(
    IN const COLOR_t k_color,
    OUT FRAMEBUFFER_t* p_framebuffer)
{
    p_framebuffer->height = 0;
    p_framebuffer->width = 0;
    memset(p_framebuffer->depths, FRAMEBUFFER_MAX_DEPTH, sizeof(DEPTH_t) * FRAMEBUFFER_DEPTHS_SIZE_MAX);
    memset(p_framebuffer->colors, k_color, sizeof(COLOR_t) * FRAMEBUFFER_DEPTHS_SIZE_MAX);
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
    IN const COLOR_t k_color,
    IN const DEPTH_t k_depth,
    INOUT FRAMEBUFFER_t* p_framebuffer)
{
    U4 idx = XY_TO_FRAMEBUFFER_IDX(k_x, k_y, p_framebuffer->width);

    if (k_depth >= p_framebuffer->depths[idx])
    {
        return;
    }
    p_framebuffer->colors[idx] = k_color;
    p_framebuffer->depths[idx] = k_depth;
}

void framebuffer_print(
    IN const FRAMEBUFFER_t* p_framebuffer)
{   
    U4 idx;
    for (U4 y = 0; y < p_framebuffer->height; y++)
    {
        for (U4 x = 0; x < p_framebuffer->width; x++)
        {   
            idx = XY_TO_FRAMEBUFFER_IDX(x, y, p_framebuffer->width);
            COLOR_t color = p_framebuffer->colors[idx];
            if (!color)
            {
                continue;
            }
            //attron(COLOR_PAIR(color >> 8));
            mvaddch((I) y, (I) x, (CH) color);
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
    U4 maxY = (U4) MIN(pFramebuffer->height, ceil(MAX(triangleXY.ptA.y, MAX(triangleXY.ptB.y, triangleXY.ptC.y)))+1);
    U4 maxX = (U4) MIN(pFramebuffer->width, ceil(MAX(triangleXY.ptA.x, MAX(triangleXY.ptB.x, triangleXY.ptC.x)))+1);
    
    for (U4 y = minY; y < maxY; y++)
    {
        for (U4 x = minX; x < maxX; x++)
        {
            if (triangle_isPointIn(x, y, &triangleXY))
            {
                framebuffer_setPixel(x, y, '#', 0, pFramebuffer);
            }
        } 
    }
}

