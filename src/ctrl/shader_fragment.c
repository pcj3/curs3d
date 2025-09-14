#include "shader_fragment.h"
#include "defs.h"


void shaderFragment_do(
    IN VECTOR3_t* pNormals,
    IN VECTOR3_t* pPosToLight,
    OUT R4*       pBrightness)
{
    vector3_normalize(pNormals, pNormals);
    vector3_normalize(pPosToLight, pPosToLight);
    R4 shade = pNormals->x * pPosToLight->x 
        + pNormals->y * pPosToLight->y 
        + pNormals->z * pPosToLight->z;
    shade = MAX(.19, shade);
    *pBrightness = (1.f - shade);
}