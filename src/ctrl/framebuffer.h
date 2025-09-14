#ifndef DRAW_FRAMEBUFFER_h
#define DRAW_FRAMEBUFFER_h

#include "triangle.h"
#include "defs.h"
#include "braille.h"

#define FRAMEBUFFER_MAX_DEPTH ((DEPTH_t) 0xFF)
#define FRAMEBUFFER_SIZE_MAX (30000)
#define FRAMEBUFFER_DEPTHS_SIZE_MAX (FRAMEBUFFER_SIZE_MAX * BRAILLE_DOTS_COUNT)
#define FRAMEBUFFER_COLORS_SIZE_MAX (FRAMEBUFFER_SIZE_MAX * BRAILLE_DOTS_COUNT)
#define FRAMEBUFFER_GLYPHS_SIZE_MAX (FRAMEBUFFER_SIZE_MAX)

#define XY_TO_FRAMEBUFFER_IDX(x, y, width) ((y) * (width) + (x))

typedef struct FRAMEBUFFER_s {
    U4 width;
    U4 height;
    GLYPH_t glyphs[FRAMEBUFFER_GLYPHS_SIZE_MAX];
    DEPTH_t depths[FRAMEBUFFER_DEPTHS_SIZE_MAX];
    COLOR_t colors[FRAMEBUFFER_COLORS_SIZE_MAX];
} FRAMEBUFFER_t;

void framebuffer_clear(
    OUT FRAMEBUFFER_t* p_framebuffer);

void framebuffer_setSize(
    IN U4 width,
    IN U4 heigth,
    OUT FRAMEBUFFER_t* p_framebuffer);

void framebuffer_setPixel(
    IN const U4 kX,
    IN const U4 kY,
    IN const BRAILLE_t kBraille,
    INOUT FRAMEBUFFER_t* pFamebuffer);

void framebuffer_rasterizeTriangle(
    IN TRIANGLE_t* pTriangleVerticies,
    IN TRIANGLE_t* pTriangleNormals,
    IN TRIANGLE_t* pTrianglePosToLight,
    OUT FRAMEBUFFER_t* pFramebuffer);

#endif // DRAW_FRAMEBUFFER_h