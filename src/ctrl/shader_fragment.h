#ifndef CTRL_SHADER_FRAGMENT_h
#define CTRL_SHADER_FRAGMENT_h
#include "defs.h"
#include "vector3.h"


void shaderFragment_do(
    IN VECTOR3_t* pNormals,
    IN VECTOR3_t* pPosToLight,
    OUT R4*       pBrightness);



#endif // CTRL_SHADER_FRAGMENT_h