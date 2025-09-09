#ifndef DRAW_FRAMEBUFFER_h
#define DRAW_FRAMEBUFFER_h

#define FRAMEBUFFER_DEPTHS_SIZE_MAX 10000
#define FRAMEBUFFER_COLORS_SIZE_MAX 10000

#include "defs.h"
#include "triangle.h"

#define FRAMEBUFFER_MAX_DEPTH 0xFF
#define XY_TO_FRAMEBUFFER_IDX(x, y, width) ((y) * (width) + (x))

typedef struct FRAMEBUFFER_s {
    U4 width;
    U4 height;
    COLOR_t colors[FRAMEBUFFER_COLORS_SIZE_MAX];
    DEPTH_t depths[FRAMEBUFFER_DEPTHS_SIZE_MAX];
} FRAMEBUFFER_t; 

void framebuffer_clear(
    IN const COLOR_t k_color,
    OUT FRAMEBUFFER_t* p_framebuffer);

void framebuffer_setSize(
    IN U4 width,
    IN U4 heigth,
    OUT FRAMEBUFFER_t* p_framebuffer);

void framebuffer_setPixel(
    IN const U4 k_x,
    IN const U4 k_y,
    IN const COLOR_t k_color,
    IN const DEPTH_t k_depth,
    INOUT FRAMEBUFFER_t* p_framebuffer);

void framebuffer_rasterizeTriangle(
    IN TRIANGLE_t* pTriangle,
    OUT FRAMEBUFFER_t* pFramebuffer);

void framebuffer_draw(
    IN const FRAMEBUFFER_t* p_framebuffer);
    
#endif // DRAW_FRAMEBUFFER_h