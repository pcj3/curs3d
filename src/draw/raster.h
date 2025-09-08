#ifndef DRAW_RASTER_h
#define DRAW_RASTER_h

#include "defs.h"
#include "triangle.h"
#include "framebuffer.h"

void raster_triangle(
    IN TRIANGLE_t* p_triangle,
    OUT FRAMEBUFFER_t* p_framebuffer);

void raster_draw(
    IN const FRAMEBUFFER_t* p_framebuffer);
#endif // DRAW_RASTER_h