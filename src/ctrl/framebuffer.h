#ifndef DRAW_FRAMEBUFFER_h
#define DRAW_FRAMEBUFFER_h

#define FRAMEBUFFER_DEPTHS_SIZE_MAX 20000
#define FRAMEBUFFER_GLYPHS_SIZE_MAX 20000

#include "defs.h"
#include "triangle.h"

#define FRAMEBUFFER_MAX_DEPTH 0xFF
#define XY_TO_FRAMEBUFFER_IDX(x, y, width) ((y) * (width) + (x))

typedef struct FRAMEBUFFER_s {
    U4 width;
    U4 height;
    GLYPH_t glyphs[FRAMEBUFFER_GLYPHS_SIZE_MAX];
    DEPTH_t depths[FRAMEBUFFER_DEPTHS_SIZE_MAX];
} FRAMEBUFFER_t;

void framebuffer_clear(
    IN const GLYPH_t k_glyph,
    OUT FRAMEBUFFER_t* p_framebuffer);

void framebuffer_setSize(
    IN U4 width,
    IN U4 heigth,
    OUT FRAMEBUFFER_t* p_framebuffer);

void framebuffer_setPixel(
    IN const U4 k_x,
    IN const U4 k_y,
    IN const GLYPH_t k_glyph,
    IN const DEPTH_t k_depth,
    INOUT FRAMEBUFFER_t* p_framebuffer);

void framebuffer_rasterizeTriangle(
    IN TRIANGLE_t* pTriangle,
    OUT FRAMEBUFFER_t* pFramebuffer);


#endif // DRAW_FRAMEBUFFER_h