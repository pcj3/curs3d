#include <math.h>

#include "defs.h"
#include "raster.h"
#include "triangle.h"

void draw_raster(
    IN TRIANGLE_t* p_triangle,
    OUT FRAMEBUFFER_t* p_frameBuffer)
{
    

    U4 minY = (U4) MAX(0, MIN(p_triangle->ptA.y, MIN(p_triangle->ptB.y, p_triangle->ptC.y)));
    U4 minX = (U4) MAX(0, MIN(p_triangle->ptA.x, MIN(p_triangle->ptB.x, p_triangle->ptC.x)));
    U4 maxY = (U4) MIN(p_frameBuffer->height, ceil(MAX(p_triangle->ptA.y, MAX(p_triangle->ptB.y, p_triangle->ptC.y)))+1);
    U4 maxX = (U4) MIN(p_frameBuffer->width, ceil(MAX(p_triangle->ptA.x, MAX(p_triangle->ptB.x, p_triangle->ptC.x)))+1);
    
    for (U4 y = minY; y < maxY; y++)
    {
        for (U4 x = minX; x < maxX; x++)
        {
            if (triangle_isPointIn(x, y, p_triangle))
            {
                mvaddch(y, x, '#');
            }
            else 
            {
                mvaddch(y, x, '.');
            }
        } 
    }
}