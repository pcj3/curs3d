#include "shader_fragment.h"
#include "defs.h"
#include "vector3.h"

void shaderFragment_do(
    IN VECTOR4_t* pNormals,
    IN VECTOR4_t* pPosToLight,
    OUT R4*       pBrightness)
{
    VECTOR3_t normal = {
        .x = pNormals->x,
        .y = pNormals->y,
        .z = pNormals->z,
    };

    VECTOR3_t postoLight = {
        .x = pPosToLight->x,
        .y = pPosToLight->y,
        .z = pPosToLight->z,
    };
    vector3_normalize(&normal, &normal);
    vector3_normalize(&postoLight, &postoLight);
    R4 brightness = MAX(.19f, 
        normal.x * postoLight.x + normal.y * postoLight.y + normal.z * postoLight.z);
    *pBrightness = 1.f - brightness;
}