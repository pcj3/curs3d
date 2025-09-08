#include <math.h>

#include "defs.h"
#include "raster.h"
#include "triangle.h"

#define TO_PIXEL_XY(x, dhim) (x * hdim + hdim)

void raster_triangle(
    IN TRIANGLE_t* pTriangle,
    OUT FRAMEBUFFER_t* pFramebuffer)
{   
    TRIANGLE_t triangleXY;
    triangle_transformToPixelXY(pTriangle, pFramebuffer, &triangleXY);

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

void raster_draw(IN const FRAMEBUFFER_t* p_frambuffer)
{
    framebuffer_print(p_frambuffer);
}