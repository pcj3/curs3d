#ifndef DRAW_RASTER_h
#define DRAW_RASTER_h

#include "defs.h"
#include "vector2.h"
#include "triangle.h"

typedef struct FRAMEBUFFER_s {
    U4 width;
    U4 height;
} FRAMEBUFFER_t; 

void draw_raster(
    IN TRIANGLE_t* p_triangle,
    OUT FRAMEBUFFER_t* p_frameBuffer);

#endif // DRAW_RASTER_h