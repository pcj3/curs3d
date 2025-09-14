#include "framebuffer.h"
#include "shader_fragment.h"

void framebuffer_clear(
    OUT FRAMEBUFFER_t* p_framebuffer)
{
    p_framebuffer->height = 0;
    p_framebuffer->width = 0;
    memset(p_framebuffer->depths, FRAMEBUFFER_MAX_DEPTH, sizeof(DEPTH_t) * FRAMEBUFFER_DEPTHS_SIZE_MAX);
    memset(p_framebuffer->colors, 0, sizeof(COLOR_t) * FRAMEBUFFER_COLORS_SIZE_MAX);
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
    U4 idxPixelDot = idxPixel * BRAILLE_DOTS_COUNT;
    for (U1 idxDot = 0; idxDot < BRAILLE_DOTS_COUNT; idxDot++)
    {
        if (    (braille_getDotState(kBraille.dotMask, idxDot))
                && (kBraille.depths[idxDot] < pFramebuffer->depths[idxPixelDot+idxDot])
        )
        {
            braille_setDot(&pFramebuffer->glyphs[idxPixel], idxDot);
            pFramebuffer->depths[idxPixelDot+idxDot] = kBraille.depths[idxDot];
            pFramebuffer->colors[idxPixelDot+idxDot] = kBraille.colors[idxDot];
        }
    }
}

void framebuffer_rasterizeTriangle(
    IN TRIANGLE_t* pTriangleVerticies,
    IN TRIANGLE_t* pTriangleNormals,
    IN TRIANGLE_t* pTrianglePosToLight,
    OUT FRAMEBUFFER_t* pFramebuffer)
{
    TRIANGLE_t triangleXY;
    triangle_transformToPixelXY(pTriangleVerticies,
        pFramebuffer->width,
        pFramebuffer->height,
        &triangleXY);

    U4 minY = (U4) MAX(0, MIN(triangleXY.ptA.y, MIN(triangleXY.ptB.y, triangleXY.ptC.y)));
    U4 minX = (U4) MAX(0, MIN(triangleXY.ptA.x, MIN(triangleXY.ptB.x, triangleXY.ptC.x)));
    U4 maxY = (U4) MIN(pFramebuffer->height, 
                        ceilf(MAX(triangleXY.ptA.y, 
                            MAX(triangleXY.ptB.y, 
                                triangleXY.ptC.y)))+1);
    U4 maxX = (U4) MIN(pFramebuffer->width,
                        ceilf(MAX(triangleXY.ptA.x, 
                            MAX(triangleXY.ptB.x, 
                                triangleXY.ptC.x)))+1);

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
                triangle_setVecBarrycentric(
                    (R4)x + BRAILLE_LUT[idxDot].dx,
                    (R4)y + BRAILLE_LUT[idxDot].dy,
                    &dataBarrycentric,
                    &triangleXY.ptC,
                    &vecBarrycentric);

                if (triangle_isPointIn(&vecBarrycentric))
                {   
                    R4 denom = (vecBarrycentric.x / pTriangleVerticies->ptA.w) 
                        + (vecBarrycentric.y / pTriangleVerticies->ptB.w) 
                        + (vecBarrycentric.z / pTriangleVerticies->ptC.w);
                    VECTOR3_t correctedBarrycentric = {
                        .x = vecBarrycentric.x / pTriangleVerticies->ptA.w / denom,
                        .y = vecBarrycentric.y / pTriangleVerticies->ptB.w / denom,
                        .z = vecBarrycentric.z / pTriangleVerticies->ptC.w / denom, 
                    };

                    braille_setDot(&braille.dotMask, idxDot);
                    braille.depths[idxDot] = ( 
                        (pTriangleVerticies->ptA.z / pTriangleVerticies->ptA.w) * vecBarrycentric.x 
                        + (pTriangleVerticies->ptB.z / pTriangleVerticies->ptB.w) * vecBarrycentric.y 
                        + (pTriangleVerticies->ptC.z / pTriangleVerticies->ptC.w) * vecBarrycentric.z) 
                        * FRAMEBUFFER_MAX_DEPTH;
                    
                    VECTOR3_t correctedNormals = {
                        .x =      pTriangleNormals->ptA.x* correctedBarrycentric.x
                                + pTriangleNormals->ptB.x * correctedBarrycentric.y 
                                + pTriangleNormals->ptC.x * correctedBarrycentric.z,
                        .y =      pTriangleNormals->ptA.y * correctedBarrycentric.x
                                + pTriangleNormals->ptB.y * correctedBarrycentric.y
                                + pTriangleNormals->ptC.y * correctedBarrycentric.z,
                        .z =      pTriangleNormals->ptA.z * correctedBarrycentric.x
                                + pTriangleNormals->ptB.z * correctedBarrycentric.y
                                + pTriangleNormals->ptC.z * correctedBarrycentric.z
                    };

                    VECTOR3_t correctedPosToLight = {
                        .x =      (pTrianglePosToLight->ptA.x * correctedBarrycentric.x 
                                + pTrianglePosToLight->ptB.x * correctedBarrycentric.y 
                                + pTrianglePosToLight->ptC.x * correctedBarrycentric.z)
                                / denom,
                        .y =      (pTrianglePosToLight->ptA.y * correctedBarrycentric.x
                                + pTrianglePosToLight->ptB.y * correctedBarrycentric.y
                                + pTrianglePosToLight->ptC.y * correctedBarrycentric.z)
                                / denom,
                        .z =      (pTrianglePosToLight->ptA.z * correctedBarrycentric.x
                                + pTrianglePosToLight->ptB.z * correctedBarrycentric.y
                                + pTrianglePosToLight->ptC.z * correctedBarrycentric.z)
                                / denom
                    };

                    
                    R4 shade;
                    shaderFragment_do(&correctedNormals,
                        &correctedPosToLight,
                        &shade);

                    braille.colors[idxDot] = shade * SHADE_COUNT;
                }
            }
            
            framebuffer_setPixel(x, y, braille, pFramebuffer);
        }
    }
}
