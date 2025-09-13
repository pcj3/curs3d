#ifndef CTRL_SHADER_FRAGMENT_h
#define CTRL_SHADER_FRAGMENT_h
#include "defs.h"
#include "vector4.h"


void shaderFragment_do(
    IN VECTOR4_t* pNormals,
    IN VECTOR4_t* pPosToLight,
    OUT R4*       pBrightness);



#endif // CTRL_SHADER_FRAGMENT_h